// MathLibBenchmark.cpp : Defines the entry point for the console application.

//

#include "stdafx.hpp"

// #include <SSEVector3.h>
#include <windows.h>

// #include "Matrix4x4.hpp"
#include <iostream>
#include "Quaternion.hpp"

using namespace LinearMath;

int _tmain( int argc, _TCHAR* argv[] )
{
	// SSEVector3 test1(151,32,876);
	// SSEVector3 test2(561,24,313);
	//
	// SSEVector3 res = test1 ^ test2;
	//
	// printf("Values: %f, %f, %f\n", res.GetX(), res.GetY(), res.GetZ());
	LARGE_INTEGER frequenzy, start, end;

	// typedef Matrix4x4_tpl<float> Matrix4;

	typedef Quaternion_tpl< float > Quaternion;

	// Matrix4 res2;

	QueryPerformanceFrequency( &frequenzy );

	float a = 1.0f;
	float b = 2.0f;
	float c = 3.0f;
	float d = 4.0f;
	float e = 5.0f;
	float f = 6.0f;
	float g = 7.0f;
	float h = 8.0f;
	float i = 9.0f;
	float j = 10.0f;
	float k = 11.0f;
	float l = 12.0f;
	float m = 13.0f;
	float n = 14.0f;
	float o = 15.0f;
	float p = 16.0f;

	QueryPerformanceCounter( &start );

	// Add Benchmark here

	QueryPerformanceCounter( &end );

	std::cout << "Load Val: " << ( end.LowPart - start.LowPart ) / ( float )frequenzy.LowPart << std::endl;

	return 0;
}
