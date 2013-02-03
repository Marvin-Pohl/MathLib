#pragma once
#ifndef _MP_VECTOR_2_H_
#define _MP_VECTOR_2_H_

#include "precompiledHeader.h"

namespace LinearMath
{

	class DLLExport Vector2
	{

public:

		Vector2( void );

		Vector2( Scalar val );

		Vector2( Scalar x, Scalar y );

		~ Vector2( void );

		/**
		Operators
		
		*/

		// + Operators
		Vector2 operator +( const Vector2& v ) const;
		Vector2 &operator +=( const Vector2& v );

		// - Operators
		Vector2 operator -( const Vector2& v ) const;
		Vector2 &operator -=( const Vector2& v );

		// * Operators
		Vector2 operator *( const Scalar& scalar ) const;
		Vector2 &operator *=( const Scalar& scalar );
		inline friend Vector2 operator*( const Scalar& scalar, const Vector2& v )
		{
			return Vector2( scalar * v.X, scalar * v.Y );
		}

		Scalar operator *( const Vector2& v ) const;

		// / Operators
		Vector2 operator /( const Scalar& scalar ) const;
		Vector2 &operator /=( const Scalar& scalar );

		Scalar X;
		Scalar Y;

		// Methods
		Scalar LengthSquared( void ) const;
		Scalar Length( void ) const;
		void Normalize( void );
		Vector2 NormalizedCopy( void ) const;
		Scalar PerpDotProduct( const Vector2& v ) const;
		Scalar DotProduct( const Vector2& v ) const;

protected:

private:

	};
}
#endif