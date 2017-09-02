/*
 * MutexSample.h
 *
 *  Created on: Sep 1, 2017
 *      Author: peter
 */

#ifndef THREADDEMO_SOURCE_MUTEXSAMPLE_H_
#define THREADDEMO_SOURCE_MUTEXSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace ThreadDemo
{

	using SampleSubsystem::Sample;

	class MutexSample: public Sample
	{
	public:
		MutexSample():
			Sample("MutexSample")
		{}

		virtual ~MutexSample(){}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace ThreadDemo */

#endif /* THREADDEMO_SOURCE_MUTEXSAMPLE_H_ */
