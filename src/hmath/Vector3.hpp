#ifndef __hmath_Vector3__
#define __hmath_Vector3__

#include "Vector.hpp"

namespace hm {

using Vector3 = Vector<3>;

template<int N>
inline Vector<N> cross( const Vector<N>& v0, const Vector<N>& v1 );

template<int N>
inline Vector<N> crossUnit( const Vector<N>& v0, const Vector<N>& v1 );

template<int N>
inline Vector<N> crossUnitRobust( const Vector<N>& v0, const Vector<N>& v1 );

#include "Vector3.inl"

}

#endif
