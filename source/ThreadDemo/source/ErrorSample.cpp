/*
 * ErrorSample.cpp
 *
 *  Created on: Sep 4, 2017
 *      Author: peter
 */

#include "ThreadDemo/ErrorSample.h"

#include "Poco/ErrorHandler.h"
#include "Poco/Exception.h"
#include "Poco/Runnable.h"
#include "Poco/Thread.h"

namespace ThreadDemo
{
	using Poco::ErrorHandler;
	using Poco::Exception;
	using Poco::Runnable;
	using Poco::Thread;

	class ErrorSampleException: public Exception
	{
	public:
		ErrorSampleException():
			Exception("Error Sample Exception")
		{}

		virtual ~ErrorSampleException(){}
	};

	class ExceptionRunner : public Runnable
	{
	public:
		ExceptionRunner(std::ostream& os):
			_os(os)
		{}

		virtual ~ExceptionRunner(){}

		void run()
		{
			_os<<"Thread will throw an exception (id = "<<Thread::current()->id()<<")"<<std::endl;
			throw ErrorSampleException();
		}

	private:
		std::ostream& _os;
	};

	class SampleErrorHandler : public Poco::ErrorHandler
	{
		void excpetion(const Exception &exp)
		{
			std::cout<<exp.displayText()<<" in thread (id = "<<Thread::current()->id()<<")"<<std::endl;
		}

		void exception(const std::exception &exp)
		{
			std::cout<<"Exception "<<exp.what()<<" in thread (id = "<<Thread::current()->id()<<")"<<std::endl;
		}

		void exception()
		{
			std::cout<<"Unknown Exception from thread (id = "<<Thread::current()->id()<<")"<<std::endl;
		}
	};

	void ErrorSample::run(std::ostream &os, std::istream &is)
	{
		os<<"Creating a thread causing an exception"<<std::endl;
		ExceptionRunner errorRunnable(os);
		Thread t1;
		t1.start(errorRunnable);
		t1.join();
		os<<"Exception from thread not handled, program continuing..."<<std::endl<<std::endl;

		os<<"Now registering Errorhandler writing Exception info to std::cerr"<<std::endl;
		SampleErrorHandler sampleErrorHandler;
		ErrorHandler* pOldErrorHandler = Poco::ErrorHandler::set(&sampleErrorHandler);

		Thread t2;
		os<<"Creating again a thread causin exception:"<<std::endl;
		t2.start(errorRunnable);
		t2.join();

		Poco::ErrorHandler::set(pOldErrorHandler);

		os<<"And now"<<std::endl;
	}

} /* namespace ThreadDemo */
