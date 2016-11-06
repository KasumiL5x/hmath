#ifndef __hmath_Matrix3x3__
#define __hmath_Matrix3x3__

#include "Matrix.hpp"

namespace hm {

using Matrix3x3 = Matrix<3, 3>;

Matrix3x3 inverse( const Matrix3x3& M, bool* isInvertible=nullptr );
float determinant( const Matrix3x3& M );

#include "Matrix3x3.inl"

}

#endif
