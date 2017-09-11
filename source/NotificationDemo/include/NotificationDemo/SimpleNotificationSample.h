/*
 * SimpleNotificationSample.h
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung eines NoticifationCenter in Poco
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef NOTIFICATIONDEMO_SOURCE_SIMPLENOTIFICATIONSAMPLE_H_
#define NOTIFICATIONDEMO_SOURCE_SIMPLENOTIFICATIONSAMPLE_H_

#include "SampleSubsystem/SampleSub.h"

namespace NotificationDemo
{
	using SampleSubsystem::Sample;

	class SimpleNotificationSample: public Sample
	{
	public:
		SimpleNotificationSample()
			:Sample("SimpleNotificationSample")
		{}

		virtual ~SimpleNotificationSample(){}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace NotificationDemo */

#endif /* NOTIFICATIONDEMO_SOURCE_SIMPLENOTIFICATIONSAMPLE_H_ */
