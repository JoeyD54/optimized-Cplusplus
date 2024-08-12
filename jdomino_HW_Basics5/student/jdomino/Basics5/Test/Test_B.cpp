//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <string.h>
#include "_UnitTestConfiguration.h"
#include "B.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

TEST(Test_B_Enable, TestConfig::ALL)
{
#if Test_B_Enable

	// Did you do any work?
	FILE_MODIFIED_CHECK(".\\..\\B\\B.cpp", ".\\Basics5\\B\\B.cpp", 0x5917fb21);

	StPatricks x;

	CHECK( strcmp( x.GetDay(), "March 17") == 0 );

#endif
} TEST_END

// --- End of file ---
