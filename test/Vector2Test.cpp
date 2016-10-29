#include "CppUnitTest.h"
#include <hmath/Vector2.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace hmath_test {

const static float Epsilon = 0.00001f;

TEST_CLASS(Vector2Test) {

public:
	TEST_METHOD(ArrayConstructor) {
		std::array<float, 2> values = {0.0f, 1.0f};
		hmath::Vector2 vec(values);
		Assert::AreEqual(0.0f, vec[0], Epsilon);
		Assert::AreEqual(1.0f, vec[1], Epsilon);
	}

	TEST_METHOD(InitializerListConstructor) {
		const float a = 1.0f;
		const float b = 2.0f;

		hmath::Vector2 vec = {a, b};
		Assert::AreEqual(a, vec[0], Epsilon);
		Assert::AreEqual(b, vec[1], Epsilon);

		hmath::Vector2 vec2 = {a};
		Assert::AreEqual(a,  vec2[0], Epsilon);
		Assert::AreEqual(0.0f, vec2[1], Epsilon);
	}

	TEST_METHOD(Accessors) {
		const float a = 2.0f;
		const float b = 3.0f;
		hmath::Vector2 vec = {a, b};
		Assert::AreEqual(a, vec[0], Epsilon);
		Assert::AreEqual(b, vec[1], Epsilon);
		//vec[-1]; // asserts
		//vec[2]; // asserts

		const hmath::Vector2 const_vec = {a, b};
		Assert::AreEqual(a, const_vec[0], Epsilon);
		Assert::AreEqual(b, const_vec[1], Epsilon);

		Assert::AreEqual(a, const_vec.x(), Epsilon);
		Assert::AreEqual(b, const_vec.y(), Epsilon);
	}

	TEST_METHOD(ComparisonOperators) {
		hmath::Vector2 a = {1.0f, 2.0f};
		hmath::Vector2 b = {1.0f, 2.0f};
		Assert::IsTrue(a == b);
		Assert::IsFalse(a != b);
	}

	TEST_METHOD(TupleOperators) {
		hmath::Vector2 vec;

		vec.makeZero();
		Assert::AreEqual(0.0f, vec[0], Epsilon);
		Assert::AreEqual(0.0f, vec[1], Epsilon);

		vec.makeOne();
		Assert::AreEqual(1.0f, vec[0], Epsilon);
		Assert::AreEqual(1.0f, vec[1], Epsilon);

		vec.makeUnit(0);
		Assert::AreEqual(1.0f, vec[0], Epsilon);
		Assert::AreEqual(0.0f, vec[1], Epsilon);
		vec.makeUnit(1);
		Assert::AreEqual(0.0f, vec[0], Epsilon);
		Assert::AreEqual(1.0f, vec[1], Epsilon);
		//vec.makeUnit(-1); // asserts
		//vec.makeUnit(2); // asserts
	}

	TEST_METHOD(Statics) {
		hmath::Vector2 zero = hmath::Vector2::zero();
		Assert::AreEqual(0.0f, zero[0], Epsilon);
		Assert::AreEqual(0.0f, zero[1], Epsilon);

		hmath::Vector2 one = hmath::Vector2::one();
		Assert::AreEqual(1.0f, one[0], Epsilon);
		Assert::AreEqual(1.0f, one[1], Epsilon);

		hmath::Vector2 left = hmath::Vector2::left();
		Assert::AreEqual(-1.0f, left[0], Epsilon);
		Assert::AreEqual(0.0f, left[1], Epsilon);

		hmath::Vector2 right = hmath::Vector2::right();
		Assert::AreEqual(1.0f, right[0], Epsilon);
		Assert::AreEqual(0.0f, right[1], Epsilon);

		hmath::Vector2 up = hmath::Vector2::up();
		Assert::AreEqual(0.0f, up[0], Epsilon);
		Assert::AreEqual(1.0f, up[1], Epsilon);

		hmath::Vector2 down = hmath::Vector2::down();
		Assert::AreEqual(0.0f, down[0], Epsilon);
		Assert::AreEqual(-1.0f, down[1], Epsilon);
	}

	TEST_METHOD(UnaryOperators) {
		const float a = 1.0f;
		const float b = 2.0f;
		const hmath::Vector2 vec = {a, b};

		const hmath::Vector2 pos = +vec;
		Assert::AreEqual(a, pos[0], Epsilon);
		Assert::AreEqual(b, pos[1], Epsilon);

		const hmath::Vector2 neg = -vec;
		Assert::AreEqual(-a, neg[0], Epsilon);
		Assert::AreEqual(-b, neg[1], Epsilon);
	}

	TEST_METHOD(LinearAlgebraOperations) {
		const float a = 1.0f;
		const float b = 2.0f;
		const float c = 3.0f;
		const float d = 4.0f;

		const hmath::Vector2 vec_a = {a, b};
		const hmath::Vector2 vec_b = {c, d};

		const hmath::Vector2 vec_add = vec_a + vec_b;
		Assert::AreEqual(a+c, vec_add[0], Epsilon);
		Assert::AreEqual(b+d, vec_add[1], Epsilon);

		const hmath::Vector2 vec_sub = vec_a - vec_b;
		Assert::AreEqual(a-c, vec_sub[0], Epsilon);
		Assert::AreEqual(b-d, vec_sub[1], Epsilon);

		const hmath::Vector2 vec_mul_scalar = vec_a * c;
		Assert::AreEqual(a*c, vec_mul_scalar[0], Epsilon);
		Assert::AreEqual(b*c, vec_mul_scalar[1], Epsilon);

		const hmath::Vector2 vec_mul_scalar2 = c * vec_a;
		Assert::AreEqual(a*c, vec_mul_scalar2[0], Epsilon);
		Assert::AreEqual(b*c, vec_mul_scalar2[1], Epsilon);

		const hmath::Vector2 vec_div_scalar = vec_a / c;
		Assert::AreEqual(a/c, vec_div_scalar[0], Epsilon);
		Assert::AreEqual(b/c, vec_div_scalar[1], Epsilon);

		hmath::Vector2 vec_plus_equals = {a, b};
		vec_plus_equals += {c, d};
		Assert::AreEqual(a+c, vec_plus_equals[0], Epsilon);
		Assert::AreEqual(b+d, vec_plus_equals[1], Epsilon);

		hmath::Vector2 vec_minus_equals = {a, b};
		vec_minus_equals -= {c, d};
		Assert::AreEqual(a-c, vec_minus_equals[0], Epsilon);
		Assert::AreEqual(b-d, vec_minus_equals[1], Epsilon);

		hmath::Vector2 vec_mul_equals = {a, b};
		vec_mul_equals *= c;
		Assert::AreEqual(a*c, vec_mul_equals[0], Epsilon);
		Assert::AreEqual(b*c, vec_mul_equals[1], Epsilon);

		hmath::Vector2 vec_div_equals = {a, b};
		vec_div_equals /= c;
		Assert::AreEqual(a/c, vec_div_equals[0], Epsilon);
		Assert::AreEqual(b/c, vec_div_equals[1], Epsilon);

		hmath::Vector2 vec_div_zero = {a, b};
		vec_div_zero /= 0.0f;
		Assert::AreEqual(0.0f, vec_div_zero[0], Epsilon);
		Assert::AreEqual(0.0f, vec_div_zero[1], Epsilon);
	}

	TEST_METHOD(ComponentAlgebraOperations) {
		const float a = 1.0f;
		const float b = 2.0f;
		const float c = 3.0f;
		const float d = 4.0f;

		const hmath::Vector2 vec_a = {a, b};
		const hmath::Vector2 vec_b = {c, d};

		// also tests vec *= vec
		const hmath::Vector2 mul = vec_a * vec_b;
		Assert::AreEqual(a*c, mul[0], Epsilon);
		Assert::AreEqual(b*d, mul[1], Epsilon);

		// also tests vec /= vec
		const hmath::Vector2 div = vec_a / vec_b;
		Assert::AreEqual(a/c, div[0], Epsilon);
		Assert::AreEqual(b/d, div[1], Epsilon);
	}

	TEST_METHOD(Dot) {
		const hmath::Vector2 vec_a = {12, 20};
		const hmath::Vector2 vec_b = {16, -5};
		Assert::AreEqual(92.0f, hmath::dot(vec_a, vec_b), Epsilon);
	}
	
	TEST_METHOD(Length) {
		const hmath::Vector2 vec = {12, 20};
		Assert::AreEqual(23.3238f, hmath::length(vec), Epsilon);
	}

	TEST_METHOD(LengthRobust) {
		const hmath::Vector2 vec = {12, 20};
		Assert::AreEqual(23.3238f, hmath::lengthRobust(vec), Epsilon);

		const hmath::Vector2 vec_zero = {0.0f, 0.0f};
		Assert::AreEqual(0.0f, hmath::lengthRobust(vec_zero), Epsilon);
	}

	TEST_METHOD(SqrLength) {
		const hmath::Vector2 vec = {12, 20};
		Assert::AreEqual(12*12+20*20, hmath::sqrLength(vec), Epsilon);
	}

	TEST_METHOD(Normalize) {
		hmath::Vector2 vec = {12, 20};

		const float preLen = hmath::normalize(vec);
		const float nrmLen = hmath::length(vec);
		Assert::AreEqual(23.3238f, preLen, Epsilon);
		Assert::AreEqual(1.0f, nrmLen, Epsilon);

		hmath::Vector2 zero = {0.0f, 0.0f};
		const float zeroPreLen = hmath::normalize(zero);
		const float zeroNrmLen = hmath::length(zero);
		Assert::AreEqual(0.0f, zeroPreLen, Epsilon);
		Assert::AreEqual(0.0f, zeroNrmLen, Epsilon);
		Assert::AreEqual(0.0f, zero[0], Epsilon);
		Assert::AreEqual(0.0f, zero[1], Epsilon);
	}

	TEST_METHOD(NormalizeRobust) {
		hmath::Vector2 vec = {12, 20};

		const float preLen = hmath::normalizeRobust(vec);
		const float nrmLen = hmath::length(vec);
		Assert::AreEqual(23.3238f, preLen, Epsilon);
		Assert::AreEqual(1.0f, nrmLen, Epsilon);

		hmath::Vector2 zero = {0.0f, 0.0f};
		const float zeroPreLen = hmath::normalizeRobust(zero);
		const float zeroNrmLen = hmath::length(zero);
		Assert::AreEqual(0.0f, zeroPreLen, Epsilon);
		Assert::AreEqual(0.0f, zeroNrmLen, Epsilon);
		Assert::AreEqual(0.0f, zero[0], Epsilon);
		Assert::AreEqual(0.0f, zero[1], Epsilon);
	}

	TEST_METHOD(Distance) {
		const hmath::Vector2 vec_a = {12, 20};
		const hmath::Vector2 vec_b = {16, -5};
		Assert::AreEqual(25.317978f, hmath::distance(vec_a, vec_b), Epsilon);
	}

	TEST_METHOD(SqrDistance) {
		const hmath::Vector2 vec_a = {12, 20};
		const hmath::Vector2 vec_b = {16, -5};
		// 641 = (16 + 625) = (4^2 + -25^2)
		Assert::AreEqual(641.0f, hmath::sqrDistance(vec_a, vec_b), Epsilon);
	}

	TEST_METHOD(Lerp){
		const float a = 0.0f;
		const float b = 0.0f;
		const float c = 1.0f;
		const float d = 2.0f;
		const hmath::Vector2 vec_a = {a, b};
		const hmath::Vector2 vec_b = {c, d};

		const hmath::Vector2 zero = hmath::lerp(vec_a, vec_b, 0.0f);
		Assert::AreEqual(a, zero[0], Epsilon);
		Assert::AreEqual(b, zero[1], Epsilon);

		const hmath::Vector2 one = hmath::lerp(vec_a, vec_b, 1.0f);
		Assert::AreEqual(c, one[0], Epsilon);
		Assert::AreEqual(d, one[1], Epsilon);

		const hmath::Vector2 half = hmath::lerp(vec_a, vec_b, 0.5f);
		Assert::AreEqual(c/2, half[0], Epsilon);
		Assert::AreEqual(d/2, half[1], Epsilon);

		const hmath::Vector2 dub = hmath::lerp(vec_a, vec_b, 2.0f);
		Assert::AreEqual(c*2, dub[0], Epsilon);
		Assert::AreEqual(d*2, dub[1], Epsilon);

		const hmath::Vector2 neg = hmath::lerp(vec_a, vec_b, -1.0f);
		Assert::AreEqual(-c, neg[0], Epsilon);
		Assert::AreEqual(-d, neg[1], Epsilon);
	}

	TEST_METHOD(LerpClamped) {
		const float a = 0.0f;
		const float b = 0.0f;
		const float c = 1.0f;
		const float d = 2.0f;
		const hmath::Vector2 vec_a = {a, b};
		const hmath::Vector2 vec_b = {c, d};

		const hmath::Vector2 zero = hmath::lerpClamped(vec_a, vec_b, 0.0f);
		Assert::AreEqual(a, zero[0], Epsilon);
		Assert::AreEqual(b, zero[1], Epsilon);

		const hmath::Vector2 one = hmath::lerpClamped(vec_a, vec_b, 1.0f);
		Assert::AreEqual(c, one[0], Epsilon);
		Assert::AreEqual(d, one[1], Epsilon);

		const hmath::Vector2 half = hmath::lerpClamped(vec_a, vec_b, 0.5f);
		Assert::AreEqual(c/2, half[0], Epsilon);
		Assert::AreEqual(d/2, half[1], Epsilon);

		const hmath::Vector2 dub = hmath::lerpClamped(vec_a, vec_b, 2.0f);
		Assert::AreEqual(c, dub[0], Epsilon);
		Assert::AreEqual(d, dub[1], Epsilon);

		const hmath::Vector2 neg = hmath::lerpClamped(vec_a, vec_b, -1.0f);
		Assert::AreEqual(0.0f, neg[0], Epsilon);
		Assert::AreEqual(0.0f, neg[1], Epsilon);
	}

	TEST_METHOD(Minimum) {
		const float a = 0.0f;
		const float b = 10.0f;
		const float c = 1.0f;
		const float d = -2.0f;
		const hmath::Vector2 vec_a = {a, b};
		const hmath::Vector2 vec_b = {c, d};

		const hmath::Vector2 min = hmath::minimum(vec_a, vec_b);
		Assert::AreEqual(a, min[0], Epsilon);
		Assert::AreEqual(d, min[1], Epsilon);
	}

	TEST_METHOD(Maximum) {
		const float a = 0.0f;
		const float b = 10.0f;
		const float c = 1.0f;
		const float d = -2.0f;
		const hmath::Vector2 vec_a = {a, b};
		const hmath::Vector2 vec_b = {c, d};

		const hmath::Vector2 max = hmath::maximum(vec_a, vec_b);
		Assert::AreEqual(c, max[0], Epsilon);
		Assert::AreEqual(b, max[1], Epsilon);
	}

	TEST_METHOD(Approx) {
		const float a = 1.0f;
		const float b = 0.99998f;
		const hmath::Vector2 vec_a = {a, a};
		const hmath::Vector2 vec_b = {b, b};
		Assert::IsTrue(hmath::approximately(vec_a, vec_b));

		const float c = 1.0f;
		const float d = 0.998f;
		const hmath::Vector2 vec_c = {c, c};
		const hmath::Vector2 vec_d = {d, d};
		Assert::IsFalse(hmath::approximately(vec_c, vec_d));
	}

	TEST_METHOD(Reflect) {
		// 45 degree vector on horizontal plane
		const float angle = 45.0f * 0.0174532924f;
		const hmath::Vector2 dir = {cosf(angle), sinf(angle)};
		const hmath::Vector2 nrm = {1.0f, 0.0f};

		// reflected vector angle difference should be 90
		const hmath::Vector2 refl = hmath::reflect(dir, nrm);
		const float angleBetween = acosf(hmath::dot(dir, refl)) * 57.29578f;

		Assert::AreEqual(90.0f, angleBetween, Epsilon);
	}
};

}