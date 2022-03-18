//
// Created by wandero on 2022-03-05.
//

#ifndef RAY_TRACER_CPP_RAY_TRACER_H
#define RAY_TRACER_CPP_RAY_TRACER_H

#include "utils/color.h"
#include "ray.h"
#include "hittable/hittable.h"
#include <limits>

template<typename T>
class RayTracer
{
public:
	RayTracer(const Hittable<T> &w, unsigned int b)
		: world(w), max_bounce(b)
	{}

	[[nodiscard]] Color
	ray_color(const Ray &ray) const
	{
		return Color{solve(ray, max_bounce)};
	}

private:
	const Hittable<T> &world;
	unsigned int max_bounce;

	[[nodiscard]] Vec3
	solve(const Ray &ray, unsigned int bounce) const
	{
		if (bounce <= 0) {
			return {0, 0, 0};
		}
		else {
			auto hit = world.hit(ray, {0.001, std::numeric_limits<float>::max()});
			if (hit.is_some()) {
				auto r = hit.unwrap();
				Option<tuple<Vec3, Ray>> scattered = r.scatter(ray);
				if (scattered.is_some()) {
					auto&[attenuation, new_ray] = scattered.unwrap_mut();
					return attenuation.element_mul_inplace(solve(new_ray, bounce - 1));
				}
				else {
					return {0, 0, 0};
				}
			}
			else {
				auto dir = ray.dir.unit();
				auto t = 0.5f * (dir[1] + 1.f);
				return Vec3{1., 1., 1.}.mul_inplace(1.f - t)
					.add_inplace(Vec3{0.5, 0.7, 1.}.mul_inplace(t));
			}
		}
	}
};


#endif //RAY_TRACER_CPP_RAY_TRACER_H
