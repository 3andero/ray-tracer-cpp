//
// Created by wandero on 2022-03-04.
//

#ifndef RAY_TRACER_CPP_HITTABLE_VARIANT_H
#define RAY_TRACER_CPP_HITTABLE_VARIANT_H

#include <array>
#include "sphere.h"
#include "plane.h"

class HittableVariant: public Hittable<HittableVariant>
{
public:
	enum class Var
	{
		Sphere,
		Plane,
	};

	explicit HittableVariant(Sphere d)
		: tag_(Var::Sphere), data(Data{ .sphere{d}})
	{
	}

	explicit HittableVariant(Plane d)
		: tag_(Var::Plane), data(Data{ .plane{d}})
	{
	}

	[[nodiscard]] Option<HitRecord>
	do_hit(const Ray &ray, array<float, 2> ray_len_range) const;

private:
	union Data
	{
		Sphere sphere;
		Plane plane;
	};
	Var tag_;
	Data data;
};

#endif //RAY_TRACER_CPP_HITTABLE_VARIANT_H
