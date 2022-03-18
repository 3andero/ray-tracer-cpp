//
// Created by wandero on 2022-03-04.
//

#ifndef RAY_TRACER_CPP_MATERIAL_VARIANT_H
#define RAY_TRACER_CPP_MATERIAL_VARIANT_H

#include "lambertian.h"
#include "mirror.h"
#include "refraction.h"

class Materials: public Material<Materials>
{
public:
	enum class Var
	{
		Lambertian,
		Mirror,
		Refraction,
	};

	explicit Materials(Lambertian d)
	: tag_(Var::Lambertian), data(Data{ .l{d}})
	{
	}

	explicit Materials(Mirror d)
		: tag_(Var::Mirror), data(Data{ .m{d}})
	{
	}

	explicit Materials(Refraction d)
		: tag_(Var::Refraction), data(Data{ .r{d}})
	{
	}

	[[nodiscard]] Option<std::tuple<Vec3, Ray>>
	do_scatter(const HitRecord &h, const Ray &ray_in) const;
private:
	union Data
	{
		Lambertian l;
		Mirror m;
		Refraction r;
	};
	Var tag_;
	Data data;
};

#endif //RAY_TRACER_CPP_MATERIAL_VARIANT_H
