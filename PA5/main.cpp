//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------

// User headers
#include "UnitTest.h"
#include "PerformanceTest.h"

int main()
{
	// execute the tests
	TestRegistry::RunTests();

	// Run the performance tests
	PerformanceTest();
}

// ---  End of File ---------------
