/*
 * PriorityNQSample.h
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von priorisierten Notifications zwischen Threads
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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
