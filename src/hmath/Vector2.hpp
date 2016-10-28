#ifndef __hmath_Vector2__
#define __hmath_Vector2__

#include <array>
#include <cmath>
#include <cassert>

namespace hmath {

class Vector2 {
public:
	Vector2();
	Vector2( const std::array<float, 2>& values );

	// accessors
	inline float const& operator[]( int index ) const;
	inline float& operator[]( int index );
	inline float x() const;
	inline float y() const;
	inline float z() const;

	// comparison operators
	inline bool operator==( const Vector2& vec ) const;
	inline bool operator!=( const Vector2& vec ) const;

	// tuple operations
	void makeZero();
	void makeUnit( int index );

	static Vector2 Zero();
	static Vector2 Unit( int index );

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
Vector2& operator*( Vector2& vec, float scalar );
Vector2& operator*( float scalar, Vector2& vec );
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

#include "Vector2.inc"

}

#endif
