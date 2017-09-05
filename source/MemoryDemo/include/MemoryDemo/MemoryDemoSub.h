/*
 * MemoryDemoSub.h
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#ifndef MEMORYDEMO_SOURCE_MEMORYDEMOSUB_H_
#define MEMORYDEMO_SOURCE_MEMORYDEMOSUB_H_

#include "SampleSubsystem/SampleSub.h"

namespace MemoryDemo
{

	class MemoryDemoSub: public SampleSubsystem::SampleSub
	{
	public:
		MemoryDemoSub();

		virtual ~MemoryDemoSub()
		{}
	};

} /* namespace MemoryDemo */

#endif /* MEMORYDEMO_SOURCE_MEMORYDEMOSUB_H_ */
