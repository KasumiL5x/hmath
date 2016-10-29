#ifndef __hmath_Functions__
#define __hmath_Functions__

namespace hm {

inline float clamp01( float val ) {
	if( val < 0.0f ) {
		return 0.0f;
	}
	if( val > 1.0f ) {
		return 1.0f;
	}
	return val;
}

inline float minimum( float a, float b ) {
	return (a < b) ? a : b;
}

inline float maximum( float a, float b ) {
	return (a > b) ? a : b;
}

}

#endif
