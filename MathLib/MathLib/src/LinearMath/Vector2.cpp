#include "precompiledHeader.h"
#include "Vector2.h"

#include <math.h>

namespace LinearMath
{

	Vector2::Vector2( void ) :
		X( 0 ),
		Y( 0 )
	{
	}

	Vector2::Vector2( Scalar val ) :
		X( val ),
		Y( val )
	{
	}

	Vector2::Vector2( Scalar x, Scalar y ) :
		X( x ),
		Y( y )
	{
	}

	Vector2::~Vector2( void )
	{
	}

	Vector2 Vector2::operator+( const Vector2& v ) const
	{

		return Vector2( this->X + v.X, this->Y + v.Y );
	}

	Vector2 &Vector2::operator+=( const Vector2& v )
	{
		X += v.X;
		Y += v.Y;
		return *this;
	}

	Vector2 Vector2::operator-( const Vector2& v ) const
	{
		return Vector2( this->X - v.X, this->Y - v.Y );
	}

	Vector2 &Vector2::operator-=( const Vector2& v )
	{
		X -= v.X;
		Y -= v.Y;
		return *this;
	}

	Vector2 Vector2::operator*( const Scalar& scalar ) const
	{
		return Vector2( X * scalar, Y * scalar );
	}

	Scalar Vector2::operator*( const Vector2& v ) const
	{
		return ( X * v.X ) + ( Y * v.Y );
	}

	Vector2 &Vector2::operator*=( const Scalar& scalar )
	{
		X *= scalar;
		Y *= scalar;
		return *this;
	}

	Vector2 Vector2::operator/( const Scalar& scalar ) const
	{
		return Vector2( X / scalar, Y / scalar );
	}

	Vector2 &Vector2::operator/=( const Scalar& scalar )
	{
		X /= scalar;
		Y /= scalar;
		return *this;
	}

	Scalar Vector2::LengthSquared( void ) const
	{
		return ( X * X ) + ( Y * Y );
	}

	Scalar Vector2::Length( void ) const
	{
		return sqrt( LengthSquared() );
	}

	void Vector2::Normalize( void )
	{
		Scalar length = Length();
		X /= length;
		Y /= length;
	}

	Vector2 Vector2::NormalizedCopy( void ) const
	{
		Scalar length = Length();

		return Vector2( X / length, Y / length );
	}

	Scalar Vector2::PerpDotProduct( const Vector2& v ) const
	{
		return Vector2(-Y, X) * v;
	}

	Scalar Vector2::DotProduct( const Vector2& v ) const
	{
		return *this * v;
	}

}
