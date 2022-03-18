//
// Created by wandero on 2022-03-02.
//

#ifndef RAY_TRACER_CPP_HIT_RECORD_H
#define RAY_TRACER_CPP_HIT_RECORD_H

#include "../utils/point.h"
#include "../utils/vec.h"
#include "../material/material_variant.h"

class HitPosition
{
public:
	enum class Position
	{
		Inside,
		Outsize,

	};

	Position position;

	VectorRT normal;

	HitPosition(Position pos, VectorRT nm)
		: position(pos), normal(nm)
	{
	}

	[[nodiscard]] const VectorRT &
	unwrap() const
	{
		return normal;
	}
	[[nodiscard]] bool
	is_inside() const
	{
		return position == Position::Inside;
	}
};

class HitRecord
{
public:
	float ray_len;
	HitPosition normal;
	PointRT hit_point;
	Materials material;

	HitRecord(float rl, HitPosition nm, PointRT hp, Materials mt)
		: ray_len(rl), normal(nm), hit_point(hp),
		  material(mt)
	{}

	[[nodiscard]] Option<tuple<Vec3, Ray>>
	scatter(const Ray &r) const
	{
		return material.scatter(*this, r);
	}
};

#endif //RAY_TRACER_CPP_HIT_RECORD_H
