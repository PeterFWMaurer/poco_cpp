/*
 * RefCountingSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel für ein von Hand implementiertes Objekt mit Referenzzählung
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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

	// SimpleRefCounting implementiert ein Objekt, dass die Referenzen auf sich zählt und sich selbst löscht,
	// wenn es nicht mehr benötigt wird.
	class SimpleRefCounting
	{
	public:
		// Beim Erzeugen wird der Referrenzzähler auf 1 gesetzt.
		SimpleRefCounting(std::ostream& os):
			_rc(1),
			_os(os)
		{
			printInfo("SimpleRefCounting constructor called");
		}

		// Die Methode duplicate() wird aufgerufen, wenn ein neuer Smartpointer auf das Objekt erzeugt wird.
		//
		void duplicate()
		{
			FastMutex::ScopedLock lock(_rcMutex);
			++_rc;
			printInfo("SimpleRefCounting duplicate called");
		}

		// Die Methode release() wird aufgerufen, wenn ein Smartpointer gelöscht wird, also keine Referenz mehr
		// auf das Objekt benötigt
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

		// Der private Destruktor verhindert, dass das Objekt auf dem Stack angelegt wird
		//
		virtual ~SimpleRefCounting()
		{
			printInfo("SimpleRefCounting destructor called");
		}

		// Hildsmethode zur Ausgabe der Adresse und des Referenzzählers
		void printInfo(const std::string &msg)
		{
			_os<<msg<<" object : "<<reinterpret_cast<Poco::UIntPtr>(this)<<" rc : "<<_rc<<std::endl;
		}

		// Copykonstruktor und Assignmentoperator werden privat angelegt, um versehentliches Kopieren
		// des Objekts zu verhindern.
		//
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
