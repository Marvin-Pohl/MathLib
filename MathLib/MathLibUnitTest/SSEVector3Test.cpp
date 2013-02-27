#include "stdafx.h"
#include "CppUnitTest.h"
#include <SSEVector3.h>
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace LinearMath;

typedef float Scalar;

//typedef LinearMath::SSEVector3 SSEVector3;

namespace MathLibUnitTest
{		

	TEST_CLASS(SSEVector3Test)
	{
	public:

		TEST_METHOD(SSEVector3Constructor1)
		{
			SSEVector3 v;

			Assert::AreEqual(0.0f, v.GetX());
			Assert::AreEqual(0.0f, v.GetY());
			Assert::AreEqual(0.0f, v.GetZ());
		}

		TEST_METHOD(SSEVector3Constructor2)
		{
			SSEVector3 v(5);

			Assert::AreEqual(5.0f, v.GetX());
			Assert::AreEqual(5.0f, v.GetY());
			Assert::AreEqual(5.0f, v.GetZ());
		}

		TEST_METHOD(SSEVector3Constructor3)
		{
			SSEVector3 v(2.5f,3.7f,42.0f);

			Assert::AreEqual(2.5f, v.GetX());
			Assert::AreEqual(3.7f, v.GetY());
			Assert::AreEqual(42.0f, v.GetZ());

		}

		TEST_METHOD(SSEVector3Add)
		{
			SSEVector3 v1(10,20,30);
			SSEVector3 v2(40,50,60);

			SSEVector3 v3 = v1 + v2;

			Assert::AreEqual(v1.GetX() + v2.GetX(), v3.GetX());
			Assert::AreEqual(v1.GetY() + v2.GetY(), v3.GetY());
			Assert::AreEqual(v1.GetZ() + v2.GetZ(), v3.GetZ());
		}

		TEST_METHOD(SSEVector3Add2)
		{
			SSEVector3 v1(10,20,30);
			SSEVector3 v2(40,50,60);

			v1 += v2;

			Assert::AreEqual(50.0f, v1.GetX());
			Assert::AreEqual(70.0f, v1.GetY());
			Assert::AreEqual(90.0f, v1.GetZ());
		}

		TEST_METHOD(SSEVector3Sub1)
		{
			SSEVector3 v1(10,20,30);
			SSEVector3 v2(40,50,60);

			SSEVector3 v3 = v1 - v2;

			Assert::AreEqual(v1.GetX() - v2.GetX(), v3.GetX());
			Assert::AreEqual(v1.GetY() - v2.GetY(), v3.GetY());
			Assert::AreEqual(v1.GetZ() - v2.GetZ(), v3.GetZ());
		}

		TEST_METHOD(SSEVector3Sub2)
		{
			SSEVector3 v1(10,20,30);
			SSEVector3 v2(40,50,60);

			v1 -= v2;

			Assert::AreEqual(-30.0f, v1.GetX());
			Assert::AreEqual(-30.0f, v1.GetY());
			Assert::AreEqual(-30.0f, v1.GetZ());
		}

		TEST_METHOD(SSEVector3Mult1)
		{
			SSEVector3 v(10,20,30);
			Scalar scal = 10;

			SSEVector3 out = v*scal;

			Assert::AreEqual(100.0f, out.GetX());
			Assert::AreEqual(200.0f, out.GetY());
			Assert::AreEqual(300.0f, out.GetZ());
		}

		TEST_METHOD(SSEVector3Mult2)
		{
			SSEVector3 v(10,20,30);
			Scalar scal = 10;

			v*=scal;

			Assert::AreEqual(100.0f, v.GetX());
			Assert::AreEqual(200.0f, v.GetY());
			Assert::AreEqual(300.0f, v.GetZ());
		}

		TEST_METHOD(SSEVector3Mult3)
		{
			SSEVector3 v(10,20,30);
			Scalar scal = 10;

			SSEVector3 out = scal * v;

			Assert::AreEqual(100.0f, out.GetX());
			Assert::AreEqual(200.0f, out.GetY());
		}

		TEST_METHOD(SSEVector3Mult4)
		{
			SSEVector3 v1(10,20,30);
			SSEVector3 v2(40,50,60);

			Scalar scal = v1*v2;

			Assert::AreEqual(((10.0f*40.0f)+(20.0f*50.0f)+(30.0f*60.0f)), scal);
		}

		TEST_METHOD(SSEVector3Div1)
		{
			SSEVector3 v(10,20,30);
			Scalar scal = 10;

			SSEVector3 out = v/scal;

			Assert::AreEqual(1.0f, out.GetX());
			Assert::AreEqual(2.0f, out.GetY());
			Assert::AreEqual(3.0f, out.GetZ());
		}

		TEST_METHOD(SSEVector3Div2)
		{
			SSEVector3 v(10,20,30);
			Scalar scal = 10;

			v/=scal;

			Assert::AreEqual(1.0f, v.GetX());
			Assert::AreEqual(2.0f, v.GetY());
			Assert::AreEqual(3.0f, v.GetZ());
		}

		TEST_METHOD(SSEVector3LengthSq)
		{
			SSEVector3 v(10,20,30);

			Scalar length = v.LengthSquared();

			Assert::AreEqual((10.0f*10.0f)+(20.0f*20.0f)+(30.0f*30.0f),length);
		}

		TEST_METHOD(SSEVector3Length)
		{
			SSEVector3 v(4,0,-3);

			Scalar length = v.Length();

			Assert::AreEqual(5.0f, length);
		}

		TEST_METHOD(SSEVector3Normalize)
		{
			SSEVector3 v(10,20,30);

			Scalar length = v.Length();

			v.Normalize();

			Assert::AreEqual(10.0f/length, v.GetX());
			Assert::AreEqual(20.0f/length, v.GetY());
			Assert::AreEqual(30.0f/length, v.GetZ());
		}

		TEST_METHOD(SSEVector3NormalizeCopy)
		{
			SSEVector3 v(10.0f,20.0f,30.0f);


			Scalar length = v.Length();
			SSEVector3 out = v.NormalizedCopy();


			Assert::AreEqual(10.0f/length, out.GetX());
			Assert::AreEqual(20.0f/length, out.GetY());
			Assert::AreEqual(30.0f/length, out.GetZ());
			Assert::AreNotEqual(v.GetX(),out.GetX());
			Assert::AreNotEqual(v.GetY(),out.GetY());
			Assert::AreNotEqual(v.GetZ(),out.GetZ());

		}

		TEST_METHOD(SSEVector3DotProduct)
		{
			SSEVector3 v1(10,20,30);
			SSEVector3 v2(40,50,60);

			Scalar scal = v1.DotProduct(v2);

			Assert::AreEqual(((10.0f*40.0f)+(20.0f*50.0f)+(30.0f*60.0f)), scal);
		}

		TEST_METHOD(SSEVector3CrossProduct)
		{
			SSEVector3 v1(1,0,0);
			SSEVector3 v2(0,1,0);

			SSEVector3 out = v1 ^ v2;

			Assert::AreEqual(0.0f, out.GetX());
			Assert::AreEqual(0.0f, out.GetY());
			Assert::AreEqual(1.0f, out.GetZ());
		}
	};
}