#include "MathLibPCH.h"
#include "SSEMatrix4x4.h"
#include <smmintrin.h>

namespace LinearMath
{
	const SSEMatrix4x4 SSEMatrix4x4::ZERO
		(
		0.0f,0.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f,0.0f
		);

	const SSEMatrix4x4 SSEMatrix4x4::ZERO_AFFINE
		(
		0.0f,0.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
		);

	const SSEMatrix4x4 SSEMatrix4x4::IDENTITY
		(
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
		);

	SSEMatrix4x4::SSEMatrix4x4()
	{
		m_col0 = _mm_set_ps( 0, 0, 0, 0 );
		m_col1 = _mm_set_ps( 0, 0, 0, 0 );
		m_col2 = _mm_set_ps( 0, 0, 0, 0 );
		m_col3 = _mm_set_ps( 0, 0, 0, 0 );
	}

	SSEMatrix4x4::SSEMatrix4x4( const __m128& col0, const __m128& col1, const __m128& col2, const __m128& col3 ) :
		m_col0( col0 ),
		m_col1( col1 ),
		m_col2( col2 ),
		m_col3( col3 )
	{

	}

	SSEMatrix4x4::SSEMatrix4x4( 
		float M11, float M12, float M13, float M14, 
		float M21, float M22, float M23, float M24, 
		float M31, float M32, float M33, float M34, 
		float M41, float M42, float M43, float M44 )
	{
		m_col0 = _mm_set_ps( M14, M13, M12, M11 );
		m_col1 = _mm_set_ps( M24, M23, M22, M21 );
		m_col2 = _mm_set_ps( M34, M33, M32, M31 );
		m_col3 = _mm_set_ps( M44, M43, M42, M41 );
	}

	SSEMatrix4x4::SSEMatrix4x4( const SSEMatrix4x4& matrix )
	{
		m_col0 = matrix.m_col0;
		m_col1 = matrix.m_col1;
		m_col2 = matrix.m_col2;
		m_col3 = matrix.m_col3;
	}

	SSEMatrix4x4::~SSEMatrix4x4()
	{

	}

	LinearMath::SSEMatrix4x4 SSEMatrix4x4::operator+( const SSEMatrix4x4& matrix ) const
	{
		SSEMatrix4x4 result( *this );
		result += matrix;
		return result;
	}

	SSEMatrix4x4& SSEMatrix4x4::operator+=( const SSEMatrix4x4& matrix )
	{
		m_col0 = _mm_add_ps( m_col0, matrix.m_col0 );
		m_col1 = _mm_add_ps( m_col1, matrix.m_col1 );
		m_col2 = _mm_add_ps( m_col2, matrix.m_col2 );
		m_col3 = _mm_add_ps( m_col3, matrix.m_col3 );
		return *this;
	}

	LinearMath::SSEMatrix4x4 SSEMatrix4x4::operator-( const SSEMatrix4x4& matrix ) const
	{
		SSEMatrix4x4 result( *this );
		result -= matrix;
		return result;
	}

	LinearMath::SSEMatrix4x4 SSEMatrix4x4::operator-=( const SSEMatrix4x4& matrix )
	{
		m_col0 = _mm_sub_ps( m_col0, matrix.m_col0 );
		m_col1 = _mm_sub_ps( m_col1, matrix.m_col1 );
		m_col2 = _mm_sub_ps( m_col2, matrix.m_col2 );
		m_col3 = _mm_sub_ps( m_col3, matrix.m_col3 );
		return *this;
	}

	LinearMath::SSEMatrix4x4 SSEMatrix4x4::operator*( const SSEMatrix4x4& matrix ) const
	{
		return SSEMatrix4x4( *this ) *= matrix;
	}

