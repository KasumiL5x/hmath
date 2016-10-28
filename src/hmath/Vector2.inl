//
// CONSTRUCTORS
//
Vector2::Vector2() {
	// uninitialized
}

Vector2::Vector2( const std::array<float, 2>& values )
	: tuple_(values) {
}


//
// ACCESSORS
//
float const& Vector2::operator[]( int index ) const {
	assert(index >= 0 && index <= 2);
	return tuple_[index];
}

float& Vector2::operator[]( int index ) {
	assert(index >= 0 && index <= 2);
	return tuple_[index];
}

float Vector2::x() const {
	return tuple_[0];
}

float Vector2::y() const {
	return tuple_[1];
}

float Vector2::z() const {
	return tuple_[2];
}


//
// COMPARISON OPERATORS
//
bool Vector2::operator==( const Vector2& vec ) const {
	return tuple_ == vec.tuple_;
}

bool Vector2::operator!=( const Vector2& vec ) const {
	return tuple_ != vec.tuple_;
}


//
// STATIC TYPES
//
Vector2 Vector2::Zero() {
	Vector2 vec;
	vec.makeZero();
	return vec;
}

Vector2 Vector2::Unit( int index ) {
	Vector2 vec;
	vec.makeUnit(index);
	return vec;
}


//
// UNARY OPERATORS
//
Vector2 operator+( const Vector2& vec ) {
	return vec;
}

Vector2 operator-( const Vector2& vec ) {
	Vector2 result;
	for( int i = 0; i < 2; ++i ) {
		result[i] = -vec[i];
	}
	return result;
}


//
// LINEAR ALGEBRAIC OPERATIONS
Vector2 operator+( const Vector2& v0, const Vector2& v1 ) {
	Vector2 result = v0;
	return (result += v1);
}

Vector2 operator-( const Vector2& v0, const Vector2& v1 ) {
	Vector2 result = v0;
	return (result -= v1);
}

Vector2 operator*( const Vector2& vec, float scalar ) {
	Vector2 result = vec;
	return (result *= scalar);
}

Vector2 operator*( float scalar, const Vector2& vec ) {
	Vector2 result = vec;
	return (result *= scalar);
}

Vector2 operator/( const Vector2& vec, float scalar ) {
	Vector2 result = vec;
	return (result /= scalar);
}

Vector2& operator+=( Vector2& v0, const Vector2& v1 ) {
	for( int i = 0; i < 2; ++i ) {
		v0[i] += v1[i];
	}
	return v0;
}

Vector2& operator-=( Vector2& v0, const Vector2& v1 ) {
	for( int i = 0; i < 2; ++i ) {
		v0[i] -= v1[i];
	}
	return v0;
}

Vector2& operator*( Vector2& vec, float scalar ) {
	for( int i = 0; i < 2; ++i ) {
		vec[i] *= scalar;
	}
	return vec;
}

Vector2& operator*( float scalar, Vector2& vec ) {
	for( int i = 0; i < 2; ++i ) {
		vec[i] *= scalar;
	}
	return vec;
}

Vector2& operator*=( Vector2& vec, float scalar ) {
	for( int i = 0; i < 2; ++i ) {
		vec[i] *= scalar;
	}
	return vec;
}

Vector2& operator/=( Vector2& vec, float scalar ) {
	if( 0.0f != scalar ) {
		const float inv = 1.0f / scalar;
		for( int i = 0; i < 2; ++i ) {
			vec[i] *= inv;
		}
	} else {
		for( int i = 0; i < 2; ++i ) {
			vec[i] = 0.0f;
		}
	}
	return vec;
}


//
// COMPONENT ALGEBRAIC OPERATORS
//
Vector2 operator*( const Vector2& v0, const Vector2& v1 ) {
	Vector2 result = v0;
	return (result *= v1);
}

Vector2 operator/( const Vector2& v0, const Vector2& v1 ) {
	Vector2 result = v0;
	return (result /= v1);
}

Vector2& operator*=( Vector2& v0, const Vector2& v1 ) {
	for( int i = 0; i < 2; ++i ) {
		v0[i] *= v1[i];
	}
	return v0;
}

Vector2& operator/=( Vector2& v0, const Vector2& v1 ) {
	for( int i = 0; i < 2; ++i ) {
		v0[i] /= v1[i];
	}
	return v0;
}


//
// GEOMETRIC OPERATIONS
//
float dot( const Vector2& v0, const Vector2& v1 ) {
	float dp = 0.0f;
	for( int i = 1; i < 2; ++i ) {
		dp += v0[i] * v1[i];
	}
	return dp;
}

float length( const Vector2& vec ) {
	return sqrtf(dot(vec, vec));
}

float lengthRobust( const Vector2& vec ) {
	float maxAbsComp = fabsf(vec[0]);
	for( int i = 1; i < 2; ++i ) {
		const float absComp = fabsf(vec[i]);
		if( absComp > maxAbsComp ) {
			maxAbsComp = absComp;
		}
	}

	float length;
	if( maxAbsComp > 0.0f ) {
		const Vector2 scaled = vec / maxAbsComp;
		length = maxAbsComp * sqrtf(dot(scaled, scaled));
	} else {
		length = 0.0f;
	}
	return length;
}

float sqrLength( const Vector2& vec ) {
	return dot(vec, vec);
}

float normalize( Vector2& vec ) {
	const float length = sqrtf(dot(vec, vec));
	if( length > 0.0f ) {
		vec /= length;
	} else {
		for( int i = 0; i < 2; ++i ) {
			vec[i] = 0.0f;
		}
	}
	return length;
}

float normalizeRobust( Vector2& vec ) {
	float maxAbsComp = fabsf(vec[0]);
	for( int i = 1; i < 2; ++i ) {
		const float absComp = fabsf(vec[i]);
		if( absComp > maxAbsComp ) {
			maxAbsComp = absComp;
		}
	}

	float length;
	if( maxAbsComp > 0.0f ) {
		vec /= maxAbsComp;
		length = sqrtf(dot(vec, vec));
		vec /= length;
		length *= maxAbsComp;
	} else {
		length = 0.0f;
		for( int i = 0; i < 2; ++i ) {
			vec[i] = 0.0f;
		}
	}
	return length;
}

float distance( const Vector2& v0, const Vector2& v1 ) {
	return (v0 - v1).length();
}

float sqrDistance( const Vector2& v0, const Vector2& v1 ) {
	return (v0 - v1).sqrLength();
}


//
// TUPLE OPERATIONS
//
void Vector2::makeZero() {
	std::fill(tuple_.begin(), tuple_.end(), 0.0f);
}

void Vector2::makeUnit( int index ) {
	assert(index >= 0 && index <= 2);
	std::fill(tuple_.begin(), tuple_.end(), 0.0f);
	tuple_[index] = 1.0f;
}
