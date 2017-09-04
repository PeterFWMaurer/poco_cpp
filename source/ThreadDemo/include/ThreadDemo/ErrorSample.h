/*
 * ErrorSample.h
 *
 *  Created on: Sep 4, 2017
 *      Author: peter
 */

#ifndef THREADDEMO_INCLUDE_THREADDEMO_ERRORSAMPLE_H_
#define THREADDEMO_INCLUDE_THREADDEMO_ERRORSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace ThreadDemo {

	using SampleSubsystem::Sample;

	class ErrorSample : public Sample
	{
	public:
		ErrorSample() :
			Sample("Error Sample")
		{}

		virtual ~ErrorSample(){}

		void run(std::ostream& os, std::istream &is);
	};

} /* namespace ThreadDemo */

#endif /* THREADDEMO_INCLUDE_THREADDEMO_ERRORSAMPLE_H_ */
