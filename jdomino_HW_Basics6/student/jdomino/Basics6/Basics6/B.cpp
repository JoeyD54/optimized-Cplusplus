//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include <list>
#include <algorithm>
#include <functional>
#include <vector>

#include "B.h"

int B[] = 
{
	66,
	77,
	33,
	22,
	88,
	11,
	99,
	44
};

int JunkDataB(555);

void Problem_B(	std::vector<int> &UnitTest_B_orig, 
				std::vector<int> &UnitTest_B_insert, 
				std::vector<int> &UnitTest_B_sort)
{
	// ----------------------------------------------------
	// a) Load the B[] data into a list
	//    Name the list: B_List
	// ----------------------------------------------------

		// ADD CODE HERE:
		std::vector<int> B_List;

		for (int x : B)
		{
			B_List.push_back(x);
		}
		

		//std::list<int> B_List{ JunkDataB };  // <-- REPLACE this LINE... shuts up warnings, its 100% wrong

		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_B_orig.assign(B_List.begin(), B_List.end());

	// ----------------------------------------------------
	// b) Insert the number '55' between 22 and 88 into B_List
	//    No brute force, assume there are 1000000 numbers before 22 and after 88.
	//    No iterative, simple approach, use the appropriate STL calls for efficiency
	// ----------------------------------------------------

		// ADD CODE HERE:
		std::vector<int>::iterator foundElement = std::find(B_List.begin(), B_List.end(), 22);
		if (foundElement != B_List.end() && *std::next(foundElement) == 88)
		{
			B_List.insert(foundElement + 1, 55);
		}
		

	

		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_B_insert.assign(B_List.begin(), B_List.end());

	// ----------------------------------------------------
	// c) sort the list in reverse order using the built in functional functions
	//        Largest to Smallest
	// ----------------------------------------------------

		// ADD CODE HERE:
		for (unsigned int i = 0; i < B_List.size(); i++)
		{
			for (unsigned int j = i; j < B_List.size(); j++)
			{
				//Check first element
				if (B_List[j] > B_List[i])
				{
					std::swap(B_List[j], B_List[i]);
				}
				
			}
		}


		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_B_sort.assign(B_List.begin(), B_List.end());
}

// ---  End of File ---
