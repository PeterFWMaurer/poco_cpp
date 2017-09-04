/*
 * EventSample.h
 *
 *  Created on: Sep 2, 2017
 *      Author: parallels
 */

#ifndef THREADDEMO_SOURCE_EVENTSAMPLE_H_
#define THREADDEMO_SOURCE_EVENTSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace ThreadDemo
{
	using SampleSubsystem::Sample;

	class EventSample: public Sample
	{
	public:
		EventSample():
			Sample("EventSample")
		{}

		virtual ~EventSample(){};

		void run(std::ostream& os, std::istream& is);
	};
}
#endif /* THREADDEMO_SOURCE_EVENTSAMPLE_H_ */
