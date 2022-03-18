//
// Created by wandero on 2022-03-15.
//

#include "vec3.h"

std::ostream &
operator<<(std::ostream &os, Vec3 const &m)
{
	return os << m[0] << " " << m[1] << " " << m[2] << " ";
}

bool
areEqualRel(float a, float b, float epsilon)
{
	return (fabs(a - b) <= epsilon * std::max(fabs(a), fabs(b)));
}
