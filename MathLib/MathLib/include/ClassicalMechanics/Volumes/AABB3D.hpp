#pragma once
#ifndef AABB3D_h__
	#define AABB3D_h__

	#include "MathLibPCH.hpp"
	#include "LinearMath/Vector3.hpp"
	#include "LinearMath/MathHelper.hpp"

namespace ClassicalMechanics
{
	namespace Volumes
	{
		template< typename ScalarType >
		class AABB3D_tpl
		{
		public:

			AABB3D_tpl(
				const LinearMath::Vector3_tpl< ScalarType >& min,
				const LinearMath::Vector3_tpl< ScalarType >& max );
			AABB3D_tpl( const AABB3D_tpl& aabb );

			void Min( const LinearMath::Vector3_tpl< ScalarType >& min );

			void Max( const LinearMath::Vector3_tpl< ScalarType >& max );

			const LinearMath::Vector3_tpl< ScalarType >& Min( void ) const;

			const LinearMath::Vector3_tpl< ScalarType >& Max( void ) const;

			void FillBounds( LinearMath::Vector3_tpl< ScalarType >* data ) const;

			bool Intersects( const AABB3D_tpl< ScalarType >& other ) const;

			bool Contains( const AABB3D_tpl< ScalarType >& other ) const;

			bool Contains( const LinearMath::Vector3_tpl< ScalarType >& point );

			LinearMath::Vector3_tpl< ScalarType > Centre( void ) const;

			void Centre( LinearMath::Vector3_tpl< ScalarType >& vec ) const;

			void Move( const LinearMath::Vector3_tpl< ScalarType >& offset );

			const LinearMath::Vector3_tpl< ScalarType > Size( void ) const;

			void Size( LinearMath::Vector3_tpl< ScalarType >& size ) const;

		protected:

		private:

			void CheckBounds( void );

			LinearMath::Vector3_tpl< ScalarType > m_Minimum;
			LinearMath::Vector3_tpl< ScalarType > m_Maximum;
		};

		template< typename ScalarType >
		void ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::Centre( LinearMath::Vector3_tpl< ScalarType >& vec )
		const
		{
			vec = m_Minimum + 0.5f * m_Maximum;
		}

		template< typename ScalarType >
		LinearMath::Vector3_tpl< ScalarType > ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::Centre( void )
		const
		{
			return m_Minimum + 0.5f * m_Maximum;
		}

		template< typename ScalarType >
		bool ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::Contains(
			const LinearMath::Vector3_tpl< ScalarType >& point )
		{
			using namespace LinearMath;

			Vector3_tpl< ScalarType > diff = Centre() - point;
			Vector3_tpl< ScalarType > size = Size();

			return ( MathHelper_tpl< ScalarType >::Abs( diff.X ) <= size.X )
				   && ( MathHelper_tpl< ScalarType >::Abs( diff.Y ) <= size.Y )
				   && ( MathHelper_tpl< ScalarType >::Abs( diff.Z ) <= size.Z );
		}

		template< typename ScalarType >
		bool ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::Contains( const AABB3D_tpl< ScalarType >& other )
		const
		{
			return ( ( m_Maximum.X >= other.m_Maximum.X ) && ( m_Minimum.X <= other.m_Minimum.X ) )
				   && ( ( m_Maximum.Y >= other.m_Maximum.Y ) && ( m_Minimum.Y <= other.m_Minimum.Y ) )
				   && ( ( m_Maximum.Z >= other.m_Maximum.Z ) && ( m_Minimum.Z <= other.m_Minimum.Z ) );
		}

		template< typename ScalarType >
		bool ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::Intersects( const AABB3D_tpl< ScalarType >& other )
		const
		{
			return ( ( m_Maximum.X >= other.m_Minimum.X ) && ( other.m_Maximum.X >= m_Minimum.X ) )
				   && ( ( m_Maximum.Y >= other.m_Minimum.Y ) && ( other.m_Maximum.Y >= m_Minimum.Y ) )
				   && ( ( m_Maximum.Z >= other.m_Minimum.Z ) && ( other.m_Maximum.Z >= m_Minimum.Z ) );
		}

		template< typename ScalarType >
		void ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::CheckBounds( void )
		{
			ScalarType tmp;

			if( m_Minimum.X > m_Maximum.X )
			{
				tmp = m_Maximum.X;
				m_Maximum.X = m_Minimum.X;
				m_Minimum.X = tmp;
			}

			if( m_Minimum.Y > m_Maximum.Y )
			{
				tmp = m_Maximum.Y;
				m_Maximum.Y = m_Minimum.Y;
				m_Minimum.Y = tmp;
			}

			if( m_Minimum.Z > m_Maximum.Z )
			{
				tmp = m_Maximum.Z;
				m_Maximum.Z = m_Minimum.Z;
				m_Minimum.Z = tmp;
			}
		}

		template< typename ScalarType >
		const LinearMath::Vector3_tpl< ScalarType > ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::Size( void )
		const
		{
			return m_Maximum - m_Minimum;
		}

		template< typename ScalarType >
		void ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::Size( LinearMath::Vector3_tpl< ScalarType >& size )
		const
		{
			size = m_Maximum - m_Minimum;
		}

		template< typename ScalarType >
		void ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::Move(
			const LinearMath::Vector3_tpl< ScalarType >& offset )
		{
			m_Minimum += offset;
			m_Maximum += offset;
		}

		template< typename ScalarType >
		void ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::FillBounds(
			LinearMath::Vector3_tpl< ScalarType >* data ) const
		{
			using namespace Numerics;

			for( uint8 i = 0U; i < 8U; ++i )
			{
				data[ i ] = LinearMath::Vector3_tpl< ScalarType >(
					( 1U & i ) ? m_Maximum.X : m_Minimum.X,
					( 2U & i ) ? m_Maximum.Y : m_Minimum.Y,
					( 4U & i ) ? m_Maximum.Z : m_Minimum.Z );
			}
		}

		template< typename ScalarType >
		const LinearMath::Vector3_tpl< ScalarType >& ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::Max( void )
		const
		{
			return m_Maximum;
		}

		template< typename ScalarType >
		const LinearMath::Vector3_tpl< ScalarType >& ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::Min( void )
		const
		{
			return m_Minimum;
		}

		template< typename ScalarType >
		void ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::Max(
			const LinearMath::Vector3_tpl< ScalarType >& max )
		{
			m_Maximum = max;
			CheckBounds();
		}

		template< typename ScalarType >
		void ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::Min(
			const LinearMath::Vector3_tpl< ScalarType >& min )
		{
			m_Minimum = min;
			CheckBounds();
		}

		template< typename ScalarType >
		ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::AABB3D_tpl( const AABB3D_tpl& aabb ) :
			m_Minimum( aabb.m_Minimum ),
			m_Maximum( aabb.m_Maximum )
		{
		}

		template< typename ScalarType >
		ClassicalMechanics::Volumes::AABB3D_tpl< ScalarType >::AABB3D_tpl(
			const LinearMath::Vector3_tpl< ScalarType >& min,
			const LinearMath::Vector3_tpl< ScalarType >& max ) :
			m_Minimum( min ),
			m_Maximum( max )
		{
			CheckBounds();
		}
	}
}

#endif	// AABB3D_h__
