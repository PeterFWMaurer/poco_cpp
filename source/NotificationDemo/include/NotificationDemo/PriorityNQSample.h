/*
 * PriorityNQSample.h
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#ifndef NOTIFICATIONDEMO_SOURCE_PRIORITYNQSAMPLE_H_
#define NOTIFICATIONDEMO_SOURCE_PRIORITYNQSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace NotificationDemo
{

	using SampleSubsystem::Sample;

	class PriorityNQSample: public Sample
	{
	public:
		PriorityNQSample():
			Sample("PriorityNQSample")
		{}

		virtual ~PriorityNQSample()
		{}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace NotificationDemo */

#endif /* NOTIFICATIONDEMO_SOURCE_PRIORITYNQSAMPLE_H_ */
