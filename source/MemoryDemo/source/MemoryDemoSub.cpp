/*
 * MemoryDemoSub.cpp
 *
 * Author: Peter Maurer
 *
 * Sample-Class for Poco Memory Examples
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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
