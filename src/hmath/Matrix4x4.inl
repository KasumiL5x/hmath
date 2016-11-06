Matrix4x4 inverse( const Matrix4x4& M, bool* isInvertible ) {
	Matrix4x4 inv;
	bool invertible;
	const float a0 = M(0, 0) * M(1, 1) - M(0, 1) * M(1, 0);
	const float a1 = M(0, 0) * M(1, 2) - M(0, 2) * M(1, 0);
	const float a2 = M(0, 0) * M(1, 3) - M(0, 3) * M(1, 0);
	const float a3 = M(0, 1) * M(1, 2) - M(0, 2) * M(1, 1);
	const float a4 = M(0, 1) * M(1, 3) - M(0, 3) * M(1, 1);
	const float a5 = M(0, 2) * M(1, 3) - M(0, 3) * M(1, 2);
	const float b0 = M(2, 0) * M(3, 1) - M(2, 1) * M(3, 0);
	const float b1 = M(2, 0) * M(3, 2) - M(2, 2) * M(3, 0);
	const float b2 = M(2, 0) * M(3, 3) - M(2, 3) * M(3, 0);
	const float b3 = M(2, 1) * M(3, 2) - M(2, 2) * M(3, 1);
	const float b4 = M(2, 1) * M(3, 3) - M(2, 3) * M(3, 1);
	const float b5 = M(2, 2) * M(3, 3) - M(2, 3) * M(3, 2);
	const float det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
	if( det != 0.0f ) {
		const float invDet = 1.0f / det;
		inv = Matrix4x4 {
				(+M(1, 1) * b5 - M(1, 2) * b4 + M(1, 3) * b3) * invDet,
				(-M(0, 1) * b5 + M(0, 2) * b4 - M(0, 3) * b3) * invDet,
				(+M(3, 1) * a5 - M(3, 2) * a4 + M(3, 3) * a3) * invDet,
				(-M(2, 1) * a5 + M(2, 2) * a4 - M(2, 3) * a3) * invDet,
				(-M(1, 0) * b5 + M(1, 2) * b2 - M(1, 3) * b1) * invDet,
				(+M(0, 0) * b5 - M(0, 2) * b2 + M(0, 3) * b1) * invDet,
				(-M(3, 0) * a5 + M(3, 2) * a2 - M(3, 3) * a1) * invDet,
				(+M(2, 0) * a5 - M(2, 2) * a2 + M(2, 3) * a1) * invDet,
				(+M(1, 0) * b4 - M(1, 1) * b2 + M(1, 3) * b0) * invDet,
				(-M(0, 0) * b4 + M(0, 1) * b2 - M(0, 3) * b0) * invDet,
				(+M(3, 0) * a4 - M(3, 1) * a2 + M(3, 3) * a0) * invDet,
				(-M(2, 0) * a4 + M(2, 1) * a2 - M(2, 3) * a0) * invDet,
				(-M(1, 0) * b3 + M(1, 1) * b1 - M(1, 2) * b0) * invDet,
				(+M(0, 0) * b3 - M(0, 1) * b1 + M(0, 2) * b0) * invDet,
				(-M(3, 0) * a3 + M(3, 1) * a1 - M(3, 2) * a0) * invDet,
				(+M(2, 0) * a3 - M(2, 1) * a1 + M(2, 2) * a0) * invDet
		};
		invertible = true;
	} else {
		inv.makeZero();
		invertible = false;
	}

	if( isInvertible ) {
		*isInvertible = invertible;
	}
	return inv;
}


float determinant( const Matrix4x4& M ) {
	const float a0 = M(0, 0) * M(1, 1) - M(0, 1) * M(1, 0);
	const float a1 = M(0, 0) * M(1, 2) - M(0, 2) * M(1, 0);
	const float a2 = M(0, 0) * M(1, 3) - M(0, 3) * M(1, 0);
	const float a3 = M(0, 1) * M(1, 2) - M(0, 2) * M(1, 1);
	const float a4 = M(0, 1) * M(1, 3) - M(0, 3) * M(1, 1);
	const float a5 = M(0, 2) * M(1, 3) - M(0, 3) * M(1, 2);
	const float b0 = M(2, 0) * M(3, 1) - M(2, 1) * M(3, 0);
	const float b1 = M(2, 0) * M(3, 2) - M(2, 2) * M(3, 0);
	const float b2 = M(2, 0) * M(3, 3) - M(2, 3) * M(3, 0);
	const float b3 = M(2, 1) * M(3, 2) - M(2, 2) * M(3, 1);
	const float b4 = M(2, 1) * M(3, 3) - M(2, 3) * M(3, 1);
	const float b5 = M(2, 2) * M(3, 3) - M(2, 3) * M(3, 2);
	const float det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
	return det;
}

Matrix4x4 makeTranslation( float x, float y, float z ) {
	Matrix4x4 result;
	result.makeIdentity();
	result(3, 0) = x;
	result(3, 1) = y;
	result(3, 2) = z;
	return result;
}

Matrix4x4 makeTranslation( const Vector3& position ) {
	return makeTranslation(position[0], position[1], position[2]);
}

