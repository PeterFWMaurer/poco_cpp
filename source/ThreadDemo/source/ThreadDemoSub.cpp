/*
 * TypeDemoSub.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: peter
 */

#include "ThreadDemo/ThreadDemoSub.h"
#include "ThreadDemo/ThreadSample.h"

namespace ThreadDemo
{
	ThreadDemoSub::ThreadDemoSub():
		SampleSub("ThreadDemoSub")
	{
		addSample(new ThreadSample());
	}
}
