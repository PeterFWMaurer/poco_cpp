/*
 * SampleEventInfo.h
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#ifndef EVENTDEMO_SOURCE_SAMPLEEVENTINFO_H_
#define EVENTDEMO_SOURCE_SAMPLEEVENTINFO_H_

namespace EventDemo {

	class SampleEvtInfo
	{
	public:


		SampleEvtInfo(const std::string &name):
			_count(0),
			_name(name)
		{}

		virtual ~SampleEvtInfo()
		{}

		int count()
		{
			return _count;
		}

		const std::string& name()
		{
			return _name;
		}

		int operator ++()
		{
			return ++_count;
		}

	private:
		int _count;
		std::string _name;
	};

} /* namespace EventDemo */

#endif /* EVENTDEMO_SOURCE_SAMPLEEVENTINFO_H_ */
