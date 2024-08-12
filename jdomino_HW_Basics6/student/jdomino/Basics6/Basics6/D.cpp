//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include <vector>
#include <algorithm>

#include "D.h"
#include "Vect.h"

Vect V[] =
{
	{3,5,6},
	{6,5,3},
	{3,4,7},
	{7,2,5},
	{1,3,5},
	{3,2,5},
	{2,3,4},
	{3,5,5},
	{7,3,2},
	{4,3,2},
	{1,7,1}
};

Vect JunkDataD{ 0xa,0xb,0x3 };

void Problem_D(	std::vector< Vect > &UnitTest_V_orig,
				std::vector< Vect > &UnitTest_V_sort)
{	
	// ----------------------------------------------------
	// a) Load the V[] data into a vector
	//    Name the vector: v
	// ----------------------------------------------------

		// ADD CODE HERE:
		std::vector<Vect> v;

		for (Vect x : V)
		{
			v.push_back(x);
		}
		
		//std::vector<Vect> v{ JunkDataD };  // <-- REPLACE this LINE... shuts up warnings, its 100% wrong

		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_V_orig.assign(v.begin(), v.end());

	// ----------------------------------------------------
	// b) Sort the new STL vector with strict weak ordering
	//    Don't know what strict weak ordering is... Look it up
	// ----------------------------------------------------

		// ADD CODE HERE:
		for (unsigned int i = 0; i < v.size(); i++)
		{
			for (unsigned int j = i; j < v.size(); j++)
			{
				//Check first element
				if (v[j].a < v[i].a)
				{
					std::swap(v[j], v[i]);
				}
				//if the first elements are the same, check the second
				else if (v[j].a == v[i].a && v[j].b < v[i].b)
				{
					std::swap(v[j], v[i]);
				}
				else if (v[j].a == v[i].a && v[j].b == v[i].b && v[j].c < v[i].c)
				{
					std::swap(v[j], v[i]);
				}
			}
		}
		


		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_V_sort.assign(v.begin(), v.end());
}

// ---  End of File ---
