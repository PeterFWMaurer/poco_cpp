/*
 * SampleApplication.h
 *
 *  Created on: Sep 8, 2017
 *      Author: peter
 */

#ifndef APPLICATIONDEMO_SOURCE_SAMPLEAPPLICATION_H_
#define APPLICATIONDEMO_SOURCE_SAMPLEAPPLICATION_H_

#include "Poco/Util/Application.h"

namespace ApplicationDemo
{

	using Poco::Util::Application;
	using Poco::Util::OptionSet;
	using std::string;
	using std::vector;

	class SampleApplication : public Application
	{
	public:
		SampleApplication();

		virtual ~SampleApplication();

		int main(const vector<string>& args);

		void initialize(Application& self);

		void defineOptions(OptionSet& options);

		void displayHelp();

		void handleHelp(const string &name, const string &value);

	private:
		bool _helpRequested;

	};

} /* namespace ApplicationDemo */

#endif /* APPLICATIONDEMO_SOURCE_SAMPLEAPPLICATION_H_ */
