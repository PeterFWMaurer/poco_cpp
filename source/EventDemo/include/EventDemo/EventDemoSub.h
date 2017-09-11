/*
 * EventDemoSub.h
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Events in Poco
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef EVENTDEMO_SOURCE_EVENTDEMOSUB_H_
#define EVENTDEMO_SOURCE_EVENTDEMOSUB_H_

#include "SampleSubsystem/SampleSub.h"

namespace EventDemo
{

	using SampleSubsystem::SampleSub;

	class EventDemoSub: public SampleSub
	{
	public:
		EventDemoSub();

		virtual ~EventDemoSub()
		{}
	};

}

#endif /* EVENTDEMO_SOURCE_EVENTDEMOSUB_H_ */
