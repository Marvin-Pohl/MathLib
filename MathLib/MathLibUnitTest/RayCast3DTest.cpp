#include "stdafx.hpp"
#include "CppUnitTest.h"
#include "ClassicalMechanics/Algorithms/Ray.hpp"
#include <math.h>
#include <string>

using namespace ClassicalMechanics::Algorithms;
using namespace LinearMath;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef Vector3_tpl< float > Vector3;
typedef ClassicalMechanics::Algorithms::Ray3D_tpl< float > Ray3D;

template class __declspec ( dllexport )Vector3_tpl< float >;
template class __declspec ( dllexport )Ray3D_tpl< float >;

namespace MathLibUnitTest
{
	TEST_CLASS( Ray3dTestClass )
	{
	public:

		TEST_METHOD( Ray3DTest )
		{
			Ray3D ray( Vector3( 0.5f, 0.5f, 0.5f ), Vector3( -1.0f, 0.0f, 0.0f ), 100.0f );

			const Vector3 triangle[] =
			{
				Vector3( 0.0f ), Vector3( 0.0f, 0.0f, 3.0f ), Vector3( 0.0f, 3.0f, 0.0f )
			};

			RayResult_tpl< float > result = ray.CheckCollisionTriangle( triangle );

			Assert::IsTrue( result.CollisionOccurred() );
			Assert::AreEqual( 0.0f, result.CollisionPoint().X );
			Assert::AreEqual( 0.5f, result.CollisionPoint().Y );
			Assert::AreEqual( 0.5f, result.CollisionPoint().Z );

			ray = Ray3D( Vector3( 3.0f, 3.0f, 0.5f ), Vector3( -1.0f, 0.0f, 0.0f ), 100.0f );

			result = ray.CheckCollisionTriangle( triangle );
			Assert::IsFalse( result.CollisionOccurred() );
			Assert::AreEqual( 0.0f, result.CollisionPoint().X );
			Assert::AreEqual( 0.0f, result.CollisionPoint().Y );
			Assert::AreEqual( 0.0f, result.CollisionPoint().Z );


			ray = Ray3D( Vector3( 2.0f, 2.0f, 0.5f ), Vector3( -1.0f, 0.0f, 0.0f ), 100.0f );

			result = ray.CheckCollisionTriangle( triangle );
			Assert::IsTrue( result.CollisionOccurred() );
			Assert::AreEqual( 0.0f, result.CollisionPoint().X );
			Assert::AreEqual( 2.0f, result.CollisionPoint().Y );
			Assert::AreEqual( 0.5f, result.CollisionPoint().Z );

			ray = Ray3D( Vector3( 0.0f, 1.55121f, 1.55098f ), Vector3( -1.0f, 0.0f, 0.0f ), 100.0f );

			result = ray.CheckCollisionTriangle( triangle );
			Assert::IsFalse( result.CollisionOccurred() );
			Assert::AreEqual( 0.0f, result.CollisionPoint().X );
			Assert::AreEqual( 0.0f, result.CollisionPoint().Y );
			Assert::AreEqual( 0.0f, result.CollisionPoint().Z );

			ray = Ray3D( Vector3( 0.5f, -0.16438f, 1.35815f ), Vector3( -1.0f, 0.0f, 0.0f ), 100.0f );

			result = ray.CheckCollisionTriangle( triangle );
			Assert::IsFalse( result.CollisionOccurred() );
			Assert::AreEqual( 0.0f, result.CollisionPoint().X );
			Assert::AreEqual( 0.0f, result.CollisionPoint().Y );
			Assert::AreEqual( 0.0f, result.CollisionPoint().Z );

			ray = Ray3D( Vector3( 0.5f, -0.16438f, 1.35815f ), Vector3( -1.0f, 1.67578f, 0.0f ), 100.0f );

			result = ray.CheckCollisionTriangle( triangle );
			Assert::IsTrue( result.CollisionOccurred() );

		}
	};
}
