//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

#include "UnitTest.h"
#include "Timer.h"

#include "PerformanceTest.h"

#ifdef _DEBUG
#define FACTOR 1
#else
#define FACTOR 10
#endif

void PerformanceTest()
{
	// Performance tests
	printf("\nPerformance tests: \n    Begin()\n");

	if (TestRegistry::GetStats().testPass != 7)
	{
		Trace::out("\n  ERROR---> didn't pass unit tests\n");
		Trace::out("\n    Cannot run performance tests\n\n\n");
	}
	else
	{
		Trace::out("\n");
		Timer t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1;

		// --------------- VECT 4D ----------------------------------------------

		Vect4D A;
		Trace::out("\n---------- Vect4D ----------------\n");
		printf("           : Vect4D\n");
		t2.Tic();

			A = test();
		
		t2.Toc();

		// --------------- VECT 4D SIMD ----------------------------------------------

		printf("           : Vect4D_SIMD\n");
		Vect4D_SIMD A_SIMD;
		t1.Tic();

			A_SIMD = test_simd();

		t1.Toc();

		Trace::out("  Vect4D Orig: %f s   :%f %f %f %f\n", t2.TimeInSeconds(), A.x, A.y, A.z, A.w);
		Trace::out("         SIMD: %f s   :%f %f %f %f\n", t1.TimeInSeconds(), A_SIMD.x, A_SIMD.y, A_SIMD.z, A_SIMD.w);
		Trace::out("        Ratio: %f\n", t2.TimeInSeconds() / t1.TimeInSeconds());


		// --------------- MATRIX ----------------------------------------------

		Trace::out("\n---------- Matrix ----------------\n");
		printf("           : Matrix\n");
		t3.Tic();

			Matrix B = matrix_test();

		t3.Toc();

		// --------------- Matrix SIMD ----------------------------------------------

		printf("           : Matrix_SIMD\n");
		t4.Tic();

			Matrix_SIMD B_SIMD = matrix_SIMD_test();

		t4.Toc();

		Trace::out("  Matrix Orig: %2.5f s    :%f %f %f %f\n", t3.TimeInSeconds(), B.v0.x, B.v0.y, B.v0.z, B.v0.w);
		Trace::out("                            :%f %f %f %f\n", B.v1.x, B.v1.y, B.v1.z, B.v1.w);
		Trace::out("                            :%f %f %f %f\n", B.v2.x, B.v2.y, B.v2.z, B.v2.w);
		Trace::out("                            :%f %f %f %f\n", B.v3.x, B.v3.y, B.v3.z, B.v3.w);

		Trace::out("  Matrix SIMD: %2.5f s    :%f %f %f %f\n", t4.TimeInSeconds(), B_SIMD.v0.x, B_SIMD.v0.y, B_SIMD.v0.z, B_SIMD.v0.w);
		Trace::out("                            :%f %f %f %f\n", B_SIMD.v1.x, B_SIMD.v1.y, B_SIMD.v1.z, B_SIMD.v1.w);
		Trace::out("                            :%f %f %f %f\n", B_SIMD.v2.x, B_SIMD.v2.y, B_SIMD.v2.z, B_SIMD.v2.w);
		Trace::out("                            :%f %f %f %f\n", B_SIMD.v3.x, B_SIMD.v3.y, B_SIMD.v3.z, B_SIMD.v3.w);

		Trace::out("        Ratio: %f\n", t3.TimeInSeconds() / t4.TimeInSeconds());

		// --------------- Vect * Matrix ----------------------------------------------

		Trace::out("\n---------- Vect * Matrix ----------------\n");
		printf("           : Vect * Matrix\n");
		t5.Tic();

			Vect4D C = vectMultMatrix_test();
	
		t5.Toc();

		// --------------- Vect * Matrix (SIMD) ----------------------------------------------

		printf("           : Vect * Matrix (SIMD)\n");
		t6.Tic();

			Vect4D_SIMD C_SIMD = vectMultMatrix_SIMD_test();

		t6.Toc();

		Trace::out("  Vect * Matrix Orig: %f s   :%f %f %f %f\n", t5.TimeInSeconds(), C.x, C.y, C.z, C.w);
		Trace::out("                SIMD: %f s   :%f %f %f %f\n", t6.TimeInSeconds(), C_SIMD.x, C_SIMD.y, C_SIMD.z, C_SIMD.w);
		Trace::out("               Ratio: %f\n", t5.TimeInSeconds() / t6.TimeInSeconds());


		// --------------- Matrix * Vector ----------------------------------------------

		Trace::out("\n---------- Matrix * Vect ----------------\n");
		printf("           : Matrix * Vect\n");
		t5.Tic();

			Vect4D D = matrixMultVect_test();
		
		t5.Toc();

		// --------------- Matrix * Vector (SIMD) ----------------------------------------------

		printf("           : Matrix * Vect (SIMD)\n");
		t6.Tic();

			Vect4D_SIMD D_SIMD = matrixMultVect_SIMD_test();
		
		t6.Toc();
		Trace::out("  Matrix * Vect Orig: %f s   :%f %f %f %f\n", t5.TimeInSeconds(), D.x, D.y, D.z, D.w);
		Trace::out("                SIMD: %f s   :%f %f %f %f\n", t6.TimeInSeconds(), D_SIMD.x, D_SIMD.y, D_SIMD.z, D_SIMD.w);
		Trace::out("               Ratio: %f\n", t5.TimeInSeconds() / t6.TimeInSeconds());

		// --------------- LERP ----------------------------------------------

		Trace::out("\n---------- LERP ----------------\n");
		printf("           : LERP\n");
		Vect4D LERP_C;
		t7.Tic();

			LERP_C = LERP_Tests();
		
		t7.Toc();

		// --------------- LERP SIMD ----------------------------------------------

		printf("           : LERP SIMD\n");
		Vect4D_SIMD LERP_SIMD_C;
		t8.Tic();

			LERP_SIMD_C = LERP_SIMD_Tests();

		t8.Toc();

		Trace::out("  LERP Orig: %f s   :%f %f %f %f\n", t7.TimeInSeconds(), LERP_C.x, LERP_C.y, LERP_C.z, LERP_C.w);
		Trace::out("       SIMD: %f s   :%f %f %f %f\n", t8.TimeInSeconds(), LERP_SIMD_C.x, LERP_SIMD_C.y, LERP_SIMD_C.z, LERP_SIMD_C.w);
		Trace::out("      Ratio: %f\n", t7.TimeInSeconds() / t8.TimeInSeconds());


		// --------------- RowMajor ----------------------------------------------

		Trace::out("\n---------- rowMajor ----------------\n");
		printf("           : rowMajor\n");
		Vect4D Row_C;
		t9.Tic();

			Row_C = rowMajor_test();
		
		t9.Toc();

		// --------------- RowMajor SIMD ----------------------------------------------
		printf("           : rowMajor SIMD\n");
		Vect4D_SIMD Row_SIMD_C;
		t10.Tic();

			Row_SIMD_C = rowMajor_SIMD_test();
	
		t10.Toc();

		Trace::out(" rowMajor Orig: %f s   :%f %f %f %f\n", t9.TimeInSeconds(), Row_C.x, Row_C.y, Row_C.z, Row_C.w);
		Trace::out("          SIMD: %f s   :%f %f %f %f\n", t10.TimeInSeconds(), Row_SIMD_C.x, Row_SIMD_C.y, Row_SIMD_C.z, Row_SIMD_C.w);
		Trace::out("         Ratio: %f\n", t9.TimeInSeconds() / t10.TimeInSeconds());


		// --------------- ColMajor ----------------------------------------------

		Trace::out("\n---------- colMajor ----------------\n");
		printf("           : colMajor\n");
		Vect4D Col_C;
		t11.Tic();

			Col_C = colMajor_test();
		
		t11.Toc();

		// --------------- colMajor SIMD ----------------------------------------------
		printf("           : colMajor SIMD\n");
		Vect4D_SIMD Col_SIMD_C;
		t12.Tic();

			Col_SIMD_C = colMajor_SIMD_test();
		
		t12.Toc();

		Trace::out(" colMajor Orig: %f s    :%f %f %f %f\n", t11.TimeInSeconds(), Col_C.x, Col_C.y, Col_C.z, Col_C.w);
		Trace::out("          SIMD: %f s    :%f %f %f %f\n", t12.TimeInSeconds(), Col_SIMD_C.x, Col_SIMD_C.y, Col_SIMD_C.z, Col_SIMD_C.w);
		Trace::out("         Ratio: %f\n", t11.TimeInSeconds() / t12.TimeInSeconds());

		// Tests done
		Trace::out("\nPerformance tests: done() \n\n");
		printf("\n    done() \n\n");

	}
}

// ---  End of File ---------------
