/*
 * AnySample.cpp
 *
 *  Created on: Aug 25, 2017
 *      Author: peter
 */

#include "ThreadDemo/ThreadSample.h"

#include "Poco/Any.h"
#include "Poco/ActiveMethod.h"
#include "Poco/Thread.h"
#include "Poco/Types.h"

namespace ThreadDemo
{
	using Poco::Thread;
	using Poco::Runnable;
	using Poco::ActiveMethod;
	using Poco::ActiveResult;

	class SimpleRunnable : public Runnable
	{
	public:
		SimpleRunnable(std::ostream &os):
			_os(os)
		{}

		virtual void run()
		{
			_os<<"SimpeRunnable::run called from Thread:"<<std::endl;
			ThreadSample::printThreadInfo(_os);
		}
	private:
		std::ostream &_os;
	};

	class ThreadInfoPrinter
	{
	public:
		ThreadInfoPrinter(std::ostream &os):
			_os(os)
		{}

		void print()
		{
			_os<<"ThreadInfoPrinter::print called from Thread:"<<std::endl;
		}

	private:
		std::ostream& _os;

	};

	class SimpleActiveObject
	{
	public:
		SimpleActiveObject():
			activeDoSmt(this,&SimpleActiveObject::doSmtImpl)
		{}

		ActiveMethod<int,std::ostream&,SimpleActiveObject> activeDoSmt;

	private:
		int doSmtImpl(std::ostream& os)
		{
			os<<"SimpleActiveObject::doSmt called from Thread"<<std::endl;
			ThreadSample::printThreadInfo(os);
			return 42;
		}
	};

	void ThreadSample::printThreadInfo(std::ostream& os)
	{
		Thread *myThread = Thread::current();
		if (myThread==0)
		{
			os<<"For the main Thread, Thread::current() delivers a Null-Pointer!"<<
					std::endl<<std::endl;
		}
		else
		{
			os<<"Poco Thread Id:"<<myThread->id()<<std::endl;
			os<<"Native Thread Id:"<<myThread->currentTid()<<std::endl;
			os<<"Thread Priority (Poco):"<<myThread->getPriority()<<std::endl;
			os<<"Thread Priority (native):"<<myThread->getOSPriority()<<std::endl;
			os<<"Thread Name:"<<myThread->name()<<std::endl<<std::endl;
		}

	}

	void ThreadSample::run(std::ostream &os, std::istream &is)
	{
		// We call the printThreadInfo function form run to get info about it.
		os<<"Infos about current run of ThreadSample::run"<<std::endl;
		printThreadInfo(os);

		// Ein Runnable und einen Thread erzeugen und das Runnable starten.
		SimpleRunnable myRunnable(os);
		Thread mySimpleThread;
		mySimpleThread.start(myRunnable);

		// Auf den Abschluss des Thread warten
		mySimpleThread.join();

		// Wir lassen den Thread erneut laufen, diesmal mit einer Lambda Funktion
		mySimpleThread.startFunc([&os]()
				{
					os<<"Lambda called from Thread"<<std::endl;
					ThreadSample::printThreadInfo(os);
				}
		);
		mySimpleThread.join();

		// Jetzt erzeugen wir unser SimpleActiveObject und rufen unsere
		// Methode auf:
		SimpleActiveObject myActiveObject;
		ActiveResult<int> result=myActiveObject.activeDoSmt(os);
		result.wait();
		os<<"Result of our active method: "<<result.data()<<std::endl;


	}
}



