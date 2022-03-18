//
// Created by wandero on 2022-03-02.
//

#ifndef RAY_TRACER_CPP_VEC_H
#define RAY_TRACER_CPP_VEC_H

#include "vec3.h"
#include <iostream>

class PointRT;

class VectorRT: public Vec3Wrapper<VectorRT>
{
public:
	using Vec3Wrapper::Vec3Wrapper;

	[[nodiscard]] VectorRT
	add(const VectorRT &o) const
	{
		return VectorRT{inner.add(o.inner)};
	}

	VectorRT &
	add_inplace(const VectorRT &o)
	{
		inner.add_inplace(o.inner);
		return *this;
	}

	[[nodiscard]] PointRT
	add(const PointRT &o) const;

	[[nodiscard]] VectorRT
	sub(const VectorRT &o) const
	{
		return VectorRT{inner.sub(o.inner)};
	}

	[[nodiscard]] VectorRT
	cross(const VectorRT &o) const
	{
		return VectorRT{inner.cross(o.inner)};
	}

	VectorRT &
	sub_inplace(const VectorRT &o)
	{
		inner.sub_inplace(o.inner);
		return *this;
	}

	VectorRT &
	neg_inplace()
	{
		inner.neg_inplace();
		return *this;
	}

	[[nodiscard]] VectorRT
	neg() const
	{
		auto newVec = inner;
		newVec.neg_inplace();
		return VectorRT{newVec};
	}

	VectorRT &
	into_unit()
	{
		inner.into_unit();
		return *this;
	}

	[[nodiscard]] VectorRT
	unit() const
	{
		return VectorRT{inner.unit()};
	}

	[[nodiscard]] float
	dot(const VectorRT &o) const
	{
		return inner.dot(o.inner);
	}
};


#endif //RAY_TRACER_CPP_VEC_H
