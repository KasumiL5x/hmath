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
