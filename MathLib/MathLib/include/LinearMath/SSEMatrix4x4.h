#pragma once

#include "MathLibPCH.h"
#include <xmmintrin.h>

#ifndef SSEMatrix4x4_h__
#define SSEMatrix4x4_h__

namespace LinearMath
{
	class SSEMatrix4x4
	{
	public:
		SSEMatrix4x4();
		~SSEMatrix4x4();

	private:

		__m128 col0, col1, col2, col3;

	};
}

#endif // SSEMatrix4x4_h__