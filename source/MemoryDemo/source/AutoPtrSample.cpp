/*
 * AutoPtrSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Poco::AutoPtr
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "MemoryDemo/AutoPtrSample.h"

#include "Poco/AutoPtr.h"
#include "Poco/RefCountedObject.h"

namespace MemoryDemo
{
	using Poco::AutoPtr;
	using Poco::RefCountedObject;

	// Die Klasse BaseRCObj dient als Beispiel für ein Objekt mit Referenzzählung, das sinnvoller
	// Weise von Poco::RefCountObject abgeleitet wird. Es handelt sich um eine Abstrakte Basisklasse
	//
	class BaseRCObj : public RefCountedObject
	{
	public:
		// Es erweist sich als nützlich, den AutoPtr für ein RefCountedObject von vornherein als
		// Typ mit Namen Ptr zu deklarieren.
		typedef AutoPtr<BaseRCObj> Ptr;

		BaseRCObj(std::ostream& os):
			_os(os)
		{}

		virtual ~BaseRCObj(){}

		virtual void doSmt()=0;

	protected:
		std::ostream& _os;
	};

	// Die Klasse RCObjTypeA ist eine Spezialisierung von BaseRCObj und erbt natülcin dessen Referenzzählung
	//
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

	// Die Klasse RCObjTypeB ist eine anderer Spezialisierung von BaseRCObj
	//
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
		// Wir erzeugen Objekte der beiden von BaseRCObj abgeleiteten Klassen und speicherb sie in
		// Auto-Pointern auf die Basisklasse.
		//
		BaseRCObj::Ptr pObj1(new RCObjTypeA(os));
		BaseRCObj::Ptr pObj2(new RCObjTypeB(os));

		// Jetzt casten wir ein Objekt direkt mit dem im AutoPtr eingebauten Downcast.
		RCObjTypeA::Ptr pA = pObj2.cast<RCObjTypeA>();
		if (!pA)
		{
			std::cout<<"Casting TypeB to TypeA failed as expected"<<std::endl;
			pA = pObj1.cast<RCObjTypeA>();
			pA->doSmt();
		}
	}
} /* namespace MemoryDemo */
