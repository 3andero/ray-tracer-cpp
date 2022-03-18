#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by wandero on 2022-03-15.
//

#include "gtest/gtest.h"
#include "../src/utils/vec3.h"

class Vec3WrapperImpl: public Vec3Wrapper<Vec3WrapperImpl>
{
public:
	using Vec3Wrapper::Vec3Wrapper;
};

TEST(Vec3WrapperOperatioins, AsVec3)
{
	Vec3WrapperImpl v0{1.1, 2.2, 3.3};
	Vec3WrapperImpl v0_1{1.1, 2.2, 3.3};
	Vec3 res{1.1, 2.2, 3.3};
	auto v0_vec3 = v0.as_vec3();
	ASSERT_EQ(v0_vec3, res);
	v0_vec3[1] = 2;
	ASSERT_EQ(v0, v0_1);
}

TEST(Vec3WrapperOperatioins, Mul)
{
	Vec3WrapperImpl v0{1.1, 2.2, 3.3};
	Vec3WrapperImpl v0_1{1.1, 2.2, 3.3};
	Vec3WrapperImpl res{2.2, 4.4, 6.6};
	ASSERT_EQ(v0.mul(2), res);
	ASSERT_EQ(v0, v0_1);
}

TEST(Vec3WrapperOperatioins, MulInplace)
{
	Vec3WrapperImpl v0{1.1, 2.2, 3.3};
	Vec3WrapperImpl v0_1{1.1, 2.2, 3.3};
	Vec3WrapperImpl res{2.2, 4.4, 6.6};
	ASSERT_EQ(v0.mul_inplace(2), res);
	ASSERT_EQ(v0, res);
}

TEST(Vec3WrapperOperatioins, Add)
{
	Vec3WrapperImpl v0{1.1, 2.2, 3.3};
	Vec3WrapperImpl v0_1{1.1, 2.2, 3.3};
	Vec3 v1{4.1, 4.2, 6.3};
	Vec3WrapperImpl res{5.2, 6.4, 9.6};
	ASSERT_EQ(v0.add(v1), res);
	ASSERT_EQ(v0, v0_1);
}

TEST(Vec3WrapperOperatioins, AddInplace)
{
	Vec3WrapperImpl v0{1.1, 2.2, 3.3};
	Vec3WrapperImpl v0_1{1.1, 2.2, 3.3};
	Vec3 v1{4.1, 4.2, 6.3};
	Vec3WrapperImpl res{5.2, 6.4, 9.6};
	ASSERT_EQ(v0.add_inplace(v1), res);
	ASSERT_EQ(v0, res);
}

TEST(Vec3WrapperOperatioins, Index)
{
	Vec3WrapperImpl v0{1.1, 2.2, 3.3};
	ASSERT_FLOAT_EQ(v0[0], 1.1);
}

TEST(Vec3WrapperOperatioins, IndexMut)
{
	Vec3WrapperImpl v0{1.1, 2.2, 3.3};
	ASSERT_FLOAT_EQ(v0[0], 1.1);
	v0[0] += 1;
	ASSERT_FLOAT_EQ(v0[0], 2.1);
}

#pragma clang diagnostic pop