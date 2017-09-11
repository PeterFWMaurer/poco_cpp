/*
 * NotificationDemoSub.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Delegates mit Zerfallsdatum in Poco
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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
