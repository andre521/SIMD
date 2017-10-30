//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "PerformanceTest.h"

#ifdef _DEBUG
#define LERP_COUNT 500000
#else
#define LERP_COUNT 5000000
#endif

Vect4D LERP_Tests()
{
	Vect4D vOut;
	Vect4D A(1.00f, 2.0f, 3.0f, 4.0f);
	Vect4D B(21.00f, 12.0f, 23.0f, 40.0f);
	Vect4D C(13.00f, 24.0f, 33.0f, 40.0f);
	Vect4D D(0.50f, 22.0f, 43.0f, 40.0f);
	Vect4D E(1.30f, 23.0f, 35.0f, 40.0f);
	Vect4D F(15.00f, 72.0f, 35.0f, 40.0f);
	Vect4D G(21.00f, 92.0f, 33.0f, 40.0f);

	vOut = VectApp::Lerp(A, B, 0.65f);

	for (int i = 0; i < LERP_COUNT; i++)
	{
		vOut = VectApp::Lerp(A, vOut, 0.65f);
		vOut = VectApp::Lerp(B, vOut, 0.15f);
		vOut = VectApp::Lerp(C, vOut, 0.25f);
		vOut = VectApp::Lerp(D, vOut, 0.35f);
		vOut = VectApp::Lerp(E, vOut, 0.45f);
		vOut = VectApp::Lerp(F, vOut, 0.55f);
		vOut = VectApp::Lerp(G, vOut, 0.65f);
		vOut = VectApp::Lerp(A, vOut, 0.75f);
		vOut = VectApp::Lerp(A, vOut, 0.85f);
		vOut = VectApp::Lerp(B, vOut, 0.95f);
		vOut = VectApp::Lerp(C, vOut, 0.05f);
		vOut = VectApp::Lerp(D, vOut, 0.15f);
		vOut = VectApp::Lerp(E, vOut, 0.25f);
		vOut = VectApp::Lerp(F, vOut, 0.35f);
		vOut = VectApp::Lerp(G, vOut, 0.45f);
		vOut = VectApp::Lerp(A, vOut, 0.65f);
		vOut = VectApp::Lerp(B, vOut, 0.15f);
		vOut = VectApp::Lerp(C, vOut, 0.25f);
		vOut = VectApp::Lerp(D, vOut, 0.35f);
		vOut = VectApp::Lerp(E, vOut, 0.45f);
		vOut = VectApp::Lerp(F, vOut, 0.55f);
		vOut = VectApp::Lerp(G, vOut, 0.65f);
		vOut = VectApp::Lerp(A, vOut, 0.75f);
		vOut = VectApp::Lerp(A, vOut, 0.85f);
		vOut = VectApp::Lerp(B, vOut, 0.95f);
		vOut = VectApp::Lerp(C, vOut, 0.05f);
		vOut = VectApp::Lerp(D, vOut, 0.15f);
		vOut = VectApp::Lerp(E, vOut, 0.25f);
		vOut = VectApp::Lerp(F, vOut, 0.35f);
		vOut = VectApp::Lerp(G, vOut, 0.45f);
		vOut = VectApp::Lerp(A, vOut, 0.65f);
		vOut = VectApp::Lerp(B, vOut, 0.15f);
		vOut = VectApp::Lerp(C, vOut, 0.25f);
		vOut = VectApp::Lerp(D, vOut, 0.35f);
		vOut = VectApp::Lerp(E, vOut, 0.45f);
		vOut = VectApp::Lerp(F, vOut, 0.55f);
		vOut = VectApp::Lerp(G, vOut, 0.65f);
		vOut = VectApp::Lerp(A, vOut, 0.75f);
		vOut = VectApp::Lerp(A, vOut, 0.85f);
		vOut = VectApp::Lerp(B, vOut, 0.95f);
		vOut = VectApp::Lerp(C, vOut, 0.05f);
		vOut = VectApp::Lerp(D, vOut, 0.15f);
		vOut = VectApp::Lerp(E, vOut, 0.25f);
		vOut = VectApp::Lerp(F, vOut, 0.35f);
		vOut = VectApp::Lerp(G, vOut, 0.45f);
	}

	return vOut;
}

// ---  End of File ---------------
