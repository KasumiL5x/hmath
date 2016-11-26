//
// CONSTRUCTORS
//
template<int N>
Vector<N>::Vector() {
}

template<int N>
Vector<N>::Vector( const std::array<float, N>& values )
	: tuple_(values) {
}

template<int N>
Vector<N>::Vector( std::initializer_list<float> values ) {
	int i = 0;
	for( auto value : values ) {
		if( i < N ) {
			tuple_[i++] = value;
		} else {
			break;
		}
	}
	for( ; i < N; ++i ) {
		tuple_[i] = 0.0f;
	}
}


//
// ACCESSORS
//
template<int N>
float const& Vector<N>::operator[]( int index ) const {
	assert(index >= 0 && index < N);
	return tuple_[index];
}

template<int N>
float& Vector<N>::operator[]( int index ) {
	assert(index >= 0 && index < N);
	return tuple_[index];
}


//
// TUPLE OPERATIONS
//
template<int N>
void Vector<N>::makeOne() {
	std::fill(tuple_.begin(), tuple_.end(), 1.0f);
}

template<int N>
void Vector<N>::makeZero() {
	std::fill(tuple_.begin(), tuple_.end(), 0.0f);
}

template<int N>
void Vector<N>::makeUnit( int index ) {
	assert(index >= 0 && index < N);
	std::fill(tuple_.begin(), tuple_.end(), 0.0f);
	tuple_[index] = 1.0f;
}


//
// STATIC VECTORS
//
template<int N>
Vector<N> Vector<N>::zero() {
	Vector<N> vec;
	vec.makeZero();
	return vec;
}

template<int N>
Vector<N> Vector<N>::one() {
	Vector<N> vec;
	vec.makeOne();
	return vec;
}

template<int N>
Vector<N> Vector<N>::unit( int index ) {
	Vector<N> vec;
	vec.makeUnit(index);
	return vec;
}


//
// UNARY OPERATIONS
//
template<int N>
Vector<N> operator+( const Vector<N>& vec ) {
	return vec;
}

template<int N>
Vector<N> operator-( const Vector<N>& vec ) {
	Vector<N> result;
	for( int i = 0; i < N; ++i ) {
		result[i] = -vec[i];
	}
	return result;
}


//
// LINEAR-ALGEBRAIC OPERATIONS
//
template<int N>
Vector<N> operator+( const Vector<N>& v0, const Vector<N>& v1 ) {
	Vector<N> result = v0;
	return (result += v1);
}

template<int N>
Vector<N> operator-( const Vector<N>& v0, const Vector<N>& v1 ) {
	Vector<N> result = v0;
	return (result -= v1);
}

template<int N>
Vector<N> operator*( const Vector<N>& vec, float scalar ) {
	Vector<N> result = vec;
	return (result *= scalar);
}

template<int N>
Vector<N> operator*( float scalar, const Vector<N>& vec ) {
	Vector<N> result = vec;
	return (result *= scalar);
}

template<int N>
Vector<N> operator/( const Vector<N>& vec, float scalar ) {
	Vector<N> result = vec;
	return (result /= scalar);
}

template<int N>
Vector<N>& operator+=( Vector<N>& v0, const Vector<N>& v1 ) {
	for( int i = 0; i < N; ++i ) {
		v0[i] += v1[i];
	}
	return v0;
}

template<int N>
Vector<N>& operator-=( Vector<N>& v0, const Vector<N>& v1 ) {
	for( int i = 0; i < N; ++i ) {
		v0[i] -= v1[i];
	}
	return v0;
}

template<int N>
Vector<N>& operator*=( Vector<N>& vec, float scalar ) {
	for( int i = 0; i < N; ++i ) {
		vec[i] *= scalar;
	}
	return vec;
}

template<int N>
Vector<N>& operator/=( Vector<N>& vec, float scalar ) {
	if( scalar != 0.0f ) {
		const float inv = 1.0f / scalar;
		for( int i = 0; i < N; ++i ) {
			vec[i] *= inv;
		}
	} else {
		vec.makeZero();
	}
	return vec;
}


//
// COMPONENT ALGEBRAIC OPERATIONS
//
template<int N>
Vector<N> operator*( const Vector<N>& v0, const Vector<N>& v1 ) {
	Vector<N> result = v0;
	return (result *= v1);
}

template<int N>
Vector<N> operator/( const Vector<N>& v0, const Vector<N>& v1 ) {
	Vector<N> result = v0;
	return (result /= v1);
}

template<int N>
Vector<N>& operator*=( Vector<N>& v0, const Vector<N>& v1 ) {
	for( int i = 0; i < N; ++i ) {
		v0[i] *= v1[i];
	}
	return v0;
}

