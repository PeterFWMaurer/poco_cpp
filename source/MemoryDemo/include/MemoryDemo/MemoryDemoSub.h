/*
 * MemoryDemoSub.h
 *
 * Author: Peter Maurer
 *
 * Sample-Class for Poco Memory Examples
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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
