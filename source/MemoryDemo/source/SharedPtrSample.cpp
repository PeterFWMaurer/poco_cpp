/*
 * SharedPtrSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Poco::SharedPtr
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "MemoryDemo/SharedPtrSample.h"

#include "Poco/SharedPtr.h"

#include <algorithm>
#include <iterator>

namespace MemoryDemo
{
	using Poco::SharedPtr;
	using Poco::ReleaseArrayPolicy;
	using Poco::ReferenceCounter;

	// Beispiel für eine Basisklasse, erbt nicht von Poco::RefCountedObject
	class BaseSmp
	{
	public:
		// Auch bei Sharedpointeren empfiehlt es sich, den Typ für den Sharedpointer gleich
		// mitzudefinieren.
		typedef SharedPtr<BaseSmp> Ptr;

		BaseSmp(){}
		virtual ~BaseSmp(){}
	};

	// Abgeleitete Beispielklasse
	class InhSmp : public BaseSmp
	{
	public:
		typedef SharedPtr<InhSmp> Ptr;

		InhSmp(){}

		virtual ~InhSmp(){}
	};


	void SharedPtrSample::run(std::ostream& os, std::istream &is)
	{
		// Wir erzeugen einen SharedPtr auf die Basisklasse und einen auf die abgeleitete Klasse
		// beide sind vom Sharedpointertyp der Basisklasse.
		BaseSmp::Ptr pBase1(new BaseSmp);
		BaseSmp::Ptr pBase2(new InhSmp);

		// Wir versuchen den Zeiger auf das Objekt der Basisklasse auf den spezialisierten Zeigertyp zu casten
		InhSmp::Ptr pInh=pBase1.cast<InhSmp>();
		if (!pInh)
		{
			// Das geht natürlich schief...
			std::cout<<"Cast fails as expected"<<std::endl;

			// ...und wir führen den korrekten Downcast durch.
			pInh=pBase2.cast<InhSmp>();
			if (pInh)
			{
				std::cout<<"Correct cast worked as expected"<<std::endl;
			}
		}

		// Jetzt erzeugen wir einen SharedPtr auf ein Array. Dabei ist zu beachten, dass eine entsprechende
		// Releasepolicy mitgegeben wird, da sonst der falsche delete-Operator im Destruktor verwendet wird.
		const int INT_ARRAY_LEN=10;
		SharedPtr<int,ReferenceCounter,ReleaseArrayPolicy<int>> pIntArray(new int[INT_ARRAY_LEN]);
		for (int i=0; i<INT_ARRAY_LEN; i++)
		{
			pIntArray[i]=i;
		}
		// Der folgende Code ist auskommentiert, weil er Zeigt, was passiert, wenn zwei SharedPtr auf
		// denselben Rawpointer erzeugt werden.
		//
		// int * rpI=new int(42);
		// SharedPtr<int>pI1(rpI);
		// SharedPtr<int>pI2(rpI); // ERROR!!!! Never assign the same raw pointer to two SharedPtr
	}

} /* namespace MemoryDemo */
