//
// CONSTRUCTORS
//
Vector2::Vector2() {
	// uninitialized
}

Vector2::Vector2( const std::array<float, 2>& values )
	: tuple_(values) {
}

Vector2::Vector2( std::initializer_list<float> values ) {
	int i = 0;
	for( auto val : values ) {
		if( i < 2 ) {
			tuple_[i++] = val;
		} else {
			break;
		}
	}
	for( ; i < 2; ++i ) {
		tuple_[i] = 0.0f;
	}
}


//
// ACCESSORS
//
float const& Vector2::operator[]( int index ) const {
	assert(index >= 0 && index <= 1);
	return tuple_[index];
}

float& Vector2::operator[]( int index ) {
	assert(index >= 0 && index <= 1);
	return tuple_[index];
}

float Vector2::x() const {
	return tuple_[0];
}

float Vector2::y() const {
	return tuple_[1];
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
Vector2 Vector2::zero() {
	Vector2 vec;
	vec.makeZero();
	return vec;
}

Vector2 Vector2::one() {
	Vector2 vec;
	vec.makeOne();
	return vec;
}

Vector2 Vector2::left() {
	Vector2 vec;
	vec[0] = -1;
	vec[1] = 0;
	return vec;
}

Vector2 Vector2::right() {
	Vector2 vec;
	vec[0] = 1;
	vec[1] = 0;
	return vec;
}


Vector2 Vector2::up() {
	Vector2 vec;
	vec[0] = 0;
	vec[1] = 1;
	return vec;
}

Vector2 Vector2::down() {
	Vector2 vec;
	vec[0] = 0;
	vec[1] = -1;
	return vec;
}

Vector2 Vector2::unit( int index ) {
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
	result[0] = -vec[0];
	result[1] = -vec[1];
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
	v0[0] += v1[0];
	v0[1] += v1[1];
	return v0;
}

Vector2& operator-=( Vector2& v0, const Vector2& v1 ) {
	v0[0] -= v1[0];
	v0[1] -= v1[1];
	return v0;
}

Vector2& operator*=( Vector2& vec, float scalar ) {
	vec[0] *= scalar;
	vec[1] *= scalar;
	return vec;
}

Vector2& operator/=( Vector2& vec, float scalar ) {
	if( 0.0f != scalar ) {
		const float inv = 1.0f / scalar;
		vec[0] *= inv;
		vec[1] *= inv;
	} else {
		vec[0] = vec[1] = 0.0f;
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
	v0[0] *= v1[0];
	v0[1] *= v1[1];
	return v0;
}

Vector2& operator/=( Vector2& v0, const Vector2& v1 ) {
	v0[0] /= v1[0];
	v0[1] /= v1[1];
	return v0;
}


//
// GEOMETRIC OPERATIONS
//
float dot( const Vector2& v0, const Vector2& v1 ) {
	float dp = (v0[0] * v1[0]) + v0[1] * v1[1];
	return dp;
}

float length( const Vector2& vec ) {
	return sqrtf(dot(vec, vec));
}

float lengthRobust( const Vector2& vec ) {
	const float abs_x = fabsf(vec[0]);
	const float abs_y = fabsf(vec[1]);
	const float maxAbsComp = abs_x > abs_y ? abs_x : abs_y;

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
		vec[0]=vec[1] = 0.0f;
	}
	return length;
}

float normalizeRobust( Vector2& vec ) {
	const float abs_x = fabsf(vec[0]);
	const float abs_y = fabsf(vec[1]);
	const float maxAbsComp = abs_x > abs_y ? abs_x : abs_y;

	float length;
	if( maxAbsComp > 0.0f ) {
		vec /= maxAbsComp;
		length = sqrtf(dot(vec, vec));
		vec /= length;
		length *= maxAbsComp;
	} else {
		length = 0.0f;
		vec[0]=vec[1] = 0.0f;
	}
	return length;
}

float distance( const Vector2& v0, const Vector2& v1 ) {
	return length(v0 - v1);
}

float sqrDistance( const Vector2& v0, const Vector2& v1 ) {
	return sqrLength(v0 - v1);
}

Vector2 lerp( const Vector2& v0, const Vector2& v1, float t ) {
	Vector2 result;
	result[0] = v0[0] + (v1[0] - v0[0]) * t;
	result[1] = v0[1] + (v1[1] - v0[1]) * t;
	return result;
}

Vector2 lerpClamped( const Vector2& v0, const Vector2& v1, float t ) {
	t = clamp01(t);
	Vector2 result;
	result[0] = v0[0] + (v1[0] - v0[0]) * t;
	result[1] = v0[1] + (v1[1] - v0[1]) * t;
	return result;
}

Vector2 minimum( const Vector2& v0, const Vector2& v1 ) {
	Vector2 result;
	result[0] = minimum(v0[0], v1[0]);
	result[1] = minimum(v0[1], v1[1]);
	return result;
}

Vector2 maximum( const Vector2& v0, const Vector2& v1 ) {
	Vector2 result;
	result[0] = maximum(v0[0], v1[0]);
	result[1] = maximum(v0[1], v1[1]);
	return result;
}

bool approximately( const Vector2& v0, const Vector2& v1 ) {
	return sqrLength(v0 - v1) < Epsilon;
}

Vector2 reflect( const Vector2& direction, const Vector2& normal ) {
	Vector2 result = ((-2.0f * dot(normal, direction)) * normal) + direction;
	return result;
}

//
// TUPLE OPERATIONS
//
void Vector2::makeZero() {
	std::fill(tuple_.begin(), tuple_.end(), 0.0f);
}

void Vector2::makeOne() {
	std::fill(tuple_.begin(), tuple_.end(), 1.0f);
}

void Vector2::makeUnit( int index ) {
	assert(index >= 0 && index <= 1);
	std::fill(tuple_.begin(), tuple_.end(), 0.0f);
	tuple_[index] = 1.0f;
}
