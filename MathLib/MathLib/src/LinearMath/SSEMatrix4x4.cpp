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
		/***************************************/
		/* Based on http://download.intel.com/design/PentiumIII/sml/24504301.pdf */
		/***************************************/
		__m128 zero = _mm_set_ps( 0, 0, 0, 0 );

		__m128 minor0 = zero, minor1 = zero, minor2 = zero, minor3 = zero;
		__m128 row0 = zero, row1 = zero, row2 = zero, row3 = zero;
		__m128 det = zero, tmp1 = zero;
		
		tmp1 = _mm_loadh_pi(_mm_loadl_pi(tmp1, (__m64*)(&m_col0)), (__m64*)(&m_col1));
		row1 = _mm_loadh_pi(_mm_loadl_pi(row1, (__m64*)(&m_col2)), (__m64*)(&m_col3));
		row0 = _mm_shuffle_ps(tmp1, row1, 0x88);
		row1 = _mm_shuffle_ps(row1, tmp1, 0xDD);
		tmp1 = _mm_loadh_pi(_mm_loadl_pi(tmp1, (__m64*)(((float*)&m_col0)+ 2)), (__m64*)(((float*)&m_col1)+ 2));
		row3 = _mm_loadh_pi(_mm_loadl_pi(row3, (__m64*)(((float*)&m_col2)+2)), (__m64*)(((float*)&m_col3)+2));
		row2 = _mm_shuffle_ps(tmp1, row3, 0x88);
		row3 = _mm_shuffle_ps(row3, tmp1, 0xDD);
		//-----------------------------------------------
		tmp1 = _mm_mul_ps(row2, row3);
		tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
		minor0 = _mm_mul_ps(row1, tmp1);
		minor1 = _mm_mul_ps(row0, tmp1);
		tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
		minor0 = _mm_sub_ps(_mm_mul_ps(row1, tmp1), minor0);
		minor1 = _mm_sub_ps(_mm_mul_ps(row0, tmp1), minor1);
		minor1 = _mm_shuffle_ps(minor1, minor1, 0x4E);
		//-----------------------------------------------
		tmp1 = _mm_mul_ps(row1, row2);
		tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
		minor0 = _mm_add_ps(_mm_mul_ps(row3, tmp1), minor0);
		minor3 = _mm_mul_ps(row0, tmp1);
		tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
		minor0 = _mm_sub_ps(minor0, _mm_mul_ps(row3, tmp1));
		minor3 = _mm_sub_ps(_mm_mul_ps(row0, tmp1), minor3);
		minor3 = _mm_shuffle_ps(minor3, minor3, 0x4E);
		//-----------------------------------------------
		tmp1 = _mm_mul_ps(_mm_shuffle_ps(row1, row1, 0x4E), row3);
		tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
		row2 = _mm_shuffle_ps(row2, row2, 0x4E);
		minor0 = _mm_add_ps(_mm_mul_ps(row2, tmp1), minor0);
		minor2 = _mm_mul_ps(row0, tmp1);
		tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
		minor0 = _mm_sub_ps(minor0, _mm_mul_ps(row2, tmp1));
		minor2 = _mm_sub_ps(_mm_mul_ps(row0, tmp1), minor2);
		minor2 = _mm_shuffle_ps(minor2, minor2, 0x4E);
		//-----------------------------------------------
		tmp1 = _mm_mul_ps(row0, row1);//Streaming SIMD Extensions - Inverse of 4x4 Matrix
		
		tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
		minor2 = _mm_add_ps(_mm_mul_ps(row3, tmp1), minor2);
		minor3 = _mm_sub_ps(_mm_mul_ps(row2, tmp1), minor3);
		tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
		minor2 = _mm_sub_ps(_mm_mul_ps(row3, tmp1), minor2);
		minor3 = _mm_sub_ps(minor3, _mm_mul_ps(row2, tmp1));
		//-----------------------------------------------
		tmp1 = _mm_mul_ps(row0, row3);
		tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
		minor1 = _mm_sub_ps(minor1, _mm_mul_ps(row2, tmp1));
		minor2 = _mm_add_ps(_mm_mul_ps(row1, tmp1), minor2);
		tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
		minor1 = _mm_add_ps(_mm_mul_ps(row2, tmp1), minor1);
		minor2 = _mm_sub_ps(minor2, _mm_mul_ps(row1, tmp1));
		//-----------------------------------------------
		tmp1 = _mm_mul_ps(row0, row2);
		tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
		minor1 = _mm_add_ps(_mm_mul_ps(row3, tmp1), minor1);
		minor3 = _mm_sub_ps(minor3, _mm_mul_ps(row1, tmp1));
		tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
		minor1 = _mm_sub_ps(minor1, _mm_mul_ps(row3, tmp1));
		minor3 = _mm_add_ps(_mm_mul_ps(row1, tmp1), minor3);
		//-----------------------------------------------
		det = _mm_mul_ps(row0, minor0);
		det = _mm_add_ps(_mm_shuffle_ps(det, det, 0x4E), det);
		det = _mm_add_ss(_mm_shuffle_ps(det, det, 0xB1), det);
		tmp1 = _mm_rcp_ss(det);
		det = _mm_sub_ss(_mm_add_ss(tmp1, tmp1), _mm_mul_ss(det, _mm_mul_ss(tmp1, tmp1)));
		det = _mm_shuffle_ps(det, det, 0x00);
		minor0 = _mm_mul_ps(det, minor0);
		//_mm_storel_pi((__m64*)(src), minor0);
		//_mm_storeh_pi((__m64*)(src+2), minor0);
		m_col0 = minor0;
		minor1 = _mm_mul_ps(det, minor1);
		//_mm_storel_pi((__m64*)(src+4), minor1);
		//_mm_storeh_pi((__m64*)(src+6), minor1);
		m_col1 = minor1;
		minor2 = _mm_mul_ps(det, minor2);
		//_mm_storel_pi((__m64*)(src+ 8), minor2);
		//_mm_storeh_pi((__m64*)(src+10), minor2);
		m_col2 = minor2;
		minor3 = _mm_mul_ps(det, minor3);
		//_mm_storel_pi((__m64*)(src+12), minor3);
		//_mm_storeh_pi((__m64*)(src+14), minor3);
		m_col3 = minor3;
	}

	LinearMath::SSEMatrix4x4 SSEMatrix4x4::InvertedCopy() const
	{
		
		SSEMatrix4x4 matrix(*this);
		matrix.Invert();
		return matrix;
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

}