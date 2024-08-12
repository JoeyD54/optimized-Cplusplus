//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "Nyble.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

TEST(Nyble_SpecialOps2, TestConfig::ALL)
{
#if Nyble_SpecialOps2

	FILE_MODIFIED_CHECK("..\\Basics1\\Nyble.cpp", 0x7813b5a4);

	Nyble C(7);
	Nyble D;

	D = +C;

	CHECK(C.getData() == 7);
	CHECK(D.getData() == 10);

#endif
} TEST_END

//---  End of File ---
