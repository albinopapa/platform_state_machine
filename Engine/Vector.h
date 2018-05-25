#pragma once

#include <type_traits>

template<size_t ElemCount, typename ElemType>
class Vector{};

template<typename T>
class Vector<2, T>
{
public:
	static constexpr size_t elem_count = 2;
public:
	Vector() = default;
	Vector( T _x, T _y ) : x( _x ), y( _y ){}
	Vector& operator+=( const Vector& _other )
	{
		x += _other.x;
		y += _other.y;
		return *this;
	}
	Vector& operator-=( const Vector& _other )
	{
		x -= _other.x;
		y -= _other.y;
		return *this;
	}
	Vector& operator*=(const T& _scalar )
	{
		x *= _scalar;
		y *= _scalar;
		return *this;
	}
	Vector& operator/=(const T& _scalar )
	{
		if constexpr( std::is_floating_point_v<T> )
		{
			const auto invScalar = T( 1. ) / _scalar;
			return *this *= invScalar;
		}
		x /= _scalar;
		y /= _scalar;
		return *this;
	}
public:
	T x, y;
};

template<typename T>
class Vector<3, T>
{
public:
	static constexpr size_t elem_count = 3;
public:
	Vector() = default;
	Vector( T _x, T _y, T _z ) : x( _x ), y( _y ), z( _z ){}

	Vector& operator+=( const Vector& _other )
	{
		x += _other.x;
		y += _other.y;
		z += _other.z;
		return *this;
	}
	Vector& operator-=( const Vector& _other )
	{
		x -= _other.x;
		y -= _other.y;
		z -= _other.z;
		return *this;
	}
	Vector& operator*=( const T& _scalar )
	{
		x *= _scalar;
		y *= _scalar;
		z *= _scalar;
		return *this;
	}
	Vector& operator/=( const T& _scalar )
	{
		if constexpr( std::is_floating_point_v<T> )
		{
			const auto invScalar = T( 1. ) / _scalar;
			return *this *= invScalar;
		}

		x /= _scalar;
		y /= _scalar;
		z /= _scalar;
		return *this;
	}
public:
	T x, y, z;
};

template<template<class> class vec_type, class scalar_type>
vec_type<scalar_type> operator+( const vec_type<scalar_type>& _lhs, const vec_type<scalar_type>& _rhs )
{
	return vec_type<scalar_type>( _lhs ) += _rhs;
}
template<template<class> class vec_type, class scalar_type>
vec_type<scalar_type> operator-( const vec_type<scalar_type>& _lhs, const vec_type<scalar_type>& _rhs )
{
	return vec_type<scalar_type>( _lhs ) -= _rhs;
}
template<template<class> class vec_type, class scalar_type>
vec_type<scalar_type> operator*( const vec_type<scalar_type>& _lhs, const scalar_type _rhs )
{
	return vec_type<scalar_type>( _lhs ) *= _rhs;
}
template<template<class> class vec_type, class scalar_type>
vec_type<scalar_type> operator*( const scalar_type _lhs, const vec_type<scalar_type>& _rhs )
{
	return _rhs *= _lhs;
}
template<template<class> class vec_type, class scalar_type>
vec_type<scalar_type> operator/( const vec_type<scalar_type>& _lhs, const scalar_type _rhs )
{
	return vec_type<scalar_type>( _lhs ) /= _rhs;
}

template<template<class> class vec_type, class scalar_type>
scalar_type DotProduct( const vec_type<scalar_type>& _lhs, const vec_type<scalar_type>& _rhs )
{
	scalar_type result = ( _lhs.x * _rhs.x ) + ( _lhs.y * _rhs.y );
	if constexpr( vec_type<scalar_type>::elem_count == 3 )
	{
		result += ( _lhs.z * _rhs.z );
	}

	return result;
}

template<template<class> class vec_type, class scalar_type>
auto CrossProduct( const vec_type<scalar_type>& _lhs, const vec_type<scalar_type>& _rhs )
->std::conditional_t<vec_type<scalar_type>::elem_count == 2, scalar_type, vec_type<scalar_type>>
{
	if constexpr( vec_type<scalar_type>::elem_count == 2 )
	{
		return ( _lhs.y * _rhs.x ) - ( _lhs.x * _rhs.y );
	}
	else if constexpr( vec_type<scalar_type>::elem_count == 3 )
	{
		return
			vec_type<scalar_type>( _lhs.y * _rhs.z, _lhs.z * _rhs.x, _lhs.x * _rhs.y ) -
			vec_type<scalar_type>( _lhs.z * _rhs.y, _lhs.x * _rhs.z, _lhs.y * _rhs.z );
	}
}

template<template<class> class vec_type, class scalar_type>
vec_type<scalar_type> Lerp( const vec_type<scalar_type>& _start, const vec_type<scalar_type>& _end, scalar_type _t )
{
	return _start + ( ( _end - _start ) * _t );
}

template<class T> using Vec2 = Vector<2, T>;
template<class T> using Vec3 = Vector<3, T>;
using Vec2f = Vector<2, float>;
using Vec3f = Vector<3, float>;