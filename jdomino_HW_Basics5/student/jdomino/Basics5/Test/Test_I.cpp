//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <string.h>
#include "_UnitTestConfiguration.h"
#include "I.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

TEST(Test_I_Enable, TestConfig::ALL)
{
#if Test_I_Enable

	// Did you do any work?
	FILE_MODIFIED_CHECK(".\\..\\I\\I.cpp", ".\\Basics5\\I\\I.cpp", 0x305a1e7a);

	// initialize the array
	PrepareArray();

	//compute the Nth Triangular Number
	int sum = GetTriangularSum();

	CHECK(sum == 45);

#endif
} TEST_END

// --- End of File ---
