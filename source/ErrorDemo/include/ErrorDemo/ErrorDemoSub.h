/*
 * ErrorDemoSub.h
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#ifndef ERRORDEMO_SOURCE_ERRORDEMOSUB_H_
#define ERRORDEMO_SOURCE_ERRORDEMOSUB_H_

#include "SampleSubsystem/SampleSub.h"

namespace ErrorDemo {

	using SampleSubsystem::SampleSub;

	class ErrorDemoSub: public SampleSub
	{
	public:
		ErrorDemoSub();

		virtual ~ErrorDemoSub()
		{}
	};

} /* namespace ErrorDemo */

#endif /* ERRORDEMO_SOURCE_ERRORDEMOSUB_H_ */
