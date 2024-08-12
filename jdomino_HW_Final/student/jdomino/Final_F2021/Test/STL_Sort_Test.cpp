//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"

#include "STLSort.h"


TEST_WITH_TEARDOWN(STL_Sort_Test_Enable, TestConfig::ALL)
{
#if STL_Sort_Test_Enable

	// PLACE HOLDER - you don't get TESTS for your FINAL!

	//    vIn (input):
//        2 3 4 5 5 --> Median: 4
//        8 6 7 2 5 --> Median: 6
//        5 6 4 5 8 --> Median: 5
//        3 2 1 3 5 --> Median: 3
//        9 5 2 3 6 --> Median: 5
//        2 3 4 1 2 --> Median: 2
//        9 8 5 1 5 --> Median: 5

	//vData v1 = { 2,3,4,5,5 };
	//vData v2 = { 8,6,7,2,5 };
	//vData v3 = { 5,6,4,5,8 };
	//vData v4 = { 3,2,1,3,5 };
	//vData v5 = { 9,5,2,3,6 };
	//vData v6 = { 2,3,4,1,2 };
	//vData v7 = { 9,8,5,1,5 };

	//std::vector<vData> vect1;
	//std::vector<vData> sVect1;
	//vect1.push_back(v1);
	//vect1.push_back(v2);
	//vect1.push_back(v3);
	//vect1.push_back(v4);
	//vect1.push_back(v5);
	//vect1.push_back(v6);
	//vect1.push_back(v7);

	//for (vData tempData : vect1)
	//{
	//	Trace::out("Struct contains: %d, %d, %d, %d, %d\n", tempData.a, tempData.b, tempData.c, tempData.d, tempData.e);
	//}

	//SortMe(vect1, sVect1);

	//Trace::out("\n--------------------------\n");

	//for (vData tempData : sVect1)
	//{
	//	Trace::out("Struct contains: %d, %d, %d, %d, %d\n", tempData.a, tempData.b, tempData.c, tempData.d, tempData.e);
	//}

#endif
} TEST_END

TEST_TEARDOWN(STL_Sort_Test_Enable)
{
}

// ---  End of File ---
