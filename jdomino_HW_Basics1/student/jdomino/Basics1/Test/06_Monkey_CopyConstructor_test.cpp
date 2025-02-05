//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "Monkey.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

TEST( Monkey_CopyConstructor, TestConfig::ALL)
{
#if Monkey_CopyConstructor

	FILE_MODIFIED_CHECK("..\\Basics1\\Monkey.cpp", 0x0cbd1174);

	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	Monkey blue_mono(777,888);

	CHECK( blue_mono.getX() == 777 );
	CHECK( blue_mono.getY() == 888 );
	CHECK( strcmp(blue_mono.getStatus(),"ThIs tring was initilized by a clever user!") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	Monkey green_mono( blue_mono );

	CHECK( green_mono.getX() == 777 );
	CHECK( green_mono.getY() == 888 );
	CHECK( strcmp(green_mono.getStatus(),"ThIs tring was initilized by a clever user!") == 0) ; 
	CHECK( Monkey::numStringsCreated == 2 );
	CHECK( Monkey::numStringsDestroyed == 0 );

#endif
} TEST_END

//---  End of File ---
