//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef BUCKET_H
#define BUCKET_H

#include "Item.h"

// Forward Declaration
class BucketMan;

class Bucket
{
public:
	enum class name
	{
		B0,
		B1,
		B2,
		B3,
		B4,
		B5,
		B6,
		B7,
		B8,
		B9
	};

public:
	Bucket() = delete;
	Bucket(const Bucket::name name);
	Bucket(const Bucket&) = delete;
	Bucket& operator = (const Bucket&) = delete;

	// ------------------------------------------------
	// Do All work in the destructor
	// ------------------------------------------------
	~Bucket();

	void Add(Item* pItem);
	void Print();
	void PrintComplete();

	char *GetStringName(const Bucket* pBucket) const;
	char* GetStringName(const Item* pItem) const;

private:
	void privAddToFront(Item* pItem);

// ----------------------------------------------
// Data:
// ----------------------------------------------
public:
	Bucket    *pNext;
	Bucket    *pPrev;
	Item      *poHead;
	name      Name;
	BucketMan *pMan;
};

#endif

// --- End of File ---
