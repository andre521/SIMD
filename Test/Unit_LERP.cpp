//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "UnitTest.h"

#include "LERP.h"
#include "LERP_SIMD.h"

#define f_eq(A,B) (  fabs(A - B) < 0.001f)
#define V_EQ(A,B) ((f_eq(A.x,B.x) ) && ( f_eq(A.y, B.y)) && (f_eq(A.z,B.z)) && (f_eq(A.w,B.w) ))

TEST(LERP, SIMD_Tests)
{
	Vect4D va(0.0f, 0.0f, 0.0f, 0.0f);
	Vect4D vb(10.0f, 20.0f, 30.0f, 40.0f);
	Vect4D vout;

	vout = VectApp::Lerp(va, vb, 0.0f);

	CHECK((vout.x == 0.0f));
	CHECK((vout.y == 0.0f));
	CHECK((vout.z == 0.0f));
	CHECK((vout.w == 0.0f));

	va.set(0.0f, 0.0f, 0.0f, 0.0f);
	vb.set(10.0f, 20.0f, 30.0f, 40.0f);

	vout = VectApp::Lerp(va, vb, 0.5f);

	CHECK((vout.x == 5.0f));
	CHECK((vout.y == 10.0f));
	CHECK((vout.z == 15.0f));
	CHECK((vout.w == 20.0f));

	va.set(0.0f, 0.0f, 0.0f, 0.0f);
	vb.set(10.0f, 20.0f, 30.0f, 40.0f);

	vout = VectApp::Lerp(va, vb, 0.25f);

	CHECK((vout.x == 2.5f));
	CHECK((vout.y == 5.0f));
	CHECK((vout.z == 7.50f));
	CHECK((vout.w == 10.0f));

	va.set(0.0f, 0.0f, 0.0f, 0.0f);
	vb.set(10.0f, 20.0f, 30.0f, 40.0f);

	vout = VectApp::Lerp(va, vb, 1.0f);

	CHECK((vout.x == 10.0f));
	CHECK((vout.y == 20.0f));
	CHECK((vout.z == 30.0f));
	CHECK((vout.w == 40.0f));

	Vect4D_SIMD va_simd(0.0f, 0.0f, 0.0f, 0.0f);
	Vect4D_SIMD vb_simd(10.0f, 20.0f, 30.0f, 40.0f);
	Vect4D_SIMD vout_simd;

	vout_simd = VectApp_SIMD::Lerp(va_simd, vb_simd, 0.0f);

	CHECK((vout_simd.x == 0.0f));
	CHECK((vout_simd.y == 0.0f));
	CHECK((vout_simd.z == 0.0f));
	CHECK((vout_simd.w == 0.0f));

	va_simd.set(0.0f, 0.0f, 0.0f, 0.0f);
	vb_simd.set(10.0f, 20.0f, 30.0f, 40.0f);

	vout_simd = VectApp_SIMD::Lerp(va_simd, vb_simd, 0.5f);

	CHECK((vout_simd.x == 5.0f));
	CHECK((vout_simd.y == 10.0f));
	CHECK((vout_simd.z == 15.0f));
	CHECK((vout_simd.w == 20.0f));

	va_simd.set(0.0f, 0.0f, 0.0f, 0.0f);
	vb_simd.set(10.0f, 20.0f, 30.0f, 40.0f);

	vout_simd = VectApp_SIMD::Lerp(va_simd, vb_simd, 0.25f);

	CHECK((vout_simd.x == 2.5f));
	CHECK((vout_simd.y == 5.0f));
	CHECK((vout_simd.z == 7.50f));
	CHECK((vout_simd.w == 10.0f));

	va_simd.set(0.0f, 0.0f, 0.0f, 0.0f);
	vb_simd.set(10.0f, 20.0f, 30.0f, 40.0f);

	vout_simd = VectApp_SIMD::Lerp(va_simd, vb_simd, 1.0f);

	CHECK((vout_simd.x == 10.0f));
	CHECK((vout_simd.y == 20.0f));
	CHECK((vout_simd.z == 30.0f));
	CHECK((vout_simd.w == 40.0f));

	Vect4D_SIMD vOut;
	Vect4D_SIMD A(1.00f, 2.0f, 3.0f, 4.0f);
	Vect4D_SIMD B(21.00f, 12.0f, 23.0f, 40.0f);

	vOut = VectApp_SIMD::Lerp(A, B, 0.5f);

	CHECK((vOut.x == 11.0f));
	CHECK((vOut.y == 7.0f));
	CHECK((vOut.z == 13.0f));
	CHECK((vOut.w == 22.0f));

	vOut = VectApp_SIMD::Lerp(A, vOut, 0.5f);

	CHECK((vOut.x == 6.0f));
	CHECK((vOut.y == 4.5f));
	CHECK((vOut.z == 8.0f));
	CHECK((vOut.w == 13.0f));

	Vect4D_SIMD vOut_SIMD;
	Vect4D_SIMD A_SIMD(1.00f, 2.0f, 3.0f, 4.0f);
	Vect4D_SIMD B_SIMD(21.00f, 12.0f, 23.0f, 40.0f);

	vOut_SIMD = VectApp_SIMD::Lerp(A_SIMD, B_SIMD, 0.5f);

	CHECK((vOut_SIMD.x == 11.0f));
	CHECK((vOut_SIMD.y == 7.0f));
	CHECK((vOut_SIMD.z == 13.0f));
	CHECK((vOut_SIMD.w == 22.0f))

	vOut_SIMD = VectApp_SIMD::Lerp(A_SIMD, vOut_SIMD, 0.5f);

	CHECK((vOut_SIMD.x == 6.0f));
	CHECK((vOut_SIMD.y == 4.5f));
	CHECK((vOut_SIMD.z == 8.0f));
	CHECK((vOut_SIMD.w == 13.0f));
}

// ---  End of File ---------------
