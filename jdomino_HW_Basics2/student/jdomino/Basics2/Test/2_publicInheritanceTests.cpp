//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "UnitTestBufferManager.h"
#include "D.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

TEST(Public2, TestConfig::ALL)
{
	FILE_MODIFIED_CHECK("..\\Basics2\\D.cpp", 0x7a1fef24);

	D d0;

	CHECK(d0.getX() == 33);
	CHECK(d0.getY() == 44);
	CHECK(d0.getZ() == 55);

	D d1(0xAA, 0xBB, 0xCC);

	CHECK(d1.getX() == 0xAA);
	CHECK(d1.getY() == 0xBB);
	CHECK(d1.getZ() == 0xCC);

	CHECK(UnitTestBufferManager::getInstance()->getCount() == 0);

} TEST_END


// End of File
