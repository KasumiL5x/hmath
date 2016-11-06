#ifndef __hmath_Matrix2x2__
#define __hmath_Matrix2x2__

#include "Matrix.hpp"

namespace hm {

using Matrix2x2 = Matrix<2, 2>;

void makeRotation( float angle, Matrix2x2& rotation );
float getRotationAngle( const Matrix2x2& rotation );

/**
 * Calculates the inverse of the given Matrix.
 * 
 * @param M Input Matrix.
 * @param isInvertible If not null, returns whether or not the input Matrix is invertible.
 */
Matrix2x2 inverse( const Matrix2x2& M, bool* isInvertible=nullptr );

/**
 * Computes the determinant of the given Matrix.
 * 
 * @param M Input Matrix.
 */
float determinant( const Matrix2x2& M );

#include "Matrix2x2.inl"

}

#endif
