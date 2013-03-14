#include "stdafx.h"
#include "CppUnitTest.h"
#include <SSEVector2.h>
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace LinearMath;

typedef float Scalar;

//typedef LinearMath::SSEVector2 SSEVector2;

namespace MathLibUnitTest
{		

	TEST_CLASS(SSEVector2Test)
	{
	public:

		TEST_METHOD(SSEVector2Constructor1)
		{
			SSEVector2 v;

			Assert::AreEqual(0.0f, v.GetX());
			Assert::AreEqual(0.0f, v.GetY());
		}

		TEST_METHOD(SSEVector2Constructor2)
		{
			SSEVector2 v(5);

			Assert::AreEqual(5.0f, v.GetX());
			Assert::AreEqual(5.0f, v.GetY());
		}

		TEST_METHOD(SSEVector2Constructor3)
		{
			SSEVector2 v(2.5f,3.7f);

			Assert::AreEqual(2.5f, v.GetX());
			Assert::AreEqual(3.7f, v.GetY());

		}

		TEST_METHOD(SSEVector2Add)
		{
			SSEVector2 v1(10,20);
			SSEVector2 v2(40,50);

			SSEVector2 v3 = v1 + v2;

			Assert::AreEqual(v1.GetX() + v2.GetX(), v3.GetX());
			Assert::AreEqual(v1.GetY() + v2.GetY(), v3.GetY());
		}

		TEST_METHOD(SSEVector2Add2)
		{
			SSEVector2 v1(10,20);
			SSEVector2 v2(40,50);

			v1 += v2;

			Assert::AreEqual(50.0f, v1.GetX());
			Assert::AreEqual(70.0f, v1.GetY());
		}

		TEST_METHOD(SSEVector2Sub1)
		{
			SSEVector2 v1(10,20);
			SSEVector2 v2(40,50);

			SSEVector2 v3 = v1 - v2;

			Assert::AreEqual(v1.GetX() - v2.GetX(), v3.GetX());
			Assert::AreEqual(v1.GetY() - v2.GetY(), v3.GetY());
		}

		TEST_METHOD(SSEVector2Sub2)
		{
			SSEVector2 v1(10,20);
			SSEVector2 v2(40,50);

			v1 -= v2;

			Assert::AreEqual(-30.0f, v1.GetX());
			Assert::AreEqual(-30.0f, v1.GetY());
		}

		TEST_METHOD(SSEVector2Mult1)
		{
			SSEVector2 v(10,20);
			Scalar scal = 10;

			SSEVector2 out = v*scal;

			Assert::AreEqual(100.0f, out.GetX());
			Assert::AreEqual(200.0f, out.GetY());
		}

		TEST_METHOD(SSEVector2Mult2)
		{
			SSEVector2 v(10,20);
			Scalar scal = 10;

			v*=scal;

			Assert::AreEqual(100.0f, v.GetX());
			Assert::AreEqual(200.0f, v.GetY());
		}

		TEST_METHOD(SSEVector2Mult3)
		{
			SSEVector2 v(10,20);
			Scalar scal = 10;

			SSEVector2 out = scal * v;

			Assert::AreEqual(100.0f, out.GetX());
			Assert::AreEqual(200.0f, out.GetY());
		}

		TEST_METHOD(SSEVector2Mult4)
		{
			SSEVector2 v1(10,20);
			SSEVector2 v2(40,50);

			Scalar scal = v1*v2;

			Assert::AreEqual(((10.0f*40.0f)+(20.0f*50.0f)), scal);
		}

		TEST_METHOD(SSEVector2Div1)
		{
			SSEVector2 v(10,20);
			Scalar scal = 10;

			SSEVector2 out = v/scal;

			Assert::AreEqual(1.0f, out.GetX());
			Assert::AreEqual(2.0f, out.GetY());
		}

		TEST_METHOD(SSEVector2Div2)
		{
			SSEVector2 v(10,20);
			Scalar scal = 10;

			v/=scal;

			Assert::AreEqual(1.0f, v.GetX());
			Assert::AreEqual(2.0f, v.GetY());
		}

		TEST_METHOD(SSEVector2LengthSq)
		{
			SSEVector2 v(10,20);

			Scalar length = v.LengthSquared();

			Assert::AreEqual((10.0f*10.0f)+(20.0f*20.0f),length);
		}

		TEST_METHOD(SSEVector2Length)
		{
			SSEVector2 v(4,-3);

			Scalar length = v.Length();

			Assert::AreEqual(5.0f, length);
		}

		TEST_METHOD(SSEVector2Normalize)
		{
			SSEVector2 v(10,20);

			Scalar length = v.Length();

			v.Normalize();

			Assert::AreEqual(10.0f/length, v.GetX());
			Assert::AreEqual(20.0f/length, v.GetY());
		}

		TEST_METHOD(SSEVector2NormalizeCopy)
		{
			SSEVector2 v(10.0f,20.0f);


			Scalar length = v.Length();
			SSEVector2 out = v.NormalizedCopy();


			Assert::AreEqual(10.0f/length, out.GetX());
			Assert::AreEqual(20.0f/length, out.GetY());
			Assert::AreNotEqual(v.GetX(),out.GetX());
			Assert::AreNotEqual(v.GetY(),out.GetY());

		}

		TEST_METHOD(SSEVector2DotProduct)
		{
			SSEVector2 v1(10,20);
			SSEVector2 v2(40,50);

			Scalar scal = v1.DotProduct(v2);

			Assert::AreEqual(((10.0f*40.0f)+(20.0f*50.0f)), scal);
		}
	};
}