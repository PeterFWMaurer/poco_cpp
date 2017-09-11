/*
 * RefCountingSample.h
 *
 * Author: Peter Maurer
 *
 * Beispiel für ein von Hand implementiertes Objekt mit Referenzzählung
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef MEMORYDEMO_SOURCE_REFCOUNTINGSAMPLE_H_
#define MEMORYDEMO_SOURCE_REFCOUNTINGSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace MemoryDemo
{
	using SampleSubsystem::Sample;

	class RefCountingSample: public SampleSubsystem::Sample
	{
	public:
		RefCountingSample():
			Sample("RefCountingSample")
		{}

		virtual ~RefCountingSample()
		{}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace MemoryDemo */

#endif /* MEMORYDEMO_SOURCE_REFCOUNTINGSAMPLE_H_ */
