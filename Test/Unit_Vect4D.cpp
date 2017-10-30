//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "UnitTest.h"

#include "Vect4D.h"
#include "Vect4D_Simd.h"

#define f_eq(A,B) (  fabs(A - B) < 0.001f)
#define V_EQ(A,B) ((f_eq(A.x,B.x) ) && ( f_eq(A.y, B.y)) && (f_eq(A.z,B.z)) && (f_eq(A.w,B.w) ))

TEST(vect4d, SIMD_TESTS)
{
	Vect4D A;
	Vect4D B;
	Vect4D C;

	A.x = 5.0f;
	A.y = 6.0f;
	A.z = 7.0f;
	A.w = 8.0f;

	B.x = 10.0f;
	B.y = 20.0f;
	B.z = 30.0f;
	B.w = 40.0f;

	Vect4D D;
	D = B;
	D += A;
	Vect4D E;
	E = A + B;

	Vect4D F;
	F = B;
	F -= A;
	Vect4D G;
	G = A - B;

	Vect4D H;
	H = B;
	H *= A;
	Vect4D I;
	I = A * B;

	Vect4D J;
	J = B;
	J /= A;
	Vect4D K;
	K = A / B;

	Vect4D a(1, 2, 3, 4);
	Vect4D b(10, 10, 10, 10);

	float t = a.dot(b);

	Vect4D_SIMD A_simd;
	Vect4D_SIMD B_simd;

	A_simd.x = 5.0f;
	A_simd.y = 6.0f;
	A_simd.z = 7.0f;
	A_simd.w = 8.0f;

	B_simd.x = 10.0f;
	B_simd.y = 20.0f;
	B_simd.z = 30.0f;
	B_simd.w = 40.0f;

	CHECK(V_EQ(A, A_simd));
	CHECK(V_EQ(B, B_simd));

	Vect4D_SIMD D_simd;

	D_simd = B_simd;
	D_simd += A_simd;

	CHECK(V_EQ(D, D_simd));

	Vect4D_SIMD E_simd;
	E_simd = A_simd + B_simd;

	CHECK(V_EQ(E, E_simd));

	Vect4D_SIMD F_simd;
	F_simd = B_simd;
	F_simd -= A_simd;

	CHECK(V_EQ(F, F_simd));

	Vect4D_SIMD G_simd;
	G_simd = A_simd - B_simd;

	CHECK(V_EQ(G, G_simd));

	Vect4D_SIMD H_simd;
	H_simd = B_simd;
	H_simd *= A_simd;

	CHECK(V_EQ(H, H_simd));

	Vect4D_SIMD I_simd;
	I_simd = A_simd * B_simd;

	CHECK(V_EQ(I, I_simd));

	Vect4D_SIMD J_simd;
	J_simd = B_simd;
	J_simd /= A_simd;

	CHECK(V_EQ(J, J_simd));

	Vect4D_SIMD K_simd;
	K_simd = A_simd / B_simd;

	CHECK(V_EQ(K, K_simd));

	Vect4D_SIMD a_simd;
	a_simd = Vect4D_SIMD(1, 2, 3, 4);
	Vect4D_SIMD b_simd;
	b_simd = Vect4D_SIMD(10, 10, 10, 10);

	CHECK(V_EQ(a, a_simd));
	CHECK(V_EQ(b, b_simd));

	float t_simd = a_simd.dot(b_simd);

	CHECK(t == t_simd);
}

// ---  End of File ---------------
