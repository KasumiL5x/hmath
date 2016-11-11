#ifndef __hmath_Matrix__
#define __hmath_Matrix__

#include <array>
#include <initializer_list>
#include <cassert>
#include "GaussianElimination.hpp"
#include "Vector.hpp"

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

template<int N> 
inline Matrix<N, N> inverse( const Matrix<N, N>& M, bool* canInverse=nullptr );

template<int N>
inline float determinant( const Matrix<N, N>& M );

template<int Rows, int Cols>
inline Matrix<Rows, Cols> transpose( const Matrix<Rows, Cols>& M );

// matrix * vector
template<int Rows, int Cols>
Vector<Rows> operator*( const Matrix<Rows, Cols>& M, const Vector<Cols>& V );

// V^T*M
template<int Rows, int Cols>
Vector<Cols> operator*( const Vector<Rows>& V, const Matrix<Rows, Cols>& M );

// M*M
template<int Rows, int Cols, int Common>
Matrix<Rows, Cols> operator*( const Matrix<Rows, Common>& A, const Matrix<Common, Cols>& B );

// insert N-by-N matrix into (N+1)-by-(N+1) with new entries at 0 except for the last row/col, which is 1
template<int N>
inline Matrix<N+1, N+1> lift( const Matrix<N, N>& M );

// extract (N-1)-by-(N-1) block from input N-by-N matrix
template<int N>
inline Matrix<N-1, N-1> project( const Matrix<N, N>& M );

#include "Matrix.inl"

}

#endif
