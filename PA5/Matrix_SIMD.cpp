//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "Vect4D_SIMD.h"
#include "Matrix_SIMD.h"

//Vect4D_SIMD Matrix_SIMD::operator * (const Vect4D_SIMD &v)
//{
//	
//
//	return Vect4D_SIMD(v0.realDot(v), v1.realDot(v), v2.realDot(v), v3.realDot(v));
//}

//Matrix_SIMD Matrix_SIMD::operator * (const Matrix_SIMD &t)
//{
//
//	// Across then down!
//	Vect4D_SIMD tmp1 = _mm_set_ps(t.m0, t.m4, t.m8, t.m12);
//	Vect4D_SIMD tmp2 = _mm_set_ps(t.m1, t.m5, t.m9, t.m13);
//	Vect4D_SIMD tmp3 = _mm_set_ps(t.m2, t.m6, t.m10, t.m14);
//	Vect4D_SIMD tmp4 = _mm_set_ps(t.m3, t.m7, t.m11, t.m15);
//
//	Vect4D_SIMD fin1 = _mm_set_ps(v0.realDot(tmp1), v0.realDot(tmp2), v0.realDot(tmp3), v0.realDot(tmp4));
//	Vect4D_SIMD fin2 = _mm_set_ps(v1.realDot(tmp1), v1.realDot(tmp2), v1.realDot(tmp3), v1.realDot(tmp4));
//	Vect4D_SIMD fin3 = _mm_set_ps(v2.realDot(tmp1), v2.realDot(tmp2), v2.realDot(tmp3), v2.realDot(tmp4));
//	Vect4D_SIMD fin4 = _mm_set_ps(v3.realDot(tmp1), v3.realDot(tmp2), v3.realDot(tmp3), v3.realDot(tmp4));
//
//	Matrix_SIMD mat = Matrix_SIMD(fin1, fin2, fin3, fin4);
//
//	return mat;
//}

// ---  End of File ---------------
