//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "PerformanceTest.h"

#ifdef _DEBUG
#define VECT_COUNT 2000000
#else
#define VECT_COUNT 10000000
#endif

Vect4D test()
{
	Vect4D A;
	Vect4D B;
	Vect4D C;
	Vect4D N;

	N.x = 400.0f;
	N.y = 400.0f;
	N.z = 400.0f;
	N.w = 400.0f;

	A.x = 5.0f;
	A.y = 6.0f;
	A.z = 7.0f;
	A.w = 8.0f;

	B.x = 10.0f;
	B.y = 20.0f;
	B.z = 30.0f;
	B.w = 40.0f;

	for (int i = 0; i < VECT_COUNT; i++)
	{
		Vect4D D;
		D = B;
		D += A;
		Vect4D E = A + B;

		Vect4D F;
		F = B;
		F -= A;
		Vect4D G = A - B;

		Vect4D H;
		H = B;
		H *= A;
		Vect4D I = A * B;

		Vect4D J;
		J = B;
		J /= A;
		Vect4D K = A / B;

		Vect4D a(1, 2, 3, 4);
		Vect4D b(10, 10, 10, 10);

		Vect4D c;

		float t = a.dot(b);
		B.x *= 1.0f / t;

		A += B;
		A += C;
		A += D;
		A += E;
		A += F;
		A += G;
		A += H;
		A += I;
		A += a;
		A += b;
		A += c;
		A /= N;
	}

	return A;
}

// ---  End of File ---------------
