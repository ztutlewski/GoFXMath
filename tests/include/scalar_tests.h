#ifndef SCALAR_TESTS_DOT_H
#define SCALAR_TESTS_DOT_H
#include "scalar_math.h"
#include "catch.hpp"
#include <array>
#include <cmath>
#include <limits>

template<gofxmath::FloatPrecision precisionLevel = gofxmath::FloatPrecision::HIGH>
inline bool ApproxEqual_Debug(float left, float right)
{
	static const float EPSILON = gofxmath::FloatPrecisionValue<precisionLevel>();

	return abs(left - right) < EPSILON;
}

template<gofxmath::FloatPrecision precisionLevel = gofxmath::FloatPrecision::HIGH>
inline void RunScalarTest(float result, float expected)
{
	INFO("RESULT: " << result);
	INFO("EXPECTED: " << expected);
	CHECK(ApproxEqual_Debug<precisionLevel>(result, expected));
}

void RunScalarInfTest(float result);

template<gofxmath::FloatPrecision precisionLevel = gofxmath::FloatPrecision::HIGH>
inline void RunScalarApproxInfTest(float result)
{
	INFO("RESULT: " << result);
	static const float LIMIT = (4.0f - precisionLevel * precisionLevel) * 1.0e+4f;

	bool checkResult = std::isinf(result) || abs(result) >= LIMIT;

	CHECK(checkResult);
}


extern const std::array<float, gofxmath::NUM_PRECISION_VALS> INF_PRECISION_VALS;

#endif