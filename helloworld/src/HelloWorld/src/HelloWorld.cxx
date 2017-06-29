/*
 * HelloWorld.cxx
 *
 *  Created on: 29.01.2017
 *      Author: peter
 */

#include "HelloHelper.h"

#include <iostream>


int main()
{
	HelloHelper worldHelper("World");

	std::cout<<worldHelper.sayHello()<<std::endl;
	return 0;
}


