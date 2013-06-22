#include "stdafx.hpp"
#include "CppUnitTest.h"
#include "Vector3.hpp"
#include "ClassicalMechanics/Volumes/AABB3D.hpp"

using namespace ClassicalMechanics::Volumes;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template class __declspec( dllexport ) LinearMath::Vector3_tpl< float >;
template class __declspec( dllexport ) LinearMath::Vector3_tpl< double >;

template class __declspec( dllexport ) AABB3D_tpl< float >;
template class __declspec( dllexport ) AABB3D_tpl< double >;

namespace MathLibUnitTest
{
	// TODO: Test AABB3D_tpl
}
