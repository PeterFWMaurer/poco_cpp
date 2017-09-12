/*
 * SimpleShared.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: parallels
 */

#include <iostream>

extern "C"
{
	void saySomething()
	{
		std::cout<<"something"<<std::endl;
	}
}

