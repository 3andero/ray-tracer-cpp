//
// Created by wandero on 2022-03-15.
//

#include "gtest/gtest.h"
#include "../src/utils/rand_utils.h"

TEST(PointTests, RandTest)
{
	for (int i = 0; i < 10000000; ++i) {
		auto res = random_float();
		ASSERT_TRUE(res >= -1. && res <= 1.);
	}
}

TEST(PointTests, RandVecTest)
{
	for (int i = 0; i < 10000000; ++i) {
		auto res = random_unit_vec();
		ASSERT_FLOAT_EQ(res.length(), 1.f);
	}
}