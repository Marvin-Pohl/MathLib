#include "stdafx.hpp"
#include "CppUnitTest.h"
#include "Vector3.hpp"
#include "ClassicalMechanics/Volumes/AABB3D.hpp"

using namespace ClassicalMechanics::Volumes;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template class __declspec ( dllexport )LinearMath::Vector3_tpl< float >;
template class __declspec ( dllexport )LinearMath::Vector3_tpl< double >;

template class __declspec ( dllexport )AABB3D_tpl< float >;
template class __declspec ( dllexport )AABB3D_tpl< double >;

typedef LinearMath::Vector3_tpl< float > Vector3;
typedef AABB3D_tpl< float > AABB3D;

namespace MathLibUnitTest
{
	TEST_CLASS( AABB3DTestClass )
	{
	public:

		TEST_METHOD( AABB3DConstructorTest )
		{
			AABB3D aabb( Vector3( 0.0f, 0.0f, 0.0f ), Vector3( 1.0f, 1.0f, 1.0f ) );

			Vector3 min = aabb.Min();
			Vector3 max = aabb.Max();

			Assert::AreEqual( 0.0f, min.X );
			Assert::AreEqual( 0.0f, min.Y );
			Assert::AreEqual( 0.0f, min.Z );
			Assert::AreEqual( 1.0f, max.X );
			Assert::AreEqual( 1.0f, max.Y );
			Assert::AreEqual( 1.0f, max.X );

			aabb = AABB3D( Vector3( 1.0f, 1.0f, 1.0f ), Vector3( 0.0f, 0.0f, 0.0f ) );

			min = aabb.Min();
			max = aabb.Max();

			Assert::AreEqual( 0.0f, min.X );
			Assert::AreEqual( 0.0f, min.Y );
			Assert::AreEqual( 0.0f, min.Z );
			Assert::AreEqual( 1.0f, max.X );
			Assert::AreEqual( 1.0f, max.Y );
			Assert::AreEqual( 1.0f, max.X );
		}

		TEST_METHOD( AABB3DIntersectTest )
		{
			AABB3D aabb1 = AABB3D( Vector3( 0.0f ), Vector3( 2.0f ) );
			AABB3D aabb2 = AABB3D( Vector3( 1.0f ), Vector3( 3.0f ) );
			AABB3D aabb3 = AABB3D( Vector3( 10.0f ), Vector3( 20.0f ) );

			Assert::IsTrue( aabb1.Intersects( aabb2 ) );
			Assert::IsTrue( aabb2.Intersects( aabb1 ) );
			Assert::IsFalse( aabb1.Intersects( aabb3 ) );
			Assert::IsFalse( aabb3.Intersects( aabb1 ) );
			Assert::IsTrue( aabb1.Intersects( aabb1 ) );
		}

		TEST_METHOD( AABB3DContainsTest )
		{
			AABB3D aabb1 = AABB3D( Vector3( 0.0f ), Vector3( 1.0f ) );
			AABB3D aabb2 = AABB3D( Vector3( 0.1f ), Vector3( 0.9f ) );
			AABB3D aabb3 = AABB3D( Vector3( 0.0f ), Vector3( 0.1f, 2.0f, 1.0f ) );

			Vector3 point1( 0.5f );
			Vector3 point2( 1.0f );
			Vector3 point3( 2.0f );

			Assert::IsTrue( aabb1.Contains( point1 ) );
			Assert::IsTrue( aabb1.Contains( point2 ) );
			Assert::IsFalse( aabb1.Contains( point3 ) );
			Assert::IsTrue( aabb1.Contains( aabb2 ) );
			Assert::IsFalse( aabb1.Contains( aabb3 ) );
		}
	};
}
