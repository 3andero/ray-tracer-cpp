#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by wandero on 2022-03-14.
//

#include "gtest/gtest.h"
#include "../src/utils/vec3.h"

TEST(Vec3Operatioins, Add)
{
	Vec3 v0{0.5, 1.5, 2.5};
	Vec3 v1{0, 1, 2};
	auto res = Vec3{0.5, 2.5, 4.5};
	ASSERT_EQ(v0.add(v1), res);
}

TEST(Vec3Operatioins, AddInplace)
{
	Vec3 v0{0.5, 1.5, 2.5};
	Vec3 v1{0, 1, 2};
	auto res = Vec3{0.5, 2.5, 4.5};
	ASSERT_EQ(v0.add_inplace(v1), res);
	ASSERT_EQ(v0, res);
	auto v1_1 = Vec3{0, 1, 2};
	ASSERT_EQ(v1, v1_1);
}

TEST(Vec3Operatioins, Indexing)
{
	Vec3 v0{0.5, 1.5, 2.5};
	ASSERT_EQ(v0[0], 0.5f);
}

TEST(Vec3Operatioins, IndexingMut)
{
	Vec3 v0{0.5, 1.5, 2.5};
	v0[0] = 1.f;
	ASSERT_EQ(v0[0], 1.f);
}

TEST(Vec3Operatioins, Sub)
{
	Vec3 v0{0.5, 1.6, 2.7};
	Vec3 v1{0, 1, 2};
	auto res = Vec3{0.5, 0.6, 0.7};
	ASSERT_EQ(v0.sub(v1), res);
}

TEST(Vec3Operatioins, SubMut)
{
	Vec3 v0{0.5, 1.6, 2.7};
	Vec3 v1{0, 1, 2};
	Vec3 v1_1{0, 1, 2};
	auto res = Vec3{0.5, 0.6, 0.7};
	ASSERT_EQ(v0.sub_inplace(v1), res);
	ASSERT_EQ(v0, res);
	ASSERT_EQ(v1, v1_1);
}

TEST(Vec3Operatioins, Mul)
{
	Vec3 v0{0.5, 1.6, 2.7};
	Vec3 v0_1{0.5, 1.6, 2.7};

	auto res = Vec3{1.f, 3.2f, 5.4f};
	ASSERT_EQ(v0.mul(2), res);
	ASSERT_EQ(v0, v0_1);
}

TEST(Vec3Operatioins, MulInplace)
{
	Vec3 v0{0.5, 1.6, 2.7};
	Vec3 v0_1{0.5, 1.6, 2.7};

	auto res = Vec3{1.f, 3.2f, 5.4f};
	ASSERT_EQ(v0.mul_inplace(2), res);
	ASSERT_EQ(v0, res);
}

TEST(Vec3Operatioins, NegInplace)
{
	Vec3 v0{0.5, 1.6, 2.7};

	auto res = Vec3{-0.5, -1.6, -2.7};
	ASSERT_EQ(v0.neg_inplace(), res);
	ASSERT_EQ(v0, res);
}

TEST(Vec3Operatioins, ElementMul)
{
	Vec3 v0{0.5, 1.6, 2.7};
	Vec3 v0_1{0.5, 1.6, 2.7};
	Vec3 v1{2, 3, 4};
	Vec3 v1_1{2, 3, 4};

	auto res = Vec3{1, 4.8, 10.8};
	ASSERT_EQ(v0.element_mul(v1), res);
	ASSERT_EQ(v0, v0_1);
	ASSERT_EQ(v1, v1_1);
}

TEST(Vec3Operatioins, ElementMulInplace)
{
	Vec3 v0{0.5, 1.6, 2.7};
	Vec3 v1{2, 3, 4};
	Vec3 v1_1{2, 3, 4};

	auto res = Vec3{1, 4.8, 10.8};
	ASSERT_EQ(v0.element_mul_inplace(v1), res);
	ASSERT_EQ(v0, res);
	ASSERT_EQ(v1, v1_1);
}

TEST(Vec3Operatioins, Dot)
{
	Vec3 v0{0.5, 1.6, 2.7};
	Vec3 v0_1{0.5, 1.6, 2.7};
	Vec3 v1{2, 3, 4};
	Vec3 v1_1{2, 3, 4};

	auto res = Vec3{1, 4.8, 10.8};
	ASSERT_FLOAT_EQ(v0.dot(v1), 16.6);
	ASSERT_EQ(v0, v0_1);
	ASSERT_EQ(v1, v1_1);
}

TEST(Vec3Operatioins, Cross)
{
	Vec3 v0{1.1, 2.2, 3.3};
	Vec3 v0_1{1.1, 2.2, 3.3};
	Vec3 v1{4.4, 5.5, 6.6};
	Vec3 v1_1{4.4, 5.5, 6.6};

	auto res = Vec3{-3.63, 7.26, -3.63};
	ASSERT_EQ(v0.cross(v1), res);
	ASSERT_EQ(v0, v0_1);
	ASSERT_EQ(v1, v1_1);
}

TEST(Vec3Operatioins, Length2)
{
	Vec3 v0{1.1, 2.2, 3.3};
	Vec3 v0_1{1.1, 2.2, 3.3};

	ASSERT_FLOAT_EQ(v0.length_squared(), 16.94);
	ASSERT_EQ(v0, v0_1);
}

TEST(Vec3Operatioins, Length)
{
	Vec3 v0{1.1, 2.2, 3.3};
	Vec3 v0_1{1.1, 2.2, 3.3};

	ASSERT_FLOAT_EQ(v0.length(), 4.1158228);
	ASSERT_EQ(v0, v0_1);
}

TEST(Vec3Operatioins, Unit)
{
	Vec3 v0{1.1, 2.2, 3.3};
	Vec3 v0_1{1.1, 2.2, 3.3};
	Vec3 res{0.267261, 0.534522, 0.801784};
	ASSERT_EQ(v0.unit(), res);
	ASSERT_EQ(v0, v0_1);
}

TEST(Vec3Operatioins, IntoUnit)
{
	Vec3 v0{1.1, 2.2, 3.3};
	Vec3 res{0.267261, 0.534522, 0.801784};
	ASSERT_EQ(v0.into_unit(), res);
	ASSERT_EQ(v0, res);
}

TEST(Vec3Operatioins, Equal)
{
	Vec3 v0{1.1, 2.2, 3.3};
	Vec3 v0_1{1.1, 2.2, 3.3};
	ASSERT_EQ(v0, v0_1);
}

#pragma clang diagnostic pop