/*
 * SampleServer.cpp
 *
 *  Created on: Sep 9, 2017
 *      Author: peter
 */

#include "ServerDemo/SampleServer.h"

#include "ServerDemo/EchoServerMTSub.h"

#include <iostream>

POCO_SERVER_MAIN(ServerDemo::SampleServer);

namespace ServerDemo
{
	SampleServer::SampleServer()
	{
		addSubsystem(new EchoServerMTSub());
	}

	SampleServer::~SampleServer()
	{}

	void SampleServer::initialize(Application &self)
	{
		loadConfiguration();
		ServerApplication::initialize(self);
	}

	void SampleServer::uninitialize()
	{
		ServerApplication::uninitialize();
	}

	void SampleServer::defineOptions(OptionSet& options)
	{
		ServerApplication::defineOptions(options);
	}

	int SampleServer::main(const vector<string>& args)
	{
		EchoServerMTSub& echoServer = getSubsystem<EchoServerMTSub>();
		echoServer.startService();
		waitForTerminationRequest();
		echoServer.stopService();

		return Application::EXIT_OK;
	}

} /* namespace ApplicationDemo */
