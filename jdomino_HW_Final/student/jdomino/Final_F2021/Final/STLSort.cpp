//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <algorithm>
#include "STLSort.h"

// ----------------------------------------------
// Sort the stl vectors:
//
// Sort by Median value (largest first)
//     If there is a tie.. use strict weak ordering
//     largest number is first and so on...
//
// Assume:
//     vOut is initally empty
//     vIn is read-only
//     Sorted array is stored in vOut
//
// Example:
//    vIn (input):
//        2 3 4 5 5 --> Median: 4
//        8 6 7 2 5 --> Median: 6
//        5 6 4 5 8 --> Median: 5
//        3 2 1 3 5 --> Median: 3
//        9 5 2 3 6 --> Median: 5
//        2 3 4 1 2 --> Median: 2
//        9 8 5 1 5 --> Median: 5
//        
//    vOut (output):
//        8 6 7 2 5 --> Median: 6
//        9 8 5 1 5 --> Median: 5
//        9 5 2 3 6 --> Median: 5
//        5 6 4 5 8 --> Median: 5
//        2 3 4 5 5 --> Median: 4
//        3 2 1 3 5 --> Median: 3
//        2 3 4 1 2 --> Median: 2
//
// Hopefully you see the obvious pattern
//
// ----------------------------------------------

void SortMe(const std::vector< vData >& vIn,
            std::vector< vData >& vOut)
{
	//The plan:
	//	Store vIn in a local vector
	//  Sort the elements in each struct in local vector
	//	Store median from that
	//	put larger median first
	//	if they tie,
	//		use strict weak ordering
	// 
	//	When storing into vOut, use vIn
	//	It's unsorted
	// 
	// 
	//step one, get the median
	//sort via median
	//if tie, use Strict weak ordering

	std::vector<vData> v;
	std::vector<vData> vSort;
	v = vIn;
	vSort = v;

	int median1 = 0;
	int median2 = 0;
	
	//Step through vectors
	for (unsigned int i = 0; i < v.size(); i++)
	{
		SortStruct(vSort[i]);
		median1 = vSort[i].c;
			
		for (unsigned int j = i; j < v.size(); j++)
		{
			SortStruct(vSort[j]);
			median2 = vSort[j].c;

			//Check the median
			if (median2 > median1)
			{
				std::swap(vSort[j], vSort[i]);
				std::swap(v[j], v[i]);
				median1 = median2;
			}
			//if the medians are the same, check the second
			else if (median1 == median2)
			{
				if (v[j].a > v[i].a)
				{
					std::swap(vSort[j], vSort[i]);
					std::swap(v[j], v[i]);
					median1 = median2;
				}
				else if (v[j].a == v[i].a && v[j].b > v[i].b)
				{
					std::swap(vSort[j], vSort[i]);
					std::swap(v[j], v[i]);
					median1 = median2;
				}
				else if (v[j].a == v[i].a && v[j].b == v[i].b && v[j].c > v[i].c)
				{
					std::swap(vSort[j], vSort[i]);
					std::swap(v[j], v[i]);
					median1 = median2;
				}
				else if (v[j].a == v[i].a && v[j].b == v[i].b && v[j].c == v[i].c && v[j].d > v[i].d)
				{
					std::swap(vSort[j], vSort[i]);
					std::swap(v[j], v[i]);
					median1 = median2;
				}
				else if (v[j].a == v[i].a && v[j].b == v[i].b && v[j].c == v[i].c && v[j].d == v[i].d && v[j].e > v[i].e)
				{
					std::swap(vSort[j], vSort[i]);
					std::swap(v[j], v[i]);
					median1 = median2;
				}
			}
		}
	}

	vOut = v;
}

void SortStruct(vData & vIn)
{

	int vDataSize = sizeof(vData) / sizeof(int);
	//Set point to top of struct list
	int* pInt = &vIn.a;
	int* pInt2 = &vIn.b;

	for (int k = 0; k < vDataSize; k++)
	{
		for (int l = k; l < vDataSize - 1; l++)
		{
			if (*pInt2 < *pInt)
			{
				//if 2nd pointer is smaller, swap the data.
				int pTemp = *pInt;
				*pInt = *pInt2;
				*pInt2 = pTemp;
			}
			pInt2++;
		}
		pInt++;
		pInt2 = pInt + 1;
	}
}

// ---  End of File ---
