/*
 * PocoSampleApplication.h
 *
 * Author: Peter Maurer
 *
 * Application running foundation samples
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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

		void initialize(Application &self);

		void displayHelp();

		void handleHelp(const std::string& name, const std::string& value);

		int main(const std::vector<std::string> &args);

	private:
		bool _helpRequested;

	};
}

#endif /* POCOSAMPLE_INCLUDE_POCOSAMPLE_POCOSAMPLEAPPLICATION_H_ */
