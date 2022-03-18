#include "src/camera.h"
#include "src/hittable/hittable_container.h"
#include "src/material/material_variant.h"
#include "src/anti_aliasing.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void
extend_from_string(vector<char> &buf, const string &val)
{
	for (let c : val) {
		buf.push_back(c);
	}
}

template<typename... Args>
void
extend_from_string(vector<char> &buf, const string &val, const Args &... arg)
{
	extend_from_string(buf, val);
	extend_from_string(buf, arg...);
}

void
push_pixel(vector<char> &buf, float val_)
{
	assert(val_ <= 1. && val_ >= 0.);
	let val = (int)(sqrt(val_) * 255.);
	if (val == 0) {
		buf.push_back(' ');
		return;
	}

	for (auto div : {100, 10, 1}) {
		if (val >= div) {
			buf.push_back((char)(((val / div) % 10) + '0'));
		}
	}
}

void
save_img(const string &name, const vector<Color> &img, int height, int width)
{
	ofstream file;
	file.open(name);
	let expected_len = width * height * 12 + 40;
	let_mut write_buf = vector<char>();
	write_buf.reserve(expected_len);
	extend_from_string(write_buf,
					   "P3\n",
					   std::to_string(width),
					   " ",
					   std::to_string(height),
					   "\n255\n");
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			let &c = img[i * width + j];
			push_pixel(write_buf, c[0]);
			write_buf.push_back(' ');
			push_pixel(write_buf, c[1]);
			write_buf.push_back(' ');
			push_pixel(write_buf, c[2]);
			write_buf.push_back('\n');
		}
	}

	file << write_buf.data();
	file.close();
}

int
main(int, char **)
{
	let width = 1920;
	let height = (int)(width / (16. / 9.));
	let cam =
		Camera::create(
			PointRT{{2., 3., 2.5}},
			PointRT{{0., 0.8, -1.}},
			VectorRT{{0., 1., 0.}},
			4,
			16. / 9.,
			1.
		);

	let lamb1 = Materials{Lambertian{{0.3, 0.61, 0.77}}};
	let lamb2 = Materials{Lambertian{{1., 0.55, 0.6}}};
	let m1 = Materials{Mirror{{0.9, 0.9, 0.9}, 0.}};
	let rf1 = Materials{Refraction{{0.8, 0.85, 0.9}, 1.5}};
	let rf2 = Materials{Refraction{{0.8, 0.85, 0.9}, 1.3}};

	let world = HittableContainer{
		HittableVariant{
			Sphere{
				PointRT{{0, 0.5, -2.}},
				0.5,
				m1,
			}},
		HittableVariant{Sphere{
			PointRT{{1.7, 1, -2.3}},
			1,
			rf1,
		}},
		HittableVariant{Sphere{
			PointRT{{-1.5, 1, -2.2}},
			1,
			lamb2,
		}},
		HittableVariant{Sphere{
			PointRT{{-1, 0.2, -1.2}},
			0.2,
			rf2,
		}},
		HittableVariant{Sphere{
			PointRT{{0.8, 0.2, -1.2}},
			0.2,
			rf2,
		}},
		HittableVariant{Plane::new_infinite({0.f, 0.f, -2.f}, {0.f, 1.f, 0.f}, lamb1)}
	};

	let tracer = RayTracer{world, 50};
	let aa = createMSAA({height, width}, {20, 20}, tracer, cam);
	let total_pixel = width * height;
	let_mut res = vector<Color>{};
	res.reserve(total_pixel);
	cout << "start" << endl;
	let start_time = time(nullptr);
	for (int id = 0; id < total_pixel; ++id) {
//		if (id % 100 == total_pixel % 100) {
//			cout << id << " " << total_pixel << endl;
//		}
		let i = height - id / width - 1;
		let j = id % width;
		res.push_back(aa.get_color(i, j));
	}
	cout << "elapsed: " << time(nullptr) - start_time << endl;

	save_img("./test1.ppm", res, height, width);
}
