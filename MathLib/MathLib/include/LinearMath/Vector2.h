#include "precompiledHeader.h"

namespace LinearMath
{

	class DLLExport Vector2
	{

public:

		Vector2( void );

		Vector2( Scalar val );

		Vector2( Scalar x, Scalar y );

		~Vector2( void );

		/**
		Operators
		
		*/

		// + Operators
		Vector2 operator +( const Vector2& v );
		Vector2 &operator +=( const Vector2& v );

		// - Operators
		Vector2 operator -( const Vector2& v );
		Vector2 &operator -=( const Vector2& v );

		// * Operators
		Vector2 operator *( const Scalar& scalar );
		Vector2 &operator *=( const Scalar& scalar );

		Scalar operator *( const Vector2& v );

		// / Operators
		Vector2 operator /( const Scalar& scalar );
		Vector2 &operator /=( const Scalar& scalar );

		Scalar X;
		Scalar Y;

		// Methods

		Scalar LengthSquared();
		Scalar Length();
		void Normalize();
		Vector2 NormalizedCopy();
		Vector2 PerpDotProduct(const Vector2& v);
		Scalar DotProduct( const Vector2& v);

protected:

private:

	};
}
