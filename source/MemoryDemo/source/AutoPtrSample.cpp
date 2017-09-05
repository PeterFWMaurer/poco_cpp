/*
 * AutoPtrSample.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#include "MemoryDemo/AutoPtrSample.h"

#include "Poco/AutoPtr.h"
#include "Poco/RefCountedObject.h"

namespace MemoryDemo
{
	using Poco::AutoPtr;
	using Poco::RefCountedObject;

	class BaseRCObj : public RefCountedObject
	{
	public:
		typedef AutoPtr<BaseRCObj> Ptr;

		BaseRCObj(std::ostream& os):
			_os(os)
		{}

		virtual ~BaseRCObj(){}

		virtual void doSmt()=0;

	protected:
		std::ostream& _os;
	};

	class RCObjTypeA : public BaseRCObj
	{
	public:
		typedef AutoPtr<RCObjTypeA> Ptr;

		RCObjTypeA(std::ostream& os):
			BaseRCObj(os)
		{}

		virtual ~RCObjTypeA(){}

		void doSmt()
		{
			_os<<"RCObjTypeA::doSmt() called"<<std::endl;
		}
	};

	class RCObjTypeB : public BaseRCObj
	{
	public:
		typedef AutoPtr<RCObjTypeB> Ptr;

		RCObjTypeB(std::ostream& os):
			BaseRCObj(os)
		{}

		virtual ~RCObjTypeB(){}

		void doSmt()
		{
			_os<<"RCObjTypeB::doSmt() called"<<std::endl;
		}
	};


	void AutoPtrSample::run(std::ostream& os, std::istream& is)
	{
		BaseRCObj::Ptr pObj1(new RCObjTypeA(os));
		BaseRCObj::Ptr pObj2(new RCObjTypeB(os));

		RCObjTypeA::Ptr pA;
		pA = pObj2.cast<RCObjTypeA>();
		if (!pA)
		{
			std::cout<<"Casting TypeB to TypeA failed as expected"<<std::endl;
			pA = pObj1.cast<RCObjTypeA>();
			pA->doSmt();
		}



	}

} /* namespace MemoryDemo */
