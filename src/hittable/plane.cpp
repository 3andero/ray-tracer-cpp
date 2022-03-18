//
// Created by wandero on 2022-03-17.
//

#include "plane.h"
#include "../utils/common.h"

Option<HitRecord>
Plane::do_hit(const Ray &ray, array<float, 2> ray_len_range) const
{
	let ray_len = origin.sub(ray.start).dot(z) / z.dot(ray.dir);

	if (!in_range(ray_len, ray_len_range)) {
		return None<HitRecord>();
	}

	let hit_point = ray.at(ray_len);

	if (x_y.is_some()) {
		let[x, y] = x_y.unwrap();
		let o_hp = hit_point.sub(origin);
		let dx = o_hp.dot(x) / (x.dot(x));
		let dy = o_hp.dot(y) / (y.dot(y));
		if (!in_range(dx, array{0.f, 1.f}) || !in_range(dy, array{0.f, 1.f})) {
			return None<HitRecord>();
		}
	}
	return Some(
		HitRecord{
			ray_len,
			ray.dir.dot(z) < 0 ?
			HitPosition{HitPosition::Position::Outsize, z} :
			HitPosition{HitPosition::Position::Inside, z.neg()},
			hit_point,
			material,
		}
	);
}
