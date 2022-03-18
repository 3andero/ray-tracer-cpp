//
// Created by wandero on 2022-03-04.
//

#ifndef RAY_TRACER_CPP_SPHERE_H
#define RAY_TRACER_CPP_SPHERE_H

#include "../utils/point.h"
#include "hittable.h"
#include "../material/material_variant.h"
#include "../utils/enum_utils.h"

class Sphere: public Hittable<Sphere>
{
public:
	PointRT center;
	float radius;
	MaterialVariant material;

	Sphere(PointRT ct, float rd, MaterialVariant mt)
		: center(ct), radius(rd), material(mt)
	{}

	[[nodiscard]] Option<HitRecord>
	do_hit(const Ray &ray, array<float, 2> ray_len_range) const;
};

#endif //RAY_TRACER_CPP_SPHERE_H
