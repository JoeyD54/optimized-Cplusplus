//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <string.h>
#include "_UnitTestConfiguration.h"
#include "H.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

TEST(Test_H_Enable, TestConfig::ALL)
{
#if Test_H_Enable

	// Did you do any work?
	FILE_MODIFIED_CHECK(".\\..\\H\\H.cpp", ".\\Basics5\\H\\H.cpp", 0x1bbace55);

	// init the variables
	int n = 0;
	int sum = 0;

	// sum up the numbers
	while (getNum(n) && n)
	{
		sum += n;
	}

	CHECK(sum == 45);

#endif
}	TEST_END

// --- End of File ---
