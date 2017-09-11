/*
 * EchoServeConnection.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: parallels
 */

#include "ServerDemo/EchoServerConnection.h"

namespace ServerDemo
{

	EchoServerConnection::EchoServerConnection(const StreamSocket& socket):
		TCPServerConnection(socket)
	{
		// TODO Auto-generated constructor stub

	}

	EchoServerConnection::~EchoServerConnection()
	{
		// TODO Auto-generated destructor stub
	}

	void EchoServerConnection::run()
	{

	}

} /* namespace ServerDemo */
