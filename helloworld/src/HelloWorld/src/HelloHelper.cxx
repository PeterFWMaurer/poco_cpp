/*
 * HelloHelper.cpp
 *
 *  Created on: Jun 28, 2017
 *      Author: peter
 */

#include "HelloHelper.h"

HelloHelper::HelloHelper(string name):
	_name(name)
{}

HelloHelper::~HelloHelper() {
	// TODO Auto-generated destructor stub
}

string HelloHelper::sayHello()
{
	string response = "Hello, ";
	response.append(_name);
	response.append("!");
	return response;
}
