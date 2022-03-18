//
// Created by wandero on 2022-03-17.
//

#include "rand_utils.h"

float
random_float()
{
	static std::random_device rd;
	static std::mt19937 e2(rd());
	static std::uniform_real_distribution<float>
		dist(-1., 1.);
	return dist(e2);
}

Vec3
random_unit_vec()
{
	let x = random_float();
	let y = random_float() * sqrtf((float)1. - x * x);
	float z = sqrtf((float)1. - x * x - y * y);
	if (random_float() < 0.) {
		z = -z;
	}
	return {x, y, z};
}