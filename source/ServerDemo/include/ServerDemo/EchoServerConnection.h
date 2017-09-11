/*
 * EchoServeConnection.h
 *
 *  Created on: Sep 10, 2017
 *      Author: parallels
 */

#ifndef SERVERDEMO_SOURCE_ECHOSERVERCONNECTION_H_
#define SERVERDEMO_SOURCE_ECHOSERVERCONNECTION_H_

#include "Poco/Logger.h"
#include "Poco/Net/TCPServerConnection.h"

namespace ServerDemo
{
	using Poco::Logger;
	using Poco::Net::StreamSocket;
	using Poco::Net::TCPServerConnection;

	class EchoServerConnection: public TCPServerConnection
	{
	public:

		EchoServerConnection(const StreamSocket& socket, Logger &logger);

		virtual ~EchoServerConnection();

		void run();

		static const int BUFFER_SIZE=1024;

	private:
		Logger& _logger;
	};

}

#endif /* SERVERDEMO_SOURCE_ECHOSERVERCONNECTION_H_ */