	SSEMatrix4x4& SSEMatrix4x4::operator*=( const SSEMatrix4x4& mat )
	{
		SSEMatrix4x4 matrix(mat);
		matrix.Transpose();

		__m128 zero = _mm_set_ps( 0,0,0,0 );

		__m128 tmp_col0(zero);
		__m128 tmp_col1(zero);
		__m128 tmp_col2(zero);
		__m128 tmp_col3(zero);

		tmp_col0 = _mm_add_ps ( _mm_dp_ps( m_col0, matrix.m_col0, 0xF1 ), tmp_col0 );
		tmp_col0 = _mm_add_ps ( _mm_dp_ps( m_col0, matrix.m_col1, 0xF2 ), tmp_col0 );
		tmp_col0 = _mm_add_ps ( _mm_dp_ps( m_col0, matrix.m_col2, 0xF4 ), tmp_col0 );
		tmp_col0 = _mm_add_ps ( _mm_dp_ps( m_col0, matrix.m_col3, 0xF8 ), tmp_col0 );

		tmp_col1 = _mm_add_ps ( _mm_dp_ps( m_col1, matrix.m_col0, 0xF1 ), tmp_col1 );
		tmp_col1 = _mm_add_ps ( _mm_dp_ps( m_col1, matrix.m_col1, 0xF2 ), tmp_col1 );
		tmp_col1 = _mm_add_ps ( _mm_dp_ps( m_col1, matrix.m_col2, 0xF4 ), tmp_col1 );
		tmp_col1 = _mm_add_ps ( _mm_dp_ps( m_col1, matrix.m_col3, 0xF8 ), tmp_col1 );

		tmp_col2 = _mm_add_ps ( _mm_dp_ps( m_col2, matrix.m_col0, 0xF1 ), tmp_col2 );
		tmp_col2 = _mm_add_ps ( _mm_dp_ps( m_col2, matrix.m_col1, 0xF2 ), tmp_col2 );
		tmp_col2 = _mm_add_ps ( _mm_dp_ps( m_col2, matrix.m_col2, 0xF4 ), tmp_col2 );
		tmp_col2 = _mm_add_ps ( _mm_dp_ps( m_col2, matrix.m_col3, 0xF8 ), tmp_col2 );

		tmp_col3 = _mm_add_ps ( _mm_dp_ps( m_col3, matrix.m_col0, 0xF1 ), tmp_col3 );
		tmp_col3 = _mm_add_ps ( _mm_dp_ps( m_col3, matrix.m_col1, 0xF2 ), tmp_col3 );
		tmp_col3 = _mm_add_ps ( _mm_dp_ps( m_col3, matrix.m_col2, 0xF4 ), tmp_col3 );
		tmp_col3 = _mm_add_ps ( _mm_dp_ps( m_col3, matrix.m_col3, 0xF8 ), tmp_col3 );

		m_col0 = tmp_col0;
		m_col1 = tmp_col1;
		m_col2 = tmp_col2;
		m_col3 = tmp_col3;

		return *this;
	}

	void SSEMatrix4x4::Invert()
	{

	}

	LinearMath::SSEMatrix4x4 SSEMatrix4x4::InvertedCopy() const
	{
		return SSEMatrix4x4(*this);
	}

	LinearMath::SSEMatrix4x4 SSEMatrix4x4::TransposedCopy() const
	{
		SSEMatrix4x4 result( *this );
		result.Transpose();
		return result;
	}

	void SSEMatrix4x4::Transpose()
	{
		_MM_TRANSPOSE4_PS(m_col0, m_col1, m_col2, m_col3)

		//__m128 T3 = _mm_unpacklo_ps(m_col0, m_col1);
		//__m128 T2 = _mm_unpacklo_ps(m_col2, m_col3);
		//__m128 T1 = _mm_unpackhi_ps(m_col0, m_col1);
		//__m128 T0 = _mm_unpackhi_ps(m_col2, m_col3);
		//
		//m_col0 = _mm_unpacklo_ps(T0, T1);
		//m_col1 = _mm_unpackhi_ps(T0, T1);
		//m_col2 = _mm_unpacklo_ps(T2, T3);
		//m_col3 = _mm_unpackhi_ps(T2, T3);
	}

	float SSEMatrix4x4::GetM_1_1() const
	{
		__m128 xmm0 = m_col0 ; 
		float result[ 4 ] ;
		_mm_storeu_ps( result, xmm0 );
		return result[ 0 ];
	}

	float SSEMatrix4x4::GetM_1_2() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col0 );
		return result[ 1 ];	}

	float SSEMatrix4x4::GetM_1_3() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col0 );
		return result[ 2 ];
	}

	float SSEMatrix4x4::GetM_1_4() const
	{

		float result[ 4 ];
		_mm_storeu_ps( result, m_col0 );
		return result[ 3 ];
	}

	float SSEMatrix4x4::GetM_2_1() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col1 );
		return result[ 0 ];
	}

	float SSEMatrix4x4::GetM_2_2() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col1 );
		return result[ 1 ];	
	}

	float SSEMatrix4x4::GetM_2_3() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col1 );
		return result[ 2 ];	
	}

	float SSEMatrix4x4::GetM_2_4() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col1 );
		return result[ 3 ];	
	}

	float SSEMatrix4x4::GetM_3_1() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col2 );
		return result[ 0 ];	
	}

	float SSEMatrix4x4::GetM_3_2() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col2 );
		return result[ 1 ];	
	}

	float SSEMatrix4x4::GetM_3_3() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col2 );
		return result[ 2 ];	
	}

	float SSEMatrix4x4::GetM_3_4() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col2 );
		return result[ 3 ];	
	}

	float SSEMatrix4x4::GetM_4_1() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col3 );
		return result[ 0 ];	
	}

	float SSEMatrix4x4::GetM_4_2() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col3 );
		return result[ 1 ];	
	}

	float SSEMatrix4x4::GetM_4_3() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col3 );
		return result[ 2 ];	
	}

	float SSEMatrix4x4::GetM_4_4() const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, m_col3 );
		return result[ 3 ];	
	}

	float SSEMatrix4x4::GetSpecificFloat( __m128 col, const unsigned int pos ) const
	{
		float result[ 4 ];
		_mm_storeu_ps( result, col );
		return result[ pos ];
	}

}