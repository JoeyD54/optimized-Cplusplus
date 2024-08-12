//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <string.h>
#include "_UnitTestConfiguration.h"
#include "F.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

TEST(Test_F_Enable, TestConfig::ALL)
{
#if Test_F_Enable	

	// Did you do any work?
	FILE_MODIFIED_CHECK(".\\..\\F\\F.cpp", ".\\Basics5\\F\\F.cpp", 0xb8397525);

	CHECK(FindBitsInNibble(0x5F3) == 8);

#endif
}	TEST_END

// --- End of File ---
