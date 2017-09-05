/*
 * AutoPtrSample.h
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#ifndef MEMORYDEMO_SOURCE_AUTOPTRSAMPLE_H_
#define MEMORYDEMO_SOURCE_AUTOPTRSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace MemoryDemo
{

	using SampleSubsystem::Sample;

	class AutoPtrSample: public Sample
	{
	public:
		AutoPtrSample():
			Sample("AutoPtrSampe")
		{}

		virtual ~AutoPtrSample()
		{}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace MemoryDemo */

#endif /* MEMORYDEMO_SOURCE_AUTOPTRSAMPLE_H_ */
