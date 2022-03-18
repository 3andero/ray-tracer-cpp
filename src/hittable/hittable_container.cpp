//
// Created by wandero on 2022-03-04.
//

#include "hittable_container.h"

Option<HitRecord>
HittableContainer::do_hit(const Ray &ray, array<float, 2> ray_len_range) const
{
	auto hit = None<HitRecord>();

	for (const auto &ele : elements) {
		let_mut maybe_record = ele.hit(ray, ray_len_range);
		if (maybe_record.is_none()) {
			continue;
		}
		if (hit.is_none()) {
			hit = maybe_record;
			continue;
		}
		let &curr = hit.unwrap();
		let &new_rec = maybe_record.unwrap();
		if (new_rec.ray_len < curr.ray_len) {
			ray_len_range[1] = new_rec.ray_len;
			hit = maybe_record;
		}
	}

	return hit;
}