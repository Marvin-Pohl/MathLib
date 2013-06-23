#pragma once
#ifndef Ray_h__
	#define Ray_h__

	#include "MathLibPCH.hpp"
	#include "LinearMath/Vector3.hpp"

namespace ClassicalMechanics
{
	namespace Algorithms
	{
		template< typename ScalarType >
		class RayResult_tpl
		{
		public:

			RayResult_tpl( void );

			RayResult_tpl( const LinearMath::Vector3_tpl< ScalarType >& collisionPoint, bool collisionOccurred );

			const LinearMath::Vector3_tpl< ScalarType > CollisionPoint( void ) const;

			const bool CollisionOccurred( void ) const;

		protected:

		private:

			LinearMath::Vector3_tpl< ScalarType > m_CollisionPoint;
			bool m_CollisionOccurred;
		};

		template< typename ScalarType >
		ClassicalMechanics::Algorithms::RayResult_tpl<ScalarType>::RayResult_tpl( void ) :
			m_CollisionOccurred( false ),
			m_CollisionPoint( LinearMath::Vector3_tpl< ScalarType >( 0 ) )
		{

		}

		template< typename ScalarType >
		class Ray3D_tpl
		{
		public:

			Ray3D_tpl( const LinearMath::Vector3_tpl< ScalarType >& origin,
				const LinearMath::Vector3_tpl< ScalarType >& direction,
				ScalarType length );

			RayResult_tpl< ScalarType > CheckCollisionTriangle( const LinearMath::Vector3_tpl< ScalarType >* triangle );

		protected:

		private:

			LinearMath::Vector3_tpl< ScalarType > m_Origin;
			LinearMath::Vector3_tpl< ScalarType > m_Direction;

			ScalarType m_Length;
		};

		template< typename ScalarType >
		ClassicalMechanics::Algorithms::Ray3D_tpl< ScalarType >::Ray3D_tpl(
			const LinearMath::Vector3_tpl< ScalarType >& origin,
			const LinearMath::Vector3_tpl< ScalarType >& direction,
			ScalarType length ) :
			m_Origin( origin ),
			m_Direction( direction.NormalizedCopy() ),
			m_Length( length )
		{
		}

		template< typename ScalarType >
		RayResult_tpl< ScalarType > ClassicalMechanics::Algorithms::Ray3D_tpl< ScalarType >::CheckCollisionTriangle(
			const LinearMath::Vector3_tpl< ScalarType >* triangle )
		{
			using namespace LinearMath;

			Vector3_tpl< ScalarType > u = triangle[ 1 ] - triangle[ 0 ];
			Vector3_tpl< ScalarType > v = triangle[ 2 ] - triangle[ 0 ];
			Vector3_tpl< ScalarType > w;
			Vector3_tpl< ScalarType > n = ( u ^ v );

			ScalarType denom = n * ( m_Direction * m_Length );

			if( denom == 0 )
			{
				return RayResult_tpl< ScalarType >( Vector3_tpl< ScalarType >( 0 ), false );
			}

			ScalarType r = ( n * ( triangle[ 0 ] - m_Origin ) ) / denom;
			if( r < 0 || r > m_Length )
			{
				return RayResult_tpl< ScalarType >( Vector3_tpl< ScalarType >( 0 ), false );
			}

			w = ( m_Origin + m_Direction * r ) - triangle[ 0 ];

			denom = ( u * v );
			denom *= denom;
			denom -= ( u * u ) * ( v * v );

			// May store dot products, because they are used more than once
			ScalarType si = ( ( u * v ) * ( w * v ) - ( v * v ) * ( w * u ) ) / denom;
			ScalarType ti = ( ( u * v ) * ( w * u ) - ( u * u ) * ( w * v ) ) / denom;

			bool result = ( si >= 0 ) && ( ti >= 0 ) && ( ( si + ti ) <= 1 );
			return RayResult_tpl< ScalarType >( result ? triangle[ 0 ] + si * u + ti * v : Vector3_tpl< ScalarType >(
				0 ), result );
		}

		template< typename ScalarType >
		const bool ClassicalMechanics::Algorithms::RayResult_tpl< ScalarType >::CollisionOccurred( void ) const
		{
			return m_CollisionOccurred;
		}

		template< typename ScalarType >
		const LinearMath::Vector3_tpl< ScalarType > ClassicalMechanics::Algorithms::RayResult_tpl< ScalarType >::
		CollisionPoint( void ) const
		{
			return m_CollisionPoint;
		}

		template< typename ScalarType >
		ClassicalMechanics::Algorithms::RayResult_tpl< ScalarType >::RayResult_tpl( const LinearMath::Vector3_tpl<
			ScalarType >& collisionPoint, bool collisionOccurred ) :
			m_CollisionOccurred( collisionOccurred ),
			m_CollisionPoint( collisionPoint )
		{
		}
	}
}

#endif	// Ray_h__
