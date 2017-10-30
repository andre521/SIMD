//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#ifndef PERFORMANCE_TEST_H
#define PERFORMANCE_TEST_H

#include "Vect4D.h"
#include "Vect4D_SIMD.h"
#include "Matrix.h"
#include "Matrix_SIMD.h"
#include "LERP.h"
#include "LERP_SIMD.h"

Vect4D rowMajor_test();
Vect4D_SIMD rowMajor_SIMD_test();

Vect4D colMajor_test();
Vect4D_SIMD colMajor_SIMD_test();

Vect4D test();
Vect4D_SIMD test_simd();

Matrix matrix_test();
Matrix_SIMD matrix_SIMD_test();

Vect4D vectMultMatrix_test();
Vect4D_SIMD vectMultMatrix_SIMD_test();

Vect4D matrixMultVect_test();
Vect4D_SIMD matrixMultVect_SIMD_test();

Vect4D LERP_Tests();
Vect4D_SIMD LERP_SIMD_Tests();

void PerformanceTest();

#endif

// ---  End of File ---------------
