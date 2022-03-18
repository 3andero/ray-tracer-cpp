//
// Created by wandero on 2022-03-05.
//

#include "material_variant.h"

[[nodiscard]] Option<std::tuple<Vec3, Ray>>
MaterialVariant::do_scatter(const HitRecord &h, const Ray &ray_in) const
{
	let_mut res = None_<std::tuple<Vec3, Ray>>();
	std::visit(overload{
		[&](const Lambertian &l)
		{
			res = l.scatter(h, ray_in);
		},
		[&](const Mirror &l)
		{
			res = l.scatter(h, ray_in);
		},
		[&](const Refraction &l)
		{
			res = l.scatter(h, ray_in);
		},
	}, *this);
	return res;
}
