//
// Created by wandero on 2022-03-03.
//

#ifndef RAY_TRACER_CPP_ENUM_UTILS_H
#define RAY_TRACER_CPP_ENUM_UTILS_H

#include <variant>

template<typename T>
struct Some
{
	T val;
};

template<typename T>
Some(T) -> Some<T>;

struct None
{
};

template<typename T>
using OptionVariant = std::variant<Some<T>, None>;

template<typename T>
class Option: public OptionVariant<T>
{
public:
	using OptionVariant<T>::OptionVariant;
	using OptionVariant<T>::operator=;

	const T &
	unwrap() const
	{
		return std::get<Some<T>>(*this).val;
	}

	T &
	unwrap_mut()
	{
		return std::get<Some<T>>(*this).val;
	}

	[[nodiscard]] bool
	is_some() const
	{
		return this->index() == 0;
	}

	[[nodiscard]] bool
	is_none() const
	{
		return this->index() != 0;
	}
};

template<typename T>
Option(Some<T>) -> Option<T>;


template<typename T>
Option<T>
Some_(T val)
{
	return Option{Some{val}};
}

template<typename T>
Option<T>
None_()
{
	return Option<T>{None{}};
}

template<typename T>
struct Ok
{
	T val;
};

template<typename T> Ok(T) -> Ok<T>;

template<typename T>
struct Err
{
	T err;
};

template<typename T> Err(T) -> Err<T>;

template<typename R, typename E>
using Result = std::variant<Err<E>, Ok<R>>;

template<class... Ts>
struct overload: Ts ...
{
	using Ts::operator()...;
};

template<class... Ts>
overload(Ts...) -> overload<Ts...>;

#endif //RAY_TRACER_CPP_ENUM_UTILS_H
