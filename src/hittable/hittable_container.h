//
// Created by wandero on 2022-03-04.
//

#ifndef RAY_TRACER_CPP_HITTABLE_CONTAINER_H
#define RAY_TRACER_CPP_HITTABLE_CONTAINER_H

#include <vector>
#include <array>
#include "hittable_variant.h"

class HittableContainer: public Hittable<HittableContainer>
{
public:
	HittableContainer()
		: elements({})
	{
	}

	HittableContainer(std::initializer_list<HittableVariant> ele)
		: elements(ele)
	{
	}

	[[nodiscard]] Option<HitRecord>
	do_hit(const Ray &ray, array<float, 2> ray_len_range) const;

	std::vector<HittableVariant> elements;
};


#endif //RAY_TRACER_CPP_HITTABLE_CONTAINER_H
