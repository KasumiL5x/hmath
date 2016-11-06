Matrix3x3 inverse( const Matrix3x3& M, bool* isInvertible ) {
	Matrix3x3 inv;
	bool invertible;
	const float c00 = M(1, 1)*M(2, 2) - M(1, 2)*M(2, 1);
	const float c10 = M(1, 2)*M(2, 0) - M(1, 0)*M(2, 2);
	const float c20 = M(1, 0)*M(2, 1) - M(1, 1)*M(2, 0);
	const float det = M(0, 0)*c00 + M(0, 1)*c10 + M(0, 2)*c20;
	if( det != 0.0f ) {
		const float invDet = 1.0f / det;
		inv = Matrix3x3 {
				c00*invDet,
				(M(0, 2)*M(2, 1) - M(0, 1)*M(2, 2))*invDet,
				(M(0, 1)*M(1, 2) - M(0, 2)*M(1, 1))*invDet,
				c10*invDet,
				(M(0, 0)*M(2, 2) - M(0, 2)*M(2, 0))*invDet,
				(M(0, 2)*M(1, 0) - M(0, 0)*M(1, 2))*invDet,
				c20*invDet,
				(M(0, 1)*M(2, 0) - M(0, 0)*M(2, 1))*invDet,
				(M(0, 0)*M(1, 1) - M(0, 1)*M(1, 0))*invDet
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

float determinant( const Matrix3x3& M ) {
	const float c00 = M(1, 1)*M(2, 2) - M(1, 2)*M(2, 1);
	const float c10 = M(1, 2)*M(2, 0) - M(1, 0)*M(2, 2);
	const float c20 = M(1, 0)*M(2, 1) - M(1, 1)*M(2, 0);
	const float det = M(0, 0)*c00 + M(0, 1)*c10 + M(0, 2)*c20;
	return det;
}
