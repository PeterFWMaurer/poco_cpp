/*
 * SimpleEventSample.h
 *
 *  Created on: Sep 6, 2017
 *      Author: peter
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
