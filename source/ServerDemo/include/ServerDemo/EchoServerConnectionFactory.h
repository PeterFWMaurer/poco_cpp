/*
 * EchoServerConnectionFactory.h
 *
 *  Created on: Sep 10, 2017
 *      Author: parallels
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
