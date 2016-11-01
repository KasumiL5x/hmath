#include "CppUnitTest.h"
#include "MathHelper.hpp"
#include <hmath/Matrix.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace hmath_test {

TEST_CLASS(MatrixTest) {
	TEST_METHOD(Dummy) {
		hm::Matrix<4, 4> mat;
	}
};

}