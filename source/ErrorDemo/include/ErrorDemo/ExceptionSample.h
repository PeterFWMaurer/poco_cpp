/*
 * ExceptionSample.h
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#ifndef ERRORDEMO_SOURCE_EXCEPTIONSAMPLE_H_
#define ERRORDEMO_SOURCE_EXCEPTIONSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace ErrorDemo
{
	using SampleSubsystem::Sample;

	class ExceptionSample: public Sample
	{
	public:
		ExceptionSample():
			Sample("Exception Sample")
		{}

		virtual ~ExceptionSample()
		{}

		void run(std::ostream &os, std::istream &is);
	};

} /* namespace ErrorDemo */

#endif /* ERRORDEMO_SOURCE_EXCEPTIONSAMPLE_H_ */
