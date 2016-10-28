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

		//hmath::Vector2 vec_plus
	}
};

}