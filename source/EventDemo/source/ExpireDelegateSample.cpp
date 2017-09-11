/*
 * ExpireDelegateSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Delegates mit Zerfallsdatum in Poco
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "EventDemo/ExpireDelegateSample.h"

#include "EventDemo/SampleEventInfo.h"
#include "EventDemo/SampleEventSource.h"
#include "EventDemo/SampleEventTarget.h"

#include "Poco/Delegate.h"
#include "Poco/Expire.h"
#include "Poco/Thread.h"

namespace EventDemo
{
	using Poco::Expire;
	using Poco::Thread;

	void ExpireDelegateSample::run(std::ostream &os, std::istream &is)
	{
		// Source, Target und Event wie gewohnt erzeugen
		SampleEventSource mySource;
		SampleEventTarget myTarget("target",os);
		SampleEvtInfo evtData("My Event");

		// Dem Delegate wird mit Hilfe von Poco::Expire eine Zerfallszeit zugeordnet.
		mySource.event += Expire<SampleEvtInfo>(Poco::delegate(&myTarget,&SampleEventTarget::onSampleEvent),1000);
		std::cout<<"Firing Event:"<<std::endl;

		// Vor Ablauf der Zefallszeit wird das Event gesendet...
		mySource.fireSampleEvent(evtData);
		std::cout<<"Waiting before firing again..."<<std::endl;

		Thread::sleep(2000);

		// ... danach nicht mehr
		mySource.fireSampleEvent(evtData);
		os<<"Fired again after 2000ms sleep!"<<std::endl;
	}
}
