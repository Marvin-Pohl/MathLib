#include "precompiledHeader.h"
#include "Vector3.h"
#include <math.h>

namespace LinearMath
{

	Vector3::Vector3( void ) :
		X( 0 ),
		Y( 0 ),
		Z( 0 )
	{
	}

	Vector3::Vector3( Scalar val ) :
		X( val ),
		Y( val ),
		Z( val )
	{
	}

	Vector3::Vector3( Scalar x, Scalar y, Scalar z ) :
		X( x ),
		Y( y ),
		Z( z )
	{
	}

	Vector3::~Vector3( void )
	{
	}

	LinearMath::Vector3 Vector3::operator+( const Vector3& v )
	{
		return Vector3( X + v.X, Y + v.Y, Z + v.Z );
	}

	Vector3 &Vector3::operator+=( const Vector3& v )
	{
		X += v.X;
		Y += v.Y;
		Z += v.Z;
		return *this;
	}

	LinearMath::Vector3 Vector3::operator-( const Vector3& v )
	{
		return Vector3( X - v.X, Y - v.Y, Z - v.Z );
	}

	Vector3 &Vector3::operator-=( const Vector3& v )
	{
		X -= v.X;
		Y -= v.Y;
		Z -= v.Z;
		return *this;
	}

	LinearMath::Vector3 Vector3::operator*( const Scalar& scalar )
	{
		return Vector3( X * scalar, Y * scalar, Z * scalar );
	}

	Scalar Vector3::operator*( const Vector3& v )
	{
		return ( X * v.X ) + ( Y * v.Y ) + ( Z * v.Z );
	}

	Vector3 &Vector3::operator*=( const Scalar& scalar )
	{
		X *= scalar;
		Y *= scalar;
		Z *= scalar;
		return *this;
	}

	LinearMath::Vector3 Vector3::operator/( const Scalar& scalar )
	{
		return Vector3( X / scalar, Y / scalar, Z / scalar );
	}

	Vector3 &Vector3::operator/=( const Scalar& scalar )
	{
		X /= scalar;
		Y /= scalar;
		Z /= scalar;
		return *this;
	}

	Scalar Vector3::LengthSquared( void )
	{
		return ( X * X ) + ( Y * Y ) + ( Z * Z );
	}

	Scalar Vector3::Length( void )
	{
		return sqrt( LengthSquared() );
	}

	void Vector3::Normalize( void )
	{
		Scalar length = Length();
		X /= length;
		Y /= length;
		Z /= length;
	}

	LinearMath::Vector3 Vector3::NormalizedCopy( void )
	{
		Scalar length = Length();
		return Vector3( X / length, Y / length, Z / length );
	}

	LinearMath::Vector3 Vector3::operator^( const Vector3& v )
	{
		return Vector3( 
			Y * v.Z - Z * v.Y, 
			Z * v.X - X * v.Z, 
			X * v.Y - Y * v.X 
			);
	}

	LinearMath::Vector3 Vector3::CrossProduct( const Vector3& v )
	{
		return *this ^ v;
	}

}
