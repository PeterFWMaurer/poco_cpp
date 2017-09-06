/*
 * EventDemoSub.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: peter
 */

#include "EventDemo/EventDemoSub.h"

#include "EventDemo/SimpleEventSample.h"

namespace EventDemo
{
	using EventDemo::SimpleEventSample;

	EventDemoSub::EventDemoSub():
		SampleSub("EvnetDemoSub")
	{
		addSample(new SimpleEventSample());
	}

}
