/*
 * DemoClass_test.cpp
 *
 *  Created on: Jun 29, 2017
 *      Author: peter
 */

#include "DemoClass.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace demo;

class DemoClassFixture: public ::testing::Test {
public:
	DemoClassFixture() {
	}

	virtual ~DemoClassFixture() {
	}

	void SetUp() {
	}

	void TeadDown() {
	}
};

TEST_F(DemoClassFixture,DemoClass) {
	// TODO Add meaningful tests
	FAIL();
}

