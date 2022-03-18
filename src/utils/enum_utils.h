//
// Created by wandero on 2022-03-03.
//

#ifndef RAY_TRACER_CPP_ENUM_UTILS_H
#define RAY_TRACER_CPP_ENUM_UTILS_H


template<typename T>
class Option
{
public:
	enum class Var
	{
		SOME,
		NONE,
	};

	const T &
	unwrap() const
	{
		assert(tag == Var::SOME);
		return data.val;
	}

	T &
	unwrap_mut()
	{
		assert(tag == Var::SOME);
		return data.val;
	}

	[[nodiscard]] bool
	is_some() const
	{
		return tag == Var::SOME;
	}

	[[nodiscard]] bool
	is_none() const
	{
		return tag == Var::NONE;
	}
private:
	template<typename U>
	friend Option<U>
	Some(U val);

	template<typename U>
	friend Option<U>
	None();

	explicit Option(T val)
		: tag(Var::SOME), data(Data{.val= val})
	{
	}

	explicit Option()
		: tag(Var::NONE), data(Data{.na=false})
	{
	}

	union Data
	{
		T val;
		bool na;
	};

	Var tag;
	Data data;
};

template<typename T>
Option<T>
Some(T val)
{
	return Option(val);
}

template<typename U>
Option<U>
None()
{
	return Option<U>();
}

//template<typename T>
//Option(Some<T>) -> Option<T>;
//
//
//template<typename T>
//Option<T>
//Some_(T data)
//{
//	return Option{Some{data}};
//}
//
//template<typename T>
//Option<T>
//None_()
//{
//	return Option<T>{None{}};
//}
//
//template<typename T>
//struct Ok
//{
//	T data;
//};
//
//template<typename T> Ok(T) -> Ok<T>;
//
//template<typename T>
//struct Err
//{
//	T err;
//};
//
//template<typename T> Err(T) -> Err<T>;
//
//template<typename R, typename E>
//using Result = std::variant<Err<E>, Ok<R>>;
//
//template<class... Ts>
//struct overload: Ts ...
//{
//	using Ts::operator()...;
//};
//
//template<class... Ts>
//overload(Ts...) -> overload<Ts...>;

#endif //RAY_TRACER_CPP_ENUM_UTILS_H
