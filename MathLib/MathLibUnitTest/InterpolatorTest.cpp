#include "stdafx.hpp"
#include "CppUnitTest.h"
#include "Analysis/Interpolation/Interpolator.hpp"
#include "LinearMath/Vector2.hpp"
#include "ClassicalMechanics/Volumes/AABB3D.hpp"

using namespace Analysis;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef float Scalar;

template class __declspec ( dllexport )Analysis::Interpolator_tpl< Scalar, Scalar >;
template class __declspec ( dllexport )LinearMath::Vector2_tpl< Scalar >;

typedef Analysis::Interpolator_tpl< Scalar, Scalar > FloatInterpolator;
typedef LinearMath::Vector2_tpl< Scalar > Vector2;
typedef Analysis::Interpolator_tpl< Vector2, Scalar > VectorInterpolator;

namespace MathLibUnitTest
{
	TEST_CLASS( InterpolatorTestClass )
	{
	public:

		TEST_METHOD( Lerp )
		{
			float start = 0.0f;
			float end = 1.0f;
			float x = 0.5f;
			float result = FloatInterpolator::Lerp( start, end, x );

			Assert::AreEqual( 0.5f, result );
		}

		TEST_METHOD( LerpVector2 )
		{
			Vector2 start = Vector2( 0.0f, 0.0f );
			Vector2 end = Vector2( 1.0f, 1.0f );
			float x = 0.5f;
			Vector2 result = VectorInterpolator::Lerp( start, end, x );

			Assert::AreEqual( 0.5f, result.x );
			Assert::AreEqual( 0.5f, result.y );
		}

		TEST_METHOD( SmoothInterpolate )
		{
			float start = 0.0f;
			float end = 1.0f;
			float x = 1.0f;
			float result1 = FloatInterpolator::SmoothInterpolation( start, end, x );
			float result2 = FloatInterpolator::SmoothInterpolation( start, end, 0.0f );

			Assert::AreEqual( 1.0f, result1 );
			Assert::AreEqual( 0.0f, result2 );
		}

		TEST_METHOD( SmoothInterpolateVector2 )
		{
			Vector2 start = Vector2( 0.0f, 0.0f );
			Vector2 end = Vector2( 1.0f, 1.0f );
			float x = 1.0f;
			Vector2 result1 = VectorInterpolator::SmoothInterpolation( start, end, x );
			Vector2 result2 = VectorInterpolator::SmoothInterpolation( start, end, 0.0f );

			Assert::AreEqual( 1.0f, result1.x );
			Assert::AreEqual( 1.0f, result1.y );

			Assert::AreEqual( 0.0f, result2.x );
			Assert::AreEqual( 0.0f, result2.y );
		}
	};
}
