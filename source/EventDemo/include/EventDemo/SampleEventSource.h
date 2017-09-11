/*
 * SampleEventSource.h
 *
 * Author: Peter Maurer
 *
 * Beispielklasse  für eine EventSource in Poco
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef EVENTDEMO_INCLUDE_EVENTDEMO_SAMPLEEVENTSOURCE_H_
#define EVENTDEMO_INCLUDE_EVENTDEMO_SAMPLEEVENTSOURCE_H_

#include "Poco/BasicEvent.h"

namespace EventDemo
{
	using Poco::BasicEvent;

	// Eine beliebige Klasse kann als Quelle für ein Event dienen.
	class SampleEventSource
	{
	public:
		// In der Regel wird ein Event als Typ inerhalb der Eventsource definiert, dazu wird das Template
		// BasicEvent verwendet.
		typedef BasicEvent<SampleEvtInfo> SampleEvent;

		SampleEvent event;

		SampleEventSource(){}

		virtual ~SampleEventSource(){}

		// Eine Eventsource hat für ein Event in der Regel eine fire... Funktion.
		void fireSampleEvent(SampleEvtInfo& evi)
		{
			//event(this,evi);
			event.notify(this,evi);
		}
	};
}



#endif /* EVENTDEMO_INCLUDE_EVENTDEMO_SAMPLEEVENTSOURCE_H_ */
