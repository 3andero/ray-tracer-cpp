//
// Created by wandero on 2022-03-04.
//

#include "lambertian.h"
#include "../hittable/hit_record.h"
#include "../utils/rand_utils.h"

[[nodiscard]] Option<std::tuple<Vec3, Ray>>
Lambertian::do_scatter(const HitRecord &h, const Ray &ray_in) const
{
	let target = h.hit_point.add(h.normal.unwrap()).add_inplace(VectorRT(random_unit_vec()));
	return Some_(tuple{color.as_vec3(), Ray(h.hit_point, target)});
}