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

namespace MemoryDemo
{
	MemoryDemoSub::MemoryDemoSub()
		:SampleSubsystem::SampleSub("MemoryDemo")
	{
		addSample(new RefCountingSample());
		addSample(new AutoPtrSample());
		addSample(new SharedPtrSample());
	}
}
