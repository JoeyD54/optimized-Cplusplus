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

extern PerformanceTimer t_Merge;

// Used for TEARDOWN
static OList *pOList_3 = nullptr;
static DestructCommand *pDestCommand_3 = nullptr;

TEST_WITH_TEARDOWN(Combo_Test_Enable, TestConfig::ALL)
{
#if Combo_Test_Enable
	//-----------------------------------------------------------------------------
	// 0) Create objects
	//-----------------------------------------------------------------------------

	PerformanceTimer t5;

	//-----------------------------------------------------------------------------
	// 1) Create the original Link List timing
	//-----------------------------------------------------------------------------

	// Do not modify or data this function, you need to leave this routine alone.
	pOList_3 = new OList(25000);

	// Setup the destructor
	pDestCommand_3 = new UnitTestDestructCommand(pOList_3);
	pOList_3->SetDestructCommand(pDestCommand_3);

	// find a specific key
	Node foundNode;

	bool foundFlag = pOList_3->FindKey(0x7f9e1b10, foundNode);

	CHECK(foundNode.key == 0x7F9E1B10);
	CHECK(foundNode.x == 657018931);
	CHECK(foundNode.y == 1315507706);
	CHECK(foundNode.z == 1847085303);
	CHECK(foundFlag == true);

	//-----------------------------------------------------------------------------
	// 2) (Merge/Insert)Combo Timing
	//-----------------------------------------------------------------------------

	// Experiment with this number for best results
	// Set the CutoffLength to the best value in the constuctor
	int CutoffLength = pOList_3->GetCutoffLength();  
	
	// DELETE ME... only for testing on Keenan's PC
	//CutoffLength = 32;

	t5.Tic();
		
		// -----------------------------------------------------------------------
		// ---->  Create this function, Merge Sort with Insertion Sort <---------- 
		// -----------------------------------------------------------------------
		// -----  CutoffLength is length that determines when to used   ----------
		// -----  Insertion Sort instead of Merge Sort for sublist of   ----------
		// -----  of smaller lengths                                    ---------- 
		// -----------------------------------------------------------------------
		pOList_3->MergeComboSort(CutoffLength);

	t5.Toc();

	// Make sure new list is proper
	bool result = OList::VerifySortOrder(pOList_3);
	CHECK(result == true);

	Trace::out2("           Combo Time: %f ms   Cutoff length: %d\n", t5.TimeInSeconds() * 1000.0f, CutoffLength);
	Trace::out2("\n");
	Trace::out2(" Combo_Vs_Merge Ratio: %f faster\n", t_Merge.TimeInSeconds() / t5.TimeInSeconds());

	delete pOList_3;
	pOList_3 = nullptr;
	delete pDestCommand_3;
	pDestCommand_3 = nullptr;


#endif
}  TEST_END

TEST_TEARDOWN(Combo_Test_Enable)
{
#if Combo_Test_Enable

	delete pOList_3;
	delete pDestCommand_3;

#endif
}

// ---  End of File ---------------
