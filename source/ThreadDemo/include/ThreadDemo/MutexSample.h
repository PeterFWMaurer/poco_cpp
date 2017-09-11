/*
 * MutexSample.h
 *
 * Author: Peter Maurer
 *
 * Beispiel, das die Verwendung von Poco::Mutex illustriert.
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef THREADDEMO_SOURCE_MUTEXSAMPLE_H_
#define THREADDEMO_SOURCE_MUTEXSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace ThreadDemo
{

	using SampleSubsystem::Sample;

	class MutexSample: public Sample
	{
	public:
		MutexSample():
			Sample("MutexSample")
		{}

		virtual ~MutexSample(){}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace ThreadDemo */

#endif /* THREADDEMO_SOURCE_MUTEXSAMPLE_H_ */
