/*
 * PoolSample.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: peter
 */

#include "MemoryDemo/PoolSample.h"

#include "Poco/MemoryPool.h"
#include "Poco/SharedPtr.h"

#include <vector>

namespace MemoryDemo
{

	using Poco::MemoryPool;
	using Poco::SharedPtr;
	using std::vector;

	class SampleManagedObject
	{
	public:
		SampleManagedObject()
		{}

		virtual ~SampleManagedObject()
		{}

		void * operator new(size_t size)
		{
			poco_assert(size==sizeof(SampleManagedObject));
			std::cout<<"New called"<<std::endl;
			return _pool.get();
		}

		void operator delete(void *pAlloc)
		{
			std::cout<<"Delete called"<<std::endl;
			_pool.release(pAlloc);
		}

		static int allocated()
		{
			return _pool.allocated();
		}

		static int available()
		{
			return _pool.available();
		}

		static void printPoolInfo(std::ostream& os)
		{
			os<<"MyManagedObject::_pool : "<<available()<<" Blocks available, "<<allocated()<<" Blocks allocated"<<std::endl;
		}


	private:
		static MemoryPool _pool;
		int _someMemory[20];
	};

	MemoryPool SampleManagedObject::_pool(sizeof(SampleManagedObject),10,10);

	void PoolSample::run(std::ostream& os, std::istream& is)
	{
		SampleManagedObject::printPoolInfo(os);
		SampleManagedObject *pObject = new SampleManagedObject();
		os<<"SampleManagedObject created"<<std::endl;
		SampleManagedObject::printPoolInfo(os);
		os<<"SampleManagedObject created"<<std::endl;
		delete pObject;
		SampleManagedObject::printPoolInfo(os);
		{
			vector<SharedPtr<SampleManagedObject>> objVec;
			for (int i=0;i<11;i++)
			{
				os<<"Trying to create a new managed object"<<std::endl;
				try
				{
					objVec.push_back(new SampleManagedObject());
					SampleManagedObject::printPoolInfo(os);
				}
				catch (const Poco::Exception &exp)
				{
					os<<"Allocation of SampleManagedObject failed:"<<std::endl;
					os<<exp.displayText()<<std::endl;
				}
			}
		}
		os<<"After leaving scope for our vector:"<<std::endl;
		SampleManagedObject::printPoolInfo(os);
	}
}
