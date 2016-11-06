#ifndef __hmath_Matrix2x2__
#define __hmath_Matrix2x2__

#include "Matrix.hpp"

namespace hm {

using Matrix2x2 = Matrix<2, 2>;

void makeRotation( float angle, Matrix2x2& rotation );
float getRotationAngle( const Matrix2x2& rotation );
Matrix2x2 inverse( const Matrix2x2& M, bool* isInvertible=nullptr );
float determinant( const Matrix2x2& M );

#include "Matrix2x2.inl"

}

#endif
