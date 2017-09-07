/*
 * AsyncEventSample.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#include "EventDemo/AsyncEventSample.h"
#include "EventDemo/SampleEventInfo.h"

#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"
#include "Poco/Thread.h"

namespace EventDemo
{
	using Poco::BasicEvent;
	using Poco::Thread;

	class AsyncEventSource
	{
	public:
		typedef BasicEvent<SampleEvtInfo> SampleEvent;

		SampleEvent event;

		AsyncEventSource(){}

		virtual ~AsyncEventSource(){}

		void asyncFireSampleEvent(SampleEvtInfo& evi)
		{
			event.notifyAsync(this,evi);
		}
	};

	class AsyncEventTarget
	{
	public:
		AsyncEventTarget(const std::string& name, std::ostream& os):
			_name(name),
			_os(os)
		{}

		virtual ~AsyncEventTarget(){}

		void onSampleEvent(const void *pSender,SampleEvtInfo& evt)
		{
			_os<<"Target is processing Event in Thread "<<Thread::current()->id()<<std::endl;
			_os<<"Target "<<_name<<" received Event "<<evt.name()<<" count="<<evt.count()<<" sleeping for a moment..."<<std::endl;
			Thread::sleep(100);
			++evt;
			_os<<"AsyncEventTarget::onSampleEvent finished"<<std::endl;
		}

	private:
		std::string _name;
		std::ostream& _os;
	};



	void AsyncEventSample::run(std::ostream& os, std::istream& is)
	{
		AsyncEventSource mySource;
		SampleEvtInfo evtData("myEventInfo");

		AsyncEventTarget myTarget("myTarget",os);

		mySource.event += Poco::delegate(&myTarget,&AsyncEventTarget::onSampleEvent);

		std::cout<<"Firing asynchronous event to myTarget..."<<std::endl;
		mySource.asyncFireSampleEvent(evtData);

		os<<"After firing: My Event count = "<<evtData.count()<<std::endl<<std::endl;
		os<<"Sleeping for 10ms..."<<std::endl;
		Thread::sleep(10);
		os<<"After waiting: My Event count = "<<evtData.count()<<std::endl<<std::endl;
		os<<"Sleeping for 1sec..."<<std::endl;
		Thread::sleep(1000);
		os<<"After waiting: My Event count = "<<evtData.count()<<std::endl<<std::endl;

		{
			SampleEvtInfo myData("myData");
			mySource.asyncFireSampleEvent(myData);
			++myData;
			os<<"After firing and increasing myData: My Event count = "<<myData.count()<<std::endl;
		}
		Thread::sleep(1000);
		os<<"Waited for processing of event"<<std::endl;
	}

} /* namespace EventDemo */
