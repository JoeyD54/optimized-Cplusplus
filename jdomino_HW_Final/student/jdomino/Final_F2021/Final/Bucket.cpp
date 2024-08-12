//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "BucketMan.h"
#include "Bucket.h"

// ------------------------------------------------
// Do All work in the destructor
// ------------------------------------------------
Bucket::~Bucket()
{
	//Does this bucket have items?
	if (this->poHead)
	{
		//We need to delete them all
		Item* pItem;
		
		while (this->poHead)
		{
			pItem = this->poHead->pNext;
			delete this->poHead;
			this->poHead = pItem;
		}
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

