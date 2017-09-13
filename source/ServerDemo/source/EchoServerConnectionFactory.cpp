/*
 * EchoServerConnectionFactory.cpp
 *
 * EchoServeConnection.h
 *
 * Author: Peter Maurer
 *
 * Beispiel fuer eine TCPServerConnectionFactory, die eine EchoServerConnection erzeugt
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
