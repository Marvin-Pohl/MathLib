#include "precompiledHeader.h"

namespace LinearMath
{

	class DLLExport Vector2
	{

	public:

		Vector2( void );

		Vector2(Scalar val);

		Vector2(Scalar x, Scalar y);

		~Vector2( void );

		/**
		Operators
		
		*/

		//+

		Vector2 operator +(const Vector2& v);
		Vector2& operator +=(const Vector2& v);


		//-
		Vector2 operator -(const Vector2& v);
		Vector2& operator -=(const Vector2& v);

		//*
		Vector2 operator *(const Scalar& scalar);
		Vector2& operator *=(const Scalar& scalar);

		// /
		Vector2 operator /(const Scalar& scalar);
		Vector2& operator /=(const Scalar& scalar);



private:

		Scalar m_X;
		Scalar m_Y;

	};
}
