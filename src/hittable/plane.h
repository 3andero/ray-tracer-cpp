//
// Created by wandero on 2022-03-17.
//

#ifndef PLANE_H
#define PLANE_H

#include <utility>

#include "../utils/point.h"
#include "../utils/enum_utils.h"
#include "../material/material_variant.h"
#include "hittable.h"

class Plane: public Hittable<Plane>
{
public:
	PointRT origin;
	Option<tuple<VectorRT, VectorRT>> x_y;
	VectorRT z;
	MaterialVariant material;

	static Plane
	new_finite(PointRT origin,
			   VectorRT x,
			   VectorRT y,
			   MaterialVariant m)
	{
		let z = x.cross(y);
		return Plane{origin, Some_(tuple(x, y)), z, m};
	}

	static Plane
	new_infinite(PointRT origin,
				 VectorRT z,
				 MaterialVariant m)
	{
		return Plane{origin, None_<tuple<VectorRT, VectorRT>>(), z, m};
	}
	[[nodiscard]] Option<HitRecord>
	do_hit(const Ray &ray, array<float, 2> ray_len_range) const;
private:
	Plane(PointRT origin,
		  Option<tuple<VectorRT, VectorRT>> x_y,
		  VectorRT z,
		  MaterialVariant material)
		: origin(origin), x_y(std::move(x_y)), z(z), material(material)
	{}

};

#endif //PLANE_H
