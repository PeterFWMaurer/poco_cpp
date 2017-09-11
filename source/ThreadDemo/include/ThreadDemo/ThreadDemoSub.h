/*
 * TypeDemoSub.h
 *
 * Author: Peter Maurer
 *
 * Sample class for Poco thread samples
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef TYPEDEMO_INCLUDE_THREADDEMO_THREADDEMOSUB_H_
#define TYPEDEMO_INCLUDE_THREADDEMO_THREADDEMOSUB_H_

#include "SampleSubsystem/SampleSub.h"


namespace ThreadDemo
{
	using SampleSubsystem::SampleSub;

	class ThreadDemoSub : public SampleSub
	{
	public:
		ThreadDemoSub();

		virtual ~ThreadDemoSub(){}
	};

}



#endif /* TYPEDEMO_INCLUDE_THREADDEMO_THREADDEMOSUB_H_ */
