//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "Nyble.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

TEST( Nyble_SpecialOps, TestConfig::ALL)
{	
#if Nyble_SpecialOps

	FILE_MODIFIED_CHECK("..\\Basics1\\Nyble.cpp", 0x7813b5a4);

	Nyble A(5);
	Nyble B;

	B = ~A;

	CHECK( A.getData() == 5 );
	CHECK( B.getData() == 0xA );

	Nyble C(0xC);
	Nyble D;

	D = ~C;

	CHECK(C.getData() == 0xC);
	CHECK(D.getData() == 3);

#endif
} TEST_END

//---  End of File ---
