/*
 * EchoServerConnectionFactory.h
 *
 * EchoServeConnection.h
 *
 * Author: Peter Maurer
 *
 * Beispiel fuer eine TCPServerConnectionFactory, die eine EchoServerConnection erzeugt
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef SERVERDEMO_SOURCE_ECHOSERVERCONNECTIONFACTORY_H_
#define SERVERDEMO_SOURCE_ECHOSERVERCONNECTIONFACTORY_H_


#include <Poco/Net/TCPServerConnectionFactory.h>

#include "Poco/Logger.h"

namespace ServerDemo {

	using Poco::Logger;
	using Poco::Net::StreamSocket;
	using Poco::Net::TCPServerConnection;
	using Poco::Net::TCPServerConnectionFactory;

	class EchoServerConnectionFactory: public TCPServerConnectionFactory
	{
	public:
		EchoServerConnectionFactory(Logger& _logger);

		virtual ~EchoServerConnectionFactory();

		TCPServerConnection* createConnection(const StreamSocket& socket);

	private:
		Logger& _logger;
	};

} /* namespace ServerDemo */

#endif /* SERVERDEMO_SOURCE_ECHOSERVERCONNECTIONFACTORY_H_ */
