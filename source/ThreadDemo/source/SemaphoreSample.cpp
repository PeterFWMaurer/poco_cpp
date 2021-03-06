/*
 * SemaphoreSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel, das die Verwendung von Poco::Semaphore illustriert.
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "ThreadDemo/SemaphoreSample.h"

#include "Poco/Runnable.h"
#include "Poco/Semaphore.h"
#include "Poco/ThreadPool.h"

namespace ThreadDemo
{
	using Poco::Runnable;
	using Poco::Semaphore;
	using Poco::Thread;
	using Poco::ThreadPool;

	// Die Klasse Semaworker wartet in ihrer run() Methode auf eine Semaphore und gibt eine Fehlermeldung
	// aus, wenn die Semaphore nicht belegt werden kann.
	class SemaWorker : public Runnable
	{
	public:
		SemaWorker(Semaphore &semaphore, std::ostream& os):
			_semaphore(semaphore),
			_os(os)
		{};

		virtual ~SemaWorker(){};

		void run()
		{
			auto currentThreadId = Thread::current()->id();
			_os<<"Entering SemaWorker::run in thread "<<currentThreadId<<std::endl;
			if (_semaphore.tryWait(100))
			{
				_os<<"Entered range protected by semaphore in thread "<<currentThreadId<<std::endl;
				Thread::sleep(1000);
				_semaphore.set();
			}
			else
			{
				_os<<"Thread "<<currentThreadId<<" didn't get the semaphore."<<std::endl;
			}
			_os<<"Exiting SemaWorker::run in thread"<<currentThreadId<<std::endl;
		}

	private:
		Semaphore& _semaphore;
		std::ostream& _os;

	};

	void SemaphoreSample::run(std::ostream& os, std::istream& is)
	{
		// Unsere Semaphore lässt gleichzeitig 2 Threads zu
		Semaphore mySemaphore(2);
		SemaWorker worker(mySemaphore,os);
		ThreadPool::defaultPool().start(worker);
		ThreadPool::defaultPool().start(worker);
		ThreadPool::defaultPool().start(worker);

		ThreadPool::defaultPool().joinAll();
	}
} /* namespace ThreadDemo */
