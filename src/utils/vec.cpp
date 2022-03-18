//
// Created by wandero on 2022-03-02.
//

#include "vec.h"
#include "point.h"

PointRT
VectorRT::add(const PointRT &o) const
{
	return o.add(*this);
}