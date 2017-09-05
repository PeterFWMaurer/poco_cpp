/*
 * AssertionSample.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#include "ErrorDemo/AssertionSample.h"

#include "Poco/Exception.h"

namespace ErrorDemo
{
	using Poco::Exception;

	void AssertionSample::run(std::ostream& os, std::istream& is)
	{
#		ifdef _DEBUG
		os<<"Running debug version"<<std::endl;
#		else
		os<<"Runnung release version"<<std::endl;
#		endif
		try
		{
			poco_assert_dbg(false);
			os<<"This line is reached only in release build"<<std::endl;
			poco_assert(false);
		}
		catch (const Exception &exp)
		{
			os<<exp.displayText()<<std::endl;
		}

		try
		{
			void *p1=&p1;
			void *p2=0;
			poco_check_ptr(p1);
			os<<"p1 is a valid pointer"<<std::endl;
			poco_check_ptr(p2);
		}
		catch (const Exception &exp)
		{
			os<<exp.displayText()<<std::endl;
		}

		try
		{
			poco_bugcheck();
		//	poco_bugcheck_msg("My bugcheck message");
		}
		catch (const Exception &exp)
		{
			os<<exp.displayText()<<std::endl;
		}


	}

} /* namespace ErrorDemo */
