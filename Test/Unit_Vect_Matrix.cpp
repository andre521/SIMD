//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "UnitTest.h"

#include "Vect4D.h"
#include "Vect4D_SIMD.h"
#include "Matrix.h"
#include "Matrix_SIMD.h"

#define f_eq(A,B) (  fabs(A - B) < 0.001f)
#define V_EQ(A,B) ((f_eq(A.x,B.x) ) && ( f_eq(A.y, B.y)) && (f_eq(A.z,B.z)) && (f_eq(A.w,B.w) ))

TEST(Vect_Matrix, SIMD_Tests)
{
	Vect4D A(1, 2, 3, 4);
	Vect4D B(11, 12, 13, 14);
	Vect4D C(21, 22, 23, 24);

	Vect4D MV0(1, 2, 3, 4);
	Vect4D MV1(5, 6, 7, 8);
	Vect4D MV2(9, 10, 11, 12);
	Vect4D MV3(13, 14, 15, 16);

	Matrix M(MV0, MV1, MV2, MV3);

	Vect4D vout1;
	Vect4D vout2;
	Vect4D vout3;

	vout1 = A * M;
	vout2 = B * M;
	vout3 = C * M;

	Vect4D_SIMD A_simd;
	A_simd = Vect4D_SIMD(1, 2, 3, 4);
	Vect4D_SIMD B_simd;
	B_simd = Vect4D_SIMD(11, 12, 13, 14);
	Vect4D_SIMD C_simd;
	C_simd = Vect4D_SIMD(21, 22, 23, 24);

	Vect4D_SIMD MV0_simd(1, 2, 3, 4);
	Vect4D_SIMD MV1_simd(5, 6, 7, 8);
	Vect4D_SIMD MV2_simd(9, 10, 11, 12);
	Vect4D_SIMD MV3_simd(13, 14, 15, 16);

	CHECK(M.v0.x == 1.0f);

	Matrix_SIMD M_simd;
	M_simd = Matrix_SIMD(MV0_simd, MV1_simd, MV2_simd, MV3_simd);

	Vect4D_SIMD vout1_simd;
	Vect4D_SIMD vout2_simd;
	Vect4D_SIMD vout3_simd;

	vout1_simd = A_simd * M_simd;
	vout2_simd = B_simd * M_simd;
	vout3_simd = C_simd * M_simd;

	CHECK(V_EQ(M.v0, M_simd.v0));
	CHECK(V_EQ(M.v1, M_simd.v1));
	CHECK(V_EQ(M.v2, M_simd.v2));
	CHECK(V_EQ(M.v3, M_simd.v3));

	CHECK(V_EQ(A, A_simd));
	CHECK(V_EQ(B, B_simd));
	CHECK(V_EQ(C, C_simd));

	CHECK(V_EQ(vout1, vout1_simd));
	CHECK(V_EQ(vout2, vout2_simd));
	CHECK(V_EQ(vout3, vout3_simd));
}

// ---  End of File ---------------
