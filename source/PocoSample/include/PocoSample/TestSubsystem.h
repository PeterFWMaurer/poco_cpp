/*
 * TestSubsystem.h
 *
 *  Created on: Aug 23, 2017
 *      Author: peter
 */

#ifndef POCOSAMPLE_INCLUDE_POCOSAMPLE_TESTSUBSYSTEM_H_
#define POCOSAMPLE_INCLUDE_POCOSAMPLE_TESTSUBSYSTEM_H_

#include <string>

#include "Poco/Util/Subsystem.h"

namespace Poco
{
	namespace Util
	{
		class Application;
		class OptionSet;
	}
}

using Poco::Util::Application;
using Poco::Util::Subsystem;
using Poco::Util::OptionSet;

class TestSubsystem: public Subsystem
{
	const char *name() const;

	void initialize(Application &app);

	void reinitialize(Application &app);

	void uninitialize();

	void defineOptions(OptionSet &options);

	void handleTestOption(const std::string& name, const std::string& value);
};


#endif /* POCOSAMPLE_INCLUDE_POCOSAMPLE_TESTSUBSYSTEM_H_ */
