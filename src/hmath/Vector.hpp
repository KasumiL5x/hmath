#ifndef __hmath_Vector__
#define __hmath_Vector__

#include <array>
#include <initializer_list>
#include <cassert>
#include "Constants.hpp"
#include "Functions.hpp"

namespace hm {

template<int N>
class Vector {
public:
	Vector();
	Vector( const std::array<float, N>& values );
	Vector( std::initializer_list<float> values );

	// accessors
	inline float const& operator[]( int index ) const;
	inline float& operator[]( int index );

	// tuple operations
	void makeOne();
	void makeZero();
	void makeUnit( int index );

	// static vectors
	static Vector zero();
	static Vector one();

protected:
	std::array<float, N> tuple_;
};

// unary operations
template<int N>
Vector<N> operator+( const Vector<N>& vec );

template<int N>
Vector<N> operator-( const Vector<N>& vec );

// linear algebraic operations
template<int N>
Vector<N> operator+( const Vector<N>& v0, const Vector<N>& v1 );

template<int N>
Vector<N> operator-( const Vector<N>& v0, const Vector<N>& v1 );

template<int N>
Vector<N> operator*( const Vector<N>& vec, float scalar );

template<int N>
Vector<N> operator*( float scalar, const Vector<N>& vec );

template<int N>
Vector<N> operator/( float scalar, const Vector<N>& vec );

template<int N>
Vector<N>& operator+=( Vector<N>& v0, const Vector<N>& v1 );

template<int N>
Vector<N>& operator-=( Vector<N>& v0, const Vector<N>& v1 );

template<int N>
Vector<N>& operator*=( Vector<N>& vec, float scalar );

template<int N>
Vector<N>& operator/=( Vector<N>& vec, float scalar );

// component algebraic operations
template<int N>
Vector<N> operator*( const Vector<N>& v0, const Vector<N>& v1 );

template<int N>
Vector<N> operator/( const Vector<N>& v0, const Vector<N>& v1 );

template<int N>
Vector<N>& operator*=( Vector<N>& v0, const Vector<N>& v1 );

template<int N>
Vector<N>& operator/=( Vector<N>& v0, const Vector<N>& v1 );

// geometric operations
template<int N>
float dot( const Vector<N>& v0, const Vector<N>& v1 );

template<int N>
float length( const Vector<N>& vec );

template<int N>
float lengthRobust( const Vector<N>& vec );

template<int N>
float sqrLength( const Vector<N>& vec );

template<int N>
float normalize( Vector<N>& vec );

template<int N>
float normalizeRobust( Vector<N>& vec );

template<int N>
float distance( const Vector<N>& v0, const Vector<N>& v1 );

template<int N>
float sqrDistance( const Vector<N>& v0, const Vector<N>& v1 );

template<int N>
Vector<N> minimum( const Vector<N>& v0, const Vector<N>& v1 );

template<int N>
Vector<N> maximum( const Vector<N>& v0, const Vector<N>& v1 );

template<int N>
bool approximately( const Vector<N>& v0, const Vector<N>& v1 );

template<int N>
Vector<N> lerp( const Vector<N>& v0, const Vector<N>& v1, float t );

template<int N>
Vector<N> lerpClamped( const Vector<N>& v0, const Vector<N>& v1, float t );

template<int N>
Vector<N> reflect( const Vector<N>& direction, const Vector<N>& normal );

#include "Vector.inl"

}

#endif
