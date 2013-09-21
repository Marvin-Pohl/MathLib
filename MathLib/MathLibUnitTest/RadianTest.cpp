#include "stdafx.hpp"
#include "CppUnitTest.h"
#include <MathHelper.hpp>
#include <math.h>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace LinearMath;

typedef LinearMath::Degree_tpl<float> Degree;
typedef LinearMath::Radian_tpl<float> Radian;
typedef LinearMath::MathHelper_tpl<float> MathHelper;

template class __declspec( dllexport ) MathHelper_tpl< float >;
template class __declspec( dllexport ) Degree_tpl< float >;
template class __declspec( dllexport ) Radian_tpl< float >;


namespace MathLibUnitTest
{		
	TEST_CLASS(RadianTestClass)
	{
		TEST_METHOD(RadianConstructors)
		{
			Radian rad = Radian();

			Assert::AreEqual(0.0f,rad.AsRadianValue());

			Radian rad1 = Radian(1.0f);

			Assert::AreEqual(1.0f,rad1.AsRadianValue());

			Radian rad2 = Radian( rad1 );

			Assert::AreEqual(1.0f,rad2.AsRadianValue());
		}

		TEST_METHOD(RadianCasts)
		{
			Radian rad3 = (Radian) 1.0f;

			Assert::AreEqual(1.0f,rad3.AsRadianValue());

			Radian rad4 = static_cast<Radian> (1.0f);

			Assert::AreEqual(1.0f,rad4.AsRadianValue());

		}

		TEST_METHOD(AssignOperators)
		{
			Radian rad1;

			rad1 = Radian(1.0f);

			Assert::AreEqual(1.0f,rad1.AsRadianValue());

			rad1 = Degree(180.0f);

			Assert::AreEqual(MathHelper::GetPI(),rad1.AsRadianValue());
		}
	};
}