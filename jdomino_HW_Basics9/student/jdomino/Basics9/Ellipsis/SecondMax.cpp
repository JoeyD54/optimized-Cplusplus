//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include <vector>
#include <algorithm>

#include "SecondMax.h"

int SecondMax(int count, ...)
{
	// Do your magic here:

	va_list list;
	va_start(list, count);

	bool largestChanged = false;
	int val1 = 0;
	int temp = 0;
	int largest = 0;
	int scndLargest = 0;

	for (int i = 0; i < count; i++)
	{
		val1 = va_arg(list, int);
		
		//get largest first
		if (val1 > largest && val1 != largest)
		{
			temp = largest;
			largest = val1;
			largestChanged = true;
		}
		//did largest fail due to a bigger number already being stored?
		//Check if new number is bigger than second largest number
		else if (val1 < largest && val1 > scndLargest)
		{
			scndLargest = val1;
		}
	

		//Store second largest
		if (largestChanged)
		{
			scndLargest = temp;
		}

		largestChanged = false;
	}

	va_end(list);

	return scndLargest;
}

// ---  End of File ---------------
