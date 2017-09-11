/*
 * BufferSample.h
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Poco::Buffer
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef MEMORYDEMO_SOURCE_BUFFERSAMPLE_H_
#define MEMORYDEMO_SOURCE_BUFFERSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace MemoryDemo {

	using SampleSubsystem::Sample;

	class BufferSample: public Sample
	{
	public:
		BufferSample():
			Sample("BufferSample")
		{}

		virtual ~BufferSample()
		{}

		void run(std::ostream& os, std::istream &is);
	};

} /* namespace MemoryDemo */

#endif /* MEMORYDEMO_SOURCE_BUFFERSAMPLE_H_ */
