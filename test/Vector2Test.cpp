#include "CppUnitTest.h"
#include "MathHelper.hpp"
#include <hmath/Vector2.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace hmath_test {

//
// SIMPLE TESTS JUST FOR MY SANITY; NOT MEANT FOR EVERY CORNER CASE!
//

const static float EPSILON = 1e-7f;

TEST_CLASS(Vector2Test) {
	TEST_METHOD(ConstructorEmpty) {
		hm::Vector2 vec; // not much here
	}

	TEST_METHOD(ConstructorArray) {
		const std::array<float, 2> arr = {1.0f, 2.0f};
		hm::Vector2 vecOne(arr);
		Assert::AreEqual(1.0f, arr[0], EPSILON);
		Assert::AreEqual(2.0f, arr[1], EPSILON);
	}

	TEST_METHOD(ConstructorInitializerList) {
		// too few elements
		hm::Vector2 tooFew = {1.0f};
		Assert::AreEqual(1.0f, tooFew[0], EPSILON);
		Assert::AreEqual(0.0f, tooFew[1], EPSILON);

		// too many elements
		hm::Vector2 tooMany = {1.0f, 2.0f, 3.0f};
		Assert::AreEqual(1.0f, tooMany[0], EPSILON);
		Assert::AreEqual(2.0f, tooMany[1], EPSILON);

		// just right
		hm::Vector2 justRight = {1.0f, 2.0f};
		Assert::AreEqual(1.0f, justRight[0], EPSILON);
		Assert::AreEqual(2.0f, justRight[1], EPSILON);
	}

	TEST_METHOD(Accessors) {
		// standard accessors
		hm::Vector2 vec = {1.0f, 2.0f};
		Assert::AreEqual(1.0f, vec[0], EPSILON);
		Assert::AreEqual(2.0f, vec[1], EPSILON);
		//vec[-1]; // asserts
		//vec[2]; // asserts

		// const accessors
		const hm::Vector2 constVec = {1.0f, 2.0f};
		Assert::AreEqual(1.0f, constVec[0], EPSILON);
		Assert::AreEqual(2.0f, constVec[1], EPSILON);
		//constVec[-1]; // asserts
		//constVec[2]; // asserts
	}

	TEST_METHOD(TupleOperations) {
		hm::Vector2 vec;
		
		vec.makeZero();
		Assert::AreEqual(0.0f, vec[0], EPSILON);
		Assert::AreEqual(0.0f, vec[1], EPSILON);

		vec.makeOne();
		Assert::AreEqual(1.0f, vec[0], EPSILON);
		Assert::AreEqual(1.0f, vec[1], EPSILON);

		vec.makeUnit(0);
		Assert::AreEqual(1.0f, vec[0], EPSILON);
		Assert::AreEqual(0.0f, vec[1], EPSILON);

		vec.makeUnit(1);
		Assert::AreEqual(0.0f, vec[0], EPSILON);
		Assert::AreEqual(1.0f, vec[1], EPSILON);

		//vec.makeUnit(-1);
		//vec.makeUnit(2);
	}

	TEST_METHOD(StaticVectors) {
		const auto zero = hm::Vector2::zero();
		Assert::AreEqual(0.0f, zero[0], EPSILON);
		Assert::AreEqual(0.0f, zero[1], EPSILON);

		const auto one = hm::Vector2::one();
		Assert::AreEqual(1.0f, one[0], EPSILON);
		Assert::AreEqual(1.0f, one[1], EPSILON);

		const auto unit_0 = hm::Vector2::unit(0);
		Assert::AreEqual(1.0f, unit_0[0], EPSILON);
		Assert::AreEqual(0.0f, unit_0[1], EPSILON);

		const auto unit_1 = hm::Vector2::unit(1);
		Assert::AreEqual(0.0f, unit_1[0], EPSILON);
		Assert::AreEqual(1.0f, unit_1[1], EPSILON);

		//hm::Vector2::unit(-1); // asserts
		//hm::Vector2::unit(2); // asserts

		// compile-time metatemplate only valid for Vector<2>
		const auto up = hm::Vector2::up();
		Assert::AreEqual(0.0f, up[0], EPSILON);
		Assert::AreEqual(1.0f, up[1], EPSILON);

		auto down = hm::Vector2::down();
		Assert::AreEqual(0.0f, down[0], EPSILON);
		Assert::AreEqual(-1.0f, down[1], EPSILON);

		auto left = hm::Vector2::left();
		Assert::AreEqual(-1.0f, left[0], EPSILON);
		Assert::AreEqual(0.0f, left[1], EPSILON);
		
		auto right = hm::Vector2::right();
		Assert::AreEqual(1.0f, right[0], EPSILON);
		Assert::AreEqual(0.0f, right[1], EPSILON);
	}

	TEST_METHOD(UnaryOperators) {
		const hm::Vector2 vec = {1.0f, 2.0f};

		const hm::Vector2 pos = +vec;
		Assert::AreEqual(1.0f, pos[0], EPSILON);
		Assert::AreEqual(2.0f, pos[1], EPSILON);

		const hm::Vector2 neg = -vec;
		Assert::AreEqual(-1.0f, neg[0], EPSILON);
		Assert::AreEqual(-2.0f, neg[1], EPSILON);
	}

	TEST_METHOD(LinearAlgebraicOperators) {
		const float a=1.0f, b=2.0f, c=3.0f, d=4.0f, scalar=5.0f;
		const hm::Vector2 v0 = {a, b};
		const hm::Vector2 v1 = {c, d};

		// vec + vec
		const auto vec_add = v0 + v1;
		Assert::AreEqual(a+c, vec_add[0], EPSILON);
		Assert::AreEqual(b+d, vec_add[1], EPSILON);

		// vec - vec
		const auto vec_sub = v0 - v1;
		Assert::AreEqual(a-c, vec_sub[0], EPSILON);
		Assert::AreEqual(b-d, vec_sub[1], EPSILON);

		// vec * scalar
		const auto vec_mul_scalar = v0 * scalar;
		Assert::AreEqual(a*scalar, vec_mul_scalar[0], EPSILON);
		Assert::AreEqual(b*scalar, vec_mul_scalar[1], EPSILON);

		// scalar * vec
		const auto scalar_mul_vec = scalar * v0;
		Assert::AreEqual(a*scalar, scalar_mul_vec[0], EPSILON);
		Assert::AreEqual(b*scalar, scalar_mul_vec[1], EPSILON);

		// vec / scalar
		const auto vec_div_scalar = v0 / scalar;
		Assert::AreEqual(a/scalar, vec_div_scalar[0], EPSILON);
		Assert::AreEqual(b/scalar, vec_div_scalar[1], EPSILON);

		// vec += vec
		hm::Vector2 vec_pe_vec = v0;
		vec_pe_vec += v1;
		Assert::AreEqual(a+c, vec_pe_vec[0], EPSILON);
		Assert::AreEqual(b+d, vec_pe_vec[1], EPSILON);

		// vec -= vec
		hm::Vector2 vec_me_vec = v0;
		vec_me_vec -= v1;
		Assert::AreEqual(a-c, vec_me_vec[0], EPSILON);
		Assert::AreEqual(b-d, vec_me_vec[1], EPSILON);

		// vec *= scalar
		hm::Vector2 vec_me_scalar = v0;
		vec_me_scalar *= scalar;
		Assert::AreEqual(a*scalar, vec_me_scalar[0], EPSILON);
		Assert::AreEqual(b*scalar, vec_me_scalar[1], EPSILON);

		// vec /= scalar
		hm::Vector2 vec_de_scalar = v0;
		vec_de_scalar /= scalar;
		Assert::AreEqual(a/scalar, vec_de_scalar[0], EPSILON);
		Assert::AreEqual(b/scalar, vec_de_scalar[1], EPSILON);
		// vec /= 0.0f corner case
		hm::Vector2 vec_de_zero = v0;
		vec_de_zero /= 0.0f;
		Assert::AreEqual(0.0f, vec_de_zero[0], EPSILON);
		Assert::AreEqual(0.0f, vec_de_zero[1], EPSILON);
	}

	TEST_METHOD(ComponentAlgebraicOperators) {
		const float a=1.0f, b=2.0f, c=3.0f, d=4.0f;
		const hm::Vector2 v0 = {a, b};
		const hm::Vector2 v1 = {c, d};

		// vec * vec, internally runs vec *= vec
		const auto mul = v0 * v1;
		Assert::AreEqual(a*c, mul[0], EPSILON);
		Assert::AreEqual(b*d, mul[1], EPSILON);

		// vec / vec, internally runs vec /= vec
		const auto div = v0 / v1;
		Assert::AreEqual(a/c, div[0], EPSILON);
		Assert::AreEqual(b/d, div[1], EPSILON);
	}

	TEST_METHOD(Dot) {
		const auto v0 = MathHelper::vec2FromAngle(-45.0f);
		const auto v1 = MathHelper::vec2FromAngle(45.0f);
		Assert::AreEqual(90.0f, MathHelper::dotToDegrees(hm::dot(v0, v1)), EPSILON);

		const auto v2 = MathHelper::vec2FromAngle(0.0f);
		Assert::AreEqual(45.0f, MathHelper::dotToDegrees(hm::dot(v2, v1)), EPSILON);
	}

	TEST_METHOD(Length) {
		const auto unit = hm::Vector2::unit(1);
		Assert::AreEqual(1.0f, hm::length(unit), EPSILON);

		const hm::Vector2 vec = {12.0f, 20.0f};
		Assert::AreEqual(23.323807579381203f, hm::length(vec), EPSILON);
	}

	TEST_METHOD(LengthRobust) {
		const auto unit = hm::Vector2::unit(1);
		Assert::AreEqual(1.0f, hm::lengthRobust(unit), EPSILON);

		const hm::Vector2 vec = {12.0f, 20.0f};
		Assert::AreEqual(23.323807579381203f, hm::lengthRobust(vec), EPSILON);

		const auto zero = hm::Vector2::zero();
		Assert::AreEqual(0.0f, hm::lengthRobust(zero), EPSILON);
	}

	TEST_METHOD(SqrLength) {
		const hm::Vector2 vec = {12.0f, 20.0f};
		Assert::AreEqual(544.0f, hm::sqrLength(vec), EPSILON);
	}

	TEST_METHOD(Normalize) {
		hm::Vector2 vec = {12.0f, 20.0f};
		const float preLen = hm::normalize(vec);
		const float postLen = hm::length(vec);
		Assert::AreEqual(23.323807579381203f, preLen, EPSILON);
		Assert::AreEqual(1.0f, postLen, EPSILON);

		auto zero = hm::Vector2::zero();
		const float zeroPreLen = hm::normalize(zero);
		const float zeroPostLen = hm::length(zero);
		Assert::AreEqual(0.0f, zeroPreLen, EPSILON);
		Assert::AreEqual(0.0f, zeroPostLen, EPSILON);
		Assert::AreEqual(0.0f, zero[0], EPSILON);
		Assert::AreEqual(0.0f, zero[1], EPSILON);
	}

	TEST_METHOD(NormalizeRobust) {
		hm::Vector2 vec = {12.0f, 20.0f};
		const float preLen = hm::normalizeRobust(vec);
		const float postLen = hm::length(vec);
		Assert::AreEqual(23.323807579381203f, preLen, EPSILON);
		Assert::AreEqual(1.0f, postLen, EPSILON);

		auto zero = hm::Vector2::zero();
		const float zeroPreLen = hm::normalizeRobust(zero);
		const float zeroPostLen = hm::length(zero);
		Assert::AreEqual(0.0f, zeroPreLen, EPSILON);
		Assert::AreEqual(0.0f, zeroPostLen, EPSILON);
		Assert::AreEqual(0.0f, zero[0], EPSILON);
		Assert::AreEqual(0.0f, zero[1], EPSILON);
	}

	TEST_METHOD(Distance) {
		const hm::Vector2 v0 = {12, 20};
		const hm::Vector2 v1 = {16, -5};
		Assert::AreEqual(25.317978f, hm::distance(v0, v1), EPSILON);

		const auto zero = hm::Vector2::zero();
		Assert::AreEqual(hm::length(v0), hm::distance(zero, v0), EPSILON);
	}

	TEST_METHOD(SqrDistance) {
		const hm::Vector2 v0 = {12, 20};
		const hm::Vector2 v1 = {16, -5};
		Assert::AreEqual(641.0f, hm::sqrDistance(v0, v1), EPSILON);
	}

	TEST_METHOD(Minimum) {
		const float a=1.0f, b=4.0f, c=2.0f, d=3.0f;
		const hm::Vector2 v0 = {a, b};
		const hm::Vector2 v1 = {c, d};

		const auto min = hm::minimum(v0, v1);
		Assert::AreEqual(a, min[0], EPSILON);
		Assert::AreEqual(d, min[1], EPSILON);
	}

	TEST_METHOD(Maximum) {
		const float a=1.0f, b=4.0f, c=2.0f, d=3.0f;
		const hm::Vector2 v0 = {a, b};
		const hm::Vector2 v1 = {c, d};

		const auto max = hm::maximum(v0, v1);
		Assert::AreEqual(c, max[0], EPSILON);
		Assert::AreEqual(b, max[1], EPSILON);
	}
};

}