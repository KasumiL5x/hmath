template<int N>
Vector<N> cross( const Vector<N>& v0, const Vector<N>& v1 ) {
	static_assert(3==N || 4==N, "Dimension must be 3 or 4.");

	Vector<N> result;
	result.makeZero();
	result[0] = v0[1] * v1[2] - v0[2] * v1[1];
	result[1] = v0[2] * v1[0] - v0[0] * v1[2];
	result[2] = v0[0] * v1[1] - v0[1] * v1[0];
	return result;
}

template<int N>
Vector<N> crossUnit( const Vector<N>& v0, const Vector<N>& v1 ) {
	static_assert(3==N || 4==N, "Dimension must be 3 or 4.");
	Vector<N> result = cross(v0, v1);
	normalize(result);
	return result;
}

template<int N>
Vector<N> crossUnitRobust( const Vector<N>& v0, const Vector<N>& v1 ) {
	static_assert(3==N || 4==N, "Dimension must be 3 or 4.");
	Vector<N> result = cross(v0, v1);
	normalizeRobust(result);
	return result;
}
