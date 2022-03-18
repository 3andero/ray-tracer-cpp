//
// Created by wandero on 2022-03-04.
//

#include "hittable_variant.h"

Option<HitRecord>
HittableVariant::do_hit(const Ray &ray, array<float, 2> ray_len_range) const
{
	switch (tag_) {
	case Var::Sphere:
		return data.sphere.do_hit(ray, ray_len_range);
	case Var::Plane:
		return data.plane.do_hit(ray, ray_len_range);
	}
}
