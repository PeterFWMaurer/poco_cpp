/*
 * NotificationDemoSub.h
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Delegates mit Zerfallsdatum in Poco
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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
