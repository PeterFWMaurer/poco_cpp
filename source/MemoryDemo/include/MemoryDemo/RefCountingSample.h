/*
 * RefCountingSample.h
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
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
