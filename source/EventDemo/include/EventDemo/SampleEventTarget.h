/*
 * SampleEventTarget.h
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#ifndef EVENTDEMO_INCLUDE_EVENTDEMO_SAMPLEEVENTTARGET_H_
#define EVENTDEMO_INCLUDE_EVENTDEMO_SAMPLEEVENTTARGET_H_

#include "EventDemo/SampleEventInfo.h"

#include <string>
#include <iostream>

namespace EventDemo
{
	class SampleEventTarget
	{
	public:
		SampleEventTarget(const std::string& name, std::ostream& os):
			_name(name),
			_os(os)
		{}

		virtual ~SampleEventTarget(){}

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
