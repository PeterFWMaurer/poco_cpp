/*
 * TestSubsystem.cpp
 *
 *  Created on: Aug 23, 2017
 *      Author: peter
 */


#include "PocoSample/TestSubsystem.h"

#include <iostream>

#include "Poco/Util/Option.h"
#include "Poco/Util/OptionCallback.h"
#include "Poco/Util/OptionSet.h"

using Poco::Util::Option;
using Poco::Util::OptionCallback;
using Poco::Util::OptionSet;

const char *TestSubsystem::name() const
{
	return "TestSubsystem";
}

void TestSubsystem::initialize(Application &app)
{}

void TestSubsystem::reinitialize(Application &app)
{}

void TestSubsystem::uninitialize()
{}

void TestSubsystem::defineOptions(OptionSet &options)
{
	Subsystem::defineOptions(options);

	options.addOption(Option("TestSubsystem_suboption","","Sample suboption")
			.repeatable(false)
			.required(false)
			.callback(OptionCallback<TestSubsystem>(this,&TestSubsystem::handleTestOption)));
}

void TestSubsystem::handleTestOption(const std::string& name, const std::string& value)
{
	std::cout<<"Test::Option called"<<std::endl;
}
