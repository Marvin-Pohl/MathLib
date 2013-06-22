#include "stdafx.hpp"
#include "CppUnitTest.h"
#include "Quaternion.hpp"
#include "MathHelper.hpp"

using namespace LinearMath;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef Quaternion_tpl< float > Quaternion;

namespace MathLibUnitTest
{
	void CompareQuaternion( const Quaternion& quat1, const Quaternion& quat2 )
	{
		Assert::AreEqual( quat1.X, quat2.X );
		Assert::AreEqual( quat1.Y, quat2.Y );
		Assert::AreEqual( quat1.Z, quat2.Z );
		Assert::AreEqual( quat1.W, quat2.W );
	}

	void CompareQuaternion( const float w, const float x, const float y, const float z, const Quaternion& quat2 )
	{
		Assert::AreEqual( w, quat2.W );
		Assert::AreEqual( x, quat2.X );
		Assert::AreEqual( y, quat2.Y );
		Assert::AreEqual( z, quat2.Z );
	}

	TEST_CLASS( QuaternionTestClass )
	{
	public:

		TEST_METHOD( QuaternionConstructors )
		{
			Quaternion quat;

			CompareQuaternion( 1.0f, 0.0f, 0.0f, 0.0f, quat );

			quat = Quaternion( 1.0f, 2.0f, 3.0f, 4.0f );

			CompareQuaternion( 1.0f, 2.0f, 3.0f, 4.0f, quat );

			quat = Quaternion( Vector3_tpl< float >( 0.0f, 1.0f, 0.0f ), Degree_tpl< float >( 90.0f ) );

			CompareQuaternion( MathHelper_tpl< float >::Cos( Degree_tpl<  float >(
				90.0f ) / 2 ), 0.0f,
				MathHelper_tpl< float >::Sin( Degree_tpl< float >( 90.0f ) / 2 ), 0.0f, quat );
		}

		TEST_METHOD( QuaternionStaticMethods )
		{
		}

		TEST_METHOD( QuaternionOperators )
		{
		}
	};
}
