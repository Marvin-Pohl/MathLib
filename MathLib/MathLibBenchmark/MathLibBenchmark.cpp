// MathLibBenchmark.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SSEVector3.h>

using namespace LinearMath;

int _tmain(int argc, _TCHAR* argv[])
{
	SSEVector3 test1(151,32,876);
	SSEVector3 test2(561,24,313);

	SSEVector3 res = test1 ^ test2;

	printf("Values: %f, %f, %f\n", res.GetX(), res.GetY(), res.GetZ());

	return 0;
}

