/*
 * ThreadPoolSample.cpp
 *
 *  Created on: Sep 1, 2017
 *      Author: peter
 */

#include "ThreadDemo/ThreadPoolSample.h"
#include "Poco/SharedPtr.h"
#include "Poco/ThreadPool.h"
#include "Poco/Timespan.h"
#include "Poco/Timestamp.h"

#include <limits>
#include <vector>

namespace ThreadDemo {

	using Poco::Runnable;
	using Poco::SharedPtr;
	using Poco::Thread;
	using Poco::ThreadPool;
	using Poco::Timespan;
	using Poco::Timestamp;
	using std::vector;

	class Worker : public Runnable
	{
	public:
		Worker(){}

		virtual ~Worker(){}

		void run()
		{
			for (int i=0;i<std::numeric_limits<int>::max();i++)
			{
				for (int j = 0; j<1000; j++)
				{}
			}
		}
	};

	Timespan ThreadPoolSample::createThreadsFromPool(int noOfThreads, bool preallocated)
	{
		// We create the Threadpool anyway before starting time measurement
		int minCapacity=2;
		if (preallocated)
		{
			minCapacity=noOfThreads;
		}

		ThreadPool myThreadPool(minCapacity,noOfThreads,60,0);

/*		vector<Worker> workers;
		for (int i=0;i<myThreadPool.capacity();i++)
		{
			workers.push_back(Worker());
		}
*/
		Worker myWorker;

		Timestamp beforeThreadStart;

		for (int i=0;i<noOfThreads;i++)
		{
			myThreadPool.start(myWorker);
		}

		Timespan elapsedTime = beforeThreadStart.elapsed();

		myThreadPool.joinAll();

		return elapsedTime;
	}

	Timespan ThreadPoolSample::createThreadsWithSimpleThreads(int noOfThreads)
	{
		vector<SharedPtr<Thread>> simpleThreads;
		Worker myWorker;

		Timestamp beforeThreadStart;
		for (int i=0;i<noOfThreads;i++)
		{
			simpleThreads.push_back(new Thread());
		}

		for (int i=0;i<noOfThreads;i++)
		{
			SharedPtr<Thread> currentThread = simpleThreads.at(i);
			currentThread->start(myWorker);
		}

		Timespan elapsedTime = beforeThreadStart.elapsed();

		for (int i=0;i<noOfThreads;i++)
		{
			SharedPtr<Thread> currentThread = simpleThreads.at(i);
			currentThread->join();
		}

		return elapsedTime;
	}

	void ThreadPoolSample::run(std::ostream& os, std::istream& is)
	{
		const int noOfThreads = 10;
		Timespan noPreallocPoolSpan = createThreadsFromPool(noOfThreads,false);
		Timespan preallocPoolSpan = createThreadsFromPool(noOfThreads,true);
		Timespan simpleThreadSpan = createThreadsWithSimpleThreads(noOfThreads);

		std::cout<<"Creation of Threads:"<<std::endl
				 <<noOfThreads<<" Threads withoyt preallocation of Threads in ThreadPool: "<<noPreallocPoolSpan.microseconds()<<"µs"<<std::endl
				 <<noOfThreads<<" Threads with preallocated threads in ThreadPool:        "<<preallocPoolSpan.microseconds()<<"µs"<<std::endl
				 <<noOfThreads<<" Threads not using ThradPool:                            "<<simpleThreadSpan.microseconds()<<"µs"<<std::endl;
	}
} /* namespace ThreadDemo */
