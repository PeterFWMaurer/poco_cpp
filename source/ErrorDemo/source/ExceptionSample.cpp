/*
 * ExceptionSample.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#include "ErrorDemo/ExceptionSample.h"

#include "Poco/Exception.h"

#include <typeinfo> // required for POCO_IMPLEMENT_EXCEPTION macro

namespace ErrorDemo
{
	using Poco::Exception;

	POCO_DECLARE_EXCEPTION(,MyException,Exception);

	POCO_IMPLEMENT_EXCEPTION(MyException,Exception,"ErrorDemo::MyException");

	POCO_DECLARE_EXCEPTION(,NestedSampleException,Exception);

	POCO_IMPLEMENT_EXCEPTION(NestedSampleException,Exception,"ErrorDemo::NestedSampleException");

	void offendingFunction(std::ostream& os)
	{
		os<<"Throwing MyException"<<std::endl;
		throw MyException("offendingFunction caused MyException");
	}

	void nestedOffendingFunction(std::ostream& os)
	{
		try
		{
			offendingFunction(os);
		}
		catch (const MyException &exp)
		{
			throw NestedSampleException("nestedOffendingFunction caugth MyException",exp);
		}
	}

	void ExceptionSample::run(std::ostream &os, std::istream &is)
	{
		try
		{
			offendingFunction(os);
		}
		catch (const MyException &exp)
		{
			os<<"exp.what(): "<<exp.what()<<std::endl;
			os<<"exp.message(): "<<exp.message()<<std::endl;
			os<<"exp.displayText(): "<<exp.displayText()<<std::endl;
		}

		try
		{
			nestedOffendingFunction(os);
		}
		catch (const NestedSampleException &exp)
		{
			os<<"exp.displayText(): "<<exp.displayText()<<std::endl;
			const Exception *pNestedException=exp.nested();
			if(pNestedException)
			{
				os<<"nested with:"<<std::endl;
				os<<"Nested displayText:"<<pNestedException->displayText()<<std::endl;
			}
		}
	}

} /* namespace ErrorDemo */
