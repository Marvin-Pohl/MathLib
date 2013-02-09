#pragma once
#ifndef _MP_MATRIX_4_4_H_
#define _MP_MATRIX_4_4_H_

#include "precompiledHeader.h"
#include "Vector3.h"
#include "MathHelper.h"

namespace LinearMath
{

	template < typename ScalarType >
	class Matrix4x4_tpl
	{
	public:
		/**
		\brief Creates an Identity Matrix

		| 1 | 0 | 0 | 0 |
		| 0 | 1 | 0 | 0 |
		| 0 | 0 | 1 | 0 |
		| 0 | 0 | 0 | 1 |
	
		*/
		Matrix4x4_tpl();

		/**
		\brief Creates an User Defined Matrix
	
		Layout:
		| 1_1 | 1_2 | 1_3 | 1_4 |
		| 2_1 | 2_2 | 2_3 | 2_4 |
		| 3_1 | 3_2 | 3_3 | 3_4 |
		| 4_1 | 4_2 | 4_3 | 4_4 |

		*/
		Matrix4x4_tpl(
			const ScalarType& m_1_1, const ScalarType& m_1_2, const ScalarType& m_1_3, const ScalarType& m_1_4,
			const ScalarType& m_2_1, const ScalarType& m_2_2, const ScalarType& m_2_3, const ScalarType& m_2_4,
			const ScalarType& m_3_1, const ScalarType& m_3_2, const ScalarType& m_3_3, const ScalarType& m_3_4,
			const ScalarType& m_4_1, const ScalarType& m_4_2, const ScalarType& m_4_3, const ScalarType& m_4_4,
			);

		static Matrix4x4_tpl CreateScaleMatrix( 
			const ScalarType& scaleX, const ScalarType& scaleY, const ScalarType& scaleZ );
		static Matrix4x4_tpl CreateScaleMatrix( 
			const Vector3_tpl< ScalarType >& scale );

		static Matrix4x4_tpl CreateTranslationMatrix(const ScalarType& X, const ScalarType& Y, const ScalarType& Z );
		static Matrix4x4_tpl CreateTranslationMatrix(const Vector3_tpl<ScalarType>& translation );

		~Matrix4x4_tpl();


		//Fields
		/*
		| 1_1 | 1_2 | 1_3 | 1_4 |
		| 2_1 | 2_2 | 2_3 | 2_4 |
		| 3_1 | 3_2 | 3_3 | 3_4 |
		| 4_1 | 4_2 | 4_3 | 4_4 |
		*/
		ScalarType M_1_1, M_1_2, M_1_3, M_1_4;
		ScalarType M_2_1, M_2_2, M_2_3, M_2_4;
		ScalarType M_3_1, M_3_2, M_3_3, M_3_4;
		ScalarType M_4_1, M_4_2, M_4_3, M_4_4;

	private:

	};

	template < typename ScalarType >
	Matrix4x4_tpl Matrix4x4_tpl<ScalarType>::CreateTranslationMatrix( 
		const ScalarType& X, const ScalarType& Y, const ScalarType& Z )
	{
		return Matrix4x4_tpl(
			1, 0, 0, X,
			0, 1, 0, Y,
			0, 0, 1, Z,
			0, 0, 0, 1
			);
	}



	template < typename ScalarType>
	Matrix4x4_tpl<ScalarType>::Matrix4x4_tpl(
		const ScalarType& m_1_1, const ScalarType& m_1_2, const ScalarType& m_1_3, const ScalarType& m_1_4,
		const ScalarType& m_2_1, const ScalarType& m_2_2, const ScalarType& m_2_3, const ScalarType& m_2_4,
		const ScalarType& m_3_1, const ScalarType& m_3_2, const ScalarType& m_3_3, const ScalarType& m_3_4,
		const ScalarType& m_4_1, const ScalarType& m_4_2, const ScalarType& m_4_3, const ScalarType& m_4_4,
		) :
		M_1_1( m_1_1 ),	M_1_2( m_1_2 ),	M_1_3( m_1_3 ),	M_1_4( m_1_4 ),
		M_2_1( m_2_1 ),	M_2_2( m_2_2 ),	M_2_3( m_2_3 ),	M_2_4( m_2_4 ),
		M_3_1( m_3_1 ),	M_3_2( m_3_2 ),	M_3_3( m_3_3 ),	M_3_4( m_3_4 ),
		M_4_1( m_4_1 ),	M_4_2( m_4_2 ),	M_4_3( m_4_3 ),	M_4_4( m_4_4 )
	{
	}

	template < typename ScalarType>
	Matrix4x4_tpl<ScalarType>::~Matrix4x4_tpl()
	{

	}

	template < typename ScalarType>
	Matrix4x4_tpl<ScalarType>::Matrix4x4_tpl() :
		M_1_1( 1 ), M_1_2( 0 ), M_1_3( 0 ), M_1_4( 0 ),
		M_2_1( 0 ),	M_2_2( 1 ),	M_2_3( 0 ),	M_2_4( 0 ),
		M_3_1( 0 ),	M_3_2( 0 ),	M_3_3( 1 ),	M_3_4( 0 ),
		M_4_1( 0 ),	M_4_2( 0 ),	M_4_3( 0 ),	M_4_4( 1 )
	{
	}

	template < typename ScalarType >
	Matrix4x4_tpl Matrix4x4_tpl<ScalarType>::CreateScaleMatrix( 
		const ScalarType& sX, const ScalarType& sY, const ScalarType& sZ )
	{
		return Matrix4x4_tpl(
			sX, 0, 0, 0,
			0, sY, 0, 0,
			0, 0, sZ, 0,
			0, 0,  0, 1
			);
	}

	template < typename ScalarType >
	Matrix4x4_tpl Matrix4x4_tpl<ScalarType>::CreateScaleMatrix( const Vector3_tpl< ScalarType >& scale )
	{
		return CreateScaleMatrix(scale.X, scale.Y, scale.Z);
	}
}

#endif

