/*
 * PoolSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Poco::MemoryPool
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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

	// Die Klasse SampleManagedObject ist ein Beispiel für ein Objekt, dass einen MemoryPool benutzt,
	// wenn Objekte mit new angefordert werden.
	class SampleManagedObject
	{
	public:
		SampleManagedObject()
		{}

		virtual ~SampleManagedObject()
		{}

		// Der new-Operator bezieht seinen Speicher aus einem Memorypool
		void * operator new(size_t size)
		{
			poco_assert(size==sizeof(SampleManagedObject));
			std::cout<<"New called"<<std::endl;
			return _pool.get();
		}

		// Der delet-Operator gibt den Platz im Pool wieder frei
		void operator delete(void *pAlloc)
		{
			std::cout<<"Delete called"<<std::endl;
			_pool.release(pAlloc);
		}

		// Wie viele Elemente vom Pool sind angefordert?
		static int allocated()
		{
			return _pool.allocated();
		}

		// Wie viele Elemente sind im Pool frei?
		static int available()
		{
			return _pool.available();
		}

		// Hilfsfunktion zur Ausgabe der Situation auf dem MemoryPool
		static void printPoolInfo(std::ostream& os)
		{
			os<<"MyManagedObject::_pool : "<<available()<<" Blocks available, "<<allocated()<<" Blocks allocated"<<std::endl;
		}


	private:
		// Der für die Klasse verwendete Pool wird als statisches Member angelegt
		static MemoryPool _pool;
		int _someMemory[20];
	};

	// Der Pool wird beim Start des Programms erzeugt, hier mit fester länge
	MemoryPool SampleManagedObject::_pool(sizeof(SampleManagedObject),10,10);

	void PoolSample::run(std::ostream& os, std::istream& is)
	{
		// Zunächst erzeugen wir eines unserer Objekte un geben es anschließend wieder frei, um das Konzept zu zeigen
		SampleManagedObject::printPoolInfo(os);
		SampleManagedObject *pObject = new SampleManagedObject();
		os<<"SampleManagedObject created"<<std::endl;
		SampleManagedObject::printPoolInfo(os);
		os<<"SampleManagedObject created"<<std::endl;
		delete pObject;

		SampleManagedObject::printPoolInfo(os);
		// Jetzt versuchen wir 11 Objekte zu erzeugen, eines mehr als Platz ist
		// Dies erfolgt in einem Scope, damit die shared pointer anschließend wieder freigegeben
		// werden.
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

		// Jetzt sollte unser Pool wieder leer sein.
		os<<"After leaving scope for our vector:"<<std::endl;
		SampleManagedObject::printPoolInfo(os);
	}
}
