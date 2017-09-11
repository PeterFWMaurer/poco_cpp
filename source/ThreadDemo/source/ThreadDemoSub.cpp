/*
 * TypeDemoSub.cpp
 *
 * Author: Peter Maurer
 *
 * Sample class for Poco thread samples
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "ThreadDemo/ThreadDemoSub.h"
#include "ThreadDemo/ThreadSample.h"
#include "ThreadDemo/ThreadPoolSample.h"
#include "ThreadDemo/MutexSample.h"
#include "ThreadDemo/EventSample.h"
#include "ThreadDemo/ConditionSample.h"
#include "ThreadDemo/SynchronizedSample.h"
#include "ThreadDemo/SemaphoreSample.h"
#include "ThreadDemo/ErrorSample.h"

namespace ThreadDemo
{
	ThreadDemoSub::ThreadDemoSub():
		SampleSub("ThreadDemoSub")
	{
		addSample(new ThreadSample());
		addSample(new MutexSample());
		addSample(new EventSample());
		addSample(new ConditionSample());
		addSample(new SynchronizedSample());
		addSample(new SemaphoreSample());
		addSample(new ThreadPoolSample());
//		addSample(new ErrorSample());
	}
}
