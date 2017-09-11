/*
 * EchoServeConnection.h
 *
 *  Created on: Sep 10, 2017
 *      Author: parallels
 */

#ifndef SERVERDEMO_SOURCE_ECHOSERVERCONNECTION_H_
#define SERVERDEMO_SOURCE_ECHOSERVERCONNECTION_H_

#include "Poco/Net/TCPServerConnection.h"

namespace ServerDemo
{
	using Poco::Net::StreamSocket;
	using Poco::Net::TCPServerConnection;

	class EchoServerConnection: public TCPServerConnection
	{
	public:

		EchoServerConnection(const StreamSocket& socket);

		virtual ~EchoServerConnection();

		void run();
	};

}

#endif /* SERVERDEMO_SOURCE_ECHOSERVERCONNECTION_H_ */
