#include "stdafx.hpp"
#include "CppUnitTest.h"
#include <Vector3.hpp>
#include <math.h>

using namespace LinearMath;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef float Scalar;

typedef LinearMath::Vector3_tpl< Scalar > Vector3;

template class __declspec ( dllexport )Vector3_tpl< Scalar >;

namespace MathLibUnitTest
{
	TEST_CLASS( Vector3Test )
	{
	public:

		TEST_METHOD( Vector3Constructor1 )
		{
			Vector3 v;

			Assert::AreEqual( 0.0f, v.X );
			Assert::AreEqual( 0.0f, v.Y );
			Assert::AreEqual( 0.0f, v.Z );
		}

		TEST_METHOD( Vector3Constructor2 )
		{
			Vector3 v( 5 );

			Assert::AreEqual( 5.0f, v.X );
			Assert::AreEqual( 5.0f, v.Y );
			Assert::AreEqual( 5.0f, v.Z );
		}

		TEST_METHOD( Vector3Constructor3 )
		{
			Vector3 v( 2.5f, 3.7f, 42.0f );

			Assert::AreEqual( 2.5f, v.X );
			Assert::AreEqual( 3.7f, v.Y );
			Assert::AreEqual( 42.0f, v.Z );
		}

		TEST_METHOD( Vector3Constructor4 )
		{
			Vector3 v1( 1.0f, 2.0f, 3.0f );
			Vector3 v( v1 );

			Assert::AreEqual( 1.0f, v.X );
			Assert::AreEqual( 2.0f, v.Y );
			Assert::AreEqual( 3.0f, v.Z );
		}

		TEST_METHOD( Vector3Getters )
		{
			Vector3 v( 1.0f, 2.0f, 3.0f );

			Assert::AreEqual( 1.0f, v.GetX() );
			Assert::AreEqual( 2.0f, v.GetY() );
			Assert::AreEqual( 3.0f, v.GetZ() );
		}

		TEST_METHOD( Vector3Add )
		{
			Vector3 v1( 10, 20, 30 );
			Vector3 v2( 40, 50, 60 );

			Vector3 v3 = v1 + v2;

			Assert::AreEqual( v1.X + v2.X, v3.X );
			Assert::AreEqual( v1.Y + v2.Y, v3.Y );
			Assert::AreEqual( v1.Z + v2.Z, v3.Z );
		}

		TEST_METHOD( Vector3Add2 )
		{
			Vector3 v1( 10, 20, 30 );
			Vector3 v2( 40, 50, 60 );

			v1 += v2;

			Assert::AreEqual( 50.0f, v1.X );
			Assert::AreEqual( 70.0f, v1.Y );
			Assert::AreEqual( 90.0f, v1.Z );
		}

		TEST_METHOD( Vector3Add3 )
		{
			Vector3 v1( 10, 20, 30 );
			Vector3 v2( 40, 50, 60 );

			v1 = +v2;

			Assert::AreEqual( 40.0f, v1.X );
			Assert::AreEqual( 50.0f, v1.Y );
			Assert::AreEqual( 60.0f, v1.Z );
		}

		TEST_METHOD( Vector3Sub1 )
		{
			Vector3 v1( 10, 20, 30 );
			Vector3 v2( 40, 50, 60 );

			Vector3 v3 = v1 - v2;

			Assert::AreEqual( v1.X - v2.X, v3.X );
			Assert::AreEqual( v1.Y - v2.Y, v3.Y );
			Assert::AreEqual( v1.Z - v2.Z, v3.Z );
		}

		TEST_METHOD( Vector3Sub2 )
		{
			Vector3 v1( 10, 20, 30 );
			Vector3 v2( 40, 50, 60 );

			v1 -= v2;

			Assert::AreEqual( -30.0f, v1.X );
			Assert::AreEqual( -30.0f, v1.Y );
			Assert::AreEqual( -30.0f, v1.Z );
		}

		TEST_METHOD( Vector3Sub3 )
		{
			Vector3 v1( 10, 20, 30 );
			Vector3 v2( 40, 50, 60 );

			v1 = -v2;

			Assert::AreEqual( -40.0f, v1.X );
			Assert::AreEqual( -50.0f, v1.Y );
			Assert::AreEqual( -60.0f, v1.Z );
		}

		TEST_METHOD( Vector3Mult1 )
		{
			Vector3 v( 10, 20, 30 );
			Scalar scal = 10;

			Vector3 out = v * scal;

			Assert::AreEqual( 100.0f, out.X );
			Assert::AreEqual( 200.0f, out.Y );
			Assert::AreEqual( 300.0f, out.Z );
		}

		TEST_METHOD( Vector3Mult2 )
		{
			Vector3 v( 10, 20, 30 );
			Scalar scal = 10;

			v *= scal;

			Assert::AreEqual( 100.0f, v.X );
			Assert::AreEqual( 200.0f, v.Y );
			Assert::AreEqual( 300.0f, v.Z );
		}

		TEST_METHOD( Vector3Mult3 )
		{
			Vector3 v( 10, 20, 30 );
			Scalar scal = 10;

			Vector3 out = scal * v;

			Assert::AreEqual( 100.0f, out.X );
			Assert::AreEqual( 200.0f, out.Y );
		}

		TEST_METHOD( Vector3Mult4 )
		{
			Vector3 v1( 10, 20, 30 );
			Vector3 v2( 40, 50, 60 );

			Scalar scal = v1 * v2;

			Assert::AreEqual( ( ( 10.0f * 40.0f ) + ( 20.0f * 50.0f ) + ( 30.0f * 60.0f ) ), scal );
		}

		TEST_METHOD( Vector3Div1 )
		{
			Vector3 v( 10, 20, 30 );
			Scalar scal = 10;

			Vector3 out = v / scal;

			Assert::AreEqual( 1.0f, out.X );
			Assert::AreEqual( 2.0f, out.Y );
			Assert::AreEqual( 3.0f, out.Z );
		}

		TEST_METHOD( Vector3Div2 )
		{
			Vector3 v( 10, 20, 30 );
			Scalar scal = 10;

			v /= scal;

			Assert::AreEqual( 1.0f, v.X );
			Assert::AreEqual( 2.0f, v.Y );
			Assert::AreEqual( 3.0f, v.Z );
		}

		TEST_METHOD( Vector3LengthSq )
		{
			Vector3 v( 10, 20, 30 );

			Scalar length = v.LengthSquared();

			Assert::AreEqual( ( 10.0f * 10.0f ) + ( 20.0f * 20.0f ) + ( 30.0f * 30.0f ), length );
		}

		TEST_METHOD( Vector3Length )
		{
			Vector3 v( 4, 0, -3 );

			Scalar length = v.Length();

			Assert::AreEqual( 5.0f, length );
		}

		TEST_METHOD( Vector3Normalize )
		{
			Vector3 v( 10, 20, 30 );

			Scalar length = v.Length();

			v.Normalize();

			Assert::AreEqual( 10.0f / length, v.X );
			Assert::AreEqual( 20.0f / length, v.Y );
			Assert::AreEqual( 30.0f / length, v.Z );
		}

		TEST_METHOD( Vector3NormalizeCopy )
		{
			Vector3 v( 10.0f, 20.0f, 30.0f );

			Scalar length = v.Length();
			Vector3 out = v.NormalizedCopy();

			Assert::AreEqual( 10.0f / length, out.X );
			Assert::AreEqual( 20.0f / length, out.Y );
			Assert::AreEqual( 30.0f / length, out.Z );
			Assert::AreNotEqual( v.X, out.X );
			Assert::AreNotEqual( v.Y, out.Y );
			Assert::AreNotEqual( v.Z, out.Z );
		}

		TEST_METHOD( Vector3DotProduct )
		{
			Vector3 v1( 10, 20, 30 );
			Vector3 v2( 40, 50, 60 );

			Scalar scal = v1.DotProduct( v2 );

			Assert::AreEqual( ( ( 10.0f * 40.0f ) + ( 20.0f * 50.0f ) + ( 30.0f * 60.0f ) ), scal );
		}

		TEST_METHOD( Vector3PerpDotProduct )
		{
			Vector3 v1( 1, 0, 0 );
			Vector3 v2( 0, 1, 0 );

			Vector3 out = v1.CrossProduct( v2 );

			Assert::AreEqual( 0.0f, out.X );
			Assert::AreEqual( 0.0f, out.Y );
			Assert::AreEqual( 1.0f, out.Z );
		}

		TEST_METHOD( Vector3Compare )
		{
			Vector3 v1( 1.0f, 2.0f, 3.0f );
			Vector3 v2( 1.0f, 2.0f, 3.0f );

			Assert::IsTrue( v1 == v2 );
			Assert::IsFalse( v1 != v2 );

			v2 = Vector3( 1.0f, 2.0f, 4.0f );

			Assert::IsTrue( v1 != v2 );
			Assert::IsFalse( v1 == v2 );
		}
	};
}
