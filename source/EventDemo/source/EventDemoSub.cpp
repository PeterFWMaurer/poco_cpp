/*
 * EventDemoSub.cpp
 *
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Events in Poco
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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
