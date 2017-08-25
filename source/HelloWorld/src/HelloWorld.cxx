/*
 * HelloWorld.cxx
 *
 *  Created on: 29.01.2017
 *      Author: peter
 */

#include "HelloHelper.h"

#include <Poco/ByteOrder.h>
#include <Poco/Types.h>
#include <vector>
#include <memory>
#include <iostream>

int main()
{

	Poco::UInt16 myTestNumber;
	Poco::Int64 myTestNumber64;
	std::shared_ptr<HelloHelper> worldHelper(new HelloHelper("World"));

	std::cout<<worldHelper->sayHello()<<std::endl;
	return 0;
}


