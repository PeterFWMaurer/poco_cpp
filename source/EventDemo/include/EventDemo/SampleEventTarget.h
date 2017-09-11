/*
 * SampleEventTarget.h
 *
 * Author: Peter Maurer
 *
 * Beispiel für ein Eventtarget
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef EVENTDEMO_INCLUDE_EVENTDEMO_SAMPLEEVENTTARGET_H_
#define EVENTDEMO_INCLUDE_EVENTDEMO_SAMPLEEVENTTARGET_H_

#include "EventDemo/SampleEventInfo.h"

#include <string>
#include <iostream>

namespace EventDemo
{
	// Eine Beliebige Klasse kann Events verarbeiten
	class SampleEventTarget
	{
	public:
		// Unser Target erhält einen Namen, damit wir es erkennen.
		SampleEventTarget(const std::string& name, std::ostream& os):
			_name(name),
			_os(os)
		{}

		virtual ~SampleEventTarget(){}

		// Ein Target muss eine Funktion zum Verarbeiten des Events haben. Das Event wird by reference übertragen und kann
		// verändert werden.
		void onSampleEvent(const void *pSender,SampleEvtInfo& evt)
		{
			_os<<"Target "<<_name<<" received Event "<<evt.name()<<" increasing its count."<<std::endl;
			++evt;
		}

	private:
		std::string _name;
		std::ostream& _os;
	};
}



#endif /* EVENTDEMO_INCLUDE_EVENTDEMO_SAMPLEEVENTTARGET_H_ */
