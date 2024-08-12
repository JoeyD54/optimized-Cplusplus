//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"

#include "Candy.h"
#include "FoodTruck.h"

TEST_WITH_TEARDOWN(MemoryLeak_Test_Enable, TestConfig::ALL)
{
#if MemoryLeak_Test_Enable

	// PLACE HOLDER - you don't get TESTS for your FINAL!
	/*Candy* pA = new Candy("Pop Rocks");
	Candy* pB = new Candy("Bomb Pop");
	Candy* pC = new Candy("Nerds");
	Candy* pD = new Candy("KitKat");
	WMS_Corp* pWMS_Corp = new FoodTruck();
	pWMS_Corp->Add(pA);
	pWMS_Corp->Add(pB);
	pWMS_Corp->Add(pC);
	pWMS_Corp->Add(pD);
	pWMS_Corp->Print();
	delete pWMS_Corp;*/

	CHECK(true);

	
#endif
} TEST_END


TEST_TEARDOWN(MemoryLeak_Test_Enable)
{

}


// ---  End of File ---

