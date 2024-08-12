//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef BUCKET_MAN_H
#define BUCKET_MAN_H

#include "Bucket.h"

class BucketMan
{
public:
	BucketMan();
	BucketMan(const Bucket&) = delete;
	BucketMan& operator = (const BucketMan&) = delete;

	// ------------------------------------------------
	// Do All work in the destructor
	// ------------------------------------------------
	~BucketMan();

	void Add(Bucket *pBucket);

private:

	void privAddToFront(Bucket* pBucket);

// -------------------------------
// Data:
// -------------------------------
public:
	Bucket * poHead;
};

#endif

// --- End of File ---
