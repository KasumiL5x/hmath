#ifndef __mathhelper__
#define __mathhelper__

#include <cmath>
#include <hmath/Vector2.hpp>

namespace MathHelper {

static hm::Vector2 vec2FromAngle( float degrees ) {
	const float radians = degrees * 0.0174532924f;
	return {cosf(radians), sinf(radians)};
}

static float dotToDegrees( float dp ) {
	return acosf(dp) * 57.29578f;
}

}

#endif