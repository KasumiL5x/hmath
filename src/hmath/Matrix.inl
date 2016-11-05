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


template<int Rows, int Cols>
void Matrix<Rows, Cols>::makeZero() {
	std::fill(data_.begin(), data_.end(), 0.0f);
}

template<int Rows, int Cols>
void Matrix<Rows, Cols>::makeIdentity() {
	makeZero();
	const int numDiagonal = (Rows <= Cols ? Rows : Cols);
	for( int i=0; i < numDiagonal; ++i ) {
		set(i, i, 1.0f);
	}
}

template<int Rows, int Cols>
Matrix<Rows, Cols> Matrix<Rows, Cols>::zero() {
	Matrix m;
	m.makeZero();
	return m;
}

template<int Rows, int Cols>
Matrix<Rows, Cols> Matrix<Rows, Cols>::identity() {
	Matrix m;
	m.makeIdentity();
	return m;
}


template<int N> 
Matrix<N, N> inverse( const Matrix<N, N>& M, bool* canInverse=nullptr ) {
	Matrix<N, N> invM;
	float determinant;
	bool invertible = GaussianElimination()(N, &M[0], &invM[0], determinant, nullptr, nullptr, nullptr, 0, nullptr);
	if( canInverse ) {
		*canInverse = invertible;
	}
	return invM;
}

template<int N>
float determinant( const Matrix<N, N>& M ) {
	float determinant;
	GaussianElimination()(N, &M[0], nullptr, determinant, nullptr, nullptr, nullptr, 0, nullptr);
	return determinant;
}

template<int Rows, int Cols>
Matrix<Rows, Cols> transpose( const Matrix<Rows, Cols>& M ) {
	Matrix<Cols, Rows> result;
	for( int r = 0; r < Rows; ++r ) {
		for( int c = 0; c < Cols; ++c ) {
			result(c, r) = M(r, c);
		}
	}
	return result;
}

template<int Rows, int Cols>
Vector<Rows> operator*( const Matrix<Rows, Cols>& M, const Vector<Cols>& V ) {
	Vector<Rows> result;
	for( int r = 0; r < Rows; ++r ) {
		result[r] = 0.0f;
		for( int c = 0; c < Cols; ++c ) {
			result[r] += M(r, c) * V[c];
		}
	}
	return result;
}

template<int Rows, int Cols>
Vector<Cols> operator*( const Vector<Rows>& V, const Matrix<Rows, Cols>& M ) {
	Vector<Cols> result;
	for( int c = 0; c < Cols; ++c ) {
		result[c] = 0.0f;
		for( int r = 0; r < Rows; ++r ) {
			result[c] += V[r] * M(r, c);
		}
	}
	return result;
}

template<int Rows, int Cols, int Common>
Matrix<Rows, Cols> operator*( const Matrix<Rows, Cols>& A, const Matrix<Rows, Cols>& B ) {
	Matrix<Rows, Cols> result;
	for( int r = 0; r < Rows; ++r ) {
		for( int c = 0; c < Cols; ++c ) {
			result(r, c) = 0.0f;
			for( int i = 0; i < Common; ++i ) {
				result(r, c) += A(r, i) * B(i, c);
			}
		}
	}
	return result;
}

template<int N>
Matrix<N+1, N+1> lift( const Matrix<N, N>& M ) {
	Matrix<N+1, N+1> result;
	result.makeIdentity();
	for( int r = 0; r < N; ++r ) {
		for( int c = 0; c < N; ++c ) {
			result(r, c) = M(r, c);
		}
	}
	return result;
}

template<int N>
Matrix<N-1, N-1> project( const Matrix<N, N>& M ) {
	static_assert(N >= 2, "Invalid matrix dimension.");
	Matrix<N-1, N-1> result;
	for( int r = 0; r < N - 1; ++r ) {
		for( int c = 0; c < N - 1; ++c ) {
			result(r, c) = M(r, c);
		}
	}
	return result;
}
