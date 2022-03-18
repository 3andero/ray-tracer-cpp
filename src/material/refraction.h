//
// Created by wandero on 2022-03-17.
//

#ifndef REFRACTION_H
#define REFRACTION_H

#include "../utils/vec3.h"
#include "material.h"
#include "../utils/color.h"
#include "../utils/enum_utils.h"
#include "../ray.h"
#include <tuple>

class Refraction: public Material<Refraction>
{
public:
	[[nodiscard]] Option<std::tuple<Vec3, Ray>>
	do_scatter(const HitRecord &h, const Ray &ray_in) const;

	Refraction(Vec3 attenuation,
			   float eta)
		: attenuation(attenuation), eta_(eta)
	{

	}
	static float
	reflectance(float cosO, float eta)
	{
		let_mut r0 = (1.f - eta) / (1.f + eta);
		r0 *= r0;
		return r0 + (1.f - r0) * std::powf(1.f - cosO, 5.f);
	}
private:
	Vec3 attenuation;
	float eta_;

};


#endif //REFRACTION_H
