/*
 * SampleApplication.cpp
 *
 *      Author: Peter Maurer
 */

#include "ApplicationDemo/SampleApplication.h"

#include "ApplicationDemo/DemoClient.h"

#include "Poco/Logger.h"
#include "Poco/LogStream.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/IntValidator.h"

#include <iostream>

// POCO_APP_MAIN(ApplicationDemo::SampleApplication);
//
// For demonstration reasons, we use the main fuction as defined in macro POCO_APP_MAIN explicitly
//
int main(int argc, char** argv)
{
	Poco::AutoPtr<ApplicationDemo::SampleApplication> pApp = new ApplicationDemo::SampleApplication;
	try
	{
		pApp->init(argc, argv);
	}
	catch (Poco::Exception& exc)
	{
		pApp->logger().log(exc);
		return Poco::Util::Application::EXIT_CONFIG;
	}
	return pApp->run();
}

namespace ApplicationDemo
{
	using Poco::Logger;
	using Poco::LogStream;
	using Poco::Util::HelpFormatter;
	using Poco::Util::Option;
	using Poco::Util::OptionCallback;
	using Poco::Util::IntValidator;


	SampleApplication::SampleApplication():
		_helpRequested(false)
	{
		addSubsystem(new DemoClient());
	}

	SampleApplication::~SampleApplication()
	{}

	void SampleApplication::initialize(Application& self)
	{
		loadConfiguration();
		Application::initialize(self);
		logger().debug("initializing");
	}

	void SampleApplication::defineOptions(OptionSet &options)
	{
		Application::defineOptions(options);
		options.addOption(
			Option("help","h","display help")
				.required(false)
				.repeatable(false)
				.callback(OptionCallback<SampleApplication>(this, &SampleApplication::handleHelp))
		);
	}

	void SampleApplication::handleHelp(const string &name, const string &value)
	{
		_helpRequested=true;
		displayHelp();
		stopOptionsProcessing();
	}

	void SampleApplication::displayHelp()
	{
	    HelpFormatter helpFormatter(options());
	    helpFormatter.setCommand(commandName());
	    helpFormatter.setUsage("OPTIONS");
	    helpFormatter.setHeader(
	        "Demonstrate usage of application configuration");
	    helpFormatter.format(std::cout);
	}

	int SampleApplication::main(const vector<string>& args)
	{
		if (!_helpRequested)
		{
			LogStream logStream(logger());
			logStream.information()<<"Sample Application started"<<std::endl;

			DemoClient& demoClient = getSubsystem<DemoClient>();
			if (demoClient.configured())
			{
				demoClient.run();
			}
		}
		return Application::EXIT_OK;
	}
}
