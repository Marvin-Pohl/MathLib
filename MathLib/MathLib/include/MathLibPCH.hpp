#pragma once

/**
Precompiled header for the MathLib

*/
#define MATHLIB_DLL_IMPORT  __declspec( dllimport )
#define MATHLIB_DLL_EXPORT  __declspec( dllexport )

#ifdef BUILD_MATHLIB_API
#define MATHLIB_API MATHLIB_DLL_EXPORT
#else
#define MATHLIB_API MATHLIB_DLL_IMPORT
#endif // BUILD_MATHLIB_API

namespace Numerics
{
  typedef signed char int8;
  typedef unsigned char uint8;
  typedef signed short int16;
  typedef unsigned short uint16;
  typedef signed int int32;
  typedef unsigned int uint32;
  typedef signed long long int64;
  typedef unsigned long long uint64;
}
