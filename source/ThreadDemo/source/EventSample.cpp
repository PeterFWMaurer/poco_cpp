/*
 * EventSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel, das die Verwendung von Poco::Event illustriert.
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "ThreadDemo/EventSample.h"

#include "Poco/ActiveMethod.h"
#include "Poco/Event.h"
#include "Poco/Thread.h"

namespace ThreadDemo
{
	using Poco::ActiveMethod;
	using Poco::ActiveResult;
	using Poco::Event;
	using Poco::Runnable;
	using Poco::Thread;
	using Poco::ThreadPool;

	// Worker setzt beim Start das Event und nimmt es beim Ende zurück
	class Worker
	{
	public:
		Worker():
			work(this,&Worker::workImpl)
		{}

		ActiveMethod<void,Event&,Worker> work;

	private:

		void workImpl(Event& event)
		{
			event.set();
			Thread::sleep(5000);
			event.reset();
		}
	};

	// Progress Thread druckt Punkte, solange das _progressEvent gesetzt ist das _stopEvent
	// nicht gesetzt ist.
	//
	class ProgressRunnable : public Runnable
	{
	public:
		ProgressRunnable(std::ostream& os, Event& progressEvent, Event& stopEvent):
			_os(os),
			_progressEvent(progressEvent),
			_stopEvent(stopEvent)
		{}

		virtual ~ProgressRunnable(){}

		void run()
		{
			std::cout<<"ProgressThread running"<<std::endl;
			while(!_stopEvent.tryWait(1000))
			{
				_progressEvent.wait();
				(_os<<".").flush();
			}
			std::cout<<std::endl;
		}

	private:
		std::ostream& _os;
		Event& _progressEvent;
		Event& _stopEvent;
	};

	void EventSample::run(std::ostream& os, std::istream& is)
	{
		Event showProgressEvent(false);
		Event stopEvent(true);
		Thread progressThread;

		ProgressRunnable progressRunnable(os,showProgressEvent,stopEvent);
		progressThread.start(progressRunnable);

		Worker worker;
		ActiveResult<void> workerResult = worker.work(showProgressEvent);
		workerResult.wait();

		stopEvent.set();
		progressThread.join();
	}
}
