/*
 * SharedDemoMain.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel für das Laden von Shared Libraries zur Laufzeit
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */


// LibraryLoaderTest.cpp

#include "SimpleShared/HelloPlugin.h"

#include "Poco/ClassLoader.h"
#include "Poco/Manifest.h"
#include "Poco/SharedLibrary.h"
#include "Poco/SharedPtr.h"

#include <iostream>

using Poco::ClassLoader;
using Poco::Manifest;
using Poco::SharedLibrary;
using Poco::SharedPtr;

using std::string;

typedef void (*SaySomethingFct)(); // function pointer type

int main(int argc, char** argv)
{
	// const std::string FUNCTION_NAME = "_Z12saySomethingv"
	const std::string FUNCTION_NAME = "saySomething";
	string path("/usr/local/lib/libSimpleShared");
	path.append(SharedLibrary::suffix());
	try
	{
		// Wir greifen jetzt auf die C-Funktion saySomething in der SharedLibrary zu
		//
		SharedLibrary library(path); // will also load the library
		if (library.hasSymbol(FUNCTION_NAME))
		{
			SaySomethingFct saySomething = (SaySomethingFct) library.getSymbol(FUNCTION_NAME);
			saySomething();
		}
		else
		{
			std::cout<<"Symbol saySomething not found in shared library "<<path<<std::endl;
		}

		library.unload();
		std::cout<<"Unloaded Library"<<std::endl;
	}
	catch (const Poco::Exception &exp)
	{
		std::cout<<exp.message()<<std::endl;
		std::cout<<"Check if "<<path<<" is correctly installed."<<std::endl;
	}

	// Im folgenden laden wir die Shared Library erneut, um auf die Poco
	// spezifischen Elemente zuzugreifen
	try
	{
		// Wir erzeugen einen Class Loader fuer unser HelloPlugin
		ClassLoader<HelloPlugin> helloPluginLoader;

		helloPluginLoader.loadLibrary(path);

		// Wir geben alle im helloPluginLoader gefundenen Implementierungen unserer
		// Library aus und wollen (falls mehrere vorhanden sind) die erste nehmen.
		//
		string helloName;
		for (auto it: helloPluginLoader)
		{
			std::cout<<it->first<<std::endl;
			const Manifest<HelloPlugin> *pHelloManifest = it->second;
			for (auto manIt: *pHelloManifest)
			{
				std::cout<<manIt->name()<<std::endl;
			}
		}

		auto helloMeta = *helloPluginLoader.begin()->second->begin();
		HelloPlugin* pHelloPlugin1 = helloMeta->create();
		helloMeta->autoDelete(pHelloPlugin1);
		poco_check_ptr(pHelloPlugin1);
		std::cout<<pHelloPlugin1->sayHello("Poco")<<std::endl;
		{
			SharedPtr<HelloPlugin> pHelloPlugin2 = helloMeta->create();
			std::cout<<pHelloPlugin2->sayHello("ClassLoader")<<std::endl;
		}
		helloPluginLoader.unloadLibrary(path);
	}
	catch (const Poco::Exception &exp)
	{
		std::cout<<exp.message()<<std::endl;
	}
	return 0;
}

