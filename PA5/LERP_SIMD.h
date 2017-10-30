//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#ifndef LERP_SIMD_H
#define LERP_SIMD_H

#include "Vect4D_SIMD.h"

#define UNUSED_VAR(v) ((void )v)

class VectApp_SIMD
{
public:
	static Vect4D_SIMD Lerp(const Vect4D_SIMD &a, const Vect4D_SIMD &b, const float t);
};

#endif

// ---  End of File ---------------
