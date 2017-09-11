/*
 * ExceptionSample.cpp
 *
 * Author: Peter Maurer
 *
 * Dieses Beispiel zeigt den Umgang mit Poco::Exception und der entsprechenden
 * Vererbungshierarchie
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "ErrorDemo/ExceptionSample.h"

#include "Poco/Exception.h"

#include <typeinfo> // required for POCO_IMPLEMENT_EXCEPTION macro

namespace ErrorDemo
{
	using Poco::Exception;

	// Von POCO::Exception abgeleitete Exceptions werden am besten mit Hilfe
	// des Macros POCO_DECLARE_EXCEPTION deklariert und mit POCO_IMPLEMENT_EXCEPTION
	// implementiert.
	//
	// Für statische Bibliotheken und Unix-Betriebssysteme kann auf ein API spezifisches Macro verzichtet werden
	//
	POCO_DECLARE_EXCEPTION(,MyException,Exception);
	POCO_IMPLEMENT_EXCEPTION(MyException,Exception,"ErrorDemo::MyException");
	POCO_DECLARE_EXCEPTION(,NestedSampleException,Exception);
	POCO_IMPLEMENT_EXCEPTION(NestedSampleException,Exception,"ErrorDemo::NestedSampleException");

	// Beispielfunktion zum Erzeugen einer Exception
	//
	void offendingFunction(std::ostream& os)
	{
		os<<"Throwing MyException"<<std::endl;
		// Exception werden in C++ grundsätzlich by value erzeugt.
		throw MyException("offendingFunction caused MyException");
	}

	// Beispielfunktion zum Erzeugen einer Nested Exception
	//
	void nestedOffendingFunction(std::ostream& os)
	{
		try
		{
			offendingFunction(os);
		}
		catch (const MyException &exp)
		{
			// Eine Nested Exception wird erzeugt, indem die enthaltene Exception als
			// zweites Argument im Konstruktor übergeben wird. Deshalb kann grundsätzlich
			// jede Exception unabhängig von ihrem Typ als nested Exception auftreten.
			throw NestedSampleException("nestedOffendingFunction caugth MyException",exp);
		}
	}

	// Run Funktion unseres ExceptionSamples
	//
	void ExceptionSample::run(std::ostream &os, std::istream &is)
	{
		try
		{
			offendingFunction(os);
		}
		// Exceptions werden in C++ grundsätzlich by reference gefangen
		catch (const MyException &exp)
		{
			os<<"exp.what(): "<<exp.what()<<std::endl;
			os<<"exp.message(): "<<exp.message()<<std::endl;
			os<<"exp.displayText(): "<<exp.displayText()<<std::endl;
		}

		try
		{
			nestedOffendingFunction(os);
		}
		catch (const NestedSampleException &exp)
		{
			os<<"exp.displayText(): "<<exp.displayText()<<std::endl;

			const Exception *pNestedException=exp.nested();
			if(pNestedException)
			{
				os<<"nested with:"<<std::endl;
				os<<"Nested displayText:"<<pNestedException->displayText()<<std::endl;
			}
		}
	}

} /* namespace ErrorDemo */
