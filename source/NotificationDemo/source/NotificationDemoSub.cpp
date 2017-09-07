/*
 * NotificationDemoSub.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#include "NotificationDemo/NotificationDemoSub.h"
#include "NotificationDemo/SimpleNotificationSample.h"

namespace NotificationDemo {

NotificationDemoSub::NotificationDemoSub():
	SampleSub("NotificationDemo")
{
	addSample(new SimpleNotificationSample());
}

} /* namespace NotificationDemo */
