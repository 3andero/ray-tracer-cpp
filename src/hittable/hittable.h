//
// Created by wandero on 2022-03-04.
//

#ifndef RAY_TRACER_CPP_HITTABLE_H
#define RAY_TRACER_CPP_HITTABLE_H

#include "../ray.h"
#include "../utils/enum_utils.h"
#include "hit_record.h"
#include <array>

template<typename T>
class Hittable
{
public:
	[[nodiscard]] Option<HitRecord>
	hit(const Ray &ray, array<float, 2> ray_len_range) const
	{
		return static_cast<const T *>(this)->do_hit(ray, ray_len_range);
	}
};

#endif //RAY_TRACER_CPP_HITTABLE_H
