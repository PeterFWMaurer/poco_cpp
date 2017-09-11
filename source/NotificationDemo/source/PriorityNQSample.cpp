/*
 * PriorityNQSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von pririsierten Notifications zwischen Threads
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "NotificationDemo/PriorityNQSample.h"

#include "Poco/AutoPtr.h"
#include "Poco/NObserver.h"
#include "Poco/Notification.h"
#include "Poco/NotificationCenter.h"
#include "Poco/PriorityNotificationQueue.h"
#include "Poco/Runnable.h"
#include "Poco/Thread.h"
#include "Poco/ThreadPool.h"

namespace NotificationDemo
{
	using Poco::AutoPtr;
	using Poco::NObserver;
	using Poco::Notification;
	using Poco::NotificationCenter;
	using Poco::PriorityNotificationQueue;
	using Poco::Runnable;
	using Poco::Thread;
	using Poco::ThreadPool;

	// Eine einfache Nachricht
	class TypeANotification : public Notification
	{};

	// Eine andere einfache Nachtricht
	class TypeBNotification : public Notification
	{};

	// Die Klasse NotificationProcessor definiert den Thread für die Verarbeitung unserer Nachrichten
	//
	class NotificationProcessor : public Runnable
	{
	public:
		// Sie verwendet eine PriorityNotificationQueue für die Nachrichten
		PriorityNotificationQueue queue;

		NotificationProcessor()
		{
			// Wir registrieren unsere Handler an unserem NotificationCenter
			_nc.addObserver(NObserver<NotificationProcessor,TypeANotification>(*this,&NotificationProcessor::handleSmpNotificationA));
			_nc.addObserver(NObserver<NotificationProcessor,TypeBNotification>(*this,&NotificationProcessor::handleSmpNotificationB));
		}

		// Behandlungsfunktionen für TypeANotification
		void handleSmpNotificationA(const AutoPtr<TypeANotification>& pNA)
		{
			std::cout<<"received "<<pNA->name()<<std::endl;
		}

		// Behandlungsfunktionen für TypeBNotification
		void handleSmpNotificationB(const AutoPtr<TypeBNotification>& pNB)
		{
			std::cout<<"received "<<pNB->name()<<std::endl;
		}

		// Der Thread arbeitet die NotificatinQueue ab
		void run()
		{
			while (Notification* pN=queue.waitDequeueNotification())
			{
				_nc.postNotification(pN);
			}
		}

	private:
		NotificationCenter _nc;

	};

	// Wir erzeugen unsere Notifications aus separaten Threads, deshalb haben wir ein Template für
	// die entsprechenden Runnables definiert. priority gibt an, mit welcher Priorität die
	// Notification verschickt werden soll, waitTime, wieviele ms zwischen den Notifications liegen sollen
	//
	template <typename NotificationType,int priority,int waitTime>
	class NotificationProducer : public Runnable
	{
	public:
		NotificationProducer(NotificationProcessor& processor):
			_processor(processor)
		{}

		void run()
		{
			int max_i = 1000/waitTime;
			for (int i=0;i<max_i;i++)
			{
				_processor.queue.enqueueNotification(new NotificationType(),priority);
				Thread::sleep(waitTime);
			}
		}
	private:
		NotificationProcessor& _processor;
	};

	// Runnable für TypA (Prio 1, 100ms Wartezeit)
	class TypeANotificationProducer: public NotificationProducer<TypeANotification,1,100>
	{
	public:
		TypeANotificationProducer(NotificationProcessor& processor):
			NotificationProducer(processor)
		{}
	};

	// Runnable für TypB (Prio 2, 10ms Wartezeit)
	class TypeBNotificationProducer: public NotificationProducer<TypeBNotification,2,10>
	{
	public:
		TypeBNotificationProducer(NotificationProcessor& processor):
			NotificationProducer(processor)
		{}
	};

	void PriorityNQSample::run(std::ostream& os, std::istream& is)
	{
		// Wir erzeugen unsere Runnables auf dem Stack
		NotificationProcessor myProcessor;
		TypeANotificationProducer aProd(myProcessor);
		TypeBNotificationProducer bProd(myProcessor);

		// Wir Starten die beiden Erzeugerthreads
		ThreadPool::defaultPool().start(bProd);
		ThreadPool::defaultPool().start(aProd);

		// Nach 500ms starten wir den Abarbeitungsthread
		Thread::sleep(500);
		os<<"Current Queue size: "<<myProcessor.queue.size()<<std::endl;
		ThreadPool::defaultPool().start(myProcessor);

		// Wir warten bis die Queue leer ist und rufen dann wakeUpAll auf
		while (!myProcessor.queue.empty())
		{
			Thread::sleep(100);
		}
		myProcessor.queue.wakeUpAll();

		// Wir warten bis alle Threads abgearbeiet sind
		ThreadPool::defaultPool().joinAll();
		os<<"Everything done!"<<std::endl;
	}

} /* namespace NotificationDemo */
