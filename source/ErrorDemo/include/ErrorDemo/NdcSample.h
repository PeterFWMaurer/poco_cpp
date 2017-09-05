/*
 * NdcSample.h
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#ifndef ERRORDEMO_SOURCE_NDCSAMPLE_H_
#define ERRORDEMO_SOURCE_NDCSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace ErrorDemo
{

	using SampleSubsystem::Sample;

	class NdcSample: public SampleSubsystem::Sample
	{
	public:
		NdcSample():
			Sample("NestedDiagnosticContextSample")
		{}

		virtual ~NdcSample()
		{}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace ErrorDemo */

#endif /* ERRORDEMO_SOURCE_NDCSAMPLE_H_ */