template<int N>
Vector<N>& operator/=( Vector<N>& v0, const Vector<N>& v1 ) {
	for( int i = 0; i < N; ++i ) {
		v0[i] /= v1[i];
	}
	return v0;
}


//
// GEOMETRIC OPERATIONS
//
template<int N>
float dot( const Vector<N>& v0, const Vector<N>& v1 ) {
	float dp = v0[0] * v1[0];
	for( int i = 1; i < N; ++i ) {
		dp += v0[i] * v1[i];
	}
	return dp;
}

template<int N>
float length( const Vector<N>& vec ) {
	return sqrtf(dot(vec, vec));
}

template<int N>
float lengthRobust( const Vector<N>& vec ) {
	float maxAbsComp = fabsf(vec[0]);
	for( int i = 1; i < N; ++i ) {
		const float absComp = fabsf(vec[i]);
		maxAbsComp = absComp > maxAbsComp ? absComp : maxAbsComp;
	}

	float length;
	if( maxAbsComp > 0.0f ) {
		const Vector<N> scaled = vec / maxAbsComp;
		length = maxAbsComp * sqrtf(dot(scaled, scaled));
	} else {
		length = 0.0f;
	}
	return length;
}

template<int N>
float sqrLength( const Vector<N>& vec ) {
	return dot(vec, vec);
}

template<int N>
float normalize( Vector<N>& vec ) {
	const float length = sqrtf(dot(vec, vec));
	if( length > 0.0f ) {
		vec /= length;
	} else {
		vec.makeZero();
	}
	return length;
}

template<int N>
float normalizeRobust( Vector<N>& vec ) {
	float maxAbsComp = fabsf(vec[0]);
	for( int i = 1; i < N; ++i ) {
		const float absComp = fabsf(vec[i]);
		maxAbsComp = absComp > maxAbsComp ? absComp : maxAbsComp;
	}

	float length;
	if( maxAbsComp > 0.0f ) {
		vec /= maxAbsComp;
		length = sqrtf(dot(vec, vec));
		vec /= length;
		length *= maxAbsComp;
	} else {
		length = 0.0f;
		vec.makeZero();
	}
	return length;
}

template<int N>
float distance( const Vector<N>& v0, const Vector<N>& v1 ) {
	return length(v0 - v1);
}

template<int N>
float sqrDistance( const Vector<N>& v0, const Vector<N>& v1 ) {
	return sqrLength(v0 - v1);
}

template<int N>
Vector<N> minimum( const Vector<N>& v0, const Vector<N>& v1 ) {
	Vector<N> result;
	for( int i = 0; i < N; ++i ) {
		result[i] = v0[i] < v1[i] ? v0[i] : v1[i];
	}
	return result;
}

template<int N>
Vector<N> maximum( const Vector<N>& v0, const Vector<N>& v1 ) {
	Vector<N> result;
	for( int i = 0; i < N; ++i ) {
		result[i] = v0[i] > v1[i] ? v0[i] : v1[i];
	}
	return result;
}

template<int N>
bool approximately( const Vector<N>& v0, const Vector<N>& v1 ) {
	return sqrLength(v0 - v1) < Epsilon;
}

template<int N>
Vector<N> lerp( const Vector<N>& v0, const Vector<N>& v1, float t ) {
	Vector<N> result;
	for( int i = 0; i < N; ++i ) {
		result[i] = v0[i] + (v1[i] - v0[i]) * t;
	}
	return result;
}

template<int N>
Vector<N> lerpClamped( const Vector<N>& v0, const Vector<N>& v1, float t ) {
	t = clamp01(t);
	Vector<N> result;
	for( int i = 0; i < N; ++i ) {
		result[i] = v0[i] + (v1[i] - v0[i]) * t;
	}
	return result;
}

template<int N>
Vector<N> reflect( const Vector<N>& direction, const Vector<N>& normal ) {
	Vector<N> result = ((-2.0f * dot(normal, direction)) * normal) + direction;
	return result;
}

template<int N>
Vector<N+1> lift( const Vector<N>& vec, float last ) {
	Vector<N+1> result;
	for( int i = 0; i < N; ++i ) {
		result[i] = vec[i];
	}
	result[N] = last;
	return result;
}

template<int N>
Vector<N-1> project( const Vector<N>& vec ) {
	static_assert(N >= 2, "Invalid vector dimension.");
	Vector<N-1> result;
	for( int i = 0; i < N - 1; ++i ) {
		result[i] = vec[i];
	}
	return result;
}
