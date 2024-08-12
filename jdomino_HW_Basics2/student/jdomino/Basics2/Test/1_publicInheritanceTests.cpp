//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "UnitTestBufferManager.h"
#include "B.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

TEST(Public1, TestConfig::ALL)
{
	FILE_MODIFIED_CHECK("..\\Basics2\\A.h", 0x6fe21c2c);

	if (1)  // used to control scope in this test
	{
		B dataB;
		A *pA = &dataB;
		CHECK(pA->getX() == 5);
	}

	if (1)   // used to control scope in this test
	{
		A *pA = new B;
		delete pA;
	}

	CHECK(UnitTestBufferManager::getInstance()->getCount() == 0);
	
} TEST_END


// End of File
