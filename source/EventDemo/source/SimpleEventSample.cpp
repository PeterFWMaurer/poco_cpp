/*
 * SimpleEventSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Events in Poco
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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
		// Source und Target werden auf dem Stack erzeugt
		SampleEventSource mySource;
		SampleEventTarget firstTarget("firstTarget",os);

		SampleEvtInfo evtData("My Event");

		// Source und Target werden über ein Delegate verbunden.
		os<<"Adding a target to our event source and firing the event..."<<std::endl;
	    mySource.event += Poco::delegate(&firstTarget,&SampleEventTarget::onSampleEvent);
	    // mySource.event += Poco::Delegate<EventDemo::SampleEventTarget, EventDemo::SampleEvtInfo, true>(&firstTarget,&SampleEventTarget::onSampleEvent);

	    // Jetzt kann ein Event ausgelöst werden.
		mySource.fireSampleEvent(evtData);
		os<<"After fiering: My Event count = "<<evtData.count()<<std::endl<<std::endl;

		// Unsere Source erhält ein weiteres Event...
		std::cout<<"Adding a second target to our source and firing events..."<<std::endl;
		SampleEventTarget secondTarget("secondTarget",os);
		mySource.event += Poco::delegate(&secondTarget,&SampleEventTarget::onSampleEvent);
		mySource.fireSampleEvent(evtData);
		os<<"After firing: My Event count = "<<evtData.count()<<std::endl<<std::endl;

		// Das erste Target wird von der Source gelöst
		std::cout<<"Removing firstTarget and fireing again..."<<std::endl;
		mySource.event -= Poco::delegate(&firstTarget,&SampleEventTarget::onSampleEvent);
		mySource.fireSampleEvent(evtData);
		os<<"After fiering: My Event count = "<<evtData.count()<<std::endl<<std::endl;

		// Das zweite Target wird von der Source gelöst
		os<<"Removing secondTargte and firing again..."<<std::endl;
		mySource.event -= Poco::delegate(&secondTarget,&SampleEventTarget::onSampleEvent);
		mySource.fireSampleEvent(evtData);
		os<<"After fiering: My Event count = "<<evtData.count()<<std::endl<<std::endl;
	}

}
