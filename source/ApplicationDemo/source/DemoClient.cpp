/*
 * DemoClient.cpp
 *
 *  Created on: Sep 8, 2017
 *      Author: peter
 */

#include "ApplicationDemo/DemoClient.h"

#include "Poco/Util/Application.h"


namespace ApplicationDemo
{

	POCO_IMPLEMENT_EXCEPTION(ConfigException,Poco::Exception,"DemoClient::ConfigException");


	DemoClient::DemoClient():
		_name("DemoClient"),
		_pLogger(0),
		_pConfig(0),
		_configured(false),
		_port(0),
		_count(0)
	{}

	const char* DemoClient::name() const
	{
		return _name.c_str();
	}

	void DemoClient::initialize(Application &app)
	{
		_pLogger = &Logger::get(_name);
		logger().debug("Client Subsystem initializing");
		_pConfig = app.config().createView(_name);
		AbstractConfiguration::Keys keys;
		config().keys(keys);
		for (auto keyIterator: keys)
		{
			logger().debug("%s = %s",keyIterator,config().getString(keyIterator));
		}
		_port = config().getInt("port");
		_server = config().getString("server");
		_message = config().getString("message");
		_count = config().getInt("count");
		if (_port < 0 || _port > 65535 ||
			_server.empty() ||
			_message.empty() ||
			_count <= 0)
		{
			LogStream logStream(logger());
			logStream.debug()<<"Current dir:"<<config().getString("system.currentDir")<<std::endl;
			logStream.fatal()<<"Server not correctly configured; please check your configuration"<<std::endl;
			logStream.flush();
			throw ConfigException("");
		}
		else
		{
			_configured=true;
		}

	}

	AbstractConfiguration& DemoClient::config()
	{
		poco_check_ptr(_pConfig);
		return *_pConfig;
	}

	Logger& DemoClient::logger()
	{
		poco_check_ptr(_pLogger);
		return *_pLogger;
	}

	void DemoClient::defineOptions(OptionSet &options)
	{
		options.addOption(
			Option("port","p","specify ip port of the server")
				.required(false)
				.repeatable(false)
				.argument("port")
				.validator(new IntValidator(0,65535))
				.binding(_name + ".port")
		);
	}

	bool DemoClient::configured() const
	{
		return _configured;
	}

	int DemoClient::run()
	{
		SocketAddress sockAddr(_server,_port);
		StreamSocket socket(sockAddr);
		SocketStream sockStream(socket);
		for (int i=0;i<_count;i++)
		{
			sockStream<<_message;
			sockStream.flush();
			StreamCopier::copyStream(sockStream,std::cout);
		}
		return Application::EXIT_NOHOST;
	}
}
