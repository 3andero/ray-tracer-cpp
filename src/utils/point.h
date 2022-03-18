//
// Created by wandero on 2022-03-02.
//

#ifndef RAY_TRACER_CPP_POINT_H
#define RAY_TRACER_CPP_POINT_H

#include "vec3.h"
#include "vec.h"

class PointRT: public Vec3Wrapper<PointRT>
{
public:
	using Vec3Wrapper::Vec3Wrapper;

	[[nodiscard]] PointRT
	add(const VectorRT &dir) const
	{
		return PointRT{inner.add(dir.as_vec3())};
	}

	PointRT &
	add_inplace(const VectorRT &dir)
	{
		inner.add_inplace(dir.as_vec3());
		return *this;
	}

	[[nodiscard]] VectorRT
	sub(const PointRT &o) const
	{
		return VectorRT{inner.sub(o.inner)};
	}

	[[nodiscard]] PointRT
	sub(const VectorRT &o) const
	{
		return PointRT{inner.sub(o.as_vec3())};
	}

	PointRT &
	sub_inplace(const VectorRT &o)
	{
		inner.sub_inplace(o.as_vec3());
		return *this;
	}
};

#endif //RAY_TRACER_CPP_POINT_H
