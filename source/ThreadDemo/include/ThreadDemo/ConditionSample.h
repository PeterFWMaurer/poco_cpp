/*
 * ConditionSample.h
 *
 *  Created on: Sep 4, 2017
 *      Author: peter
 */

#ifndef THREADDEMO_SOURCE_CONDITIONSAMPLE_H_
#define THREADDEMO_SOURCE_CONDITIONSAMPLE_H_

#include "SampleSubsystem/Sample.h"

#include "Poco/Condition.h"
#include "Poco/Mutex.h"

namespace ThreadDemo {

using Poco::Condition;
using Poco::Mutex;
using SampleSubsystem::Sample;

class ConditionSample: public Sample {
public:
	ConditionSample():
		Sample("CondititionSample")
	{}

	virtual ~ConditionSample() {}

	void run(std::ostream& os, std::istream& is);

private:
	Condition _condition;
	Mutex _conditionMutex;
};

} /* namespace ThreadDemo */

#endif /* THREADDEMO_SOURCE_CONDITIONSAMPLE_H_ */
