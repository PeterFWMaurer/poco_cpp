/*
 * SampleEventSource.h
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#ifndef EVENTDEMO_INCLUDE_EVENTDEMO_SAMPLEEVENTSOURCE_H_
#define EVENTDEMO_INCLUDE_EVENTDEMO_SAMPLEEVENTSOURCE_H_

#include "Poco/BasicEvent.h"

namespace EventDemo
{
	using Poco::BasicEvent;

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
}



#endif /* EVENTDEMO_INCLUDE_EVENTDEMO_SAMPLEEVENTSOURCE_H_ */
