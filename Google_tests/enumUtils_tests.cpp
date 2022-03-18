//
// Created by wandero on 2022-03-16.
//

#include "gtest/gtest.h"
#include "../src/utils/enum_utils.h"

TEST(EnumUtils, Option)
{
	auto x = Some_<int>(123);
	ASSERT_TRUE(x.is_some());
	ASSERT_EQ(x.unwrap(), 123);
	auto y = None_<int>();
	ASSERT_TRUE(y.is_none());
}