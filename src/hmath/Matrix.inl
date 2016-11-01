template<int Rows, int Cols>
Matrix<Rows, Cols>::Matrix() {
	// uninitialized
}

template<int Rows, int Cols>
Matrix<Rows, Cols>::Matrix( const std::array<float, Rows*Cols>& values ) {
	for( int r=0, i=0; r < Rows; ++r ) {
		for( int c=0; c < Cols; ++c, ++i ) {
			set(r, c, values[i]);
		}
	}
}

template<int Rows, int Cols>
Matrix<Rows, Cols>::Matrix( std::initializer_list<float> values ) {
	const int numValues = static_cast<int>(values.size());
	auto iter = values.begin();
	int r, c, i;
	for( r=0, i=0; r < Rows; ++r ) {
		for( c=0; c < Cols; ++c, ++i ) {
			if( i < numValues ) {
				set(r, c, *iter++);
			} else {
				break;
			}
		}

		if( c < Cols ) {
			for( ; c < Cols; ++c ) {
				set(r, c, 0.0f);
			}
			++r;
			break;
		}
	}

	if( r < Rows ) {
		for( ; r < Rows; ++r ) {
			for( c=0; c < Cols; ++c ) {
				set(r, c, 0.0f);
			}
		}
	}
}

template<int Rows, int Cols>
float const& Matrix<Rows, Cols>::operator()( int r, int c ) const {
	assert((r >= 0 && r < Rows) && "Row out of bounds in Matrix() operator.");
	assert((c >= 0 && c < Cols) && "Col out of bounds in Matrix() operator.");
	return get(r, c);
}

template<int Rows, int Cols>
float& Matrix<Rows, Cols>::operator()( int r, int c ) {
	assert((r >= 0 && r < Rows) && "Row out of bounds in Matrix() operator.");
	assert((c >= 0 && c < Cols) && "Col out of bounds in Matrix() operator.");
	return get(r, c);
}

template<int Rows, int Cols>
float const& Matrix<Rows, Cols>::operator[]( int index ) const {
	assert((index >= 0 && index < Rows*Cols) && "Index out of bounds in Matrix[] operator.");
	float const* el = &data_[0][0];
	return el[index];
}

template<int Rows, int Cols>
float& Matrix<Rows, Cols>::operator[]( int index ) {
	assert((index >= 0 && index < Rows*Cols) && "Index out of bounds in Matrix[] operator.");
	float* el = &data_[0][0];
	return el[index];
}

template<int Rows, int Cols>
float const& Matrix<Rows, Cols>::get( int row, int col ) const {
	assert((row >= 0 && row < Rows) && "Row out of bounds in Matrix() operator.");
	assert((col >= 0 && col < Cols) && "Col out of bounds in Matrix() operator.");
	return data_[row][col];
}

template<int Rows, int Cols>
float& Matrix<Rows, Cols>::get( int row, int col ) {
	assert((row >= 0 && row < Rows) && "Row out of bounds in Matrix() operator.");
	assert((col >= 0 && col < Cols) && "Col out of bounds in Matrix() operator.");
	return data_[row][col];
}

template<int Rows, int Cols>
void Matrix<Rows, Cols>::set( int row, int col, float value ) {
	assert((row >= 0 && row < Rows) && "Row out of bounds in Matrix() operator.");
	assert((col >= 0 && col < Cols) && "Col out of bounds in Matrix() operator.");
	data_[row][col] = value;
}
