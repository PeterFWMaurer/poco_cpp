/*
 * SynchronizedSample.cpp
 *
 *  Created on: Sep 4, 2017
 *      Author: peter
 */

#include "ThreadDemo/SynchronizedSample.h"

#include "Poco/SynchronizedObject.h"
#include "Poco/Thread.h"

namespace ThreadDemo {

	using Poco::SynchronizedObject;
	using Poco::Thread;

	class SynchObject : public SynchronizedObject
	{
	public:
		SynchObject(std::ostream& os):
			_os(os)
		{}

		virtual ~SynchObject(){}

		int getSomeInformation()
		{
			Thread *myThread = Thread::current();
			SynchObject::ScopedLock myLock(*this);
			_os<<"Entered scoped lock in SynchObject (thread id "<<myThread->id()<<")"<<std::endl;
			Thread::sleep(100);
			_os<<"Exiting scoped lock in SynchObject (thread id "<<myThread->id()<<")"<<std::endl;
			return 42;
		}

		int waitForNotification()
		{
			Thread *myThread = Thread::current();
			_os<<"Entered waitForNotification in SychObject (thread id "<<myThread->id()<<")"<<std::endl;
			wait();
			_os<<"Exiting waitForNotification in SychObject (thread id "<<myThread->id()<<")"<<std::endl;

		}

	private:
		std::ostream& _os;
	};

	void SynchronizedSample::run(std::ostream& os, std::istream& is)
	{
		SynchObject myObj(os);
		Thread t1;
		Thread t2;
		t1.startFunc([&os,&myObj]()
			{
				os<<"Thread 1 started"<<std::endl;
				myObj.getSomeInformation();
				os<<"Thread 2 finished"<<std::endl;
			}
		);
		t2.startFunc([&os,&myObj]()
			{
				os<<"Thread 2 started"<<std::endl;
				myObj.getSomeInformation();
				os<<"Thread 2 finished"<<std::endl;
			}
		);
		t1.join();
		t2.join();

		Thread t3;
		Thread t4;

		t3.startFunc([&os,&myObj]()
			{
				os<<"Thread 3 started"<<std::endl;
				myObj.waitForNotification();
				os<<"Thread 3 finished"<<std::endl;
			}
		);

		t4.startFunc([&os,&myObj]()
			{
				os<<"Thread 4 started"<<std::endl;
				myObj.waitForNotification();
				os<<"Thread 4 finished"<<std::endl;
			}
		);

		os<<"Main thread sleeping for a moment..."<<std::endl;
		Thread::sleep(100);
		os<<"Main thread will notify myObj"<<std::endl;
		myObj.notify();
		Thread::sleep(0);
		os<<"Main thread sleeping for another moment..."<<std::endl;
		Thread::sleep(100);
		os<<"Main thread notifying again myObj"<<std::endl;
		myObj.notify();
		Thread::sleep(0);
		t3.join();
		t4.join();
	}

} /* namespace ThreadDemo */
