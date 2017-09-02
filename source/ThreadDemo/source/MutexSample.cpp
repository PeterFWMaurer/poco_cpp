/*
 * MutexSample.cpp
 *
 *  Created on: Sep 1, 2017
 *      Author: peter
 */

#include "ThreadDemo/MutexSample.h"

#include "Poco/Mutex.h"
#include "Poco/ScopedLock.h"
#include "Poco/StringTokenizer.h"

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

	class Name
	{
	public:
		Name(const string &name)
		{
			StringTokenizer tokenizer(name,":");
			copy(tokenizer.begin(),tokenizer.end(),std::back_inserter(_nameParts));
		}

		virtual ~Name(){}

		void append(string SubName)
		{
			Mutex::ScopedLock lock(_nameMutex);
			StringTokenizer tokenizer(SubName,":");
			copy(tokenizer.begin(),tokenizer.end(),std::back_inserter(_nameParts));
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

	void MutexSample::run(std::ostream& os, std::istream& is)
	{
		Powers myPowers(2);
		std::cout<<myPowers.getPower(5)<<std::endl;

		Name myName("Test:Name:Lang");
		os<<"test1"<<std::endl;
		myName.append("Geht:Das");
		os<<"test1"<<std::endl;
		myName.print(os);
		os<<std::endl;
	}

} /* namespace ThreadDemo */
