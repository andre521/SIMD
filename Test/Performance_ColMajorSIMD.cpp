//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "PerformanceTest.h"

#ifdef _DEBUG
#define COL_COUNT 6000000
#else
#define COL_COUNT 30000000
#endif

Vect4D_SIMD colMajor_SIMD_test()
{
	Matrix_SIMD Rx(Vect4D_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, -0.500000f, 0.866025f, 0.000000f),
				   Vect4D_SIMD(0.000000f, -0.866025f, -0.500000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix_SIMD Ry(Vect4D_SIMD(0.707107f, 0.000000f, -0.707107f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 1.000000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.707107f, 0.000000f, 0.707107f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix_SIMD Rz(Vect4D_SIMD(0.500000f, -0.866025f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.866025f, 0.500000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 1.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix_SIMD  T(Vect4D_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 1.000000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 1.000000f, 0.000000f),
				   Vect4D_SIMD(4.000000f, 5.000000f, 6.000000f, 1.000000f));

	Matrix_SIMD  S(Vect4D_SIMD(1.000000f, 0.000000f, 0.000000f, 0.200000f),
				   Vect4D_SIMD(0.000000f, 2.000000f, 0.000000f, 0.300000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.500000f, 0.500000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.000000f, 0.130000f));

	Vect4D_SIMD  v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
	Vect4D_SIMD  vOut;

	for (int i = 0; i < COL_COUNT; i++)
	{
		vOut = S * Rx *Ry * Rz * T * v;
	}

	return vOut;
}
// ---  End of File ---------------
