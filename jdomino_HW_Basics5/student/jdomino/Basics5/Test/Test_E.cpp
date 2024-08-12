//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <string.h>
#include "_UnitTestConfiguration.h"
#include "E.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

TEST(Test_E_Enable, TestConfig::ALL)
{
#if Test_E_Enable

	// Did you do any work?
	FILE_MODIFIED_CHECK(".\\..\\E\\E.cpp", ".\\Basics5\\E\\E.cpp", 0xfca05fea);

	Dog fido;

	CHECK(strcmp(fido.GetAction(fido), "bark") == 0);

#endif
}	TEST_END

// --- End of File ---
