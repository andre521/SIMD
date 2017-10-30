//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "PerformanceTest.h"

#ifdef _DEBUG
#define MV_COUNT 10000000
#else
#define MV_COUNT 100000000
#endif

Vect4D_SIMD matrixMultVect_SIMD_test(void)
{
	Vect4D_SIMD A(1, 2, 3, 4);

	Vect4D_SIMD VA0(0.556670, 0.696747, 0.452395, 1.000000);
	Vect4D_SIMD VA1(-0.321394, 0.682796, -0.656121, 2.000000);
	Vect4D_SIMD VA2(-0.766044, 0.219846, 0.604023, 3.000000);
	Vect4D_SIMD VA3(0.000000, 0.000000, 0.000000, 1.000000);
	
	Matrix_SIMD M(VA0, VA1, VA2, VA3);
	
	Vect4D_SIMD vout;
	Vect4D_SIMD v1;
	Vect4D_SIMD v2;

	for (int i = 0; i < MV_COUNT; i++)
	{
		v1 = M * A;
		v2 = M * v1;
		A = M * v2;
	}

	return A;
}

// ---  End of File ---------------
