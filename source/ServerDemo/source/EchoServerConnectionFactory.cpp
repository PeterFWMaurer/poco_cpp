/*
 * EchoServerConnectionFactory.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: parallels
 */

#include "ServerDemo/EchoServerConnectionFactory.h"

#include "ServerDemo/EchoServerConnection.h"

namespace ServerDemo
{

	EchoServerConnectionFactory::EchoServerConnectionFactory(Logger &logger):
		_logger(logger)
	{}

	EchoServerConnectionFactory::~EchoServerConnectionFactory()
	{}

	TCPServerConnection* EchoServerConnectionFactory::createConnection(const StreamSocket& socket)
	{
		return new EchoServerConnection(socket,_logger);
	}


} /* namespace ServerDemo */
