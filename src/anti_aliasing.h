//
// Created by wandero on 2022-03-07.
//

#ifndef RAY_TRACER_CPP__ANTI_ALIASING_H_
#define RAY_TRACER_CPP__ANTI_ALIASING_H_

#include <array>
#include "ray_tracer.h"
#include "camera.h"
#include "utils/color.h"
#include "utils/vec3.h"

template<typename T>
class MSAA
{
public:
	[[nodiscard]] Color
	get_color(int _i, int _j) const
	{
		let rate = (float)(sample_size[0] * sample_size[1]);
		let_mut color = Vec3{0., 0., 0.};
		let i = (float)(_i * sample_size[0]);
		let j = (float)(_j * sample_size[1]);
		for (int si = 0; si < sample_size[0]; si++) {
			for (int sj = 0; sj < sample_size[1]; ++sj) {
				let v_percent = (i + (float)si + 1) / (shape[0]);
				let h_percent = (j + (float)sj + 1) / (shape[1]);
				let r = cam.get_ray(h_percent, v_percent);
				let sample_color = tracer.ray_color(r).as_vec3();
				color.add_inplace(sample_color);
			}
		}
		return Color{color.mul_inplace(1.f / rate)};
	}

	template<typename U>
	friend MSAA<U>
	createMSAA(std::array<int, 2> shape_,
			   std::array<int, 2> sample_size,
			   const RayTracer<U> &tracer,
			   const Camera &cam);
private:
	std::array<float, 2> shape;
	std::array<int, 2> sample_size;
	const RayTracer<T> &tracer;
	const Camera &cam;

	MSAA(std::array<float, 2> s,
		 std::array<int, 2> ss,
		 const RayTracer<T> &tr,
		 const Camera &c)
		:
		shape(s), sample_size(ss), tracer(tr), cam(c)
	{}
};

template<typename U>
MSAA<U>
createMSAA(std::array<int, 2> shape_, std::array<int, 2> sample_size, const RayTracer<U> &tracer, const Camera &cam)
{
	let shape = array{(float)shape_[0] * (float)sample_size[0], (float)shape_[1] * (float)sample_size[1]};
	return MSAA(shape, sample_size, tracer, cam);
}

#endif //RAY_TRACER_CPP__ANTI_ALIASING_H_
