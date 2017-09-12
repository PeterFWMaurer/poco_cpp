/*
 * HelloPluginImpl.cpp
 *
 * Author: Peter Maurer
 *
 * Eine Implementierung unseres Plugins mit Manifest
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen

 */

#include "../include/SimpleShared/HelloPlugin.h"

#include "Poco/ClassLibrary.h"

#include <iostream>

class HelloPluginImpl : public HelloPlugin
{
public:
	HelloPluginImpl(){}

	virtual ~HelloPluginImpl(){}

	std::string sayHello(const std::string& name)
	{
		std::string helloMsg = std::string("Hello, ");
		helloMsg += name;
		return helloMsg;
	}
};

POCO_BEGIN_MANIFEST(HelloPlugin)
	POCO_EXPORT_CLASS(HelloPluginImpl)
POCO_END_MANIFEST




