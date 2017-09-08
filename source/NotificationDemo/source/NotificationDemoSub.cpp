/*
 * NotificationDemoSub.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#include "NotificationDemo/NotificationDemoSub.h"
#include "NotificationDemo/SimpleNotificationSample.h"
#include "NotificationDemo/NotificationQueueSample.h"
#include "NotificationDemo/PriorityNQSample.h"

namespace NotificationDemo {

NotificationDemoSub::NotificationDemoSub():
	SampleSub("NotificationDemo")
{
	addSample(new SimpleNotificationSample());
	addSample(new NotificationQueueSample());
	addSample(new PriorityNQSample());
}

} /* namespace NotificationDemo */
