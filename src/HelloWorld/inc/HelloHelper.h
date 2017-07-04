/*
 * HelloHelper.h
 *
 *  Created on: Jun 28, 2017
 *      Author: peter
 */

#ifndef SRC_HELLOWORLD_SRC_HELLOHELPER_H_
#define SRC_HELLOWORLD_SRC_HELLOHELPER_H_

#include <memory>
#include <string>

using std::shared_ptr;
using std::string;

class HelloHelper {
public:
	typedef shared_ptr<HelloHelper> Ptr;

	/* Default constructor */
	HelloHelper(string name);

	/* Destuctor */
	virtual ~HelloHelper();

	string sayHello();

private:
	string _name;
};

#endif /* SRC_HELLOWORLD_SRC_HELLOHELPER_H_ */
