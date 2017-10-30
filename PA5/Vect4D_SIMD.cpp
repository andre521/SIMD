//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "Vect4D_SIMD.h"
#include "Matrix_SIMD.h"

#include <xmmintrin.h>
#include <smmintrin.h> 

Vect4D_SIMD Vect4D_SIMD::operator * (const Matrix_SIMD &m) const
{

/*
	float tmp0 = float((x * m.m0) + (y * m.m4) + (z * m.m8) + (w * m.m12));
	float tmp1 = float((x * m.m1) + (y * m.m5) + (z * m.m9) + (w * m.m13));
	float tmp2 = float((x * m.m2) + (y * m.m6) + (z * m.m10) + (w * m.m14));
	float tmp3 = float((x * m.m3) + (y * m.m7) + (z * m.m11) + (w * m.m15));
	return Vect4D_SIMD(tmp0, tmp1, tmp2, tmp3);
*/
	 //Correct - can be optimized
	// old attempt:

	Vect4D_SIMD xvect = _mm_mul_ps(m.v0._m, _mm_set_ps1(x));
	Vect4D_SIMD yvect = _mm_mul_ps(m.v1._m,_mm_set_ps1(y));
	Vect4D_SIMD zvect = _mm_mul_ps(m.v2._m,_mm_set_ps1(z));
	Vect4D_SIMD wvect = _mm_mul_ps(m.v3._m, _mm_set_ps1(w));

	Vect4D_SIMD tmp = xvect + yvect;
	Vect4D_SIMD tmp2 = tmp + zvect;
	return tmp2 + wvect; 
}

// ---  End of File ---------------


