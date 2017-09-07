/*
 * ExpireDelegateSample.h
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#ifndef EVENTDEMO_SOURCE_EXPIREDELEGATESAMPLE_H_
#define EVENTDEMO_SOURCE_EXPIREDELEGATESAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace EventDemo
{
	using SampleSubsystem::Sample;


	class ExpireDelegateSample: public Sample
	{
	public:
		ExpireDelegateSample() :
			Sample("ExpireDelegareSample")
		{}

		virtual ~ExpireDelegateSample() {
			// TODO Auto-generated destructor stub
		}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace EventDemo */

#endif /* EVENTDEMO_SOURCE_EXPIREDELEGATESAMPLE_H_ */
