#ifndef RAY_TRACER_CPP_VEC3_H
#define RAY_TRACER_CPP_VEC3_H

#define let const auto
#define let_mut auto

#include <iostream>
#include <array>
#include <cmath>

using namespace std;

using Inner = array<float, 3>;

template<typename T1, typename T2>
Inner
cross_product(const T1 &a, const T2 &b)
{
	return {a[1] * b[2] - a[2] * b[1],
			a[2] * b[0] - a[0] * b[2],
			a[0] * b[1] - a[1] * b[0]};
}

bool
areEqualRel(float a, float b, float epsilon);

class Vec3
{
public:
	Vec3(float a0, float a1, float a2)
		: inner_()
	{
		inner_ = {a0, a1, a2};
	}

	explicit Vec3(Inner inner)
		: inner_(inner)
	{
	}

	float
	operator[](const size_t idx) const
	{
		return inner_[idx];
	}

	float &
	operator[](const size_t idx)
	{
		return inner_[idx];
	}

	[[nodiscard]] Vec3
	add(const Vec3 &other) const
	{
		let_mut ret = inner_;
		for (size_t i = 0; i < 3; i++) {
			ret[i] += other[i];
		}

		return Vec3(ret);
	}

	Vec3 &
	add_inplace(const Vec3 &other)
	{
		for (size_t i = 0; i < 3; i++) {
			inner_[i] += other[i];
		}
		return *this;
	}

	[[nodiscard]] Vec3
	sub(const Vec3 &other) const
	{
		let_mut ret = inner_;
		for (size_t i = 0; i < 3; i++) {
			ret[i] -= other[i];
		}

		return Vec3{ret};
	}

	Vec3 &
	sub_inplace(const Vec3 &other)
	{
		for (size_t i = 0; i < 3; i++) {
			inner_[i] -= other[i];
		}
		return *this;
	}

	[[nodiscard]] Vec3
	mul(const float factor) const
	{
		let_mut ret = *this;

		for (size_t i = 0; i < 3; i++) {
			ret[i] *= factor;
		}

		return ret;
	}

	Vec3 &
	mul_inplace(const float factor)
	{
		for (size_t i = 0; i < 3; i++) {
			inner_[i] *= factor;
		}
		return *this;
	}

	Vec3 &
	neg_inplace()
	{
		for (size_t i = 0; i < 3; i++) {
			inner_[i] = -inner_[i];
		}
		return *this;
	}

	[[nodiscard]] Vec3
	element_mul(const Vec3 &other) const
	{
		let_mut ret = *this;

		for (size_t i = 0; i < 3; i++) {
			ret[i] *= other[i];
		}

		return ret;
	}

	[[nodiscard]] Vec3 &
	element_mul_inplace(const Vec3 &other)
	{
		for (size_t i = 0; i < 3; i++) {
			inner_[i] *= other[i];
		}
		return *this;
	}

	[[nodiscard]] float
	dot(const Vec3 &other) const
	{
		float ret = 0.;
		for (size_t i = 0; i < 3; i++) {
			ret += inner_[i] * other[i];
		}
		return ret;
	}

	[[nodiscard]] Vec3
	cross(const Vec3 &other) const
	{
		return Vec3{cross_product(inner_, other)};
	}

	[[nodiscard]] float
	length_squared() const
	{
		float res = 0.;
		for (size_t i = 0; i < 3; i++) {
			res += inner_[i] * inner_[i];
		}
		return res;
	}

	[[nodiscard]] float
	length() const
	{
		return sqrtf(length_squared());
	}

	[[nodiscard]] Vec3
	unit() const
	{
		return this->mul(1.f / this->length());
	}

	Vec3 &
	into_unit()
	{
		this->mul_inplace((float)1. / this->length());
		return *this;
	}

	bool
	operator==(const Vec3 &other) const
	{
		for (int i = 0; i < 3; i++) {
			if (!areEqualRel(inner_[i], other[i], 0.001)) {
				return false;
			}
		}
		return true;
	}

private:
	Inner inner_;
};

template<class T>
class Vec3Wrapper
{
public:
	[[nodiscard]] const Vec3 &
	as_vec3() const
	{
		return inner;
	}

	[[nodiscard]] T
	mul(const float factor) const
	{
		return T{inner.mul(factor)};
	}

	T &
	mul_inplace(const float factor)
	{
		inner.mul_inplace(factor);
		return *static_cast<T *>(this);
	}

	[[nodiscard]] T
	add(const Vec3 &o) const
	{
		return T(inner.add(o));
	}

	T &
	add_inplace(const Vec3 &factor)
	{
		inner.add_inplace(factor);
		return *static_cast<T *>(this);
	}

	float &
	operator[](size_t idx)
	{
		return inner[idx];
	}

	float
	operator[](size_t idx) const
	{
		return inner[idx];
	}

	template<class U>
	friend std::ostream &
	operator<<(std::ostream &os, Vec3Wrapper<U> const &m);

	bool
	operator==(const Vec3Wrapper<T> &other) const
	{
		return inner == other.inner;
	}

	explicit Vec3Wrapper(Vec3 val)
		: inner(val)
	{
	}

	Vec3Wrapper(float x0, float x1, float x2)
		: inner(Vec3{x0, x1, x2})
	{
	}

protected:
	Vec3 inner;
};

std::ostream &
operator<<(std::ostream &os, Vec3 const &m);

template<typename T>
std::ostream &
operator<<(std::ostream &os, Vec3Wrapper<T> const &m)
{
	return os << m.inner;
}

#endif