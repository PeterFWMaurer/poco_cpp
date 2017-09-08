/*
 * DemoClient.h
 *
 *  Created on: Sep 8, 2017
 *      Author: peter
 */

#ifndef APPLICATIONDEMO_SOURCE_DEMOCLIENT_H_
#define APPLICATIONDEMO_SOURCE_DEMOCLIENT_H_

#include "Poco/Logger.h"
#include "Poco/Util/ConfigurationView.h"
#include "Poco/Util/IntValidator.h"
#include "Poco/Util/Subsystem.h"
#include "Poco/Util/OptionSet.h"


namespace ApplicationDemo
{
	using Poco::AutoPtr;
	using Poco::Logger;
	using Poco::Util::AbstractConfiguration;
	using Poco::Util::Application;
	using Poco::Util::ConfigurationView;
	using Poco::Util::IntValidator;
	using Poco::Util::Option;
	using Poco::Util::OptionSet;
	using Poco::Util::Subsystem;
	using std::string;

	class DemoClient : public Subsystem
	{
	public:
		DemoClient():
			_name("DemoClient"),
			_pLogger(0),
			_pConfig(0)
		{}

		virtual ~DemoClient(){}

		const char *name() const
		{
			return _name.c_str();
		}

		void initialize(Application &app)
		{
			_pLogger = &Logger::get(_name);
			logger().debug("Client Subsystem initializing");
			_pConfig = app.config().createView(_name);
			AbstractConfiguration::Keys keys;
			config().keys(keys);
			for (auto keyIterator: keys)
			{
				logger().debug("%s = %s",keyIterator,config().getString(keyIterator));
			}
		}

		void uninitialize()
		{}

		AbstractConfiguration &config()
		{
			poco_check_ptr(_pConfig);
			return *_pConfig;
		}

		Logger& logger()
		{
			poco_check_ptr(_pLogger);
			return *_pLogger;
		}

		void defineOptions(OptionSet &options)
		{
			options.addOption(
				Option("port","p","specify ip port of the server")
					.required(false)
					.repeatable(false)
					.argument("port")
					.validator(new IntValidator(0,65535))
					.binding(_name + ".port")
			);
		}


	private:
		const string _name;
		Logger *_pLogger;
		AutoPtr<AbstractConfiguration> _pConfig;

	};

} /* namespace ApplicationDemo */

#endif /* APPLICATIONDEMO_SOURCE_DEMOCLIENT_H_ */
