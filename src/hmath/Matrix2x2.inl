void makeRotation( float angle, Matrix2x2& rotation ) {
	const float c = cosf(angle);
	const float s = sinf(angle);
	rotation(0, 0) =  c;
	rotation(0, 1) = -s;
	rotation(1, 0) =  s;
	rotation(1, 1) =  c;
}

float getRotationAngle( const Matrix2x2& rotation ) {
	return atan2f(rotation(1, 0), rotation(0, 0));
}

Matrix2x2 inverse( const Matrix2x2& M, bool* isInvertible ) {
	Matrix2x2 inv;
	bool invertible;
	const float det = M(0, 0)*M(1, 1) - M(0, 1)*M(1, 0);
	if( det != 0.0f ) {
		const float invDet = 1.0f / det;
		inv = Matrix2x2 {
				 M(1, 1)*invDet, -M(0, 1)*invDet,
				-M(1, 0)*invDet,  M(0, 0)*invDet
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

float determinant( const Matrix2x2& M ) {
	return M(0, 0)*M(1, 1) - M(0, 1)*M(1, 0);
}
