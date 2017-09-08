/*
 * PriorityNQSample.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
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

	class TypeANotification : public Notification
	{};

	class TypeBNotification : public Notification
	{};

	class NotificationProcessor : public Runnable
	{
	public:
		PriorityNotificationQueue queue;

		NotificationProcessor()
		{
			_nc.addObserver(NObserver<NotificationProcessor,TypeANotification>(*this,&NotificationProcessor::handleSmpNotificationA));
			_nc.addObserver(NObserver<NotificationProcessor,TypeBNotification>(*this,&NotificationProcessor::handleSmpNotificationB));
		}

		void handleSmpNotificationA(const AutoPtr<TypeANotification>& pNA)
		{
			std::cout<<"received "<<pNA->name()<<std::endl;
		}

		void handleSmpNotificationB(const AutoPtr<TypeBNotification>& pNB)
		{
			std::cout<<"received "<<pNB->name()<<std::endl;
		}

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

	class TypeANotificationProducer: public NotificationProducer<TypeANotification,1,100>
	{
	public:
		TypeANotificationProducer(NotificationProcessor& processor):
			NotificationProducer(processor)
		{}
	};

	class TypeBNotificationProducer: public NotificationProducer<TypeBNotification,2,10>
	{
	public:
		TypeBNotificationProducer(NotificationProcessor& processor):
			NotificationProducer(processor)
		{}
	};

	void PriorityNQSample::run(std::ostream& os, std::istream& is)
	{
		NotificationProcessor myProcessor;
		TypeANotificationProducer aProd(myProcessor);
		TypeBNotificationProducer bProd(myProcessor);

		ThreadPool::defaultPool().start(bProd);
		ThreadPool::defaultPool().start(aProd);

		Thread::sleep(500);

		os<<"Current Queue size: "<<myProcessor.queue.size()<<std::endl;
		ThreadPool::defaultPool().start(myProcessor);

		while (!myProcessor.queue.empty())
		{
			Thread::sleep(100);
		}

		myProcessor.queue.wakeUpAll();

		ThreadPool::defaultPool().joinAll();
		os<<"Everything done!"<<std::endl;
	}

} /* namespace NotificationDemo */
