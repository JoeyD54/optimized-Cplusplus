//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "BucketMan.h"

// ------------------------------------------------
// Do All work in the destructor
// ------------------------------------------------
BucketMan::~BucketMan()
{
	//Does this bucket manager have buckets?
	if (this->poHead)
	{
		//We need to delete them all
		Bucket* pBucket;

		while (this->poHead)
		{
			pBucket = this->poHead->pNext;
			delete this->poHead;
			this->poHead = pBucket;
		}
	}
}

// --- End of File ---

