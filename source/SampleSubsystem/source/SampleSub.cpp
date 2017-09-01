/*
 * SampleSub.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: peter
 */
#include "SampleSubsystem/SampleSub.h"

#include "Poco/Util/Option.h"
#include "Poco/String.h"


namespace SampleSubsystem
{
	using Poco::Util::Option;
	using Poco::Util::OptionCallback;

	SampleSub::SampleSub(const std::string &name):
			_name(name)
		{}

	void SampleSub::initialize(Application &app)
	{}

	void SampleSub::uninitialize()
	{}

	const char *SampleSub::name() const
	{
		return _name.c_str();
	}

	std::string SampleSub::getSampleSubDisableOptionName()
	{
		return Poco::cat(_name,std::string("_disable"));
	}

	std::string SampleSub::getSampleDisableOptionName(const std::string sampleName)
	{
		return Poco::cat(_name,std::string("_"),sampleName,std::string("_disable"));
	}

	void SampleSub::defineOptions(OptionSet& options)
	{
		Subsystem::defineOptions(options);


		options.addOption(Option(getSampleSubDisableOptionName(),"",Poco::cat(std::string("disable run of samples in"),_name))
				.callback(OptionCallback<SampleSub>(this,&SampleSub::handleDisableOption))
		);

		for (auto it : _samples)
		{
			options.addOption(Option(getSampleDisableOptionName(it->name()),"",Poco::cat(std::string("disable run of sample"),it->name()))
					.callback(OptionCallback<SampleSub>(this,&SampleSub::handleDisableOption))
//
			);
		}
	}

	void SampleSub::handleOption(const std::string &name, const std::string &value)
	{
		std::cout<<"Handle Option called: "<<name<<":"<<value<<std::endl;
	}

	void SampleSub::addSample(Sample *pSample)
	{
		_samples.push_back(pSample);
	}

	void SampleSub::handleDisableOption(const std::string &name,const std::string &value)
	{
		std::cout<<"hD called:"<<name<<std::endl;
		_disable_options[name]=true;
	}

	void SampleSub::run(std::ostream &os, std::istream &is)
	{
		if (_disable_options.find(getSampleSubDisableOptionName())==_disable_options.end())
		{
			os<<"==========================================================="<<std::endl;
			os<<name()<<std::endl;
			os<<std::endl;
			int test[10];
			for (auto it: _samples)
			{
				if (_disable_options.find(getSampleDisableOptionName(it->name()))==_disable_options.end())
				{
					os<<"------"<<std::endl;
					os<<it->name()<<":"<<std::endl<<std::endl;
					it->run(os,is);
				}
				else
				{
					os<<it->name()<<" disabled."<<std::endl;
				}
			}
		}
	}

}
