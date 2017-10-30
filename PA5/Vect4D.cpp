//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "Vect4D.h"
#include "Matrix.h"

Vect4D Vect4D::operator * (const Matrix &m) const
{	
	// xyzw going up on each loop?

	float tmp0 = float((x * m.m0) + (y * m.m4) + (z * m.m8) + (w * m.m12));
	float tmp1 = float((x * m.m1) + (y * m.m5) + (z * m.m9) + (w * m.m13));
	float tmp2 = float((x * m.m2) + (y * m.m6) + (z * m.m10) + (w * m.m14));
	float tmp3 = float((x * m.m3) + (y * m.m7) + (z * m.m11) + (w * m.m15));
	return Vect4D(tmp0, tmp1, tmp2, tmp3);


};

// ---  End of File ---------------
