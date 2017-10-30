//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "Matrix.h"

// Add code

Vect4D Matrix::operator * (const Vect4D &v)
{
	// Pretty confident this is correct
	return Vect4D(v0.realDot(v), v1.realDot(v), v2.realDot(v), v3.realDot(v));

}

Matrix Matrix::operator * (const Matrix &t)
{

	// Pretty confident this is correct
	Vect4D tmp1 = Vect4D(t.m0, t.m4, t.m8, t.m12);
	Vect4D tmp2 = Vect4D(t.m1, t.m5, t.m9, t.m13);
	Vect4D tmp3 = Vect4D(t.m2, t.m6, t.m10, t.m14);
	Vect4D tmp4 = Vect4D(t.m3, t.m7, t.m11, t.m15);

	Vect4D fin1 = Vect4D(v0.realDot(tmp1), v0.realDot(tmp2), v0.realDot(tmp3),v0.realDot(tmp4));
	Vect4D fin2 = Vect4D(v1.realDot(tmp1), v1.realDot(tmp2), v1.realDot(tmp3), v1.realDot(tmp4));
	Vect4D fin3 = Vect4D(v2.realDot(tmp1), v2.realDot(tmp2), v2.realDot(tmp3), v2.realDot(tmp4));
	Vect4D fin4 = Vect4D(v3.realDot(tmp1), v3.realDot(tmp2), v3.realDot(tmp3), v3.realDot(tmp4));
	
	Matrix mat = Matrix(fin1, fin2, fin3, fin4);
	return mat;

}

// ---  End of File ---------------
