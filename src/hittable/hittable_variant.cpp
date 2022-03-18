//
// Created by wandero on 2022-03-04.
//

#include "hittable_variant.h"

Option<HitRecord>
HittableVariant::do_hit(const Ray &ray, array<float, 2> ray_len_range) const
{
	let_mut result = None_<HitRecord>();
	std::visit(overload{
		[&result, &ray, &ray_len_range](const Sphere &s)
		{
			result = s.hit(ray, ray_len_range);
		},
		[&result, &ray, &ray_len_range](const Plane &s)
		{
			result = s.hit(ray, ray_len_range);
		}
	}, *this);
	return result;
}
