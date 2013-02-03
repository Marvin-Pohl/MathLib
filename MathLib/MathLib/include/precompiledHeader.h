#pragma once

/**
Precompiled header for the MathLib

*/
#define DLLImport	__declspec( dllimport )
#define DLLExport	__declspec( dllexport )

//#define _DOUBLE_PRECISION

#ifdef _DOUBLE_PRECISION
typedef double Scalar;
#else
typedef float Scalar;
#endif