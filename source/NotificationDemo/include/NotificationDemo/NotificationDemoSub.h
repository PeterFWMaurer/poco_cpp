/*
 * NotificationDemoSub.h
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#ifndef NOTIFICATIONDEMO_SOURCE_NOTIFICATIONDEMOSUB_H_
#define NOTIFICATIONDEMO_SOURCE_NOTIFICATIONDEMOSUB_H_

#include "SampleSubsystem/SampleSub.h"

namespace NotificationDemo {

	using SampleSubsystem::SampleSub;

	class NotificationDemoSub : public SampleSub
	{
	public:
		NotificationDemoSub();

		virtual ~NotificationDemoSub() {}
	};

}

#endif /* NOTIFICATIONDEMO_SOURCE_NOTIFICATIONDEMOSUB_H_ */
