/*
 * SimpleNotificationSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung eines NoticifationCenter in Poco
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "NotificationDemo/SimpleNotificationSample.h"

#include "Poco/AutoPtr.h"
#include "Poco/Notification.h"
#include "Poco/NotificationCenter.h"
#include "Poco/NObserver.h"
#include "Poco/Observer.h"

namespace NotificationDemo
{
	using Poco::AutoPtr;
	using Poco::Notification;
	using Poco::NotificationCenter;
	using Poco::NObserver;
	using Poco::Observer;

	// Beispiel für eine Notification, erbt von Poco::Notification
	//
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

	// Beispiel für eine von unserer SamppleNotification abgeleiteten Notification
	//
	class SpecialSampleNotification: public SampleNotification
	{
	public:
		SpecialSampleNotification():
			SampleNotification("xyz")
		{}
	};

	// Eine Beliebige Klasse kann Target für Notifictions sein
	//
	class SampleTargetT1
	{
	public:
		SampleTargetT1(std::ostream& os):
			_os(os)
		{}

		// Um Notifications verarbeiten zu können, muss eine entsprechende Funktion deklariert sein, die die
		// Notification als Rawopointer erhält...
		void handleSampleNotification(SampleNotification *rpSampleNotification)
		{
			AutoPtr<SampleNotification> pSampleNotification(rpSampleNotification);
			_os<<"handleSampleNotification called for "<<pSampleNotification->name()<<" with "<<pSampleNotification->data()<<std::endl;
		}

		// Für eine spezialisierte Notificatin kann ein eigener Handler definiert sein
		void hanldeSpecialSampleNotification(SpecialSampleNotification *rpSpecialSampleNotification)
		{
			AutoPtr<SpecialSampleNotification>pSpecialSampleNotification(rpSpecialSampleNotification);
			_os<<"handleSpecialSampleNotification called for "<<pSpecialSampleNotification->name()<<std::endl;
		}

	private:
		std::ostream& _os;
	};

	// Auch dieses Target interessiert sich für unsere SampleNotification
	class SampleTargetT2
	{
	public:
		SampleTargetT2(std::ostream& os):
			_os(os)
		{}

		// Der Handler erhält hier allerdings einen AutoPtr
		void handleSampleNotification(const AutoPtr<SampleNotification> &pSampleNotification)
		{
			_os<<"handleSampleNotification called for "<<pSampleNotification->name()<<" with "<<pSampleNotification->data()<<std::endl;
		}
	private:
		std::ostream& _os;
	};



	void SimpleNotificationSample::run(std::ostream& os, std::istream& is)
	{
		// NotificationCenter und Targets werden auf dem Stack erzeugt
		NotificationCenter nc;
		SampleTargetT1 target1(os);
		SampleTargetT2 target2(os);

		// Die Handler fürs erste Target werden am NotificationCenter als Observer angemeldet
		nc.addObserver(Observer<SampleTargetT1,SampleNotification>(target1,&SampleTargetT1::handleSampleNotification));
		nc.addObserver(Observer<SampleTargetT1,SpecialSampleNotification>(target1,&SampleTargetT1::hanldeSpecialSampleNotification));

		// Der Handler fürs zweite Target muss wegen des AutoPointers als NObserver angemeldet werden
		nc.addObserver(NObserver<SampleTargetT2,SampleNotification>(target2,&SampleTargetT2::handleSampleNotification));

		// Wir versenden die Notifications und betrachten das Ergebnis
		os<<"Posting a notification "<<std::endl;
		nc.postNotification(new SampleNotification("abc"));


		os<<"Posting the specialized notification"<<std::endl;
		nc.postNotification(new SpecialSampleNotification());

		// Die Handler werden wieder abgemeldet
		nc.removeObserver(Observer<SampleTargetT1,SampleNotification>(target1,&SampleTargetT1::handleSampleNotification));
		nc.removeObserver(Observer<SampleTargetT1,SpecialSampleNotification>(target1,&SampleTargetT1::hanldeSpecialSampleNotification));
		nc.removeObserver(NObserver<SampleTargetT2,SampleNotification>(target2,&SampleTargetT2::handleSampleNotification));
	}
} /* namespace NotificationDemo */
