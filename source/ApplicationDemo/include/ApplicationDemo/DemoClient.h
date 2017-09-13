/*
 * DemoClient.h
 *
 * Author: Peter Maurer
 *
 * DemoClient Subsystem, sends a string to server
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef APPLICATIONDEMO_SOURCE_DEMOCLIENT_H_
#define APPLICATIONDEMO_SOURCE_DEMOCLIENT_H_

#include "Poco/Logger.h"
#include "Poco/LogStream.h"
#include "Poco/StreamCopier.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Util/ConfigurationView.h"
#include "Poco/Util/IntValidator.h"
#include "Poco/Util/Subsystem.h"
#include "Poco/Util/OptionSet.h"

#include <iostream>

namespace ApplicationDemo
{
	using Poco::AutoPtr;
	using Poco::Logger;
	using Poco::LogStream;
	using Poco::StreamCopier;
	using Poco::Net::SocketAddress;
	using Poco::Net::SocketStream;
	using Poco::Net::StreamSocket;
	using Poco::Util::AbstractConfiguration;
	using Poco::Util::Application;
	using Poco::Util::ConfigurationView;
	using Poco::Util::IntValidator;
	using Poco::Util::Option;
	using Poco::Util::OptionSet;
	using Poco::Util::Subsystem;
	using std::string;

	POCO_DECLARE_EXCEPTION(,ConfigException,Poco::Exception);


	class DemoClient : public Subsystem
	{
	public:
		DemoClient();

		virtual ~DemoClient(){}

		const char* name() const;

		void initialize(Application &app);

		void uninitialize(){}

		AbstractConfiguration& config();

		Logger& logger();

		void defineOptions(OptionSet &options);

		bool configured() const;

		int run();


	private:
		const string _name;
		string _server;
		bool _configured;
		int _port;
		int _count;
		string _message;
		Logger *_pLogger;
		AutoPtr<AbstractConfiguration> _pConfig;

	};

} /* namespace ApplicationDemo */

#endif /* APPLICATIONDEMO_SOURCE_DEMOCLIENT_H_ */
