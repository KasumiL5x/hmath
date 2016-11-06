#ifndef __hmath_Matrix3x3__
#define __hmath_Matrix3x3__

#include "Matrix.hpp"

namespace hm {

using Matrix3x3 = Matrix<3, 3>;

/**
 * Calculates the inverse of the given Matrix.
 * 
 * @param M Input Matrix.
 * @param isInvertible If not null, returns whether or not the input Matrix is invertible.
 */
Matrix3x3 inverse( const Matrix3x3& M, bool* isInvertible=nullptr );

/**
 * Computes the determinant of the given Matrix.
 * 
 * @param M Input Matrix.
 */
float determinant( const Matrix3x3& M );

#include "Matrix3x3.inl"

}

#endif
