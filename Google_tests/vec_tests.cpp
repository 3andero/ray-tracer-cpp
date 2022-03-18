//
// Created by wandero on 2022-03-15.
//

#include "gtest/gtest.h"
#include "../src/utils/vec.h"
#include "../src/utils/point.h"

TEST(VecTests, Add)
{
	VectorRT v0{0.5, 1.5, 2.5};
	VectorRT v0_1{0.5, 1.5, 2.5};
	VectorRT v1{0, 1, 2};
	auto res = VectorRT{0.5, 2.5, 4.5};
	ASSERT_EQ(v0.add(v1), res);
	ASSERT_EQ(v0, v0_1);
}

TEST(VecTests, AddInplace)
{
	VectorRT v0{0.5, 1.5, 2.5};
	VectorRT v1{0, 1, 2};
	auto res = VectorRT{0.5, 2.5, 4.5};
	ASSERT_EQ(v0.add_inplace(v1), res);
	ASSERT_EQ(v0, res);
}

TEST(VecTests, AddPoint)
{
	VectorRT v0{0.5, 1.5, 2.5};
	VectorRT v0_1{0.5, 1.5, 2.5};
	PointRT v1{0, 1, 2};
	auto res = PointRT{0.5, 2.5, 4.5};
	ASSERT_EQ(v0.add(v1), res);
	ASSERT_EQ(v0, v0_1);
}

TEST(VecTests, Sub)
{
	VectorRT v0{0.5, 1.5, 2.5};
	VectorRT v1{0.5, 2.5, 4.5};
	VectorRT v1_1{0.5, 2.5, 4.5};
	VectorRT res{0, 1, 2};
	ASSERT_EQ(v1.sub(v0), res);
	ASSERT_EQ(v1, v1_1);
}

TEST(VecTests, Cross)
{
	VectorRT v0{1.1, 2.2, 3.3};
	VectorRT v0_1{1.1, 2.2, 3.3};
	VectorRT v1{4.4, 5.5, 6.6};
	VectorRT v1_1{4.4, 5.5, 6.6};

	VectorRT res{-3.63, 7.26, -3.63};
	ASSERT_EQ(v0.cross(v1), res);
	ASSERT_EQ(v0, v0_1);
	ASSERT_EQ(v1, v1_1);
}

TEST(VecTests, SubInplace)
{
	VectorRT v0{0.5, 1.5, 2.5};
	VectorRT v1{0.5, 2.5, 4.5};
	VectorRT res{0, 1, 2};
	ASSERT_EQ(v1.sub_inplace(v0), res);
	ASSERT_EQ(v1, res);
}

TEST(VecTests, NegInplace)
{
	VectorRT v0{0.5, 1.6, 2.7};

	VectorRT res{-0.5, -1.6, -2.7};
	ASSERT_EQ(v0.neg_inplace(), res);
	ASSERT_EQ(v0, res);
}

TEST(VecTests, IntoUnit)
{
	VectorRT v0{1.1, 2.2, 3.3};
	VectorRT res{0.267261, 0.534522, 0.801784};
	ASSERT_EQ(v0.into_unit(), res);
	ASSERT_EQ(v0, res);
}

TEST(VecTests, Unit)
{
	VectorRT v0{1.1, 2.2, 3.3};
	VectorRT v0_1{1.1, 2.2, 3.3};
	VectorRT res{0.267261, 0.534522, 0.801784};
	ASSERT_EQ(v0.unit(), res);
	ASSERT_EQ(v0, v0_1);
}

TEST(VecTests, Dot)
{
	VectorRT v0{0.5, 1.6, 2.7};
	VectorRT v0_1{0.5, 1.6, 2.7};
	VectorRT v1{2, 3, 4};
	VectorRT v1_1{2, 3, 4};

	VectorRT res{1, 4.8, 10.8};
	ASSERT_FLOAT_EQ(v0.dot(v1), 16.6);
	ASSERT_EQ(v0, v0_1);
	ASSERT_EQ(v1, v1_1);
}