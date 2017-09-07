/*
 * SimpleEventSample.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: peter
 */

#include "EventDemo/SimpleEventSample.h"

#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"

namespace EventDemo
{
	using Poco::BasicEvent;

	class EventData
	{
	public:
		typedef BasicEvent<EventData> EventDataEvent;

		EventData(int value,const std::string &name):
			_value(value),
			_name(name)
		{}

		virtual ~EventData()
		{}

		int value()
		{
			return _value;
		}

		const std::string& name()
		{
			return _name;
		}
	private:
		int _value;
		std::string _name;
	};

	class SampleEventSource
	{
	public:
		void fireEvent(EventData evd)
		{
			_event(this,evd);
			//_event.notify(this,EventData(1,myEvent));
		}
	private:
		EventData::EventDataEvent _event;
	};

	class SampleEventTarget
	{

	};

	void SimpleEventSample::run(std::ostream& os, std::istream& is)
	{

	}

}
