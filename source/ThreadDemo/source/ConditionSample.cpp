/*
 * ConditionSample.cpp
 *
 *  Created on: Sep 4, 2017
 *      Author: peter
 */

#include "ThreadDemo/ConditionSample.h"

#include "Poco/Runnable.h"
#include "Poco/Thread.h"

namespace ThreadDemo {

	using Poco::Runnable;
	using Poco::Thread;

	class ConditionWorker : public Runnable
	{
	public:
		ConditionWorker(Condition& condition, Mutex& mutex, const std::string &name, std::ostream &os):
			_waitCondition(condition),
			_conditionMutex(mutex),
			_name(name),
			_os(os)
		{}

		virtual ~ConditionWorker(){}

		void run()
		{
			_os<<"Thread running Runnable "<<_name<<" started"<<std::endl;
			{
				Mutex::ScopedLock lock(_conditionMutex);
				_waitCondition.wait(_conditionMutex);
			}
			_os<<"Runnable "<<_name<<" continued after waiting"<<std::endl;

		}

	private:
		Condition& _waitCondition;
		Mutex& _conditionMutex;
		std::string _name;
		std::ostream& _os;
	};

	void ConditionSample::run(std::ostream& os, std::istream& is)
	{
		ConditionWorker worker1(_condition,_conditionMutex,"Worker1",os);
		ConditionWorker worker2(_condition,_conditionMutex,"Worker2",os);
		ConditionWorker worker3(_condition,_conditionMutex,"Worker3",os);
		Thread thread1;
		Thread thread2;
		Thread thread3;
		os<<"Starting worker  threads"<<std::endl;
		thread1.start(worker1);
		thread2.start(worker2);
		thread3.start(worker3);
		Thread::sleep(100);
		os<<"Waiting 1000ms until signaling condition"<<std::endl;
		Thread::sleep(1000);
		_condition.signal();
		Thread::sleep(10);
		os<<"Waiting for another 1000ms until signaling condtion"<<std::endl;
		Thread::sleep(1000);
		_condition.signal();
		Thread::sleep(10);
		os<<"Waiting for another 1000ms until signaling condtion"<<std::endl;
		Thread::sleep(1000);
		_condition.signal();
		thread1.join();
		thread2.join();
		thread3.join();
		os<<std::endl<<"Starting worker threads again..."<<std::endl;
		thread1.start(worker1);
		thread2.start(worker2);
		thread3.start(worker3);
		Thread::sleep(100);
		os<<"Waiting 1000ms until broadcasting condition"<<std::endl;
		_condition.broadcast();
		thread1.join();
		thread2.join();
		thread3.join();
	}

} /* namespace ThreadDemo */
