/*
 * DynAnySample.cpp
 *
 *  Created on: Aug 25, 2017
 *      Author: peter
 */

#include "TypeDemo/DynAnySample.h"

#include "Poco/DynamicAny.h"
#include "Poco/Types.h"

namespace TypeDemo
{
	void DynAnySample::run(std::ostream &os,std::istream &is)
	{
		// Create a Dynamic any with a value of type UInt16
		Poco::DynamicAny myTestAny(Poco::Int32(42));

		// With extract, we need to know the value type stored in our DynamicAny
		Poco::Int32 val = myTestAny.extract<Poco::Int32>();

		// We show, that extract only works with exact type, otherwise, it results in Poco::BadCastException
		try
		{
			Poco::UInt32 val = myTestAny.extract<Poco::UInt32>();
		}
		catch (Poco::BadCastException &e)
		{
			std::cout<<e.displayText()<<std::endl;
		}

		// The convert function allows type conversion even to string
		std::string stringVal = myTestAny.convert<std::string>();

		std::cout<<"String Val = " <<stringVal<<std::endl;


		// The following code shows some pitfalls with DynamicAny
		// We define a dynamic any of type UInt16
		Poco::DynamicAny myUI16DynAny(Poco::UInt16(4711));
		std::cout<<"myUI16DynAny = "<<myUI16DynAny.extract<Poco::UInt16>()<<std::endl;

		// Now we use the ++ Operator
		myUI16DynAny++;

		// The ++ operator (as all arithmetic operators change the type in DynamicAny to int (Int32)
		try
		{
			std::cout<<"myUI16DynAny ="<<myUI16DynAny.extract<Poco::UInt16>()<<std::endl;
		}
		catch (Poco::BadCastException &e)
		{
			std::cout<<e.displayText()<<std::endl;
		}

		if (myUI16DynAny.type() == typeid(int))
		{
			std::cout<<"After Incrmement: myUI16DynAny ="<<myUI16DynAny.extract<int>()<<std::endl;
		}

	}
}


