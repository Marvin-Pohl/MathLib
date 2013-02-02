#include "Vector2.h"

namespace LinearMath
{

	Vector2::Vector2( void ) :
		m_X( 0 ),
		m_Y( 0 )
	{
	}

	Vector2::Vector2( Scalar val ) :
		m_X( val ),
		m_Y( val )
	{
	}

	Vector2::Vector2( Scalar x, Scalar y ) :
		m_X( x ),
		m_Y( y )
	{
	}

	Vector2::~Vector2( void )
	{
	}

	Vector2 Vector2::operator+( const Vector2& v )
	{
		return Vector2( this->m_X + v.m_X, this->m_Y + v.m_Y );
	}

	Vector2 &Vector2::operator+=( const Vector2& v )
	{
		m_X += v.m_X;
		m_Y += v.m_Y;
		return *this;
	}

	Vector2 Vector2::operator-( const Vector2& v )
	{
		return Vector2( this->m_X - v.m_X, this->m_Y - v.m_Y );
	}

	Vector2 &Vector2::operator-=( const Vector2& v )
	{
		m_X -= v.m_X;
		m_Y -= v.m_Y;
		return *this;
	}

	Vector2 Vector2::operator*( const Scalar& scalar )
	{
		return Vector2( m_X * scalar, m_Y * scalar );
	}

	Vector2 &Vector2::operator*=( const Scalar& scalar )
	{
		m_X *= scalar;
		m_Y *= scalar;
		return *this;
	}

	Vector2 Vector2::operator/( const Scalar& scalar )
	{
		return Vector2( m_X / scalar, m_Y / scalar );
	}

	Vector2 &Vector2::operator/=( const Scalar& scalar )
	{
		m_X /= scalar;
		m_Y /= scalar;
		return *this;
	}

}
