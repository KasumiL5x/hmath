#ifndef __hmath_Vector2__
#define __hmath_Vector2__

#include <array>
#include <initializer_list>
#include <cmath>
#include <cassert>
#include "Functions.hpp" // clamp
#include "Constants.hpp" // epsilon

namespace hmath {

class Vector2 {
public:
	Vector2();
	Vector2( const std::array<float, 2>& values );
	Vector2( std::initializer_list<float> values );

	// accessors
	inline float const& operator[]( int index ) const;
	inline float& operator[]( int index );
	inline float x() const;
	inline float y() const;

	// comparison operators
	inline bool operator==( const Vector2& vec ) const;
	inline bool operator!=( const Vector2& vec ) const;

	// tuple operations
	void makeZero();
	void makeOne();
	void makeUnit( int index );

	static Vector2 zero();
	static Vector2 one();
	static Vector2 left();
	static Vector2 right();
	static Vector2 up();
	static Vector2 down();
	static Vector2 unit( int index );

protected:
	std::array<float, 2> tuple_;
};

// unary operations
Vector2 operator+( const Vector2& vec );
Vector2 operator-( const Vector2& vec );

// linear algebraic operations
Vector2 operator+( const Vector2& v0, const Vector2& v1 );
Vector2 operator-( const Vector2& v0, const Vector2& v1 );
Vector2 operator*( const Vector2& vec, float scalar );
Vector2 operator*( float scalar, const Vector2& vec );
Vector2 operator/( const Vector2& vec, float scalar );
Vector2& operator+=( Vector2& v0, const Vector2& v1 );
Vector2& operator-=( Vector2& v0, const Vector2& v1 );
Vector2& operator*=( Vector2& vec, float scalar );
Vector2& operator/=( Vector2& vec, float scalar );

// component algebraic operations
Vector2 operator*( const Vector2& v0, const Vector2& v1 );
Vector2 operator/( const Vector2& v0, const Vector2& v1 );
Vector2& operator*=( Vector2& v0, const Vector2& v1 );
Vector2& operator/=( Vector2& v0, const Vector2& v1 );

// geometric operations
float dot( const Vector2& v0, const Vector2& v1 );
float length( const Vector2& vec );
float lengthRobust( const Vector2& vec );
float sqrLength( const Vector2& vec );
float normalize( Vector2& vec );
float normalizeRobust( Vector2& vec );
float distance( const Vector2& v0, const Vector2& v1 );
float sqrDistance( const Vector2& v0, const Vector2& v1 );
Vector2 lerp( const Vector2& v0, const Vector2& v1, float t );
Vector2 lerpClamped( const Vector2& v0, const Vector2& v1, float t );
Vector2 minimum( const Vector2& v0, const Vector2& v1 );
Vector2 maximum( const Vector2& v0, const Vector2& v1 );
bool approximately( const Vector2& v0, const Vector2& v1 );
Vector2 reflect( const Vector2& direction, const Vector2& normal );

#include "Vector2.inl"

}

#endif
