//
// Created by wandero on 2022-03-04.
//

#ifndef RAY_TRACER_CPP_HITTABLE_VARIANT_H
#define RAY_TRACER_CPP_HITTABLE_VARIANT_H

#include <variant>
#include <array>
#include "sphere.h"
#include "plane.h"

class HittableVariant: public std::variant<Sphere, Plane>, public Hittable<HittableVariant>
{
public:
	[[nodiscard]] Option<HitRecord>
	do_hit(const Ray &ray, array<float, 2> ray_len_range) const;
};

#endif //RAY_TRACER_CPP_HITTABLE_VARIANT_H
