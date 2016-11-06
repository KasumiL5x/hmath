#ifndef __hmath_Matrix4x4__
#define __hmath_Matrix4x4__

#include "Matrix.hpp"
#include "Vector3.hpp"

namespace hm {

using Matrix4x4 = Matrix<4, 4>;

Matrix4x4 inverse( const Matrix4x4& M, bool* isInvertible=nullptr );
float determinant( const Matrix4x4& M );

Matrix4x4 makeTranslation( float x, float y, float z );
Matrix4x4 makeTranslation( const Vector3& position );
// angle is in radians; axis should be normalized
Matrix4x4 makeRotation( float angle, float x, float y, float z );
Matrix4x4 makeRotation( float angle, const Vector3& axis );
Matrix4x4 makeScale( float x, float y, float z );
Matrix4x4 makeScale( const Vector3& scale );


#include "Matrix4x4.inl"

}

#endif
