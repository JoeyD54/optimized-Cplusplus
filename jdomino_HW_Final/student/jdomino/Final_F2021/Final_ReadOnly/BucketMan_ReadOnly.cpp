//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "BucketMan.h"

BucketMan::BucketMan()
	:poHead(nullptr)
{
}

void BucketMan::Add(Bucket *pBucket)
{
	assert(pBucket);
	privAddToFront(pBucket);
	pBucket->pMan = this;
}

void BucketMan::privAddToFront(Bucket* pBucket)
{
	assert(pBucket != nullptr);

	if (this->poHead == nullptr)
	{
		// first and only
		this->poHead = pBucket;
		pBucket->pNext = nullptr;
		pBucket->pPrev = nullptr;
	}
	else
	{
		// existing node... shove the new one in front
		this->poHead->pPrev = pBucket;
		pBucket->pNext = this->poHead;
		pBucket->pPrev = nullptr;
		this->poHead = pBucket;
	}
}

// --- End of File ---
