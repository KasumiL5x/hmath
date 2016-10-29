#include "CppUnitTest.h"
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
};

}