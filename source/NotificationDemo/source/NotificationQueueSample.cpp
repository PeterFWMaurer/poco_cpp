/*
 * NotificationQueueSample.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
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

	class CounterNotification : public Notification
	{
	public:
		void * operator new (size_t size)
		{
			poco_assert(size == sizeof(CounterNotification));
			return _pool.get();
		}

		void operator delete(void *pAlloc)
		{
			_pool.release(pAlloc);
		}

	private:
		static MemoryPool _pool;
	};

	MemoryPool CounterNotification::_pool(sizeof(CounterNotification),COUNTER_NOTIFICATION_POOL_SIZE,COUNTER_NOTIFICATION_POOL_SIZE);

	class CounterRunnable : public Runnable
	{
	public:
		CounterRunnable(NotificationQueue& queue):
			_queue(queue),
			_count(0)
		{
			_notificationCenter.addObserver(NObserver<CounterRunnable,CounterNotification>(*this,&CounterRunnable::handleCounterNotification));

		}

		void run()
		{
			while (Notification* pN=_queue.waitDequeueNotification())
			{
				_notificationCenter.postNotification(pN);
			}
		}

		void handleCounterNotification(const AutoPtr<CounterNotification>& pN)
		{
			_count++;
		}

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
