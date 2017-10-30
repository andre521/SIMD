//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "PerformanceTest.h"

#ifdef _DEBUG
#define MATRIX_COUNT 10000000
#else
#define MATRIX_COUNT 100000000
#endif

Matrix matrix_test()
{
	Vect4D VA0(0.556670, -0.321394, -0.766044, 0.000000);
	Vect4D VA1(0.696747, 0.682796, 0.219846, 0.000000);
	Vect4D VA2(0.452395, -0.656121, 0.604023, 0.000000);
	Vect4D VA3(1.000000, 2.000000, 3.000000, 1.000000);
	Vect4D VB0(-0.1f, -0.2f, -0.3f, -0.4f);
	Vect4D VB1(0.4f, 0.5f, 0.6f, 0.7f);
	Vect4D VB2(0.1f, 0.2f, 0.3f, 0.4f);
	Vect4D VB3(-0.4f, -0.3f, -0.2f, -0.1f);

	Matrix A(VA0, VA1, VA2, VA3);
	Matrix B(VB0, VB1, VB2, VB3);
	Matrix C = B;

	for (int i = 0; i < MATRIX_COUNT; i++)
	{
		C = C * A;
	}
	return C;
}

// ---  End of File ---------------
