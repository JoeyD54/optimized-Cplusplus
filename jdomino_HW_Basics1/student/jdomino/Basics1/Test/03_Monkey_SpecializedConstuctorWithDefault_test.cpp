//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "Monkey.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

TEST(Monkey_SpecializedConstructorWithDefault, TestConfig::ALL)
{
#if Monkey_SpecializedConstructorWithDefault

	FILE_MODIFIED_CHECK("..\\Basics1\\Monkey.cpp", 0x0cbd1174);

	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK(Monkey::numStringsCreated == 0);
	CHECK(Monkey::numStringsDestroyed == 0);

	Monkey blue_mono(333);

	CHECK(blue_mono.getX() == 333);
	CHECK(blue_mono.getY() == 555);
	CHECK(strcmp(blue_mono.getStatus(), "ThIs tring was initilized by a clever user!") == 0);
	CHECK(Monkey::numStringsCreated == 1);
	CHECK(Monkey::numStringsDestroyed == 0);

#endif
} TEST_END

//---  End of File ---
