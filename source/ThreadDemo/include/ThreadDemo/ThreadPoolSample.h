/*
 * ThreadPoolSample.h
 *
 * Author: Peter Maurer
 *
 * Beispiel, das die Verwendung von Poco::Event illustriert.
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef THREADDEMO_SOURCE_THREADPOOLSAMPLE_H_
#define THREADDEMO_SOURCE_THREADPOOLSAMPLE_H_

#include "SampleSubsystem/Sample.h"
#include "Poco/Timespan.h"

namespace ThreadDemo {

	using SampleSubsystem::Sample;

	class ThreadPoolSample: public Sample {
	public:
		ThreadPoolSample():
			Sample("ThreadPoolSample")
		{};

		virtual ~ThreadPoolSample(){};

		void run(std::ostream& os, std::istream& is);

		Poco::Timespan createThreadsFromPool(int noOfThreads, bool preallocated);

		Poco::Timespan createThreadsWithSimpleThreads(int noOfThreads);
	};

} /* namespace ThreadDemo */

#endif /* THREADDEMO_SOURCE_THREADPOOLSAMPLE_H_ */
