/*
 * BufferSample.h
 *
 *  Created on: Sep 6, 2017
 *      Author: peter
 */

#ifndef MEMORYDEMO_SOURCE_BUFFERSAMPLE_H_
#define MEMORYDEMO_SOURCE_BUFFERSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace MemoryDemo {

	using SampleSubsystem::Sample;

	class BufferSample: public Sample
	{
	public:
		BufferSample():
			Sample("BufferSample")
		{}

		virtual ~BufferSample()
		{}

		void run(std::ostream& os, std::istream &is);
	};

} /* namespace MemoryDemo */

#endif /* MEMORYDEMO_SOURCE_BUFFERSAMPLE_H_ */
