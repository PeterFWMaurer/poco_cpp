/*
 * PoolSample.h
 *
 *  Created on: Sep 6, 2017
 *      Author: peter
 */

#ifndef MEMORYDEMO_SOURCE_POOLSAMPLE_H_
#define MEMORYDEMO_SOURCE_POOLSAMPLE_H_

#include "SampleSubsystem/Sample.h"

#include "Poco/MemoryPool.h"

namespace MemoryDemo
{
	using SampleSubsystem::Sample;

	class PoolSample: public SampleSubsystem::Sample
	{
	public:
		PoolSample():
			Sample("PoolSample")
		{}

		virtual ~PoolSample()
		{}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace MemoryDemo */

#endif /* MEMORYDEMO_SOURCE_POOLSAMPLE_H_ */
