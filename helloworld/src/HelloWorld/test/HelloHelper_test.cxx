/*
 * HelloHelper_test.cxx
 *
 *  Created on: Jun 28, 2017
 *      Author: peter
 */

#include "HelloHelper.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class HelloHelperFixture: public ::testing::Test
{
public:
	HelloHelperFixture(){}

	virtual ~HelloHelperFixture(){}

	void SetUp(){}

	void TearDown(){}

};

TEST_F(HelloHelperFixture,sayHello)
{
	HelloHelper testHelper("Otto");
	string helloString=testHelper.sayHello();
	ASSERT_STREQ("Hello, Otto!",helloString.c_str());
}



