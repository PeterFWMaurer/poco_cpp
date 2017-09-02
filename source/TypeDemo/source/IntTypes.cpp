/*
 * IntTypes.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: peter
 */

#include "TypeDemo/IntTypes.h"

#include "Poco/Types.h"

namespace TypeDemo
{
	void IntTypes::run(std::ostream &os,std::istream &is)
	{
#		if defined(POCO_PTR_IS_64_BIT)
			os<<"Pointers are 64 bits wide"<<std::endl;
#		else
			os<<"Pointers are 32 bits wide"<<std::endl;
#		endif
#		if defined(POCO_LONG_IS_64_BIT)
			os<<"Type long is 64 Bits wide"<<std::endl;
#		else
			os<<"Type lomh os 32 bits wide"<<std::endl;
#		endif

		Poco::UInt32 testVar = 42;
		Poco::UIntPtr testVarUAddr = reinterpret_cast<Poco::UIntPtr>(&testVar);
		Poco::IntPtr testVarSAddr = reinterpret_cast<Poco::IntPtr>(&testVar);
		os<<"Unsigned address of testVar: "<<testVarUAddr<<std::endl;
		os<<"Signed address of testVar: "<<testVarSAddr<<std::endl;
	}
}

