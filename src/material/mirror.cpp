//
// Created by wandero on 2022-03-17.
//

#include "mirror.h"
#include "../hittable/hittable.h"

Option<std::tuple<Vec3, Ray>>
Mirror::do_scatter(const HitRecord &h, const Ray &ray_in) const
{
	let normal = h.normal.unwrap();
	let reflect = Mirror::reflect(normal, ray_in.dir).add(Mirror::fuzz(fuzz_));
	let ray_out = Ray{h.hit_point, reflect};
	return Some_(tuple{attenuation, ray_out});
}

