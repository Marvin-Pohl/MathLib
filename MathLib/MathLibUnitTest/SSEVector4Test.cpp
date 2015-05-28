#include "stdafx.hpp"
#include "CppUnitTest.h"
#include <SSEVector4.hpp>
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace LinearMath;

typedef float Scalar;

//typedef LinearMath::SSEVector4 SSEVector4;

namespace MathLibUnitTest
{

  TEST_CLASS( SSEVector4Test )
  {
  public:

    TEST_METHOD( SSEVector4Constructor1 )
    {
      SSEVector4 v;

      Assert::AreEqual( 0.0f, v.GetX() );
      Assert::AreEqual( 0.0f, v.GetY() );
      Assert::AreEqual( 0.0f, v.GetZ() );
      Assert::AreEqual( 0.0f, v.GetW() );
    }

    TEST_METHOD( SSEVector4Constructor2 )
    {
      SSEVector4 v( 5 );

      Assert::AreEqual( 5.0f, v.GetX() );
      Assert::AreEqual( 5.0f, v.GetY() );
      Assert::AreEqual( 5.0f, v.GetZ() );
      Assert::AreEqual( 5.0f, v.GetW() );
    }

    TEST_METHOD( SSEVector4Constructor3 )
    {
      SSEVector4 v( 2.5f, 3.7f, 42.0f, 555.0f );

      Assert::AreEqual( 2.5f, v.GetX() );
      Assert::AreEqual( 3.7f, v.GetY() );
      Assert::AreEqual( 42.0f, v.GetZ() );
      Assert::AreEqual( 555.0f, v.GetW() );

    }

    TEST_METHOD( SSEVector4Add )
    {
      SSEVector4 v1( 10, 20, 30, 40 );
      SSEVector4 v2( 50, 60, 70, 80 );

      SSEVector4 v3 = v1 + v2;

      Assert::AreEqual( v1.GetX() + v2.GetX(), v3.GetX() );
      Assert::AreEqual( v1.GetY() + v2.GetY(), v3.GetY() );
      Assert::AreEqual( v1.GetZ() + v2.GetZ(), v3.GetZ() );
      Assert::AreEqual( v1.GetW() + v2.GetW(), v3.GetW() );
    }

    TEST_METHOD( SSEVector4Add2 )
    {
      SSEVector4 v1( 10, 20, 30, 40 );
      SSEVector4 v2( 50, 60, 70, 80 );

      v1 += v2;

      Assert::AreEqual( 60.0f, v1.GetX() );
      Assert::AreEqual( 80.0f, v1.GetY() );
      Assert::AreEqual( 100.0f, v1.GetZ() );
      Assert::AreEqual( 120.0f, v1.GetW() );
    }

    TEST_METHOD( SSEVector4Sub1 )
    {
      SSEVector4 v1( 10, 20, 30, 40 );
      SSEVector4 v2( 50, 60, 70, 80 );

      SSEVector4 v3 = v1 - v2;

      Assert::AreEqual( v1.GetX() - v2.GetX(), v3.GetX() );
      Assert::AreEqual( v1.GetY() - v2.GetY(), v3.GetY() );
      Assert::AreEqual( v1.GetZ() - v2.GetZ(), v3.GetZ() );
      Assert::AreEqual( v1.GetW() - v2.GetW(), v3.GetW() );
    }

    TEST_METHOD( SSEVector4Sub2 )
    {
      SSEVector4 v1( 10, 20, 30, 40 );
      SSEVector4 v2( 50, 60, 70,80 );

      v1 -= v2;

      Assert::AreEqual( -40.0f, v1.GetX() );
      Assert::AreEqual( -40.0f, v1.GetY() );
      Assert::AreEqual( -40.0f, v1.GetZ() );
      Assert::AreEqual( -40.0f, v1.GetW() );
    }

    TEST_METHOD( SSEVector4Mult1 )
    {
      SSEVector4 v( 10, 20, 30, 40 );
      Scalar scal = 10;

      SSEVector4 out = v*scal;

      Assert::AreEqual( 100.0f, out.GetX() );
      Assert::AreEqual( 200.0f, out.GetY() );
      Assert::AreEqual( 300.0f, out.GetZ() );
      Assert::AreEqual( 400.0f, out.GetW() );
    }

    TEST_METHOD( SSEVector4Mult2 )
    {
      SSEVector4 v( 10, 20, 30,40 );
      Scalar scal = 10;

      v *= scal;

      Assert::AreEqual( 100.0f, v.GetX() );
      Assert::AreEqual( 200.0f, v.GetY() );
      Assert::AreEqual( 300.0f, v.GetZ() );
      Assert::AreEqual( 400.0f, v.GetW() );
    }

    TEST_METHOD( SSEVector4Mult3 )
    {
      SSEVector4 v( 10, 20, 30,40 );
      Scalar scal = 10;

      SSEVector4 out = scal * v;

      Assert::AreEqual( 100.0f, out.GetX() );
      Assert::AreEqual( 200.0f, out.GetY() );
      Assert::AreEqual( 300.0f, out.GetZ() );
      Assert::AreEqual( 400.0f, out.GetW() );
    }

    TEST_METHOD( SSEVector4Mult4 )
    {
      SSEVector4 v1( 10, 20, 30, 40 );
      SSEVector4 v2( 50, 60, 70, 80 );

      Scalar scal = v1*v2;

      Assert::AreEqual( ( ( 10.0f*50.0f ) + ( 20.0f*60.0f ) + ( 30.0f*70.0f ) + ( 40.0f*80.0f ) ), scal );
    }

    TEST_METHOD( SSEVector4Div1 )
    {
      SSEVector4 v( 10, 20, 30,40 );
      Scalar scal = 10;

      SSEVector4 out = v / scal;

      Assert::AreEqual( 1.0f, out.GetX() );
      Assert::AreEqual( 2.0f, out.GetY() );
      Assert::AreEqual( 3.0f, out.GetZ() );
      Assert::AreEqual( 4.0f, out.GetW() );
    }

    TEST_METHOD( SSEVector4Div2 )
    {
      SSEVector4 v( 10, 20, 30,40 );
      Scalar scal = 10;

      v /= scal;

      Assert::AreEqual( 1.0f, v.GetX() );
      Assert::AreEqual( 2.0f, v.GetY() );
      Assert::AreEqual( 3.0f, v.GetZ() );
      Assert::AreEqual( 4.0f, v.GetW() );
    }

    TEST_METHOD( SSEVector4LengthSq )
    {
      SSEVector4 v( 10, 20, 30, 40 );

      Scalar length = v.LengthSquared();

      Assert::AreEqual( ( 10.0f*10.0f ) + ( 20.0f*20.0f ) + ( 30.0f*30.0f ) + ( 40.0f*40.0f ), length );
    }

    TEST_METHOD( SSEVector4Length )
    {
      SSEVector4 v( 4, 0, -3, 0 );

      Scalar length = v.Length();

      Assert::AreEqual( 5.0f, length );
    }

    TEST_METHOD( SSEVector4Normalize )
    {
      SSEVector4 v( 10, 20, 30, 40 );

      Scalar length = v.Length();

      v.Normalize();

      Assert::AreEqual( 10.0f / length, v.GetX() );
      Assert::AreEqual( 20.0f / length, v.GetY() );
      Assert::AreEqual( 30.0f / length, v.GetZ() );
      Assert::AreEqual( 40.0f / length, v.GetW() );
    }

    TEST_METHOD( SSEVector4NormalizeCopy )
    {
      SSEVector4 v( 10.0f, 20.0f, 30.0f, 40.0f );


      Scalar length = v.Length();
      SSEVector4 out = v.NormalizedCopy();


      Assert::AreEqual( 10.0f / length, out.GetX() );
      Assert::AreEqual( 20.0f / length, out.GetY() );
      Assert::AreEqual( 30.0f / length, out.GetZ() );
      Assert::AreEqual( 40.0f / length, out.GetW() );
      Assert::AreNotEqual( v.GetX(), out.GetX() );
      Assert::AreNotEqual( v.GetY(), out.GetY() );
      Assert::AreNotEqual( v.GetZ(), out.GetZ() );
      Assert::AreNotEqual( v.GetW(), out.GetW() );

    }

    TEST_METHOD( SSEVector4DotProduct )
    {
      SSEVector4 v1( 10, 20, 30, 40 );
      SSEVector4 v2( 50, 60, 70, 80 );

      Scalar scal = v1.DotProduct( v2 );

      Assert::AreEqual( ( ( 10.0f*50.0f ) + ( 20.0f*60.0f ) + ( 30.0f*70.0f ) + ( 40.0f*80.0f ) ), scal );
    }
  };
}