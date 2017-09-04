/*
 * SemaphoreSample.h
 *
 *  Created on: Sep 4, 2017
 *      Author: peter
 */

#ifndef THREADDEMO_SOURCE_SEMAPHORESAMPLE_H_
#define THREADDEMO_SOURCE_SEMAPHORESAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace ThreadDemo {

	using SampleSubsystem::Sample;

	class SemaphoreSample : public Sample
	{
	public:
		SemaphoreSample():
			Sample("SemaphoreSample")
		{}

		virtual ~SemaphoreSample(){}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace ThreadDemo */

#endif /* THREADDEMO_SOURCE_SEMAPHORESAMPLE_H_ */
