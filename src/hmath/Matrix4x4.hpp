#ifndef __hmath_Matrix4x4__
#define __hmath_Matrix4x4__

#include "Matrix.hpp"
#include "Vector3.hpp"

namespace hm {

using Matrix4x4 = Matrix<4, 4>;

/**
 * Calculates the inverse of the given Matrix.
 * 
 * @param M Input Matrix.
 * @param isInvertible If not null, returns whether or not the input Matrix is invertible.
 */
inline Matrix4x4 inverse( const Matrix4x4& M, bool* isInvertible=nullptr );

/**
 * Computes the determinant of the given Matrix.
 * 
 * @param M Input Matrix.
 */
inline float determinant( const Matrix4x4& M );

/**
 * Creates a translation Matrix4x4.
 * 
 * @param x X coordinate.
 * @param y Y coordinate.
 * @param z Z coordinate.
 */
inline Matrix4x4 makeTranslation( float x, float y, float z );

/**
 * Creates a translation Matrix4x4.
 * 
 * @param position (X,Y,Z) position.
 */
inline Matrix4x4 makeTranslation( const Vector3& position );

/**
 * Creates a rotation Matrix4x4 of an angle along an axis.
 * @param angle Angle in radians.
 * @param x X component of the normalized axis of rotation.
 * @param y Y component of the normalized axis of rotation.
 * @param z Z component of the normalized axis of rotation.
 */
inline Matrix4x4 makeRotation( float angle, float x, float y, float z );

/**
	* Creates a rotation Matrix4x4 of an angle along an axis.
 * 
 * @param angle Angle in radians.
 * @param axis Normalized axis of rotation.
 */
inline Matrix4x4 makeRotation( float angle, const Vector3& axis );

/**
 * Creates a scale Matrix4x4.
 * 
 * @param x X scale.
 * @param y Y scale.
 * @param z Z scale.
 */
inline Matrix4x4 makeScale( float x, float y, float z );

/**
 * Creates a scale Matrix4x4.
 * 
 * @param scale (X,Y,Z) scale.
 */
inline Matrix4x4 makeScale( const Vector3& scale );

/**
 * Creates an orthographic projection Matrix4x4
 * 
 * @param left   Left coordinate of the viewport.
 * @param right  Right coordinate of the viewport.
 * @param bottom Bottom coordinate of the viewport.
 * @param top    Top coordinate of the viewport.
 * @param near   Near plane distance.
 * @param far    Far plane distance.
 */
inline Matrix4x4 makeOrthographic( float left, float right, float bottom, float top, float near, float far );

/**
 * Creates a frustum Matrix4x4.
 * 
 * @param left   Left coordinate of the viewport.
 * @param right  Right coordinate of the viewport.
 * @param bottom Bottom coordinate of the viewport.
 * @param top    Top coordinate of the viewport.
 * @param near   Near plane distance.
 * @param far    Far plane distance
 */
inline Matrix4x4 makeFrustum( float left, float right, float bottom, float top, float near, float far );

/**
 * Makes a right-handed perspective projection Matrix.
 * 
 * @param fovY   Vertical field of view in radians.
 * @param aspect Aspect ratio.
 * @param near   Near plane distance.
 * @param far    Far plane distance.
 */
inline Matrix4x4 makePerspective( float fovY, float aspect, float near, float far );

/**
 * Makes a right-handed lookat matrix.
 * 
 * @param eye    Eye position.
 * @param target Look at target.
 * @param up     Local up vector.
 */
inline Matrix4x4 makeLookAt( const Vector3& eye, const Vector3& target, const Vector3& up );


#include "Matrix4x4.inl"

}

#endif
