/*
 * SharedPtrSample.h
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Poco::SharedPtr
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef MEMORYDEMO_SOURCE_SHAREDPTRSAMPLE_H_
#define MEMORYDEMO_SOURCE_SHAREDPTRSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace MemoryDemo
{
	using SampleSubsystem::Sample;

	class SharedPtrSample: public Sample {
	public:
		SharedPtrSample():
			Sample("SharedPtrSample")
		{};

		virtual ~SharedPtrSample()
		{};

		void run(std::ostream& os, std::istream &is);
	};

} /* namespace MemoryDemo */

#endif /* MEMORYDEMO_SOURCE_SHAREDPTRSAMPLE_H_ */
