#ifndef __hmath_Matrix__
#define __hmath_Matrix__

#include <array>
#include <initializer_list>
#include <cassert>

namespace hm {

template<int Rows, int Cols>
class Matrix {
public:
	Matrix();
	Matrix( const std::array<float, Rows*Cols>& values );
	Matrix( std::initializer_list<float> values );

	// accessors
	inline float const& operator()( int r, int c ) const;
	inline float& operator()( int r, int c );
	inline float const& operator[]( int index ) const;
	inline float& operator[]( int index );

	inline float const& get( int row, int col ) const;
	inline float& get( int row, int col );
	inline void set( int row, int col, float value );

	void makeZero();
	void makeIdentity();
	static Matrix zero();
	static Matrix identity();

protected:
	std::array<std::array<float, Cols>, Rows> data_;
};

#include "Matrix.inl"

}

#endif