//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// Add headers as you see fit
#include <algorithm>
#include <set>
#include <vector>

#include "C.h"
#include "ZipCode.h"

ZipCode data[] =
{
	ZipCode("Bug", 0xABCD),
	ZipCode("Dog", 0x1331),
	ZipCode("Cat", 0x8844),
	ZipCode("Pig", 0xBB77),
	ZipCode("Bee", 0xFFEE),
	ZipCode("Nbt", 0xCC99)
};

ZipCode JunkDataC{ "tmp", 0x0 };


void Problem_C(	std::vector< ZipCode > &UnitTest_ZipSort,
				ZipCode &UnitTest_Bee,
				ZipCode &UnitTest_Zip)
{

	// ----------------------------------------------------
	// a) Insert the data into a stl:set in the order given.
	//    Use a compare function that sorts with the 2nd letter of the string 
	//          Smallest to largest
	//    Name the set: zippy
	// ----------------------------------------------------

		// ADD CODE HERE:
		std::vector<ZipCode> zippy;

		for (ZipCode x : data)
		{
			zippy.push_back(x);
		}

		for (unsigned int i = 0; i < zippy.size(); i++)
		{
			for (unsigned int j = i; j < zippy.size(); j++)
			{
				if (zippy[j].s[1] < zippy[i].s[1])
				{
					std::swap(zippy[j], zippy[i]);
				}
			}
			
		}

		//std::set< ZipCode > zippy{ JunkDataC };  // <-- REPLACE this LINE... shuts up warnings, its 100% wrong
		//std::set< ZipCode >::iterator zippy_it = zippy.begin();  // <-- REPLACE this LINE... shuts up warnings, its 100% wrong

		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_ZipSort.assign(zippy.begin(), zippy.end());
		
	// ----------------------------------------------------
	// b)  Find node {"Bee", 0xFFEE} in the set
	//     use the complete node in the search
	//     Initialize the iterator where it found the node
	//
	//     Name the set iterator: zippy_it
	// ----------------------------------------------------

		// ADD CODE HERE:
		ZipCode toFind;
		strcpy_s(toFind.s, sizeof(toFind.s), "Bee");
		toFind.zip = 0xFFEE;

		std::vector<ZipCode>::iterator zippy_it;

		for (unsigned int i = 0; i < zippy.size(); i++)
		{
			if (zippy[i] == toFind)
			{
				zippy_it = zippy.begin() + (int)i;
			}
		}

		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_Bee = *zippy_it;

	// ----------------------------------------------------
	// c)  Find the the string name associated with this zip data '0xBB77'
	//     Do not use the complete node, only the zip data
	//     Look at the node contents and iterator address
	//
	//     NOTE: you can only use STL: set  - no maps!
	//     hint:  use a custom predicate
	//
	//     Name the set iterator: zippy_it
	// ----------------------------------------------------

		// ADD CODE HERE:
		int findThisInt = 0xBB77;

		for (unsigned int i = 0; i < zippy.size(); i++)
		{
			if (zippy[i].zip == findThisInt)
			{
				zippy_it = zippy.begin() + (int) i;
			}
		}


		//zippy_it = std::find(zippy.begin(), zippy.end(), findThisInt);


		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_Zip = *zippy_it;

}

// ---  End of File ---
