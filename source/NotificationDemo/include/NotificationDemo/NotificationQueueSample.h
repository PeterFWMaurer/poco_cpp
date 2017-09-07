/*
 * NotificationQueueSample.h
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#ifndef NOTIFICATIONDEMO_SOURCE_NOTIFICATIONQUEUESAMPLE_H_
#define NOTIFICATIONDEMO_SOURCE_NOTIFICATIONQUEUESAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace NotificationDemo
{
	using SampleSubsystem::Sample;

	class NotificationQueueSample: public Sample
	{
	public:
		NotificationQueueSample():
			Sample("NotificationQueueSample")
		{}

		virtual ~NotificationQueueSample(){}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace NotificationDemo */

#endif /* NOTIFICATIONDEMO_SOURCE_NOTIFICATIONQUEUESAMPLE_H_ */
