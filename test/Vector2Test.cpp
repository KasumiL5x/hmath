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
};

}