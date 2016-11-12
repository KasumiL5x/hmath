#include "CppUnitTest.h"
#include "MathHelper.hpp"
#include <hmath/Matrix.hpp>
#include <hmath/Matrix4x4.hpp>
#include <hmath/Vector4.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace hmath_test {

TEST_CLASS(MatrixTest) {
	TEST_METHOD(Dummy) {
		hm::Matrix<4, 4> mat;
	}

	TEST_METHOD(Mat4x4) {
		// M*M
		hm::Matrix4x4 A = {
			0.692211151f, 0.624191821f, -0.362254649f, 0.0f,
			0.0f, 0.501949787f, 0.864896834f, 0.0f,
			0.721695125f, -0.598691225f, 0.347455204f, 0.0f,
			0.249388814f, -0.487314880f, 0.282817066f, 1.0f
		};

		hm::Matrix4x4 B = {
			2.14450693f, 0.0f, 0.0f, 0.0f,
			0.0f, 2.14450693f, 0.0f, 0.0f,
			0.0f, 0.0f, -1.00019991f, -1.0f,
			0.0f, 0.0f, -0.200020000f, 0.0f
		};

		const auto C = A * B;

		auto D = hm::multiply(A, B);

		const float EPSILON = 1e-5f;
		Assert::AreEqual(1.4844516103427763f, C.get(0, 0), EPSILON);
		Assert::AreEqual(1.3385836857838196f, C.get(0, 1), EPSILON);
		Assert::AreEqual(0.3623270673268816f, C.get(0, 2), EPSILON);
		Assert::AreEqual(0.362254649f, C.get(0, 3), EPSILON);

		Assert::AreEqual(0.0f, C.get(1, 0), EPSILON);
		Assert::AreEqual(1.076434796733524f, C.get(1, 1), EPSILON);
		Assert::AreEqual(-0.8650697355260849f, C.get(1, 2), EPSILON);
		Assert::AreEqual(-0.864896834f, C.get(1, 3), EPSILON);

		Assert::AreEqual(1.5476801969097163f, C.get(2, 0), EPSILON);
		Assert::AreEqual(-1.2838974809426893f, C.get(2, 1), EPSILON);
		Assert::AreEqual(-0.3475246637698317f, C.get(2, 2), EPSILON);
		Assert::AreEqual(-0.347455204f, C.get(2, 3), EPSILON);

		Assert::AreEqual(0.5348160398874809f, C.get(3, 0), EPSILON);
		Assert::AreEqual(-1.0450501372521184f, C.get(3, 1), EPSILON);
		Assert::AreEqual(-0.4828936039596641f, C.get(3, 2), EPSILON);
		Assert::AreEqual(-0.282817066f, C.get(3, 3), EPSILON);
	}
};

}