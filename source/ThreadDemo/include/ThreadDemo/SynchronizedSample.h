/*
 * SynchronizedSample.h
 *
 *  Created on: Sep 4, 2017
 *      Author: peter
 */

#include "SampleSubsystem/Sample.h"

#ifndef THREADDEMO_SOURCE_SYNCHRONIZEDSAMPLE_H_
#define THREADDEMO_SOURCE_SYNCHRONIZEDSAMPLE_H_

namespace ThreadDemo {

using SampleSubsystem::Sample;

class SynchronizedSample : public Sample
{
public:
	SynchronizedSample():
		Sample("SynchronizedSample")
	{}

	virtual ~SynchronizedSample(){}

	void run(std::ostream& os, std::istream& is);
};

} /* namespace ThreadDemo */

#endif /* THREADDEMO_SOURCE_SYNCHRONIZEDSAMPLE_H_ */
