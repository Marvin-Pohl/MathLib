#include "precompiledHeader.h"

namespace LinearMath
{

	class DLLExport Vector3
	{

public:

		Vector3( void );

		Vector3( Scalar val );

		Vector3( Scalar x, Scalar y , Scalar z);

		~Vector3( void );

		/**
		Operators
		
		*/

		// + Operators
		Vector3 operator +( const Vector3& v );
		Vector3 &operator +=( const Vector3& v );

		// - Operators
		Vector3 operator -( const Vector3& v );
		Vector3 &operator -=( const Vector3& v );

		// * Operators
		Vector3 operator *( const Scalar& scalar );
		Vector3 &operator *=( const Scalar& scalar );

		Scalar operator *( const Vector3& v );

		// / Operators
		Vector3 operator /( const Scalar& scalar );
		Vector3 &operator /=( const Scalar& scalar );

		//^ Operators
		Vector3 operator ^( const Vector3& v);

		Scalar X;
		Scalar Y;
		Scalar Z;

		// Methods

		Scalar LengthSquared();
		Scalar Length();
		void Normalize();
		Vector3 NormalizedCopy();
		Vector3 CrossProduct( const Vector3& v );

protected:

private:

	};
}
