//
// Created by wandero on 2022-03-17.
//

#include "refraction.h"
#include "../hittable/hittable.h"
#include <algorithm>

Option<std::tuple<Vec3, Ray>>
Refraction::do_scatter(const HitRecord &h, const Ray &ray_in) const
{
	let normal = h.normal.unwrap();
	let cosO = std::min(-normal.dot(ray_in.dir), 1.f);
	let eta = h.normal.is_inside() ? eta_ : 1.f / eta_;
	let sinO1_2 = eta * eta * (1.f - cosO * cosO);

	VectorRT out{0., 0., 0.};
	if (sinO1_2 > 1. || Refraction::reflectance(cosO, eta) > (random_float() + 1.f) / 2) {
		out = Mirror::reflect(normal, ray_in.dir);
	}
	else {
		let_mut rad1 = normal.neg();
		let_mut rad2 = (ray_in.dir.add(normal.mul(cosO))).into_unit();
		let tanO1 = std::sqrtf((sinO1_2 / (1.f - sinO1_2)));
		out = rad1.add_inplace(rad2.mul_inplace(tanO1));
	}

	let out_ray = Ray{h.hit_point, out};
	return Some_(tuple(attenuation, out_ray));
}
