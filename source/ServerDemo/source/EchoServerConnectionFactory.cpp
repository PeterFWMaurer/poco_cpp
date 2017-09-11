/*
 * EchoServerConnectionFactory.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: parallels
 */

#include "ServerDemo/EchoServerConnectionFactory.h"

namespace ServerDemo
{

	EchoServerConnectionFactory::EchoServerConnectionFactory()
	{
		// TODO Auto-generated constructor stub

	}

	EchoServerConnectionFactory::~EchoServerConnectionFactory()
	{
		// TODO Auto-generated destructor stub
	}

	TCPServerConnection* EchoServerConnectionFactory::createConnection(const StreamSocket& socket)
	{
		return 0;
	}


} /* namespace ServerDemo */
