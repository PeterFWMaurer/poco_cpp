/*
 * EchoServerMTSub.cpp
 *
 *  Created on: Sep 9, 2017
 *      Author: parallels
 */

#include "ServerDemo/EchoServerMTSub.h"

#include "ServerDemo/EchoServerConnectionFactory.h"

#include "Poco/Util/Application.h"
#include "Poco/Util/LayeredConfiguration.h"

namespace ServerDemo {

	using Poco::Net::ServerSocket;
	using Poco::Util::LayeredConfiguration;

	EchoServerMTSub::EchoServerMTSub():
		_name("EchoServerMTSub"),
		_port(DEFAULT_PORT),
		_pLogger(0)
	{}

	EchoServerMTSub::~EchoServerMTSub()
	{
		// TODO Auto-generated destructor stub
	}

	const char* EchoServerMTSub::name() const
	{
		return _name.c_str();
	}

	void EchoServerMTSub::initialize(Application &app)
	{
		_pLogger = &Logger::get(_name);
		_port = app.config().getInt("EchoServer.port",DEFAULT_PORT);
		logger().debug("Initializing EchoServerMTSub");
		logger().debug("Server will be listening on port %i",_port);
	}

	void EchoServerMTSub::uninitialize()
	{
	}

	void EchoServerMTSub::defineOptions(OptionSet &options)
	{
	}

	Logger& EchoServerMTSub::logger()
	{
		poco_check_ptr(_pLogger);
		return *_pLogger;
	}

	void EchoServerMTSub::startService()
	{
		_pTcpServer = new TCPServer(new EchoServerConnectionFactory(logger()),_port);
		_pTcpServer->start();
		logger().debug("Started TCPServer");
	}

	void EchoServerMTSub::stopService()
	{
		_pTcpServer->stop();
		logger().debug("Stopped TCPServer");
	}

} /* namespace ServerDemo */
