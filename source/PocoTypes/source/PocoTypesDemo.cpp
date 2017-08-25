/*
 * IntegerTypes.cpp
 *
 *  Created on: Aug 17, 2017
 *      Author: peter
 */

#include "PocoTypesDemo.h"

#include "Poco/Types.h"
#include "Poco/Any.h"
#include "Poco/DynamicAny.h"
#include "Poco/String.h"
#include "Poco/UTF8String.h"
#include "Poco/TextConverter.h"
#include "Poco/ASCIIEncoding.h"
#include "Poco/UTF8Encoding.h"
#include "Poco/Latin1Encoding.h"
#include <iostream>
#include <string>

void showTypes ()
{
#	if defined(POCO_PTR_IS_64_BIT)
	std::cout<<"Pointers are 64 bits wide"<<std::endl;
#	else
	std::cout<<"Pointers are 32 bits wide"<<std::endl;
#	endif
#	if defined(POCO_LONG_IS_64_BIT)
	std::cout<<"Type long is 64 Bits wide"<<std::endl;
#	else
	std::cout<<"Type lomh os 32 bits wide"<<std::endl;
#	endif

	Poco::UInt32 testVar = 42;
	Poco::UIntPtr testVarUAddr = reinterpret_cast<Poco::UIntPtr>(&testVar);
	Poco::IntPtr testVarSAddr = reinterpret_cast<Poco::IntPtr>(&testVar);
	std::cout<<"Unsigned address of testVar: "<<testVarUAddr<<std::endl;
	std::cout<<"Signed address of testVar: "<<testVarSAddr<<std::endl;
}

void showAny()
{
	// Create an any with an UInt16 Value
	Poco::Any myUInt16Any(Poco::UInt16(42));

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
	Poco::Any mySecondAny(myUInt16Any);
	ri += 47;
	std::cout<<"myUInt16Any = "<<Poco::AnyCast<Poco::UInt16>(myUInt16Any)<<std::endl;
	std::cout<<"mySecondAny = "<<Poco::AnyCast<Poco::UInt16>(mySecondAny)<<std::endl;

	// We create an any of type string and reasign mySecondAny any to it
	Poco::Any myStringAny(std::string("Hello Any"));

	// We assiegnt mySecondAny to myStringAny to illustrate reassignment
	mySecondAny = myStringAny;

	// We can check, if mySecondAny contains a string and write its value to the output:
	if (mySecondAny.type() == typeid(std::string))
	{
		std::cout<<"mySecondAny = "<<Poco::AnyCast<std::string>(mySecondAny)<<std::endl;
	}

	// We can also create an empty any ...
	Poco::Any myEmptyAny;

	// ...and check if it is empy
	if (myEmptyAny.empty())
	{
		std::cout<<"myEmptyAny is empty"<<std::endl;
	}

}

void showDynamicAny()
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

void showString()
{
	std::string myWords="                In the beginning was the word     ";
	std::cout<<Poco::trimLeft(myWords)<<"."<<std::endl;
	std::cout<<Poco::trimRight(myWords)<<"."<<std::endl;
	std::cout<<Poco::trimInPlace(myWords)<<"."<<std::endl;

	std::string russianString="был вначале словом";
	std::cout<<russianString<<std::endl;
	std::cout<<Poco::UTF8::toUpper(russianString)<<std::endl;

	russianString = Poco::cat(russianString,std::string(","),std::string("и Слово было у Бога"));
	std::cout<<russianString<<std::endl;

	Poco::UTF8Encoding utf8enc;
	Poco::ASCIIEncoding asciiEnc;
	Poco::TextConverter myConverter(utf8enc,asciiEnc);

	std::string asciiResult;
	myConverter.convert(russianString,asciiResult);

	std::cout<<"ASCII: "<<asciiResult<<std::endl;

	// Clean the string in ASCII-Result
	asciiResult.erase();

	std::string germanWords="Übel wäre es, wenn der Bär den Würger fräße.";
	myConverter.convert(germanWords,asciiResult);

	std::cout<<"UTF8:  "<<germanWords<<std::endl;
	std::cout<<"ASCII: "<<asciiResult<<std::endl;

}

int main(int argc, char *argv[])
{
	showTypes();
	showAny();
	showDynamicAny();
	showString();
	return 0;
}



