/*
 * AnySample.cpp
 *
 *  Created on: Aug 25, 2017
 *      Author: peter
 */

#include "TypeDemo/AnySample.h"

#include "Poco/Any.h"
#include "Poco/Types.h"

namespace TypeDemo
{
	using Poco::Any;

	void AnySample::run(std::ostream &os, std::istream &is)
	{
		// Create an any with an UInt16 Value
		Any myUInt16Any(Poco::UInt16(42));

		// Referece Cast to our any to show, that the ref is really looking to its value
		Poco::UInt16 &ri = Poco::RefAnyCast<Poco::UInt16>(myUInt16Any);

		ri += 12;

		std::cout<<"ri = "<<ri<<std::endl;
		std::cout<<"myUInt16Any = "<<Poco::AnyCast<Poco::UInt16>(myUInt16Any)<<std::endl;

		// The following code shows, that Any is sensitive regarding different integer types
		try
		{
			Poco::UInt32 val32 = Poco::AnyCast<Poco::UInt32>(myUInt16Any);
		}
		catch (Poco::BadCastException &e)
		{
			std::cout<<e.displayText()<<std::endl;
		}

		// We create a second any and assign it to our first any and show the value semantics of Poco::Any
		Any mySecondAny(myUInt16Any);
		ri += 47;
		std::cout<<"myUInt16Any = "<<Poco::AnyCast<Poco::UInt16>(myUInt16Any)<<std::endl;
		std::cout<<"mySecondAny = "<<Poco::AnyCast<Poco::UInt16>(mySecondAny)<<std::endl;

		// We create an any of type string and reasign mySecondAny any to it
		Any myStringAny(std::string("Hello Any"));

		// We assiegnt mySecondAny to myStringAny to illustrate reassignment
		mySecondAny = myStringAny;

		// We can check, if mySecondAny contains a string and write its value to the output:
		if (mySecondAny.type() == typeid(std::string))
		{
			std::cout<<"mySecondAny = "<<Poco::AnyCast<std::string>(mySecondAny)<<std::endl;
		}

		// We can also create an empty any ...
		Any myEmptyAny;

		// ...and check if it is empy
		if (myEmptyAny.empty())
		{
			std::cout<<"myEmptyAny is empty"<<std::endl;
		}

	}
}



