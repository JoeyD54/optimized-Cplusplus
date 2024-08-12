//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "FoodTruck.h"

FoodTruck::~FoodTruck()
{
	Candy* tempCandy;

	while (this->poFirst != nullptr)
	{
		tempCandy = this->poFirst->pNext;
		poFirst->pNext = nullptr;
		delete poFirst;
		poFirst = tempCandy;
	}
}

// --- End of File ---
