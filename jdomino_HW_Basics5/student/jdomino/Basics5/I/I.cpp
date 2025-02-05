//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "I.h"

// ----------------------------------------------------------------------
//
// I - Project
//
// Rules: Fix the code to correctly calculated the triangular sum
//        You can make this work with a small addition
//
// ----------------------------------------------------------------------

const int Num = 9;
int array[Num];

int GetTriangularSum()
{
	// calculate the triangular Nth Number
	// number: 1 + 2 + 3 + ... + N
	int total = 0;
	for (int i = 0; i < Num; i++)
	{
		total += array[i];
	}

	return total;
}

// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
void PrepareArray()
{
	int n = 0;
	// ascending array 
	// integers:  1, 
	//            2, 
	//            3,
	//            4,... , N
	for (int i = 0; i < Num; i++)
	{
		array[i] = ++n;
	}
}

// End of File