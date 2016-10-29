#ifndef __hmath_Vector3__
#define __hmath_Vector3__

#include <array>
#include <initializer_list>

namespace hmath {

class Vector3 {
	public:
		Vector3();
		Vector3( const std::array<float, 3>& values );
		Vector3( std::initializer_list<float> values );

	protected:
		std::array<float, 3> tuple_;
};

#include "Vector3.inl"

}

#endif
