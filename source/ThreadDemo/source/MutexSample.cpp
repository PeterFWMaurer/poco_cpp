/*
 * MutexSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel, das die Verwendung von Poco::Mutex illustriert.
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "ThreadDemo/MutexSample.h"

#include "Poco/Mutex.h"
#include "Poco/ScopedLock.h"
#include "Poco/StringTokenizer.h"
#include "Poco/Timespan.h"
#include "Poco/Timestamp.h"

#include <algorithm>
#include <iterator>
#include <string>
#include <vector>


namespace ThreadDemo
{

	using Poco::FastMutex;
	using Poco::Mutex;
	using Poco::ScopedLock;
	using Poco::StringTokenizer;
	using Poco::Timespan;
	using Poco::Timestamp;
	using std::copy;
	using std::string;
	using std::vector;

	// Die folgende Klasse wir durch einen FastMutex geschuetzt. Er ist in diesem Fall ausreichend,
	// da ein rekursiver Aufruf de lock Funktion ausgeschlossen ist.
	// Zweck der Klasse ist es, die n-te Potenz eines Wertes zu berechnen und falls dies fuer eine
	// andere Potenz schon erfolgt ist, einmal berechnete Werte wiederzuverwenden.
	//
	class Powers
	{
	public:
		Powers(int base):
			_base(base),
			_maxPower(1)
		{
			_powers.push_back(1);
			_powers.push_back(_base);
		}

		int getPower(int power)
		{
			// Mutex immer über ScopedLock verwenden...
			FastMutex::ScopedLock lock(_powersMutex);
			if (power>_maxPower)
			{
				for (;_maxPower<power;_maxPower++)
				{
					_powers.push_back(_powers.at(_maxPower)*_base);
				}
			}
			return _powers.at(_maxPower);
		}



		virtual ~Powers(){}

	private:
		int _base;
		int _maxPower;
		vector<int> _powers;

		Poco::FastMutex _powersMutex;
	};

	// Die Klasse Name wird durch einen Mutex geschützt, da hier ein rkursiver Zugriff
	// auf den Mutex erfolgen kann, der bei einem FastMutex zu einem Deadlock führen würde
	class Name
	{
	public:
		Name(const string &name)
		{
			StringTokenizer tokenizer(name,":");
			copy(tokenizer.begin(),tokenizer.end(),std::back_inserter(_nameParts));
		}

		virtual ~Name(){}

		void append(string subName)
		{
			Mutex::ScopedLock lock(_nameMutex);
			StringTokenizer tokenizer(subName,":");
			copy(tokenizer.begin(),tokenizer.end(),std::back_inserter(_nameParts));
		}

		void replace(string subName)
		{
			Mutex::ScopedLock lock(_nameMutex);
			_nameParts.clear();
			append(subName);
		}

		void print(std::ostream& os)
		{
			Mutex::ScopedLock lock(_nameMutex);
			std::ostream_iterator<string> osit(os,":");
			copy(_nameParts.begin(),_nameParts.end(),osit);
		}
	private:
		vector<string> _nameParts;
		Mutex _nameMutex;
	};

	// Das Folgende Template dient dem Geschwindigkeitsvergleich zwischen Mutex und FastMutex.
	// Deshalb kan der tatsächlich verwendete Mutex als Template-Argument übergeben werden
	//
	template <typename MutexPolicy>
	class MutexPerformanceMeasurement
	{
	public:
		MutexPerformanceMeasurement(){}

		virtual ~MutexPerformanceMeasurement(){}

		Timespan testLockPerformance(int count)
		{
			Timestamp beforeLock;
			for (int i=0;i<count;i++)
			{
				typename MutexPolicy::ScopedLock lock(_mutex);
			}
			return Timespan(beforeLock.elapsed());
		}
	private:
		MutexPolicy _mutex;

	};

	void MutexSample::run(std::ostream& os, std::istream& is)
	{
		Powers myPowers(2);

		Name myName("Ein:Test:Name");
		myName.append("Kann:Erweitert:werden");
		myName.replace("Mein:Namens:Ersatz");
		myName.print(os);
		os<<std::endl;

		const int repeatCount = 100000;

		// Der folgende Performancetest sollte fuer Posixsysteme keinen nennenswerten
		// Unterschied zwischen Mutex und Fastmutex aufzeigen.

		MutexPerformanceMeasurement<FastMutex> fastMutexTest;
		Timespan fastMutexTime = fastMutexTest.testLockPerformance(repeatCount);
		std::cout<<"Time for "<<repeatCount<<" fast mutex locks: "<<fastMutexTime.microseconds()<<"µs"<<std::endl;

		MutexPerformanceMeasurement<Mutex> mutexTest;
		Timespan mutexTime = mutexTest.testLockPerformance(repeatCount);
		std::cout<<"Time for "<<repeatCount<<" normal mutex locks: "<<mutexTime.microseconds()<<"µs"<<std::endl;
	}

} /* namespace ThreadDemo */
