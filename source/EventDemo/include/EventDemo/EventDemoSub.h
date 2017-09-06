/*
 * EventDemoSub.h
 *
 *  Created on: Sep 6, 2017
 *      Author: peter
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
