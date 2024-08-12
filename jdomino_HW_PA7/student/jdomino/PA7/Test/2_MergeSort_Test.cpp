//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"
#include "OList.h"
#include "Node.h"
#include "UnitTestDestructCommand.h"

// Used in Combo Test for comparision
PerformanceTimer t_Merge;

// used for comparison with merge
extern PerformanceTimer t_Insert;

// Used for Teardown
static OList *pOList_2 = nullptr;
static DestructCommand *pDestCommand_2 = nullptr;

TEST_WITH_TEARDOWN(Merge_Test_Enable, TestConfig::ALL)
{
#if Merge_Test_Enable

	//-----------------------------------------------------------------------------
	// 1) Create the original Link List timing
	//-----------------------------------------------------------------------------

	// Do not modify or data this function, you need to leave this routine alone.
	pOList_2 = new OList(25000);

	// Setup the destructor
	pDestCommand_2 = new UnitTestDestructCommand(pOList_2);
	pOList_2->SetDestructCommand(pDestCommand_2);

	// find a specific key
	Node foundNode;

	bool foundFlag = pOList_2->FindKey(0x7f9e1b10, foundNode);

	CHECK(foundNode.key == 0x7F9E1B10);
	CHECK(foundNode.x == 657018931);
	CHECK(foundNode.y == 1315507706);
	CHECK(foundNode.z == 1847085303);
	CHECK(foundFlag == true);

	//-----------------------------------------------------------------------------
	// 2) Merge Sort Timing
	//-----------------------------------------------------------------------------

	t_Merge.Tic();

		// -----------------------------------------------------
		// ---->  Create this function, use Merge sort  <-------
		// -----------------------------------------------------
		pOList_2->MergeSort();

	t_Merge.Toc();

	// Make sure new list is proper
	bool result = OList::VerifySortOrder(pOList_2);
	CHECK(result == true);

	Trace::out2("           Merge Time: %f ms\n", t_Merge.TimeInSeconds() * 1000.0f);
	Trace::out2("\n");
	Trace::out2("Merge_Vs_Insert Ratio: %f faster\n", t_Insert.TimeInSeconds() / t_Merge.TimeInSeconds() );
	Trace::out2("\n");

	delete pOList_2;
	pOList_2 = nullptr;
	delete pDestCommand_2;
	pDestCommand_2 = nullptr;

#endif
} TEST_END

TEST_TEARDOWN(Merge_Test_Enable)
{
#if Merge_Test_Enable

	delete pOList_2;
	delete pDestCommand_2;

#endif
}

// ---  End of File ---------------
