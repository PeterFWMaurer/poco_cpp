/*
 * SimpleEventSample.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: peter
 */

#include "EventDemo/SimpleEventSample.h"
#include "EventDemo/SampleEventInfo.h"
#include "EventDemo/SampleEventSource.h"
#include "EventDemo/SampleEventTarget.h"

#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"

namespace EventDemo
{

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
