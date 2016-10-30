#include "CppUnitTest.h"
#include <hmath/Vector3.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const static float EPSILON = 1e-7f;

TEST_CLASS(Vector3Test) {
public:
	TEST_METHOD(Statics) {
		const auto up = hm::Vector3::up();
		Assert::AreEqual(0.0f, up[0], EPSILON);
		Assert::AreEqual(1.0f, up[1], EPSILON);
		Assert::AreEqual(0.0f, up[2], EPSILON);

		const auto down = hm::Vector3::down();
		Assert::AreEqual(0.0f, down[0], EPSILON);
		Assert::AreEqual(-1.0f, down[1], EPSILON);
		Assert::AreEqual(0.0f, down[2], EPSILON);

		const auto left = hm::Vector3::left();
		Assert::AreEqual(-1.0f, left[0], EPSILON);
		Assert::AreEqual(0.0f, left[1], EPSILON);
		Assert::AreEqual(0.0f, left[2], EPSILON);

		const auto right = hm::Vector3::right();
		Assert::AreEqual(1.0f, right[0], EPSILON);
		Assert::AreEqual(0.0f, right[1], EPSILON);
		Assert::AreEqual(0.0f, right[2], EPSILON);

		const auto forward = hm::Vector3::forward();
		Assert::AreEqual(0.0f, forward[0], EPSILON);
		Assert::AreEqual(0.0f, forward[1], EPSILON);
		Assert::AreEqual(-1.0f, forward[2], EPSILON);

		const auto backward = hm::Vector3::backward();
		Assert::AreEqual(0.0f, backward[0], EPSILON);
		Assert::AreEqual(0.0f, backward[1], EPSILON);
		Assert::AreEqual(1.0f, backward[2], EPSILON);
	}

	TEST_METHOD(Cross) {
		const hm::Vector3 v0 = {0.0f, 1.0f, 0.0f};
		const hm::Vector3 v1 = {1.0f, 0.0f, 0.0f};

		const auto cross = hm::cross(v1, v0);
		Assert::AreEqual(0.0f, cross[0], EPSILON);
		Assert::AreEqual(0.0f, cross[1], EPSILON);
		Assert::AreEqual(1.0f, cross[2], EPSILON);
	}

	TEST_METHOD(CrossUnit) {
		const hm::Vector3 v0 = {0.0f, 999.0f, 0.0f};
		const hm::Vector3 v1 = {999.0f, 0.0f, 0.0f};

		const auto cross = hm::crossUnit(v1, v0);
		Assert::AreEqual(0.0f, cross[0], EPSILON);
		Assert::AreEqual(0.0f, cross[1], EPSILON);
		Assert::AreEqual(1.0f, cross[2], EPSILON);
		Assert::AreEqual(1.0f, hm::length(cross), EPSILON);

		const auto crossRobust = hm::crossUnitRobust(v1, v0);
		Assert::AreEqual(0.0f, crossRobust[0], EPSILON);
		Assert::AreEqual(0.0f, crossRobust[1], EPSILON);
		Assert::AreEqual(1.0f, crossRobust[2], EPSILON);
		Assert::AreEqual(1.0f, hm::length(crossRobust), EPSILON);
	}
};