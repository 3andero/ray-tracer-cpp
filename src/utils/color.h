//
// Created by wandero on 2022-03-02.
//

#ifndef RAY_TRACER_CPP_COLOR_H
#define RAY_TRACER_CPP_COLOR_H

#include "vec3.h"

class Color: public Vec3Wrapper<Color>
{
public:
	using Vec3Wrapper::Vec3Wrapper;
};

#endif //RAY_TRACER_CPP_COLOR_H
