// NOTE: Almost directly taken from GteGaussianElimination.h in GeometricTools' math library.

#ifndef __hmath_GaussianElimination__
#define __hmath_GaussianElimination__

#include <vector>
#include <cmath>

namespace hm {

class GaussianElimination {
public:
	bool operator()( int numRows,
		const float* M, float* inverseM, float& determinant,
		const float* B, float* X,
		const float* C, int numCols, float* Y ) const;

private:
	void set( int numElements, const float* source, float* target ) const;
	inline float& valueAt( int numCols, int r, int c, float* matrix ) const;
};

bool GaussianElimination::operator()( int numRows, const float* M, float* inverseM, float& determinant, const float* B, float* X, const float* C, int numCols, float* Y ) const {
	if( numRows <= 0 || !M || ((B != nullptr) != (X != nullptr)) || ((C != nullptr) != (Y != nullptr)) || (C != nullptr && numCols < 1) ) {
		// invalid input
		return false;
	}

	int numElements = numRows * numRows;
	bool wantInverse = (inverseM != nullptr);
	std::vector<float> localInverseM;

	if( !wantInverse ) {
		localInverseM.resize(numElements);
		inverseM = localInverseM.data();
	}
	set(numElements, M, inverseM);

	if( B ) {
		set(numRows, B, X);
	}

	if( C ) {
		set(numRows * numCols, C, Y);
	}

	std::vector<int> colIndex(numRows), rowIndex(numRows), pivoted(numRows);
	std::fill(pivoted.begin(), pivoted.end(), 0);

	const float zero = 0.0f;
	const float one = 1.0f;
	bool odd = false;
	determinant = one;

	// Elimination by full pivoting.
	int i1, i2, row = 0, col = 0;
	for( int i0 = 0; i0 < numRows; ++i0 ) {
		// Search matrix (excluding pivoted rows) for maximum absolute entry.
		float maxValue = zero;
		for (i1 = 0; i1 < numRows; ++i1) {
			if( !pivoted[i1] ) {
				for( i2 = 0; i2 < numRows; ++i2 ) {
					if( !pivoted[i2] ) {
						float absValue = fabsf(valueAt(numRows, i1, i2, inverseM));
						if( absValue > maxValue ) {
							maxValue = absValue;
							row = i1;
							col = i2;
						}
					}
				}
			}
		}

		if( maxValue == zero ) {
			// The matrix is not invertible.
			if( wantInverse ) {
				set(numElements, nullptr, inverseM);
			}
			determinant = zero;

			if( B ) {
				set(numRows, nullptr, X);
			}

			if( C ) {
				set(numRows * numCols, nullptr, Y);
			}
			return false;
		}

		pivoted[col] = true;

		// Swap rows so that the pivot entry is in row 'col'.
		if( row != col ) {
			odd = !odd;
			for( int i = 0; i < numRows; ++i ) {
				std::swap(valueAt(numRows, row, i, inverseM), valueAt(numRows, col, i, inverseM));
			}

			if( B ) {
				std::swap(X[row], X[col]);
			}

			if( C ) {
				for( int i = 0; i < numCols; ++i ) {
					std::swap(valueAt(numRows, row, i, Y), valueAt(numRows, col, i, Y));
				}
			}
		}

		// Keep track of the permutations of the rows.
		rowIndex[i0] = row;
		colIndex[i0] = col;

		// Scale the row so that the pivot entry is 1.
		float diagonal = valueAt(numRows, col, col, inverseM);
		determinant *= diagonal;
		float inv = one / diagonal;
		valueAt(numRows, col, col, inverseM) = one;
		for( i2 = 0; i2 < numRows; ++i2 ) {
			valueAt(numRows, col, i2, inverseM) *= inv;
		}

		if( B ) {
			X[col] *= inv;
		}

		if( C ) {
			for( i2 = 0; i2 < numCols; ++i2 ) {
				valueAt(numRows, col, i2, Y) *= inv;
			}
		}

		// Zero out the pivot column locations in the other rows.
		for( i1 = 0; i1 < numRows; ++i1 ) {
			if( i1 != col ) {
				float save = valueAt(numRows, i1, col, inverseM);
				valueAt(numRows, i1, col, inverseM) = zero;
				for( i2 = 0; i2 < numRows; ++i2 ) {
					valueAt(numRows, i1, i2, inverseM) -= valueAt(numRows, col, i2, inverseM) * save;
				}

				if( B ) {
					X[i1] -= X[col] * save;
				}

				if( C ) {
					for( i2 = 0; i2 < numCols; ++i2 ) {
						valueAt(numRows, i1, i2, Y) -= valueAt(numRows, col, i2, Y) * save;
					}
				}
			}
		}
	}

	if( wantInverse ) {
		// Reorder rows to undo any permutations in Gaussian elimination.
		for( i1 = numRows - 1; i1 >= 0; --i1 ) {
			if( rowIndex[i1] != colIndex[i1] ) {
				for( i2 = 0; i2 < numRows; ++i2 ) {
					std::swap(valueAt(numRows, i2, rowIndex[i1], inverseM), valueAt(numRows, i2, colIndex[i1], inverseM));
				}
			}
		}
	}

	if( odd ) {
		determinant = -determinant;
	}

	return true;
}

float& GaussianElimination::valueAt( int numCols, int r, int c, float* matrix ) const {
	return matrix[c + numCols*r];
}

}

#endif
