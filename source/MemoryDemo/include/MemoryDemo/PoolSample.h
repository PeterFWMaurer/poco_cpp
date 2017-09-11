/*
 * PoolSample.h
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Poco::MemoryPool
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef MEMORYDEMO_SOURCE_POOLSAMPLE_H_
#define MEMORYDEMO_SOURCE_POOLSAMPLE_H_

#include "SampleSubsystem/Sample.h"

#include "Poco/MemoryPool.h"

namespace MemoryDemo
{
	using SampleSubsystem::Sample;

	class PoolSample: public SampleSubsystem::Sample
	{
	public:
		PoolSample():
			Sample("PoolSample")
		{}

		virtual ~PoolSample()
		{}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace MemoryDemo */

#endif /* MEMORYDEMO_SOURCE_POOLSAMPLE_H_ */
