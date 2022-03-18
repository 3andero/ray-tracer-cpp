//
// Created by wandero on 2022-03-04.
//

#include "sphere.h"
#include "hit_record.h"
#include <cmath>

Option<HitRecord>
Sphere::do_hit(const Ray &ray, array<float, 2> ray_len_range) const
{
	let &m = ray.dir;
	let p_n = center.sub(ray.start);
	let m2 = m.dot(m);
	let p_n2 = p_n.dot(p_n);
	let m_p_n = m.dot(p_n);

	let b2_4ac = m_p_n * m_p_n - m2 * (p_n2 - radius * radius);
	if (b2_4ac < 0.) {
		return None<HitRecord>();
	}

	let_mut root = (m_p_n - sqrtf(b2_4ac)) / m2;
	if (root < ray_len_range[0] || root > ray_len_range[1]) {
		root = (m_p_n + sqrtf(b2_4ac)) / m2;
		if (root < ray_len_range[0] || root > ray_len_range[1]) {
			return None<HitRecord>();
		}
	}

	let hit_point = ray.at(root);
	let_mut normal = (hit_point.sub(center)).into_unit();

	using Position = HitPosition::Position;

	return Some(HitRecord{
		root,
		normal.dot(m) < 0 ? HitPosition(Position::Outsize, normal) :
		HitPosition(Position::Inside, normal.neg_inplace()),
		hit_point,
		material
	});
}