#include "precompiledHeader.h"
#include "MathHelper.h"

namespace LinearMath
{

	Radian::Radian( void ) :
		m_Rad( 0 )
	{
	}

	Radian::Radian( const Scalar& scalar ) :
		m_Rad( scalar )
	{
	}

	Radian::Radian( const Radian& rad ) :
		m_Rad( rad.m_Rad )
	{
	}

	Radian::Radian( const Degree& deg ) :
		m_Rad( MathHelper::DegreeToRad( deg ).AsRadianValue() )
	{
	}

	Radian::~Radian( void )
	{
	}
	
	//Radian &Radian::operator=( const Scalar& scalar )
	//{
	//	m_Rad = scalar;
	//	return *this;
	//}

	Radian &Radian::operator=( const Radian& rad )
	{
		m_Rad = rad.m_Rad;
		return *this;
	}

	Radian &Radian::operator=( const Degree& deg )
	{
		m_Rad = MathHelper::DegreeToRad( deg ).AsRadianValue();

		return *this;
	}

	LinearMath::Radian Radian::operator+( const Radian& rad ) const
	{
		return Radian( m_Rad + rad.m_Rad );
	}

	Radian &Radian::operator+=( const Radian& rad )
	{
		m_Rad += rad.m_Rad;
		return *this;
	}

	Radian::operator Degree( void ) const
	{
		return MathHelper::RadToDegree( *this );
	}

	Scalar Radian::AsRadianValue( void ) const
	{
		return m_Rad;
	}

	LinearMath::Degree Radian::ToDegree( void ) const
	{
		return MathHelper::RadToDegree( *this );
	}

	Scalar Radian::AsDegreeValue( void ) const
	{
		return MathHelper::RadToDegree( *this ).AsDegreeValue();
	}

	LinearMath::Radian Radian::operator-( const Radian& rad ) const
	{
		return Radian( m_Rad - rad.m_Rad );
	}

	Radian &Radian::operator-=( const Radian& rad )
	{
		m_Rad -= rad.m_Rad;

		return *this;
	}

	LinearMath::Radian Radian::operator*( const Scalar& scalar ) const
	{
		return Radian( m_Rad * scalar );
	}

	Radian operator*( const Scalar& scalar, const Radian& rad )
	{
		return Radian( scalar * rad.m_Rad );
	}

	Radian &Radian::operator*=( const Scalar& scalar )
	{
		m_Rad *= scalar;
		return *this;
	}

	LinearMath::Radian Radian::operator/( const Scalar& scalar ) const
	{
		return Radian( m_Rad / scalar );
	}

	Radian &Radian::operator/=( const Scalar& scalar )
	{
		m_Rad /= scalar;

		return *this;
	}

	bool Radian::operator==( const Radian& rad ) const
	{
		return m_Rad == rad.m_Rad;
	}

	bool Radian::operator!=( const Radian& rad ) const
	{
		return m_Rad != rad.m_Rad;
	}

	bool Radian::operator>=( const Radian& rad ) const
	{
		return m_Rad >= rad.m_Rad;
	}

	bool Radian::operator<=( const Radian& rad ) const
	{
		return m_Rad <= rad.m_Rad;
	}

	bool Radian::operator>( const Radian& rad ) const
	{
		return m_Rad > rad.m_Rad;
	}

	bool Radian::operator<( const Radian& rad ) const
	{
		return m_Rad < rad.m_Rad;
	}

	const Scalar MathHelper:: PI = 3.14159265358979323846f;

	LinearMath::Radian MathHelper::DegreeToRad( const Degree& deg )
	{
		// r/(2*PI) = alpha/(360°)
		// <=> r = alpha * (PI/180°)
		// <=> alpha = r * (180/pi)
		return Radian( deg.AsDegreeValue() * ( PI / 180.0f ) );
	}

	LinearMath::Degree MathHelper::RadToDegree( const Radian& rad )
	{
		// r/(2*PI) = alpha/(360°)
		// <=> r = alpha * (PI/180°)
		// <=> alpha = r * 180/pi
		return Degree( rad.AsRadianValue() * ( 180.0f / PI ) );
	}

	MathHelper::MathHelper( void )
	{
	}

	MathHelper::~MathHelper( void )
	{
	}

	Scalar MathHelper::Sin( const Scalar& scalar )
	{
		return sin( scalar );
	}

	Scalar MathHelper::ASin( const Scalar& scalar )
	{
		return asin( scalar );
	}

	Scalar MathHelper::Cos( const Scalar& scalar )
	{
		return cos( scalar );
	}

	Scalar MathHelper::ACos( const Scalar& scalar )
	{
		return acos( scalar );
	}

	Scalar MathHelper::Tan( const Scalar& scalar )
	{
		return tan( scalar );
	}

	Scalar MathHelper::ATan( const Scalar& scalar )
	{
		return atan( scalar );
	}

