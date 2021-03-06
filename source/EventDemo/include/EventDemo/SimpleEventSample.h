/*
 * SimpleEventSample.h
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Events in Poco
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef EVENTDEMO_SOURCE_SIMPLEEVENTSAMPLE_H_
#define EVENTDEMO_SOURCE_SIMPLEEVENTSAMPLE_H_

#include "SampleSubsystem/Sample.h"
namespace EventDemo
{
	using SampleSubsystem::Sample;

	class SimpleEventSample: public Sample
	{
	public:
		SimpleEventSample():
			Sample("SimpleEventSample")
		{}

		virtual ~SimpleEventSample()
		{}

		void run(std::ostream& os, std::istream& is);
	};

}

#endif /* EVENTDEMO_SOURCE_SIMPLEEVENTSAMPLE_H_ */
