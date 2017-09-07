/*
 * SimpleNotificationSample.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#include "NotificationDemo/SimpleNotificationSample.h"

#include "Poco/AutoPtr.h"
#include "Poco/Notification.h"
#include "Poco/NotificationCenter.h"
#include "Poco/NObserver.h"
#include "Poco/Observer.h"
#include "Poco/String.h"

namespace NotificationDemo
{
	using Poco::AutoPtr;
	using Poco::Notification;
	using Poco::NotificationCenter;
	using Poco::NObserver;
	using Poco::Observer;

	class SampleNotification: public Notification
	{
	public:
		SampleNotification(const std::string& data):
			_data(data)
		{}

		const std::string &data() const
		{
			return _data;
		}

	private:
		std::string _data;
	};

	class SpecialSampleNotification: public SampleNotification
	{
	public:
		SpecialSampleNotification():
			SampleNotification("xyz")
		{}
	};

	class SampleTargetT1
	{
	public:
		SampleTargetT1(std::ostream& os):
			_os(os)
		{}

		void handleSampleNotification(SampleNotification *rpSampleNotification)
		{
			AutoPtr<SampleNotification> pSampleNotification(rpSampleNotification);
			_os<<"handleSampleNotification called for "<<pSampleNotification->name()<<" with "<<pSampleNotification->data()<<std::endl;
		}

		void hanldeSpecialSampleNotification(SpecialSampleNotification *rpSpecialSampleNotification)
		{
			AutoPtr<SpecialSampleNotification>pSpecialSampleNotification(rpSpecialSampleNotification);
			_os<<"handleSpecialSampleNotification called for "<<pSpecialSampleNotification->name()<<std::endl;
		}

	private:
		std::ostream& _os;
	};

	class SampleTargetT2
	{
	public:
		SampleTargetT2(std::ostream& os):
			_os(os)
		{}

		void handleSampleNotification(const AutoPtr<SampleNotification> &pSampleNotification)
		{
			_os<<"handleSampleNotification called for "<<pSampleNotification->name()<<" with "<<pSampleNotification->data()<<std::endl;
		}
	private:
		std::ostream& _os;
	};



	void SimpleNotificationSample::run(std::ostream& os, std::istream& is)
	{
		NotificationCenter nc;
		SampleTargetT1 target1(os);
		SampleTargetT2 target2(os);

		nc.addObserver(Observer<SampleTargetT1,SampleNotification>(target1,&SampleTargetT1::handleSampleNotification));
		nc.addObserver(Observer<SampleTargetT1,SpecialSampleNotification>(target1,&SampleTargetT1::hanldeSpecialSampleNotification));
		nc.addObserver(NObserver<SampleTargetT2,SampleNotification>(target2,&SampleTargetT2::handleSampleNotification));

		os<<"Posting a notification "<<std::endl;
		nc.postNotification(new SampleNotification("abc"));


		os<<"Posting the specialized notification"<<std::endl;
		nc.postNotification(new SpecialSampleNotification());

		nc.removeObserver(Observer<SampleTargetT1,SampleNotification>(target1,&SampleTargetT1::handleSampleNotification));
		nc.removeObserver(Observer<SampleTargetT1,SpecialSampleNotification>(target1,&SampleTargetT1::hanldeSpecialSampleNotification));
		nc.removeObserver(NObserver<SampleTargetT2,SampleNotification>(target2,&SampleTargetT2::handleSampleNotification));
	}
} /* namespace NotificationDemo */
