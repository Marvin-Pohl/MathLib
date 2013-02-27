#include "precompiledHeader.h"
#include "SSEVector3.h"
#include <smmintrin.h>

namespace LinearMath
{


	SSEVector3::SSEVector3()
	{
		vec = _mm_set_ps( 0, 0, 0, 0 );
	}

	SSEVector3::SSEVector3( float val )
	{
		vec = _mm_set_ps( val, val, val, 0 );
	}

	SSEVector3::SSEVector3( float X, float Y, float Z )
	{
		vec = _mm_set_ps( Z, Y, X, 0 );
	}

	SSEVector3::SSEVector3( const SSEVector3& val )
	{
		vec =  __m128(val.vec);
	}

	SSEVector3::SSEVector3( const __m128& mmVal )
	{
		vec = mmVal;
	}

	SSEVector3::~SSEVector3()
	{

	}

	LinearMath::SSEVector3 SSEVector3::operator+( const SSEVector3& v ) const
	{
		return SSEVector3( _mm_add_ps( vec, v.vec ) );
	}

	SSEVector3& SSEVector3::operator+=( const SSEVector3& v )
	{
		vec = _mm_add_ps( vec, v.vec );
		return *this;
	}

	LinearMath::SSEVector3 SSEVector3::operator-( const SSEVector3& v ) const
	{
		return SSEVector3( _mm_sub_ps( vec, v.vec ) );
	}

	SSEVector3& SSEVector3::operator-=( const SSEVector3& v )
	{
		vec = _mm_sub_ps(vec, v.vec);
		return *this;
	}

	float SSEVector3::operator*( const SSEVector3& v ) const
	{
		float result[4];
		//Store in lowest float, do not multiply fourth value: 0111 0001
		const int mask = 0xE1;
		_mm_store_ss(result, _mm_dp_ps(vec, v.vec, mask));
		return result[0];
	}

	LinearMath::SSEVector3 SSEVector3::operator*( const float& scalar ) const
	{
		return SSEVector3( _mm_mul_ps( vec, _mm_set_ps( scalar, scalar, scalar, 1) ) );
	}


	SSEVector3 operator *(const float& scalar, const SSEVector3& v)
	{
		return v * scalar;
	}

	SSEVector3& SSEVector3::operator*=( const float& scalar )
	{
		vec = _mm_mul_ps( vec, _mm_set_ps( scalar, scalar, scalar, 1) );
		return *this;
	}

	LinearMath::SSEVector3 SSEVector3::operator/( const float& scalar ) const
	{
		return SSEVector3( _mm_div_ps( vec, _mm_set_ps( scalar, scalar, scalar, 1) ) );
	}

	SSEVector3& SSEVector3::operator/=( const float& scalar )
	{
		vec = _mm_div_ps( vec, _mm_set_ps( scalar, scalar, scalar, 1) );
		return *this;
	}

	LinearMath::SSEVector3 SSEVector3::operator^( const SSEVector3& v ) const
	{
		return SSEVector3
			(
			_mm_sub_ps
			(
			_mm_mul_ps(
				//Y,Z,X,W
				_mm_shuffle_ps( vec, vec, _MM_SHUFFLE(1, 3, 2, 0)),
				//Z,X,Y,W
				_mm_shuffle_ps( v.vec, v.vec, _MM_SHUFFLE(2, 1, 3, 0))
			),
			_mm_mul_ps(
				//Z,X,Y,W
				_mm_shuffle_ps( vec, vec, _MM_SHUFFLE(2,1,3,0)),
				//Y,Z,X,W
				_mm_shuffle_ps( v.vec, v.vec, _MM_SHUFFLE(1,3,2,0))
			)
			)
			);
	}

	float SSEVector3::LengthSquared() const
	{
		return *this * *this;
	}

	float SSEVector3::Length() const
	{
		float result[4];
		float lengthSquared = LengthSquared();
		const int mask = 0xEF;
		_mm_store_ss(result, _mm_sqrt_ss( _mm_dp_ps(vec, vec, mask) ));
		return result[0];
	}

	void SSEVector3::Normalize()
	{
		//Store in lowest float, do not multiply fourth value: 0111 0001
		const int mask = 0xEF;
		vec =  _mm_div_ps( vec, _mm_sqrt_ps( _mm_dp_ps(vec, vec, mask) ));
	}

	LinearMath::SSEVector3 SSEVector3::NormalizedCopy() const
	{
		SSEVector3 result(*this);
		result.Normalize();
		return result;
	}

	LinearMath::SSEVector3 SSEVector3::CrossProduct( const SSEVector3& v ) const
	{
		return (*this ^ v);
	}

	float SSEVector3::DotProduct( const SSEVector3& v ) const
	{
		return *this * v;
	}

	float SSEVector3::GetX() const
	{
		float result[4];
		_mm_store_ps(result, vec);
		return result[1];
	}

	float SSEVector3::GetY() const
	{

		float result[4];
		_mm_store_ps(result, vec);
		return result[2];
	}

	float SSEVector3::GetZ() const
	{

		float result[4];
		_mm_store_ps(result, vec);
		return result[3];
	}

}