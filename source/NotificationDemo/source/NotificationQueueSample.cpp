/*
 * NotificationQueueSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Notifications zwischen Threads
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "NotificationDemo/NotificationQueueSample.h"

#include "Poco/AutoPtr.h"
#include "Poco/MemoryPool.h"
#include "Poco/Notification.h"
#include "Poco/NotificationCenter.h"
#include "Poco/NotificationQueue.h"
#include "Poco/NObserver.h"
#include "Poco/Runnable.h"
#include "Poco/Thread.h"
#include "Poco/ThreadPool.h"


namespace NotificationDemo
{
	using Poco::AutoPtr;
	using Poco::MemoryPool;
	using Poco::Notification;
	using Poco::NotificationQueue;
	using Poco::NotificationCenter;
	using Poco::NObserver;
	using Poco::Runnable;
	using Poco::Thread;
	using Poco::ThreadPool;

	const int COUNTER_NOTIFICATION_POOL_SIZE=10000;

	// Unsere Beispielnotitification wird auf einem Memorypool erzeugt. Das ist sinnvoll, weil es sich
	// um ein kleines Objekt handelt, dass dynamisch erzeugt und vernichtet wird.
	class CounterNotification : public Notification
	{
	public:
		// Der new-Operator erzeugt die Notification in ihrem Pool
		void * operator new (size_t size)
		{
			poco_assert(size == sizeof(CounterNotification));
			return _pool.get();
		}

		// Der delete-Operator gibt den Speicher im Pool wieder frei
		void operator delete(void *pAlloc)
		{
			_pool.release(pAlloc);
		}

	private:
		static MemoryPool _pool;
	};

	// Initialisierung des Memorypools
	MemoryPool CounterNotification::_pool(sizeof(CounterNotification),COUNTER_NOTIFICATION_POOL_SIZE,COUNTER_NOTIFICATION_POOL_SIZE);

	// Das Runnable für unseren Thread verarbeitet die Notifications in unserer Queue mit Hilfe eines NotificationCenters
	//
	class CounterRunnable : public Runnable
	{
	public:
		// Erzeugt die Queue und setzt den Zähler auf Null, er soll für jede CounterNotification um eins erhöht werden.
		CounterRunnable(NotificationQueue& queue):
			_queue(queue),
			_count(0)
		{
			// Wir registrieren unseren Handler bei unserem NotificationCenter
			_notificationCenter.addObserver(NObserver<CounterRunnable,CounterNotification>(*this,&CounterRunnable::handleCounterNotification));

		}

		void run()
		{
			// Wir warten auf Notifications, solange die Queue aktiv ist.
			while (Notification* pN=_queue.waitDequeueNotification())
			{
				// ...und verarbeiten sie über unser NotificationCenter
				_notificationCenter.postNotification(pN);
			}
		}

		// Wenn wir eine Notification erhalten, inkrementieren wir den Zähler um 1
		void handleCounterNotification(const AutoPtr<CounterNotification>& pN)
		{
			_count++;
		}

		// Geter für den Zähler
		int count() const
		{
			return _count;
		}

	private:
		int _count;
		NotificationQueue& _queue;
		NotificationCenter _notificationCenter;
	};

	void NotificationQueueSample::run(std::ostream& os, std::istream& is)
	{

		NotificationQueue counterQueue;

		CounterRunnable cr1(counterQueue);
		CounterRunnable cr2(counterQueue);

		ThreadPool::defaultPool().start(cr1);
		ThreadPool::defaultPool().start(cr2);

		for (int i=0;i<COUNTER_NOTIFICATION_POOL_SIZE;i++)
		{
			counterQueue.enqueueNotification(new CounterNotification());
		}

		while (!counterQueue.empty())
		{
			Thread::sleep(10);
		}
		counterQueue.wakeUpAll();
		ThreadPool::defaultPool().joinAll();

		std::cout<<"Count Runnable1: "<<cr1.count()<<std::endl;
		std::cout<<"Count Runnable2: "<<cr2.count()<<std::endl;
	}

}
