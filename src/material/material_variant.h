//
// Created by wandero on 2022-03-04.
//

#ifndef RAY_TRACER_CPP_MATERIAL_VARIANT_H
#define RAY_TRACER_CPP_MATERIAL_VARIANT_H

#include <variant>
#include "lambertian.h"
#include "mirror.h"
#include "refraction.h"

class MaterialVariant: public std::variant<Lambertian, Mirror, Refraction>, public Material<MaterialVariant>
{
public:
	[[nodiscard]] Option<std::tuple<Vec3, Ray>>
	do_scatter(const HitRecord &h, const Ray &ray_in) const;
};

#endif //RAY_TRACER_CPP_MATERIAL_VARIANT_H
