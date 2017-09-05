/*
 * ErrorDemoSub.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#include "ErrorDemo/ErrorDemoSub.h"
#include "ErrorDemo/ExceptionSample.h"

namespace ErrorDemo
{

	using ErrorDemo::ExceptionSample;

	ErrorDemoSub::ErrorDemoSub():
		SampleSub("ErrorDemoSub")
	{
		addSample(new ExceptionSample());
	}

} /* namespace ErrorDemo */