Matrix4x4 makeRotation( float angle, float x, float y, float z ) {
	const float c = cosf(angle);
	const float s = sinf(angle);
	const float t = 1.0f - c;

	Matrix4x4 result;

	result(0, 0) = t*x*x + c;
	result(0, 1) = t*x*y + z*s;
	result(0, 2) = t*x*z - y*s;
	result(0, 3) = 0.0f;

	result(1, 0) = t*x*y - z*s;
	result(1, 1) = t*y*y + c;
	result(1, 2) = t*y*z + x*s;
	result(1, 3) = 0.0f;

	result(2, 0) = t*x*z + y*s;
	result(2, 1) = t*y*z - x*s;
	result(2, 2) = t*z*z + c;
	result(2, 3) = 0.0f;

	result(3, 0) = 0.0f;
	result(3, 1) = 0.0f;
	result(3, 2) = 0.0f;
	result(3, 3) = 1.0f;

	return result;
}

Matrix4x4 makeRotation( float angle, const Vector3& axis ) {
	return makeRotation(angle, axis[0], axis[1], axis[2]);
}

Matrix4x4 makeScale( float x, float y, float z ) {
	Matrix4x4 result;
	result.makeIdentity();
	result(0, 0) = x;
	result(1, 1) = y;
	result(2, 2) = z;
	return result;
}

Matrix4x4 makeScale( const Vector3& scale ) {
	return makeScale(scale[0], scale[1], scale[2]);
}

Matrix4x4 makeOrthographic( float left, float right, float bottom, float top, float near, float far ) {
	Matrix4x4 result;
	result.makeIdentity();
	result(0, 0) =  2.0f / (right - left);
	result(1, 1) =  2.0f / (top - bottom);
	result(2, 2) = -2.0f / (far - near);
	result(3, 0) = -(right + left) / (right - left);
	result(3, 1) = -(top + bottom) / (top - bottom);
	result(3, 2) = -(far + near) / (far - near);
	return result;
}

Matrix4x4 makeFrustum( float left, float right, float bottom, float top, float near, float far ) {
	Matrix4x4 result;
	result.makeZero();
	result(0, 0) = (2.0f * near) / (right - left);
	result(1, 1) = (2.0f * near) / (top - bottom);
	result(2, 0) = (right + left) / (right - left);
	result(2, 1) = (top + bottom) / (top - bottom);
	result(2, 2) = -(far + near) / (far - near);
	result(2, 3) = -1.0f;
	result(3, 2) = -(2.0f * far * near) / (far - near);
	return result;
}

Matrix4x4 makePerspectiveLH( float fovY, float aspect, float near, float far ) {
	const float tanHalfFovY = tan(fovY * 0.5f);
	Matrix4x4 result;
	result.makeZero();
	result(0, 0) = 1.0f / (aspect * tanHalfFovY);
	result(1, 1) = 1.0f / (tanHalfFovY);
	result(2, 2) = -(far + near) / (far - near);
	result(2, 3) = -1.0f;
	result(3, 2) = -(2.0f * far * near) / (far - near);
	return result;
}

Matrix4x4 makePerspectiveRH( float fovY, float aspect, float near, float far ) {
	const float tanHalfFovY = tan(fovY * 0.5f);
	Matrix4x4 result;
	result.makeZero();
	result(0, 0) = 1.0f / (aspect * tanHalfFovY);
	result(1, 1) = 1.0f / (tanHalfFovY);
	result(2, 2) = -(far + near) / (far - near);
	result(2, 3) = -1.0f;
	result(3, 2) = -(2.0f * far * near) / (far - near);
	return result;
}

Matrix4x4 makeLookAtLH( const Vector3& eye, const Vector3& target, const Vector3& up ) {
	auto f = target - eye;
	normalize(f);
	auto s = cross(up, f);
	normalize(s);
	const auto u = cross(f, s);
	Matrix4x4 result;
	result.makeIdentity();
	result(0, 0) = s[0];
	result(1, 0) = s[1];
	result(2, 0) = s[2];
	result(0, 1) = u[0];
	result(1, 1) = u[1];
	result(2, 1) = u[2];
	result(0, 2) = f[0];
	result(1, 2) = f[1];
	result(2, 2) = f[2];
	result(3, 0) = -dot(s, eye);
	result(3, 1) = -dot(u, eye);
	result(3, 2) = -dot(f, eye);
	return result;
}

Matrix4x4 makeLookAtRH( const Vector3& eye, const Vector3& target, const Vector3& up ) {
	auto f = target - eye;
	normalize(f);
	auto s = cross(f, up);
	normalize(s);
	auto u = cross(s, f);
	Matrix4x4 result;
	result.makeIdentity();
	result(0, 0) = s[0];
	result(1, 0) = s[1];
	result(2, 0) = s[2];
	result(0, 1) = u[0];
	result(1, 1) = u[1];
	result(2, 1) = u[2];
	result(0, 2) =-f[0];
	result(1, 2) =-f[1];
	result(2, 2) =-f[2];
	result(3, 0) =-dot(s, eye);
	result(3, 1) =-dot(u, eye);
	result(3, 2) = dot(f, eye);
	return result;
}
