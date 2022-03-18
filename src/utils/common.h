//
// Created by wandero on 2022-03-17.
//

#ifndef COMMON_H
#define COMMON_H

template<typename T>
bool
in_range(float val, T range)
{
	return val >= range[0] && val <= range[1];
}

#endif //COMMON_H
