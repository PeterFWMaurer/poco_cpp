/*
 * TestClass_test.cpp
 *
 *  Created on: Jun 28, 2017
 *      Author: peter
 */

#include "TestClass.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace test;

class TestClassFixture: public ::testing::Test {
public:

	TestClassFixture() {
	}

	virtual ~TestClassFixture() {
	}

	void SetUp() {
	}

	void TearDown() {
	}
};

TEST_F(TestClassFixture,TestClass) {
	// TODO Implement meaningful tests
	FAIL();
}
