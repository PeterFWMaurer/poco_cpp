/*
 * AnySample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel, das verschiedenen Arten zeigt, wie Threads in Poco implementiert werden können
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "ThreadDemo/ThreadSample.h"

#include "Poco/Any.h"
#include "Poco/ActiveMethod.h"
#include "Poco/Activity.h"
#include "Poco/RunnableAdapter.h"
#include "Poco/Thread.h"
#include "Poco/Types.h"

namespace ThreadDemo
{
	using Poco::Thread;
	using Poco::Runnable;
	using Poco::RunnableAdapter;
	using Poco::ActiveMethod;
	using Poco::ActiveResult;
	using Poco::Activity;

	// Threads können mit Hilfe einer von Poco::Runnable abgeleiteten Klasse implementiert werden.
	// Ein und dasselbe Runnable kann mehrfach parallel laufen
	class SimpleRunnable : public Runnable
	{
	public:
		SimpleRunnable(std::ostream &os):
			_os(os)
		{}

		// Die Funktion run() wird im Thread ausgeführt
		virtual void run()
		{
			_os<<"SimpeRunnable::run called from Thread:"<<std::endl;
			ThreadSample::printThreadInfo(_os);
		}
	private:
		std::ostream &_os;
	};

	// Ein Thread kann auch mit Hilfe eines RunnableAdapters gestarten werden. Unsere Beispielklasse
	// meldet die Funktion print() an, die im Thread ausgeführt wird
	class ThreadInfoPrinter
	{
	public:
		ThreadInfoPrinter(std::ostream &os):
			_os(os)
		{}

		void print()
		{
			_os<<"ThreadInfoPrinter::print called from Thread:"<<std::endl;
			ThreadSample::printThreadInfo(_os);
		}

	private:
		std::ostream& _os;

	};

	// Ein Objekt kann eine ActiveMethod haben, die in einem Thread aus dem Threadpool ausgefuuhrt wird
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

	// Ein objekt kann eine oder mehrer Activities haben, die in einem oder mehreren Threads ausgeführt werden
	class ObjectWithActivity
	{
	public:
		ObjectWithActivity(std::ostream& os):
			_myActivity(this,&ObjectWithActivity::runMyActivity),
			_os(os)
		{}

		virtual ~ObjectWithActivity(){}

		void startMyActivity()
		{
			_myActivity.start();
		}

		void stopMyActivity()
		{
			_myActivity.stop();
			_myActivity.wait();
		}

	protected:
		void runMyActivity()
		{
			_os<<"Running Activity in Thread:"<<std::endl;
			ThreadSample::printThreadInfo(_os);
			while (!_myActivity.isStopped())
			{
				_os<<"."<<std::flush;
				Thread::sleep(100);
			}
			_os<<std::endl;
		}

	private:
		Activity<ObjectWithActivity> _myActivity;
		std::ostream& _os;
	};

	// Hilfsfunktion zum Ausgeben von Informationen über den Thread, in dem Sie ausgeführt wird
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


		// Diesmal lassen wir in unserem Thread unseren ThreadInfoPrinter mit Hilfe des RunnableAdadpters laufen
		ThreadInfoPrinter myPrinter(os);
		RunnableAdapter<ThreadInfoPrinter> myPrinterAdapter(myPrinter,&ThreadInfoPrinter::print);
		mySimpleThread.start(myPrinterAdapter);
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
		// ActiveMethode auf:
		SimpleActiveObject myActiveObject;
		ActiveResult<int> result=myActiveObject.activeDoSmt(os);
		result.wait();
		os<<"Result of our active method: "<<result.data()<<std::endl;

		// Jetzt erzeugen wir unser ObjectWithActivity und starten unsere Activity
		ObjectWithActivity myObjectWithActivity(os);
		myObjectWithActivity.startMyActivity();
		Thread::sleep(1200);
		myObjectWithActivity.stopMyActivity();
	}
}



