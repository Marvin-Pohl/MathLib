#include "stdafx.hpp"
#include "CppUnitTest.h"
#include <SSEMatrix4x4.hpp>

using namespace LinearMath;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef SSEMatrix4x4 Matrix4x4;

namespace MathLibUnitTest
{
	TEST_CLASS( Matrix4x4TestClass )
	{
	public:

		void MatrixAreEqual( const Matrix4x4& result, const Matrix4x4& expected )
		{
			Assert::AreEqual( expected.GetM_1_1(), result.GetM_1_1() );
			Assert::AreEqual( expected.GetM_1_2(), result.GetM_1_2() );
			Assert::AreEqual( expected.GetM_1_3(), result.GetM_1_3() );
			Assert::AreEqual( expected.GetM_1_4(), result.GetM_1_4() );
			Assert::AreEqual( expected.GetM_2_1(), result.GetM_2_1() );
			Assert::AreEqual( expected.GetM_2_2(), result.GetM_2_2() );
			Assert::AreEqual( expected.GetM_2_3(), result.GetM_2_3() );
			Assert::AreEqual( expected.GetM_2_4(), result.GetM_2_4() );
			Assert::AreEqual( expected.GetM_3_1(), result.GetM_3_1() );
			Assert::AreEqual( expected.GetM_3_2(), result.GetM_3_2() );
			Assert::AreEqual( expected.GetM_3_3(), result.GetM_3_3() );
			Assert::AreEqual( expected.GetM_3_4(), result.GetM_3_4() );
			Assert::AreEqual( expected.GetM_4_1(), result.GetM_4_1() );
			Assert::AreEqual( expected.GetM_4_2(), result.GetM_4_2() );
			Assert::AreEqual( expected.GetM_4_3(), result.GetM_4_3() );
			Assert::AreEqual( expected.GetM_4_4(), result.GetM_4_4() );
		}

		TEST_METHOD( SSEMatrix4x4ConstructorTest )
		{
			Matrix4x4 m;

			m = Matrix4x4::IDENTITY;

			Assert::AreEqual( 1.0f, m.GetM_1_1() );
			Assert::AreEqual( 0.0f, m.GetM_1_2() );
			Assert::AreEqual( 0.0f, m.GetM_1_3() );
			Assert::AreEqual( 0.0f, m.GetM_1_4() );
			Assert::AreEqual( 0.0f, m.GetM_2_1() );
			Assert::AreEqual( 1.0f, m.GetM_2_2() );
			Assert::AreEqual( 0.0f, m.GetM_2_3() );
			Assert::AreEqual( 0.0f, m.GetM_2_4() );
			Assert::AreEqual( 0.0f, m.GetM_3_1() );
			Assert::AreEqual( 0.0f, m.GetM_3_2() );
			Assert::AreEqual( 1.0f, m.GetM_3_3() );
			Assert::AreEqual( 0.0f, m.GetM_3_4() );
			Assert::AreEqual( 0.0f, m.GetM_4_1() );
			Assert::AreEqual( 0.0f, m.GetM_4_2() );
			Assert::AreEqual( 0.0f, m.GetM_4_3() );
			Assert::AreEqual( 1.0f, m.GetM_4_4() );

			m = Matrix4x4::ZERO;

			Assert::AreEqual( 0.0f, m.GetM_1_1() );
			Assert::AreEqual( 0.0f, m.GetM_1_2() );
			Assert::AreEqual( 0.0f, m.GetM_1_3() );
			Assert::AreEqual( 0.0f, m.GetM_1_4() );
			Assert::AreEqual( 0.0f, m.GetM_2_1() );
			Assert::AreEqual( 0.0f, m.GetM_2_2() );
			Assert::AreEqual( 0.0f, m.GetM_2_3() );
			Assert::AreEqual( 0.0f, m.GetM_2_4() );
			Assert::AreEqual( 0.0f, m.GetM_3_1() );
			Assert::AreEqual( 0.0f, m.GetM_3_2() );
			Assert::AreEqual( 0.0f, m.GetM_3_3() );
			Assert::AreEqual( 0.0f, m.GetM_3_4() );
			Assert::AreEqual( 0.0f, m.GetM_4_1() );
			Assert::AreEqual( 0.0f, m.GetM_4_2() );
			Assert::AreEqual( 0.0f, m.GetM_4_3() );
			Assert::AreEqual( 0.0f, m.GetM_4_4() );

			m = Matrix4x4::ZERO_AFFINE;

			Assert::AreEqual( 0.0f, m.GetM_1_1() );
			Assert::AreEqual( 0.0f, m.GetM_1_2() );
			Assert::AreEqual( 0.0f, m.GetM_1_3() );
			Assert::AreEqual( 0.0f, m.GetM_1_4() );
			Assert::AreEqual( 0.0f, m.GetM_2_1() );
			Assert::AreEqual( 0.0f, m.GetM_2_2() );
			Assert::AreEqual( 0.0f, m.GetM_2_3() );
			Assert::AreEqual( 0.0f, m.GetM_2_4() );
			Assert::AreEqual( 0.0f, m.GetM_3_1() );
			Assert::AreEqual( 0.0f, m.GetM_3_2() );
			Assert::AreEqual( 0.0f, m.GetM_3_3() );
			Assert::AreEqual( 0.0f, m.GetM_3_4() );
			Assert::AreEqual( 0.0f, m.GetM_4_1() );
			Assert::AreEqual( 0.0f, m.GetM_4_2() );
			Assert::AreEqual( 0.0f, m.GetM_4_3() );
			Assert::AreEqual( 1.0f, m.GetM_4_4() );

			Matrix4x4 m1;

			Assert::AreEqual( 0.0f, m1.GetM_1_1() );
			Assert::AreEqual( 0.0f, m1.GetM_1_2() );
			Assert::AreEqual( 0.0f, m1.GetM_1_3() );
			Assert::AreEqual( 0.0f, m1.GetM_1_4() );
			Assert::AreEqual( 0.0f, m1.GetM_2_1() );
			Assert::AreEqual( 0.0f, m1.GetM_2_2() );
			Assert::AreEqual( 0.0f, m1.GetM_2_3() );
			Assert::AreEqual( 0.0f, m1.GetM_2_4() );
			Assert::AreEqual( 0.0f, m1.GetM_3_1() );
			Assert::AreEqual( 0.0f, m1.GetM_3_2() );
			Assert::AreEqual( 0.0f, m1.GetM_3_3() );
			Assert::AreEqual( 0.0f, m1.GetM_3_4() );
			Assert::AreEqual( 0.0f, m1.GetM_4_1() );
			Assert::AreEqual( 0.0f, m1.GetM_4_2() );
			Assert::AreEqual( 0.0f, m1.GetM_4_3() );
			Assert::AreEqual( 0.0f, m1.GetM_4_4() );
		}

		TEST_METHOD( SSEMatrix4x4SubtractionTest )
		{
			Matrix4x4 m1(
			1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f,
			13.0f, 14.0f, 15.0f, 16.0f
			);

			Matrix4x4 m2(
			17.0f, 18.0f, 19.0f, 20.0f,
			21.0f, 22.0f, 23.0f, 24.0f,
			25.0f, 26.0f, 27.0f, 28.0f,
			29.0f, 30.0f, 31.0f, 32.0f
			);

			Matrix4x4 result = m1 - m2;

			m1 -= m2;

			Matrix4x4 expected(
			-16.0f, -16.0f, -16.0f, -16.0f,
			-16.0f, -16.0f, -16.0f, -16.0f,
			-16.0f, -16.0f, -16.0f, -16.0f,
			-16.0f, -16.0f, -16.0f, -16.0f
			);

			MatrixAreEqual( result, expected );

			MatrixAreEqual( m1, expected );
		}

		TEST_METHOD( SSEMatrix4x4AdditionTest )
		{
			Matrix4x4 m1(
			1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f,
			13.0f, 14.0f, 15.0f, 16.0f
			);

			Matrix4x4 m2(
			17.0f, 18.0f, 19.0f, 20.0f,
			21.0f, 22.0f, 23.0f, 24.0f,
			25.0f, 26.0f, 27.0f, 28.0f,
			29.0f, 30.0f, 31.0f, 32.0f
			);

			Matrix4x4 result = m1 + m2;

			m1 += m2;

			Matrix4x4 expected(
			18.0f, 20.0f, 22.0f, 24.0f,
			26.0f, 28.0f, 30.0f, 32.0f,
			34.0f, 36.0f, 38.0f, 40.0f,
			42.0f, 44.0f, 46.0f, 48.0f
			);

			MatrixAreEqual( result, expected );

			MatrixAreEqual( m1, expected );
		}

		TEST_METHOD( SSEMatrix4x4InvertTest )
		{
			Matrix4x4 m
			(
			1.0f, 0.0f, 0.0f, 4.0f,
			0.0f, 1.0f, 0.0f, 8.0f,
			0.0f, 0.0f, 1.0f, 12.0f,
			0.0f, 0.0f, 0.0f, 1.0f
			);

			Assert::AreEqual( 1.0f, m.GetM_1_1() );
			Assert::AreEqual( 0.0f, m.GetM_1_2() );
			Assert::AreEqual( 0.0f, m.GetM_1_3() );
			Assert::AreEqual( 4.0f, m.GetM_1_4() );
			Assert::AreEqual( 0.0f, m.GetM_2_1() );
			Assert::AreEqual( 1.0f, m.GetM_2_2() );
			Assert::AreEqual( 0.0f, m.GetM_2_3() );
			Assert::AreEqual( 8.0f, m.GetM_2_4() );
			Assert::AreEqual( 0.0f, m.GetM_3_1() );
			Assert::AreEqual( 0.0f, m.GetM_3_2() );
			Assert::AreEqual( 1.0f, m.GetM_3_3() );
			Assert::AreEqual( 12.0f, m.GetM_3_4() );
			Assert::AreEqual( 0.0f, m.GetM_4_1() );
			Assert::AreEqual( 0.0f, m.GetM_4_2() );
			Assert::AreEqual( 0.0f, m.GetM_4_3() );
			Assert::AreEqual( 1.0f, m.GetM_4_4() );

			m = m * m.InvertedCopy();

			Assert::IsTrue( m.GetM_1_1() < 1.001f && m.GetM_1_1() > 0.999f );
			Assert::IsTrue( m.GetM_1_2() < 0.001f && m.GetM_1_2() > -0.001f );
			Assert::IsTrue( m.GetM_1_3() < 0.001f && m.GetM_1_3() > -0.001f );
			Assert::IsTrue( m.GetM_1_4() < 0.001f && m.GetM_1_4() > -0.001f );

			Assert::IsTrue( m.GetM_2_1() < 0.001f && m.GetM_2_1() > -0.001f );
			Assert::IsTrue( m.GetM_2_2() < 1.001f && m.GetM_2_2() > 0.999f );
			Assert::IsTrue( m.GetM_2_3() < 0.001f && m.GetM_2_3() > -0.001f );
			Assert::IsTrue( m.GetM_2_4() < 0.001f && m.GetM_2_4() > -0.001f );

			Assert::IsTrue( m.GetM_3_1() < 0.001f && m.GetM_3_1() > -0.001f );
			Assert::IsTrue( m.GetM_3_2() < 0.001f && m.GetM_3_2() > -0.001f );
			Assert::IsTrue( m.GetM_3_3() < 1.001f && m.GetM_3_3() > 0.999f );
			Assert::IsTrue( m.GetM_3_4() < 0.001f && m.GetM_3_4() > -0.001f );

			Assert::IsTrue( m.GetM_4_1() < 0.001f && m.GetM_4_1() > -0.001f );
			Assert::IsTrue( m.GetM_4_2() < 0.001f && m.GetM_4_2() > -0.001f );
			Assert::IsTrue( m.GetM_4_3() < 0.001f && m.GetM_4_3() > -0.001f );
			Assert::IsTrue( m.GetM_4_4() < 1.001f && m.GetM_4_4() > 0.999f );

			// Assert::AreEqual(1.0f, m.GetM_1_1() );
			// Assert::AreEqual(0.0f, m.GetM_1_2() );
			// Assert::AreEqual(0.0f, m.GetM_1_3() );
			// Assert::AreEqual(0.0f, m.GetM_1_4() );
			// Assert::AreEqual(0.0f, m.GetM_2_1() );
			// Assert::AreEqual(1.0f, m.GetM_2_2() );
			// Assert::AreEqual(0.0f, m.GetM_2_3() );
			// Assert::AreEqual(0.0f, m.GetM_2_4() );
			// Assert::AreEqual(0.0f, m.GetM_3_1() );
			// Assert::AreEqual(0.0f, m.GetM_3_2() );
			// Assert::AreEqual(1.0f, m.GetM_3_3() );
			// Assert::AreEqual(0.0f, m.GetM_3_4() );
			// Assert::AreEqual(0.0f, m.GetM_4_1() );
			// Assert::AreEqual(0.0f, m.GetM_4_2() );
			// Assert::AreEqual(0.0f, m.GetM_4_3() );
			// Assert::AreEqual(1.0f, m.GetM_4_4() );
		}

		TEST_METHOD( MatrixMult )
		{
			Matrix4x4 m1(
			1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 10.0f, 11.0f, 12.0f,
			13.0f, 14.0f, 15.0f, 16.0f
			);

			Matrix4x4 m2(
			17.0f, 18.0f, 19.0f, 20.0f,
			21.0f, 22.0f, 23.0f, 24.0f,
			25.0f, 26.0f, 27.0f, 28.0f,
			29.0f, 30.0f, 31.0f, 32.0f
			);

			Matrix4x4 result = m1 * m2;

			m1 *= m2;

			Matrix4x4 expected(
			250.0f, 260.0f, 270.0f, 280.0f,
			618.0f, 644.0f, 670.0f, 696.0f,
			986.0f, 1028.0f, 1070.0f, 1112.0f,
			1354.0f, 1412.0f, 1470.0f, 1528.0f
			);

			MatrixAreEqual( result, expected );

			MatrixAreEqual( m1, expected );
		}
	};
}
