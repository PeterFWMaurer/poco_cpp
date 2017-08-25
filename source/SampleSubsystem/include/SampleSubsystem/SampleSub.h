/*
 * SampleSub.h
 *
 *  Created on: Aug 24, 2017
 *      Author: peter
 */

#ifndef SAMPLESUBSYSTEM_INCLUDE_SAMPLESUBSYSTEM_SAMPLESUB_H_
#define SAMPLESUBSYSTEM_INCLUDE_SAMPLESUBSYSTEM_SAMPLESUB_H_

#include "SampleSubsystem/Sample.h"

#include <vector>
#include <unordered_map>

#include "Poco/AutoPtr.h"
#include "Poco/Util/Application.h"
#include "Poco/Util/Subsystem.h"



namespace SampleSubsystem
{

	using Poco::Util::Subsystem;
	using Poco::Util::OptionSet;
	using Poco::Util::Application;

	class SampleSub : public Subsystem
	{
	public:
		typedef std::unordered_map<std::string,bool> disable_option_map;

		/*
		 * SampleSub has allways to be created with a name, so it is implemented as a
		 * member to be set in the constructor
		 */
		SampleSub(const std::string& name);

		virtual void initialize(Application &app);

		virtual void uninitialize();

		virtual const char *name() const;

		virtual void defineOptions(OptionSet& options);

		virtual void handleOption(const std::string &name, const std::string &value);

		virtual void handleDisableOption(const std::string &name,const std::string &value);

		void addSample(Sample *pSample);

		void run(std::ostream &os, std::istream &is);

		std::string getSampleSubDisableOptionName();

		std::string getSampleDisableOptionName(const std::string sampleName);

	private:
		std::vector<Poco::AutoPtr<Sample> > _samples;
		const std::string _name;
		disable_option_map _disable_options;
	};

}

#endif /* SAMPLESUBSYSTEM_INCLUDE_SAMPLESUBSYSTEM_SAMPLESUB_H_ */
