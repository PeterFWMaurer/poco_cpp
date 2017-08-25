/*
 * PocoSampleApplication.h
 *
 *  Created on: Aug 22, 2017
 *      Author: peter
 */

#ifndef POCOSAMPLE_INCLUDE_POCOSAMPLE_POCOSAMPLEAPPLICATION_H_
#define POCOSAMPLE_INCLUDE_POCOSAMPLE_POCOSAMPLEAPPLICATION_H_

#include "Poco/Util/Application.h"

namespace FoundationSample
{

	using Poco::Util::Application;
	using Poco::Util::OptionSet;

	class SampleApp : public Application
	{
	public:
		SampleApp();

		virtual ~SampleApp()
		{}

	protected:
		void defineOptions(OptionSet& options);

		void handleOption(const std::string & name,
						  const std::string & value);

		void displayHelp();

		void handleHelp(const std::string& name, const std::string& value);

		int main(const std::vector<std::string> &args);

	private:
		bool _helpRequested;

	};
}

#endif /* POCOSAMPLE_INCLUDE_POCOSAMPLE_POCOSAMPLEAPPLICATION_H_ */
