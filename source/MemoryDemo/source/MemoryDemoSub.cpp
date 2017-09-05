/*
 * MemoryDemoSub.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#include "MemoryDemo/MemoryDemoSub.h"
#include "MemoryDemo/RefCountingSample.h"

namespace MemoryDemo
{
	MemoryDemoSub::MemoryDemoSub()
		:SampleSubsystem::SampleSub("MemoryDemo")
	{
		addSample(new RefCountingSample());
	}
} /* namespace MemoryDemo */
