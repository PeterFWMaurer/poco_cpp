/*
 * TypeDemoSub.h
 *
 *  Created on: Aug 24, 2017
 *      Author: peter
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
