/*
 * HelloWorld.cxx
 *
 *  Created on: 29.01.2017
 *      Author: peter
 */

#include "HelloHelper.h"

#include <vector>
#include <memory>
#include <iostream>

int main()
{
	std::shared_ptr<HelloHelper> worldHelper(new HelloHelper("World"));

	std::cout<<worldHelper->sayHello()<<std::endl;
	return 0;
}


