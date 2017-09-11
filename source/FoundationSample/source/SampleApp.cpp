/*
 * PocoSampleApplication.cpp
 *
 *
 */

#include "FoundationSample/SampleApp.h"

#include "TypeDemo/TypeDemoSub.h"
#include "ThreadDemo/ThreadDemoSub.h"
#include "ErrorDemo/ErrorDemoSub.h"
#include "MemoryDemo/MemoryDemoSub.h"
#include "EventDemo/EventDemoSub.h"
#include "NotificationDemo/NotificationDemoSub.h"


#include <iostream>

#include "Poco/Util/Application.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionCallback.h"


using Poco::Util::Option;
using Poco::Util::OptionCallback;
using Poco::Util::HelpFormatter;

POCO_APP_MAIN(FoundationSample::SampleApp);

namespace FoundationSample
{

	using TypeDemo::TypeDemoSub;
	using ErrorDemo::ErrorDemoSub;
	using MemoryDemo::MemoryDemoSub;
	using ThreadDemo::ThreadDemoSub;
	using SampleSubsystem::SampleSub;
	using EventDemo::EventDemoSub;
	using NotificationDemo::NotificationDemoSub;

	SampleApp::SampleApp():
			_helpRequested(false)
	{
		addSubsystem(new TypeDemoSub());
		addSubsystem(new ErrorDemoSub());
		addSubsystem(new MemoryDemoSub());
		addSubsystem(new EventDemoSub());
		addSubsystem(new NotificationDemoSub());
		// addSubsystem(new ThreadDemoSub());
	//	SampleSubsystem::SampleSub *pS=new SampleSubsystem::SampleSub("Hallo");
	//	addSubsystem(new TestSubsystem);
	}

	void SampleApp::initialize(Application &self)
	{
		Application::initialize(self);
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
		helpFormatter.setHeader("Sample Application for Elements of Poco::Foundation");
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
		{
			std::cout<<"Sample Application for Elements of Poco::Foundation"<<std::endl;

			for(auto subsysIt : subsystems())
			{
				Poco::AutoPtr<SampleSub> pSmpSub;
				pSmpSub = subsysIt.cast<SampleSub>();
				if (pSmpSub)
				{
					pSmpSub->run(std::cout,std::cin);
				}
			}
		}
		return Application::EXIT_OK;
	}
}
