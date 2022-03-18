//
// Created by wandero on 2022-03-15.
//

#include "gtest/gtest.h"
#include "../src/utils/point.h"

TEST(PointTests, Add)
{
	PointRT v0{0.5, 1.5, 2.5};
	VectorRT v1{0, 1, 2};
	auto res = PointRT{0.5, 2.5, 4.5};
	ASSERT_EQ(v0.add(v1), res);
}

TEST(PointTests, AddInplace)
{
	PointRT v0{0.5, 1.5, 2.5};
	VectorRT v1{0, 1, 2};
	auto res = PointRT{0.5, 2.5, 4.5};
	ASSERT_EQ(v0.add_inplace(v1), res);
	ASSERT_EQ(v0, res);
}

TEST(PointTests, SubPoint)
{
	PointRT v0{0.5, 1.5, 2.5};
	PointRT v0_1{0.5, 1.5, 2.5};
	auto v1 = PointRT{0.5, 2.5, 4.5};
	VectorRT res{0, 1, 2};
	ASSERT_EQ(v1.sub(v0), res);
	ASSERT_EQ(v0, v0_1);
}

TEST(PointTests, SubVector)
{
	VectorRT v0{0.5, 1.5, 2.5};
	PointRT v1{0.5, 2.5, 4.5};
	PointRT v1_1{0.5, 2.5, 4.5};
	PointRT res{0, 1, 2};
	ASSERT_EQ(v1.sub(v0), res);
	ASSERT_EQ(v1, v1_1);
}

TEST(PointTests, SubInplace)
{
	VectorRT v0{0.5, 1.5, 2.5};
	PointRT v1{0.5, 2.5, 4.5};
	PointRT res{0, 1, 2};
	ASSERT_EQ(v1.sub_inplace(v0), res);
	ASSERT_EQ(v1, res);
}