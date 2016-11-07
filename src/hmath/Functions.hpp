#ifndef __hmath_Functions__
#define __hmath_Functions__

#include <cmath>

namespace hm {

inline float clamp( float val, float min, float max ) {
	if( val < min ) {
		return min;
	}
	if( val > max ) {
		return max;
	}
	return val;
}

inline float clamp01( float val ) {
	return clamp(val, 0.0f, 1.0f);
}

inline float minimum( float a, float b ) {
	return (a < b) ? a : b;
}

inline float maximum( float a, float b ) {
	return (a > b) ? a : b;
}

inline float wrapAngle( float angle, float min, float max ) {
	return fmodf(fmodf(angle - min, max - min) + (max - min), max - min) + min;
}

}

#endif
