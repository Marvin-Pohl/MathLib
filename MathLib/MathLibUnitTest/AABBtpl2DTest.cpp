#include "stdafx.hpp"
#include "CppUnitTest.h"
#include "Vector2.hpp"
#include "ClassicalMechanics/Volumes/AABB.hpp"

using namespace ClassicalMechanics::Volumes;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template class __declspec ( dllexport )LinearMath::Vector2_tpl< float >;

template class __declspec ( dllexport )AABB_tpl< LinearMath::Vector2_tpl< float > >;

typedef LinearMath::Vector2_tpl< float > Vector2;
typedef AABB_tpl< LinearMath::Vector2_tpl< float > > AABB_tpl2D;

namespace MathLibUnitTest
{
	TEST_CLASS( AABB_tpl2DTestClass )
	{
	public:

		TEST_METHOD( AABBConstructorTest )
		{
			AABB_tpl2D aabb( Vector2( 0.0f, 0.0f ), Vector2( 1.0f, 1.0f ) );

			Vector2 min = aabb.Min();
			Vector2 max = aabb.Max();

			Assert::AreEqual( 0.0f, min.X );
			Assert::AreEqual( 0.0f, min.Y );
			Assert::AreEqual( 1.0f, max.X );
			Assert::AreEqual( 1.0f, max.Y );

			aabb = AABB_tpl2D( Vector2( 1.0f, 1.0f ), Vector2( 0.0f, 0.0f ) );

			min = aabb.Min();
			max = aabb.Max();

			Assert::AreEqual( 0.0f, min.X );
			Assert::AreEqual( 0.0f, min.Y );
			Assert::AreEqual( 1.0f, max.X );
			Assert::AreEqual( 1.0f, max.Y );
		}

		TEST_METHOD( AABBIntersectTest )
		{
			AABB_tpl2D aabb1 = AABB_tpl2D( Vector2( 0.0f ), Vector2( 2.0f ) );
			AABB_tpl2D aabb2 = AABB_tpl2D( Vector2( 1.0f ), Vector2( 3.0f ) );
			AABB_tpl2D aabb3 = AABB_tpl2D( Vector2( 10.0f ), Vector2( 20.0f ) );

			Assert::IsTrue( aabb1.Intersects( aabb2 ) );
			Assert::IsTrue( aabb2.Intersects( aabb1 ) );
			Assert::IsFalse( aabb1.Intersects( aabb3 ) );
			Assert::IsFalse( aabb3.Intersects( aabb1 ) );
			Assert::IsTrue( aabb1.Intersects( aabb1 ) );
		}

		TEST_METHOD( AABBContainsTest )
		{
			AABB_tpl2D aabb1 = AABB_tpl2D( Vector2( 0.0f ), Vector2( 1.0f ) );
			AABB_tpl2D aabb2 = AABB_tpl2D( Vector2( 0.1f ), Vector2( 0.9f ) );
			AABB_tpl2D aabb3 = AABB_tpl2D( Vector2( 0.0f ), Vector2( 0.1f, 2.0f) );

			Vector2 point1( 0.5f );
			Vector2 point2( 1.0f );
			Vector2 point3( 2.0f );

			Assert::IsTrue( aabb1.Contains( point1 ) );
			Assert::IsTrue( aabb1.Contains( point2 ) );
			Assert::IsFalse( aabb1.Contains( point3 ) );
			Assert::IsTrue( aabb1.Contains( aabb2 ) );
			Assert::IsFalse( aabb1.Contains( aabb3 ) );
		}
	};
}
