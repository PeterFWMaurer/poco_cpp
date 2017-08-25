/*
 * PocoSampleApplication.cpp
 *
 *  Created on: Aug 23, 2017
 *      Author: peter
 */

#include "PocoSample/PocoSampleApplication.h"
#include "PocoSample/TestSubsystem.h"

#include <iostream>

#include "Poco/Util/Application.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionCallback.h"

using Poco::Util::Option;
using Poco::Util::OptionCallback;
using Poco::Util::HelpFormatter;

POCO_APP_MAIN(SampleApp);

SampleApp::SampleApp():
		_helpRequested(false)
{
	addSubsystem(new TestSubsystem);
}

void SampleApp::initialize(Application &self)
{
	Application::initialize(self);
}

void SampleApp::reinitialize(Application &self)
{
	Application::reinitialize(self);
}

void SampleApp::uinitialize()
{
	Application::uninitialize();
}

void SampleApp::defineOptions(OptionSet& options)
{
	Application::defineOptions(options);

	options.addOption(Option("help","h","display help information")
		.required(false)
		.repeatable(false)
		.callback(OptionCallback<SampleApp>(this, &SampleApp::handleHelp)));


}

void SampleApp::handleOption(const std::string &name, const std::string &value)
{
	Application::handleOption(name,value);
}

void SampleApp::displayHelp()
{
	HelpFormatter helpFormatter(options());
	helpFormatter.setCommand(commandName());
	helpFormatter.setUsage("OPTIONS");
	helpFormatter.setHeader("A sample application that demonstrates some Poco features");
	helpFormatter.format(std::cout);
}

void SampleApp::handleHelp(const std::string& name, const std::string& value)
{
	displayHelp();
	stopOptionsProcessing();
}

int SampleApp::main(const std::vector<std::string> &args)
{
	if (!_helpRequested)
	std::cout<<"Poco Sample Application"<<std::endl;
}
