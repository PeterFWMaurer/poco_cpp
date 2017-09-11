/*
 * EchoServeConnection.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: parallels
 */

#include "ServerDemo/EchoServerConnection.h"

#include "Poco/UTF8String.h"
#include "Poco/Net/SocketStream.h"


namespace ServerDemo
{
	using Poco::Exception;
	using Poco::Net::SocketStream;

	using std::string;

	EchoServerConnection::EchoServerConnection(const StreamSocket& socket, Logger &logger):
		TCPServerConnection(socket),
		_logger(logger)
	{
		_logger.debug("TCPServerConnection established for client %s",socket.peerAddress().toString());
	}

	EchoServerConnection::~EchoServerConnection()
	{}

	void EchoServerConnection::run()
	{
		_logger.debug("Processing requests from client %s",socket().peerAddress().toString());
		string input;
		while(input != "finish")
		{
			try
			{
				SocketStream sockStream(socket());
				sockStream>>input;
				string output = Poco::UTF8::toUpper(input);
				sockStream<<output;
			}
			catch (const Exception &exp)
			{
				_logger.log(exp);
			}
		}
	}

} /* namespace ServerDemo */
