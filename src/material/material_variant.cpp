//
// Created by wandero on 2022-03-05.
//

#include "material_variant.h"

[[nodiscard]] Option<std::tuple<Vec3, Ray>>
Materials::do_scatter(const HitRecord &h, const Ray &ray_in) const
{
	switch (tag_) {
	case Var::Lambertian:
		return data.l.scatter(h, ray_in);
	case Var::Mirror:
		return data.m.scatter(h, ray_in);
	case Var::Refraction:
		return data.r.scatter(h, ray_in);
	}
}
