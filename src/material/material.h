//
// Created by wandero on 2022-03-02.
//

#ifndef RAY_TRACER_CPP_MATERIAL_H
#define RAY_TRACER_CPP_MATERIAL_H

#include "../ray.h"
#include "../utils/enum_utils.h"

class HitRecord;

template<typename T>
class Material
{
public:
	[[nodiscard]] Option<std::tuple<Vec3, Ray>>
	scatter(const HitRecord &h, const Ray &ray_in) const
	{
		return static_cast<const T *>(this)->do_scatter(h, ray_in);
	}
};

#endif //RAY_TRACER_CPP_MATERIAL_H




