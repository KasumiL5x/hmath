//
// CONSTRUCTORS
//
Vector3::Vector3() {
	// uninitialized
}

Vector3::Vector3( const std::array<float, 3>& values )
	: tuple_(values) {
}

Vector3::Vector3( std::initializer_list<float> values ) {
	int i = 0;
	for( auto val : values ) {
		if( i < 3 ) {
			tuple_[i++] = val;
		} else {
			break;
		}
	}
	for( ; i < 3; ++i ) {
		tuple_[i] = 0.0f;
	}
}

