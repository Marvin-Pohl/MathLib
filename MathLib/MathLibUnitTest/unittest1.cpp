#include "stdafx.hpp"
#include "CppUnitTest.h"
#include <Vector2.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathLibUnitTest
{
	TEST_CLASS( UnitTest1 )
	{
	public:

		TEST_METHOD( TestRuns )
		{
			Assert::AreEqual( 1, 1 );
		}
	};
}
