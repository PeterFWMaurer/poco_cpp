/*
 * SharedPtrSample.h
 *
 *  Created on: Sep 5, 2017
 *      Author: parallels
 */

#ifndef MEMORYDEMO_SOURCE_SHAREDPTRSAMPLE_H_
#define MEMORYDEMO_SOURCE_SHAREDPTRSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace MemoryDemo
{
	using SampleSubsystem::Sample;

	class SharedPtrSample: public Sample {
	public:
		SharedPtrSample():
			Sample("SharedPtrSample")
		{};

		virtual ~SharedPtrSample()
		{};

		void run(std::ostream& os, std::istream &is);
	};

} /* namespace MemoryDemo */

#endif /* MEMORYDEMO_SOURCE_SHAREDPTRSAMPLE_H_ */
