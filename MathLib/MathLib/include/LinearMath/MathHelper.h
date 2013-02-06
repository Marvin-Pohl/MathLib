#pragma once
#include "precompiledHeader.h"
#include <vector>

namespace LinearMath
{
	class Degree;
	class Radian;
	class DLLExport Radian
	{

public:

		Radian( void );
		explicit Radian( const Scalar& scalar );
		Radian( const Radian& rad );
		Radian( const Degree& deg );
		~ Radian( void );

		//Radian &operator =( const Scalar& scalar );
		Radian &operator =( const Radian& rad );
		Radian &operator =( const Degree& deg );

		Radian operator +( const Radian& rad ) const;
		Radian &operator +=( const Radian& rad );

		Radian operator -( const Radian& rad ) const;
		Radian &operator -=( const Radian& rad );

		Radian operator *( const Scalar& scalar ) const;
		Radian &operator *=( const Scalar& scalar );
		friend Radian operator *( const Scalar& scalar, const Radian& rad );

		Radian operator /( const Scalar& scalar ) const;
		Radian &operator /=( const Scalar& scalar );

		bool operator ==( const Radian& rad ) const;
		bool operator !=( const Radian& rad ) const;
		bool operator >=( const Radian& rad ) const;
		bool operator <=( const Radian& rad ) const;
		bool operator >( const Radian& rad ) const;
		bool operator <( const Radian& rad ) const;

		operator Degree( void ) const;

		Scalar AsRadianValue( void ) const;
		Degree ToDegree( void ) const;
		Scalar AsDegreeValue( void ) const;

private:

		Scalar m_Rad;
	};

	class DLLExport Degree
	{

public:

		Degree( void );
		explicit Degree( const Scalar& scalar );
		Degree( const Radian& rad );
		Degree( const Degree& deg );
		~ Degree( void );

		//Degree &operator =( const Scalar& scalar );
		Degree &operator =( const Radian& rad );
		Degree &operator =( const Degree& deg );

		Degree operator +( const Degree& rad ) const;
		Degree &operator +=( const Degree& rad );

		Degree operator -( const Degree& rad ) const;
		Degree &operator -=( const Degree& rad );

		Degree operator *( const Scalar& scalar ) const;
		Degree &operator *=( const Scalar& scalar );

		Degree operator /( const Scalar& scalar ) const;
		Degree &operator /=( const Scalar& scalar );

		bool operator ==( const Degree& rad ) const;
		bool operator !=( const Degree& rad ) const;
		bool operator >=( const Degree& rad ) const;
		bool operator <=( const Degree& rad ) const;
		bool operator >( const Degree& rad ) const;
		bool operator < ( const Degree&rad ) const;

		operator Radian( void ) const;

		//operator Scalar( void );
		Scalar AsRadianValue( void ) const;
		Radian ToRad( void ) const;
		Scalar AsDegreeValue( void ) const;

private:

		Scalar m_Degree;
	};

	class DLLExport MathHelper
	{

public:

		static const Scalar PI;

		static const Scalar GetPI( void );

		static Radian DegreeToRad( const Degree& deg );
		static Degree RadToDegree( const Radian& rad );

		static Scalar Sin( const Scalar& scalar );
		static Scalar ASin( const Scalar& scalar );

		static Scalar Cos( const Scalar& scalar );
		static Scalar ACos( const Scalar& scalar );

		static Scalar Tan( const Scalar& scalar );
		static Scalar ATan( const Scalar& scalar );

		static Scalar Sqrt( const Scalar& scalar );

		static Scalar Max( const Scalar& scalar1, const Scalar& scalar2 );
		static Scalar Max( const std::vector<Scalar>& values );

		static Scalar Min( const Scalar& scalar1, const Scalar& scalar2 );
		static Scalar Min( const std::vector<Scalar>& values );

		static Scalar Abs( const Scalar& scalar );

		static Scalar Lerp( const Scalar& p1, const Scalar& p2, const Scalar& lerpVal );

private:

		MathHelper( void );
		MathHelper( const MathHelper&  );
		~ MathHelper( void );
	};

}
