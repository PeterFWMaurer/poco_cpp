/*
 * MemoryDemoSub.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#include "MemoryDemo/MemoryDemoSub.h"
#include "MemoryDemo/RefCountingSample.h"
#include "MemoryDemo/AutoPtrSample.h"
#include "MemoryDemo/SharedPtrSample.h"
#include "MemoryDemo/BufferSample.h"
#include "MemoryDemo/PoolSample.h"

namespace MemoryDemo
{
	MemoryDemoSub::MemoryDemoSub()
		:SampleSubsystem::SampleSub("MemoryDemo")
	{
		addSample(new RefCountingSample());
		addSample(new AutoPtrSample());
		addSample(new SharedPtrSample());
		addSample(new BufferSample());
		addSample(new PoolSample());
	}
}
