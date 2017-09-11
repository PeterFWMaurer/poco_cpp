/*
 * EchoServerMTSub.h
 *
 *  Created on: Sep 9, 2017
 *      Author: parallels
 */

#ifndef SERVERDEMO_SOURCE_ECHOSERVERMTSUB_H_
#define SERVERDEMO_SOURCE_ECHOSERVERMTSUB_H_

#include "Poco/Logger.h"
#include "Poco/Net/TCPServer.h"
#include "Poco/Util/Subsystem.h"

namespace ServerDemo
{
	using Poco::Logger;
	using Poco::SharedPtr;
	using Poco::Net::TCPServer;
	using Poco::Util::Application;
	using Poco::Util::OptionSet;
	using Poco::Util::Subsystem;

	using std::string;

	class EchoServerMTSub: public Subsystem
	{
	public:
		EchoServerMTSub();

		virtual ~EchoServerMTSub();

		const char* name() const;

		void initialize(Application& app);

		void uninitialize();

		void defineOptions(OptionSet& options);

		Logger& logger();

		void startService();

		void stopService();

		static const int DEFAULT_PORT=2222;

	private:
		string _name;
		SharedPtr<TCPServer> _pTcpServer;
		Logger *_pLogger;
		Poco::UInt16 _port;

	};

}

#endif /* SERVERDEMO_SOURCE_ECHOSERVERMTSUB_H_ */
