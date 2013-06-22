#include "stdafx.hpp"
#include "CppUnitTest.h"
#include <Vector2.hpp>
#include <math.h>

using namespace LinearMath;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef float Scalar;

typedef LinearMath::Vector2_tpl< Scalar > Vector2;

namespace MathLibUnitTest
{
	TEST_CLASS( Vector2Test )
	{
	public:

		TEST_METHOD( Vector2Constructor1 )
		{
			Vector2 v;

			Assert::AreEqual( 0.0f, v.X );
			Assert::AreEqual( 0.0f, v.Y );
		}

		TEST_METHOD( Vector2Constructor2 )
		{
			Vector2 v( 5 );

			Assert::AreEqual( 5.0f, v.X );
			Assert::AreEqual( 5.0f, v.Y );
		}

		TEST_METHOD( Vector2Constructor3 )
		{
			Vector2 v( 2.5f, 3.7f );

			Assert::AreEqual( 2.5f, v.X );
			Assert::AreEqual( 3.7f, v.Y );
		}

		TEST_METHOD( Vector2Add )
		{
			Vector2 v1( 10, 20 );
			Vector2 v2( 30, 40 );

			Vector2 v3 = v1 + v2;

			Assert::AreEqual( v1.X + v2.X, v3.X );
			Assert::AreEqual( v1.Y + v2.Y, v3.Y );
		}

		TEST_METHOD( Vector2Add2 )
		{
			Vector2 v1( 10, 20 );
			Vector2 v2( 30, 40 );

			v1 += v2;

			Assert::AreEqual( 40.0f, v1.X );
			Assert::AreEqual( 60.0f, v1.Y );
		}

		TEST_METHOD( Vector2Sub1 )
		{
			Vector2 v1( 10, 20 );
			Vector2 v2( 30, 40 );

			Vector2 v3 = v1 - v2;

			Assert::AreEqual( v1.X - v2.X, v3.X );
			Assert::AreEqual( v1.Y - v2.Y, v3.Y );
		}

		TEST_METHOD( Vector2Sub2 )
		{
			Vector2 v1( 10, 20 );
			Vector2 v2( 30, 10 );

			v1 -= v2;

			Assert::AreEqual( -20.0f, v1.X );
			Assert::AreEqual( 10.0f, v1.Y );
		}

		TEST_METHOD( Vector2Mult1 )
		{
			Vector2 v( 10, 20 );
			Scalar scal = 10;

			Vector2 out = v * scal;

			Assert::AreEqual( 100.0f, out.X );
			Assert::AreEqual( 200.0f, out.Y );
		}

		TEST_METHOD( Vector2Mult2 )
		{
			Vector2 v( 10, 20 );
			Scalar scal = 10;

			v *= scal;

			Assert::AreEqual( 100.0f, v.X );
			Assert::AreEqual( 200.0f, v.Y );
		}

		TEST_METHOD( Vector2Mult3 )
		{
			Vector2 v( 10, 20 );
			Scalar scal = 10;

			Vector2 out = scal * v;

			Assert::AreEqual( 100.0f, out.X );
			Assert::AreEqual( 200.0f, out.Y );
		}

		TEST_METHOD( Vector2Mult4 )
		{
			Vector2 v1( 10, 20 );
			Vector2 v2( 30, 40 );

			Scalar scal = v1 * v2;

			Assert::AreEqual( ( ( 10.0f * 30.0f ) + ( 20.0f * 40.0f ) ), scal );
		}

		TEST_METHOD( Vector2Div1 )
		{
			Vector2 v( 10, 20 );
			Scalar scal = 10;

			Vector2 out = v / scal;

			Assert::AreEqual( 1.0f, out.X );
			Assert::AreEqual( 2.0f, out.Y );
		}

		TEST_METHOD( Vector2Div2 )
		{
			Vector2 v( 10, 20 );
			Scalar scal = 10;

			v /= scal;

			Assert::AreEqual( 1.0f, v.X );
			Assert::AreEqual( 2.0f, v.Y );
		}

		TEST_METHOD( Vector2LengthSq )
		{
			Vector2 v( 10, 20 );

			Scalar length = v.LengthSquared();

			Assert::AreEqual( ( 10.0f * 10.0f ) + ( 20.0f * 20.0f ), length );
		}

		TEST_METHOD( Vector2Length )
		{
			Vector2 v( 4, 3 );

			Scalar length = v.Length();

			Assert::AreEqual( 5.0f, length );
		}

		TEST_METHOD( Vector2Normalize )
		{
			Vector2 v( 10, 20 );

			Scalar length = v.Length();

			v.Normalize();

			Assert::AreEqual( 10.0f / length, v.X );
			Assert::AreEqual( 20.0f / length, v.Y );
		}

		TEST_METHOD( Vector2NormalizeCopy )
		{
			Vector2 v( 10.0f, 20.0f );

			Vector2 out = v.NormalizedCopy();
			Scalar length = v.Length();

			Assert::AreEqual( 10.0f / length, out.X );
			Assert::AreEqual( 20.0f / length, out.Y );
			Assert::AreNotEqual( v.X, out.X );
			Assert::AreNotEqual( v.Y, out.Y );
		}

		TEST_METHOD( Vector2DotProduct )
		{
			Vector2 v1( 10, 20 );
			Vector2 v2( 30, 40 );

			Scalar scal = v1.DotProduct( v2 );

			Assert::AreEqual( ( ( 10.0f * 30.0f ) + ( 20.0f * 40.0f ) ), scal );
		}

		TEST_METHOD( Vector2PerpDotProduct )
		{
			Vector2 v1( 10, 20 );
			Vector2 v2( 30, 40 );

			Scalar scal = v1.PerpDotProduct( v2 );

			Assert::AreEqual( ( ( -20.0f * 30.0f ) + ( 10.0f * 40.0f ) ), scal );
		}

		TEST_METHOD( Vector2GetRotation )
		{
			Vector2 v( 10, 0 );

			Radian_tpl< Scalar > res = v.GetRotation();

			Assert::AreEqual( 0.0f, res.AsRadianValue() );
		}
	};
}
