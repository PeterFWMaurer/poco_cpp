/*
 * AsyncEventSample.h
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#ifndef EVENTDEMO_SOURCE_ASYNCEVENTSAMPLE_H_
#define EVENTDEMO_SOURCE_ASYNCEVENTSAMPLE_H_


#include "SampleSubsystem/Sample.h"

namespace EventDemo
{
	using SampleSubsystem::Sample;

	class AsyncEventSample: public SampleSubsystem::Sample
	{
	public:
		AsyncEventSample()
			:Sample("AsyncEventSample")
		{}

		virtual ~AsyncEventSample()
		{}

		void run(std::ostream& os, std::istream& is);
	};

}

#endif /* EVENTDEMO_SOURCE_ASYNCEVENTSAMPLE_H_ */
