//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <string.h>
#include "_UnitTestConfiguration.h"
#include "J.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

TEST(Test_J_Enable, TestConfig::ALL)
{
#if Test_J_Enable

	// Did you do any work?
	FILE_MODIFIED_CHECK(".\\..\\J\\J.cpp", ".\\Basics5\\J\\J.cpp", 0xa97eb2cd);

	Dog fido(20);
	CHECK(Dog::GetVal(fido) == 20);

	Dog rex(21);
	CHECK(Dog::GetVal(fido) == 20);
	CHECK(Dog::GetVal(rex) == 21);

#endif
} TEST_END

// --- End of File ---
