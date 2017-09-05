/*
 * ErrorDemoSub.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#include "ErrorDemo/ErrorDemoSub.h"
#include "ErrorDemo/ExceptionSample.h"
#include "ErrorDemo/AssertionSample.h"
#include "ErrorDemo/NdcSample.h"

namespace ErrorDemo
{

	using ErrorDemo::ExceptionSample;
	using ErrorDemo::AssertionSample;

	ErrorDemoSub::ErrorDemoSub():
		SampleSub("ErrorDemoSub")
	{
		addSample(new ExceptionSample());
		addSample(new AssertionSample());
		addSample(new NdcSample());
	}

} /* namespace ErrorDemo */
