//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#ifndef LERP_H
#define LERP_H

#include "Vect4D.h"

#define UNUSED_VAR(v) ((void )v)

class VectApp
{
public:
	static Vect4D Lerp( const Vect4D &a,  const Vect4D &b,  const float t );
};
#endif

// ---  End of File ---------------
