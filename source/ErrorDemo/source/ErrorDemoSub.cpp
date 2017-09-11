/*
 * ErrorDemoSub.cpp
 *
 * Author: Peter Maurer
 *
 * Klasse zum Aufruf von Beispielen zum Thema Error und Exception
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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
