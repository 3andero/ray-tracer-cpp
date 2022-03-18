//
// Created by wandero on 2022-03-02.
//

#ifndef RAY_TRACER_CPP_RAY_H
#define RAY_TRACER_CPP_RAY_H

#include "utils/vec3.h"
#include "utils/point.h"
#include "utils/vec.h"

class Ray
{
public:
	PointRT start;
	VectorRT dir;

	Ray(PointRT p1, PointRT p2)
		: dir(p2.sub(p1)), start(p1)
	{
		dir.into_unit();
	}

	Ray(PointRT p1, VectorRT dir)
		: dir(dir.into_unit()), start(p1)
	{
	}

	[[nodiscard]] PointRT
	at(float x) const
	{
		return start.add(dir.mul(x));
	}

};

#endif //RAY_TRACER_CPP_RAY_H
