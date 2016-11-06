#ifndef __hmath_Matrix4x4__
#define __hmath_Matrix4x4__

#include "Matrix.hpp"

namespace hm {

using Matrix4x4 = Matrix<4, 4>;

Matrix4x4 inverse( const Matrix4x4& M, bool* isInvertible=nullptr );
float determinant( const Matrix4x4& M );

#include "Matrix4x4.inl"

}

#endif
