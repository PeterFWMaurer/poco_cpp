/*
 * SimpleEventSample.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: peter
 */

#include "EventDemo/SimpleEventSample.h"

#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"

namespace EventDemo
{
	using Poco::BasicEvent;

	class SampleEvtInfo
	{
	public:


		SampleEvtInfo(const std::string &name):
			_count(0),
			_name(name)
		{}

		virtual ~SampleEvtInfo()
		{}

		int count()
		{
			return _count;
		}

		const std::string& name()
		{
			return _name;
		}

		int operator ++()
		{
			return ++_count;
		}

	private:
		int _count;
		std::string _name;
	};

	class SampleEventSource
	{
	public:
		typedef BasicEvent<SampleEvtInfo> SampleEvent;

		SampleEvent event;

		SampleEventSource(){}

		virtual ~SampleEventSource(){}

		void fireSampleEvent(SampleEvtInfo& evi)
		{
			//event(this,evi);
			event.notify(this,evi);
		}
	};

	class SampleEventTarget
	{
	public:
		SampleEventTarget(const std::string& name, std::ostream& os):
			_name(name),
			_os(os)
		{}

		virtual ~SampleEventTarget(){}

		void onSampleEvent(const void *pSender,SampleEvtInfo& evt)
		{
			_os<<"Target "<<_name<<" received Event "<<evt.name()<<" increasing its count."<<std::endl;
			++evt;
		}

	private:
		std::string _name;
		std::ostream& _os;
	};

	void SimpleEventSample::run(std::ostream& os, std::istream& is)
	{
		SampleEventSource mySource;

		SampleEventTarget firstTarget("firstTarget",os);

		SampleEvtInfo evtData("My Event");

		os<<"Adding a target to our event source and firing the event..."<<std::endl;
	    mySource.event += Poco::delegate(&firstTarget,&SampleEventTarget::onSampleEvent);
	    // mySource.event += Poco::Delegate<EventDemo::SampleEventTarget, EventDemo::SampleEvtInfo, true>(&firstTarget,&SampleEventTarget::onSampleEvent);
		mySource.fireSampleEvent(evtData);
		os<<"After fiering: My Event count = "<<evtData.count()<<std::endl<<std::endl;

		std::cout<<"Adding a second target to our source and firing events..."<<std::endl;
		SampleEventTarget secondTarget("secondTarget",os);
		mySource.event += Poco::delegate(&secondTarget,&SampleEventTarget::onSampleEvent);
		mySource.fireSampleEvent(evtData);
		os<<"After firing: My Event count = "<<evtData.count()<<std::endl<<std::endl;

		std::cout<<"Removing firstTarget and fireing again..."<<std::endl;
		mySource.event -= Poco::delegate(&firstTarget,&SampleEventTarget::onSampleEvent);
		mySource.fireSampleEvent(evtData);
		os<<"After fiering: My Event count = "<<evtData.count()<<std::endl<<std::endl;

		os<<"Removing secondTargte and firing again..."<<std::endl;
		mySource.event -= Poco::delegate(&secondTarget,&SampleEventTarget::onSampleEvent);
		mySource.fireSampleEvent(evtData);
		os<<"After fiering: My Event count = "<<evtData.count()<<std::endl<<std::endl;
	}

}
