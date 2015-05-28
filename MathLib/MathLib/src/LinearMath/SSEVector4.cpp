#include "MathLibPCH.hpp"
#include "LinearMath/SSEVector4.hpp"
#include <smmintrin.h>
#include <stdint.h>

namespace LinearMath
{
  SSEVector4::SSEVector4()
  {
    vec = _mm_set_ps( 0, 0, 0, 0 );
  }

  SSEVector4::SSEVector4( float val )
  {
    vec = _mm_set_ps( val, val, val, val );
  }

  SSEVector4::SSEVector4( float X, float Y, float Z, float W )
  {
    vec = _mm_set_ps( W, Z, Y, X );
  }

  SSEVector4::SSEVector4( const SSEVector4& val )
  {
    vec = __m128( val.vec );
  }

  SSEVector4::SSEVector4( const __m128& mmVal )
  {
    vec = mmVal;
  }

  SSEVector4::~SSEVector4()
  {
  }

  LinearMath::SSEVector4 SSEVector4::operator +( const SSEVector4& v ) const
  {
    return SSEVector4( _mm_add_ps( vec, v.vec ) );
  }

  SSEVector4& SSEVector4::operator +=( const SSEVector4& v )
  {
    vec = _mm_add_ps( vec, v.vec );
    return *this;
  }

  LinearMath::SSEVector4 SSEVector4::operator -( const SSEVector4& v ) const
  {
    return SSEVector4( _mm_sub_ps( vec, v.vec ) );
  }

  SSEVector4& SSEVector4::operator -=( const SSEVector4& v )
  {
    vec = _mm_sub_ps( vec, v.vec );
    return *this;
  }

  float SSEVector4::operator *( const SSEVector4& v ) const
  {
    float result[ 4 ];

    // Store in lowest float, do multiply fourth value: 1111 0001
    const int mask = 0xF1;
    _mm_store_ss( result, _mm_dp_ps( vec, v.vec, mask ) );
    return result[ 0 ];
  }

  LinearMath::SSEVector4 SSEVector4::operator *( const float& scalar ) const
  {
    return SSEVector4( _mm_mul_ps( vec, _mm_set_ps( scalar, scalar, scalar, scalar ) ) );
  }

  SSEVector4 operator *( const float& scalar, const SSEVector4& v )
  {
    return v * scalar;
  }

  SSEVector4& SSEVector4::operator *=( const float& scalar )
  {
    vec = _mm_mul_ps( vec, _mm_set_ps( scalar, scalar, scalar, scalar ) );
    return *this;
  }

  LinearMath::SSEVector4 SSEVector4::operator /( const float& scalar ) const
  {
    return SSEVector4( _mm_div_ps( vec, _mm_set_ps( scalar, scalar, scalar, scalar ) ) );
  }

  SSEVector4& SSEVector4::operator /=( const float& scalar )
  {
    vec = _mm_div_ps( vec, _mm_set_ps( scalar, scalar, scalar, scalar ) );
    return *this;
  }

  float SSEVector4::LengthSquared() const
  {
    return *this * *this;
  }

  float SSEVector4::Length() const
  {
    float result[ 4 ];
    float lengthSquared = LengthSquared();

    // Store in all floats, do multiply fourth value: 0111 1111
    const int mask = 0xFF;
    _mm_store_ss( result, _mm_sqrt_ss( _mm_dp_ps( vec, vec, mask ) ) );
    return result[ 0 ];
  }

  void SSEVector4::Normalize()
  {
    // Store in all floats, do multiply fourth value: 1111 1111
    const int mask = 0xFF;
    vec = _mm_div_ps( vec, _mm_sqrt_ps( _mm_dp_ps( vec, vec, mask ) ) );
  }

  LinearMath::SSEVector4 SSEVector4::NormalizedCopy() const
  {
    SSEVector4 result( *this );
    result.Normalize();
    return result;
  }

  float SSEVector4::DotProduct( const SSEVector4& v ) const
  {
    return *this * v;
  }

  float SSEVector4::GetX() const
  {
    float result[ 32 ];
    float *data = reinterpret_cast<float*>(
      reinterpret_cast<uintptr_t>( result ) + ( 16 - ( reinterpret_cast<uintptr_t>( result ) % 16 ) ));
    _mm_store_ps( data, vec );
    return data[ 0 ];
  }

  float SSEVector4::GetY() const
  {
    float result[ 32 ];
    float *data = reinterpret_cast< float* >( 
      reinterpret_cast< uintptr_t >( result ) +( 16 - ( reinterpret_cast< uintptr_t >( result ) % 16 ) ) );
    _mm_store_ps( data, vec );
    return data[ 1 ];
  }

  float SSEVector4::GetZ() const
  {
    float result[ 32 ];
    float *data = reinterpret_cast< float* >( 
      reinterpret_cast< uintptr_t >( result ) +( 16 - ( reinterpret_cast< uintptr_t >( result ) % 16 ) ) );
    _mm_store_ps( data, vec );
    return data[ 2 ];
  }

  float SSEVector4::GetW() const
  {
    float result[ 32 ];
    float *data = reinterpret_cast< float* >( 
      reinterpret_cast< uintptr_t >( result ) +( 16 - ( reinterpret_cast< uintptr_t >( result ) % 16 ) ) );
    _mm_store_ps( data, vec );
    return data[ 3 ];
  }

  LinearMath::SSEVector3 SSEVector4::GetXYZ() const
  {
    float result[ 32 ];
    float *data = reinterpret_cast< float* >(
      reinterpret_cast< uintptr_t >( result ) +( 16 - ( reinterpret_cast< uintptr_t >( result ) % 16 ) ) );
    _mm_store_ps( data, vec );
    return SSEVector3( data[ 0 ], data[ 1 ], data[ 2 ] );
  }

}
