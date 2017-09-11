/*
 * AnySample.h
 *
 * Author: Peter Maurer
 *
 * Beispiel, das verschiedenen Arten zeigt, wie Threads in Poco implementiert werden können
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef TYPEDEMO_INCLUDE_THREADDEMO_THREADSAMPLE_H_
#define TYPEDEMO_INCLUDE_THREADDEMO_THREADSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace ThreadDemo
{
	using SampleSubsystem::Sample;

	class ThreadSample  : public Sample
	{
	public:
		ThreadSample():
			Sample("ThreadSample")
		{}

		virtual ~ThreadSample(){}

		void run(std::ostream &os, std::istream &is);

		static void printThreadInfo(std::ostream &os);
	};
}



#endif /* TYPEDEMO_INCLUDE_THREADDEMO_THREADSAMPLE_H_ */
