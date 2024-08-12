//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Bucket.h"
#include "Item.h"

// ------------------------------------------------
// Do All work in the destructor
// ------------------------------------------------
Item::~Item()
{
	//Make sure nothing is nullptr (thus the checks)

	//Delete what item holds before deleting item.
	if (this->poData)
	{
		delete this->poData;
	}

	//Reset pointers
	
	if (this->pPrev)
	{
		this->pPrev->pNext = this->pNext;
	}
	if (this->pNext)
	{
		this->pNext->pPrev = this->pPrev;
	}

	this->pPrev = nullptr;
	this->pNext = nullptr;
}

// --- End of File ---