	Scalar MathHelper::Sqrt( const Scalar& scalar )
	{
		return sqrt( scalar );
	}

	Scalar MathHelper::Max( const Scalar& scalar1, const Scalar& scalar2 )
	{
		return scalar1 > scalar2 ? scalar1 : scalar2;
	}

	Scalar MathHelper::Max( const std::vector<Scalar>& values )
	{
		if( values.size() > 0 )
		{
			Scalar max = values[0];
			for( std::vector<Scalar>::const_iterator iterator = values.cbegin(); iterator != values.cend(); ++iterator )
			{
				if( *iterator > max )
				{
					max = *iterator;
				}
			}

			return max;
		}
		else
		{
			return 0.0f;
		}
	}

	Scalar MathHelper::Min( const Scalar& scalar1, const Scalar& scalar2 )
	{
		return scalar1 < scalar2 ? scalar1 : scalar2;
	}

	Scalar MathHelper::Min( const std::vector<Scalar>& values )
	{
		if( values.size() > 0 )
		{
			Scalar min = values[0];
			for( std::vector<Scalar>::const_iterator iterator = values.cbegin(); iterator != values.cend(); ++iterator )
			{
				if( *iterator < min )
				{
					min = *iterator;
				}
			}

			return min;
		}
		else
		{
			return 0.0f;
		}
	}

	Scalar MathHelper::Abs( const Scalar& scalar )
	{
		return scalar < 0 ? -scalar : scalar;
	}

	Scalar MathHelper::Lerp( const Scalar& p1, const Scalar& p2, const Scalar& lerpVal )
	{
		return p1 + ( ( p2 - p1 ) * lerpVal );
	}

	const Scalar MathHelper::GetPI()
	{
		return PI;
	}

	Degree::Degree( void ) :
		m_Degree( 0.0f )
	{
	}

	Degree::Degree( const Scalar& scalar ) :
		m_Degree( scalar )
	{
	}

	Degree::Degree( const Radian& rad ) :
		m_Degree( MathHelper::RadToDegree( rad ).m_Degree )
	{
	}

	Degree::Degree( const Degree& deg ) :
		m_Degree( deg.m_Degree )
	{
	}

	Degree::~Degree( void )
	{
	}

	Degree &Degree::operator=( const Radian& rad )
	{
		m_Degree = MathHelper::RadToDegree( rad ).AsDegreeValue();
		return *this;
	}

	Degree &Degree::operator=( const Degree& deg )
	{
		m_Degree = deg.AsDegreeValue();

		return *this;
	}

	Degree::operator Radian( void ) const
	{
		return MathHelper::DegreeToRad( *this );
	}

	Scalar Degree::AsRadianValue( void ) const
	{
		return MathHelper::DegreeToRad( *this ).AsRadianValue();
	}

	LinearMath::Radian Degree::ToRad( void ) const
	{
		return MathHelper::DegreeToRad( *this );
	}

	Scalar Degree::AsDegreeValue( void ) const
	{
		return m_Degree;
	}

	LinearMath::Degree Degree::operator+( const Degree& deg ) const
	{
		return Degree( m_Degree + deg.m_Degree );
	}

	Degree &Degree::operator+=( const Degree& deg )
	{
		m_Degree += deg.m_Degree;

		return *this;
	}

	LinearMath::Degree Degree::operator-( const Degree& deg ) const
	{
		return Degree( m_Degree - deg.m_Degree );
	}

	Degree &Degree::operator-=( const Degree& deg )
	{
		m_Degree -= deg.m_Degree;

		return *this;
	}

	LinearMath::Degree Degree::operator*( const Scalar& scalar ) const
	{
		return Degree( m_Degree * scalar );
	}

	Degree &Degree::operator*=( const Scalar& scalar )
	{
		m_Degree *= scalar;

		return *this;
	}

	LinearMath::Degree Degree::operator/( const Scalar& scalar ) const
	{
		return Degree( m_Degree / scalar );
	}

	Degree &Degree::operator/=( const Scalar& scalar )
	{
		m_Degree /= scalar;

		return *this;
	}

	bool Degree::operator==( const Degree& deg ) const
	{
		return m_Degree == deg.m_Degree;
	}

	bool Degree::operator!=( const Degree& deg ) const
	{

		return m_Degree != deg.m_Degree;
	}

	bool Degree::operator>=( const Degree& deg ) const
	{

		return m_Degree >= deg.m_Degree;
	}

	bool Degree::operator<=( const Degree& deg ) const
	{

		return m_Degree <= deg.m_Degree;
	}

	bool Degree::operator>( const Degree& deg ) const
	{

		return m_Degree > deg.m_Degree;
	}

	bool Degree::operator<( const Degree& deg ) const
	{

		return m_Degree < deg.m_Degree;
	}

}
