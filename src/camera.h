//
// Created by wandero on 2022-03-04.
//

#ifndef RAY_TRACER_CPP_CAMERA_H
#define RAY_TRACER_CPP_CAMERA_H

#include "utils/point.h"
#include "utils/vec.h"
#include "ray.h"

class Camera
{
public:
	static Camera
	create(PointRT look_from, PointRT look_to, VectorRT up, float horizontal_len, float h_v_ratio, float focal_len)
	{
		let_mut depth = look_from.sub(look_to);
		let horizontal = up.cross(depth).into_unit().mul_inplace(horizontal_len);
		let vertical_len = horizontal_len / h_v_ratio;
		let vertical = depth.cross(horizontal).into_unit().mul_inplace(vertical_len);
		let bottom_left = look_from
			.sub(vertical.mul(0.5))
			.sub(horizontal.mul(0.5))
			.sub(depth.into_unit().mul(focal_len));

		return Camera{bottom_left, look_from, horizontal, vertical};
	}

	[[nodiscard]] Ray
	get_ray(float h_percent, float v_percent) const
	{
		let ray_start = bottom_left.add(horizontal.mul(h_percent)).add_inplace(vertical.mul(v_percent));
		return Ray{look_from, ray_start};
	}

private:
	PointRT bottom_left;
	PointRT look_from;
	VectorRT horizontal;
	VectorRT vertical;

	Camera(PointRT btn_l, PointRT lf, VectorRT hor, VectorRT ver
	)
		: bottom_left(btn_l), look_from(lf), horizontal(hor), vertical(ver)
	{}
};


#endif //RAY_TRACER_CPP_CAMERA_H
