/*
 * AssertionSample.h
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#ifndef ERRORDEMO_SOURCE_ASSERTIONSAMPLE_H_
#define ERRORDEMO_SOURCE_ASSERTIONSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace ErrorDemo {

	class AssertionSample: public SampleSubsystem::Sample
	{
	public:
		AssertionSample():
			Sample("AssertionSample")
		{}

		virtual ~AssertionSample()
		{}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace ErrorDemo */

#endif /* ERRORDEMO_SOURCE_ASSERTIONSAMPLE_H_ */
