/*
 * EventDemoSub.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: peter
 */

#include "EventDemo/EventDemoSub.h"

#include "EventDemo/SimpleEventSample.h"
#include "EventDemo/AsyncEventSample.h"
#include "EventDemo/ExpireDelegateSample.h"

namespace EventDemo
{
	EventDemoSub::EventDemoSub():
		SampleSub("EvnetDemoSub")
	{
		addSample(new SimpleEventSample());
		addSample(new AsyncEventSample());
		addSample(new ExpireDelegateSample());
	}

}
