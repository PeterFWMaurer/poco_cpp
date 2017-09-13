/*
 * SampleApplication.h
 *
 * Author: Peter Maurer
 *
 * Beispiel fuer eine Application, die ein Subststem laedt und startet
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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
