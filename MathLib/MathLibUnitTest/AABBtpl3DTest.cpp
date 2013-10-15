#include "stdafx.hpp"
#include "CppUnitTest.h"
#include "Vector3.hpp"
#include "ClassicalMechanics/Volumes/AABB.hpp"

using namespace ClassicalMechanics::Volumes;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template class __declspec ( dllexport )LinearMath::Vector3_tpl< float >;

template class __declspec ( dllexport )AABB_tpl< LinearMath::Vector3_tpl< float > >;

typedef LinearMath::Vector3_tpl< float > Vector3;
typedef AABB_tpl< LinearMath::Vector3_tpl< float > > AABB_tpl3D;

namespace MathLibUnitTest
{
	TEST_CLASS( AABB_tpl3DTestClass )
	{
	public:

		TEST_METHOD( AABBConstructorTest )
		{
			AABB_tpl3D aabb( Vector3( 0.0f, 0.0f, 0.0f ), Vector3( 1.0f, 1.0f, 1.0f ) );

			Vector3 min = aabb.Min();
			Vector3 max = aabb.Max();

			Assert::AreEqual( 0.0f, min.X );
			Assert::AreEqual( 0.0f, min.Y );
			Assert::AreEqual( 0.0f, min.Z );
			Assert::AreEqual( 1.0f, max.X );
			Assert::AreEqual( 1.0f, max.Y );
			Assert::AreEqual( 1.0f, max.X );

			aabb = AABB_tpl3D( Vector3( 1.0f, 1.0f, 1.0f ), Vector3( 0.0f, 0.0f, 0.0f ) );

			min = aabb.Min();
			max = aabb.Max();

			Assert::AreEqual( 0.0f, min.X );
			Assert::AreEqual( 0.0f, min.Y );
			Assert::AreEqual( 0.0f, min.Z );
			Assert::AreEqual( 1.0f, max.X );
			Assert::AreEqual( 1.0f, max.Y );
			Assert::AreEqual( 1.0f, max.X );
		}

		TEST_METHOD( AABBIntersectTest )
		{
			AABB_tpl3D aabb1 = AABB_tpl3D( Vector3( 0.0f ), Vector3( 2.0f ) );
			AABB_tpl3D aabb2 = AABB_tpl3D( Vector3( 1.0f ), Vector3( 3.0f ) );
			AABB_tpl3D aabb3 = AABB_tpl3D( Vector3( 10.0f ), Vector3( 20.0f ) );

			Assert::IsTrue( aabb1.Intersects( aabb2 ) );
			Assert::IsTrue( aabb2.Intersects( aabb1 ) );
			Assert::IsFalse( aabb1.Intersects( aabb3 ) );
			Assert::IsFalse( aabb3.Intersects( aabb1 ) );
			Assert::IsTrue( aabb1.Intersects( aabb1 ) );
		}

		TEST_METHOD( AABBContainsTest )
		{
			AABB_tpl3D aabb1 = AABB_tpl3D( Vector3( 0.0f ), Vector3( 1.0f ) );
			AABB_tpl3D aabb2 = AABB_tpl3D( Vector3( 0.1f ), Vector3( 0.9f ) );
			AABB_tpl3D aabb3 = AABB_tpl3D( Vector3( 0.0f ), Vector3( 0.1f, 2.0f, 1.0f ) );

			Vector3 point1( 0.5f );
			Vector3 point2( 1.0f );
			Vector3 point3( 2.0f );

			Assert::IsTrue( aabb1.Contains( point1 ) );
			Assert::IsTrue( aabb1.Contains( point2 ) );
			Assert::IsFalse( aabb1.Contains( point3 ) );
			Assert::IsTrue( aabb1.Contains( aabb2 ) );
			Assert::IsFalse( aabb1.Contains( aabb3 ) );
		}

		TEST_METHOD( AABBFillBounds )
		{
			AABB_tpl3D aabb( Vector3( 0.0f ), Vector3( 1.0f ) );

			Vector3 tmp[ 10 ] =
			{
				Vector3( -1.0f ), Vector3( -1.0f ), Vector3( -1.0f ), Vector3( -1.0f ), Vector3( -1.0f ),
				Vector3( -1.0f ), Vector3( -1.0f ),
				Vector3( -1.0f ), Vector3( -1.0f ), Vector3( -1.0f )
			};

			aabb.FillBounds( tmp + 1 );

			Assert::IsTrue( tmp[ 0 ] == Vector3( -1.0f ) );
			Assert::IsTrue( tmp[ 1 ] == Vector3( 0.0f ) );
			Assert::IsTrue( tmp[ 2 ] == Vector3( 1.0f, 0.0f, 0.0f ) );
			Assert::IsTrue( tmp[ 3 ] == Vector3( 0.0f, 1.0f, 0.0f ) );
			Assert::IsTrue( tmp[ 4 ] == Vector3( 1.0f, 1.0f, 0.0f ) );
			Assert::IsTrue( tmp[ 5 ] == Vector3( 0.0f, 0.0f, 1.0f ) );
			Assert::IsTrue( tmp[ 6 ] == Vector3( 1.0f, 0.0f, 1.0f ) );
			Assert::IsTrue( tmp[ 7 ] == Vector3( 0.0f, 1.0f, 1.0f ) );
			Assert::IsTrue( tmp[ 8 ] == Vector3( 1.0f, 1.0f, 1.0f ) );
			Assert::IsTrue( tmp[ 9 ] == Vector3( -1.0f ) );
		}
	};
}
