//
// Created by wandero on 2022-03-02.
//

#ifndef RAY_TRACER_CPP_LAMBERTIAN_H
#define RAY_TRACER_CPP_LAMBERTIAN_H

#include "material.h"
#include "../utils/color.h"
#include "../utils/enum_utils.h"
#include "../ray.h"
#include <tuple>

class Lambertian: public Material<Lambertian>
{
public:
	explicit Lambertian(Color c)
		: color(c)
	{
	}

	[[nodiscard]] Option<std::tuple<Vec3, Ray>>
	do_scatter(const HitRecord &h, const Ray &ray_in) const;

private:
	Color color;
};

#endif //RAY_TRACER_CPP_LAMBERTIAN_H
