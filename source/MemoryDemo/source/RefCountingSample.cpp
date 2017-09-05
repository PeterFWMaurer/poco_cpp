/*
 * RefCountingSample.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#include "MemoryDemo/RefCountingSample.h"

#include "Poco/AutoPtr.h"
#include "Poco/Mutex.h"
#include "Poco/RefCountedObject.h"
#include "Poco/Types.h"


namespace MemoryDemo
{
	using Poco::FastMutex;
	using Poco::AutoPtr;

	class SimpleRefCounting
	{
	public:
		SimpleRefCounting(std::ostream& os):
			_rc(1),
			_os(os)
		{
			printInfo("SimpleRefCounting constructor called");
		}

		void duplicate()
		{
			FastMutex::ScopedLock lock(_rcMutex);
			++_rc;
			printInfo("SimpleRefCounting duplicate called");
		}

		void release()
		{
			printInfo("SimpleRefCounting release called (info before decrement)");
			_rcMutex.lock();
			if (--_rc == 0)
			{
				_rcMutex.unlock();
				delete this;
			}
			else
			{
				_rcMutex.unlock();
			}
		}

	private:
		int _rc;
		FastMutex _rcMutex;
		std::ostream& _os;

		virtual ~SimpleRefCounting()
		{
			printInfo("SimpleRefCounting destructor called");

		}

		void printInfo(const std::string &msg)
		{
			_os<<msg<<" object : "<<reinterpret_cast<Poco::UIntPtr>(this)<<" rc : "<<_rc<<std::endl;
		}

		SimpleRefCounting(const SimpleRefCounting &);

		SimpleRefCounting & operator = (const SimpleRefCounting &);
	};

	class TestRCClient
	{
	public:
		TestRCClient(AutoPtr<SimpleRefCounting> pRefCounting)
			: _pRefCounting(pRefCounting)
		{}

	private:
		AutoPtr<SimpleRefCounting> _pRefCounting;
	};

	void testFunction(AutoPtr<SimpleRefCounting> pRefCounting)
	{
		TestRCClient myClient(pRefCounting);

		TestRCClient myClient2 = myClient;
	}

	AutoPtr<SimpleRefCounting> testRVFunction(std::ostream &os)
	{
		return AutoPtr<SimpleRefCounting>(new SimpleRefCounting(os));
	}

	void RefCountingSample::run(std::ostream& os, std::istream& is)
	{
		os<<"AutoPtr as parameter:"<<std::endl;
		{
			AutoPtr<SimpleRefCounting> pMySimpleRefCounting(new SimpleRefCounting(os));
			testFunction(pMySimpleRefCounting);
		}
		os<<std::endl<<"AutoPtr and shared AutoPtr"<<std::endl;
		{
			SimpleRefCounting * rpSimpleRefCounting = new SimpleRefCounting(os);
			AutoPtr<SimpleRefCounting> pOwner(rpSimpleRefCounting);
			AutoPtr<SimpleRefCounting> pShared(rpSimpleRefCounting,true);
  		}
		os<<std::endl<<"AutoPtr as return value:"<<std::endl;
		{
			AutoPtr<SimpleRefCounting> pResult = testRVFunction(os);
		}
 	}

} /* namespace MemoryDemo */
