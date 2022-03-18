//
// Created by wandero on 2022-03-17.
//

#ifndef MIRROR_H
#define MIRROR_H

#include "../utils/vec3.h"
#include "material.h"
#include "../utils/rand_utils.h"


class Mirror: public Material<Mirror>
{
public:
	[[nodiscard]] Option<std::tuple<Vec3, Ray>>
	do_scatter(const HitRecord &h, const Ray &ray_in) const;

	explicit Mirror(Vec3 at, float fuzz)
		: attenuation(at), fuzz_(fuzz)
	{
	}

	static VectorRT
	reflect(VectorRT normal, const VectorRT &in_dir)
	{
		return in_dir.sub(normal.mul_inplace(normal.mul(2.).dot(in_dir)));
	}

	static VectorRT
	fuzz(float fuzz_index)
	{
		return VectorRT(random_unit_vec()).mul_inplace(fuzz_index);
	}
private:
	Vec3 attenuation;
	float fuzz_;
};


#endif //MIRROR_H
