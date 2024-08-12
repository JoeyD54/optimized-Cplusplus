//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include <vector>
#include <algorithm>

#include "A.h"

int A[] = 
{
	6,
	7,
	3,
	2,
	8,
	1,
	9,
	4
};

int JunkDataA(777);

void Problem_A( std::vector<int> &UnitTest_A_orig, 
				std::vector<int> &UnitTest_A_insert, 
				std::vector<int> &UnitTest_A_sort)
{
	// ----------------------------------------------------
	// a) Load the A[] data into a vector
	//    Name the vector: A_Vector
	// ----------------------------------------------------

		// ADD CODE HERE:
		std::vector<int> A_Vector;

		for(int x: A)
		{
			A_Vector.push_back(x);
		}

		//std::vector<int> A_Vector{ A }; // <-- REPLACE this LINE... shuts up warnings, its 100% wrong

		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_A_orig.assign(A_Vector.begin(), A_Vector.end());

	// ----------------------------------------------------
	// b) Insert the number '5' between '2' and '8' values into A_Vector
	//    No brute force, assume there are 1000000 numbers before "2" and after "8".
	//    No iterative, simple approach, use the appropriate STL calls for efficiency
	// ----------------------------------------------------

		// ADD CODE HERE:
		
		std::vector<int>::iterator foundElement = std::find(A_Vector.begin(), A_Vector.end(), 2);
		if (foundElement != A_Vector.end() && *std::next(foundElement) == 8)
		{
			A_Vector.insert(foundElement + 1, 5);
		}
		

		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_A_insert.assign(A_Vector.begin(), A_Vector.end());

	// ----------------------------------------------------
	// c) sort the A_Vector
	//          Smallest to largest order
	// ----------------------------------------------------

		// ADD CODE HERE:
		for (unsigned int i = 0; i < A_Vector.size(); i++)
		{
			for (unsigned int j = i; j < A_Vector.size(); j++)
			{
				//Check first element
				if (A_Vector[j] < A_Vector[i])
				{
					std::swap(A_Vector[j], A_Vector[i]);
				}
			}
		}


		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_A_sort.assign(A_Vector.begin(), A_Vector.end());

}

// ---  End of File ---
