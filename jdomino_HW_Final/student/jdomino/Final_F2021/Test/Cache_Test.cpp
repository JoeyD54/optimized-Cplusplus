//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"

#include "List.h"
#include "HotList.h"
#include "Node.h"
#include "Hot.h"

TEST_WITH_TEARDOWN(Cache_Test_Enable, TestConfig::ALL)
{
#if Cache_Test_Enable 

	// PLACE HOLDER - you don't get TESTS for your FINAL!
	CHECK(true);
	//List* pList = new List();

	//HotList* pHotList = new HotList(pList);

	//PerformanceTimer t1;
	//PerformanceTimer t2;
	//// start timer
	//t1.Tic();
	//Node* pTmp = pList->Find(0x36ca2b0e);
	//t1.Toc();
	//Trace::out("Key:%x time: %f ms \n", pTmp->key, t1.TimeInSeconds() * 1000);
	//// start timer
	//t2.Tic();
	//Hot* pHotTmp = pHotList->Find(0x36ca2b0e);
	//t2.Toc();
	//Trace::out("Key:%x time: %f ms \n", pHotTmp->key, t2.TimeInSeconds() * 1000);
	//float ratio = t1.TimeInSeconds() / t2.TimeInSeconds();
	//Trace::out("Ratio: %f \n", ratio);

	//delete pList;
	//delete pHotList;

#endif
} TEST_END

TEST_TEARDOWN(Cache_Test_Enable)
{

}

// ---  End of File ---
