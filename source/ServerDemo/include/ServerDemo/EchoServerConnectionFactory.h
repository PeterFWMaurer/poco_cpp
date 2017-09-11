/*
 * EchoServerConnectionFactory.h
 *
 *  Created on: Sep 10, 2017
 *      Author: parallels
 */

#ifndef SERVERDEMO_SOURCE_ECHOSERVERCONNECTIONFACTORY_H_
#define SERVERDEMO_SOURCE_ECHOSERVERCONNECTIONFACTORY_H_


#include <Poco/Net/TCPServerConnectionFactory.h>

namespace ServerDemo {

	using Poco::Net::StreamSocket;
	using Poco::Net::TCPServerConnection;
	using Poco::Net::TCPServerConnectionFactory;

	class EchoServerConnectionFactory: public TCPServerConnectionFactory
	{
	public:
		EchoServerConnectionFactory();

		virtual ~EchoServerConnectionFactory();

		TCPServerConnection* createConnection(const StreamSocket& socket);
	};

} /* namespace ServerDemo */

#endif /* SERVERDEMO_SOURCE_ECHOSERVERCONNECTIONFACTORY_H_ */
