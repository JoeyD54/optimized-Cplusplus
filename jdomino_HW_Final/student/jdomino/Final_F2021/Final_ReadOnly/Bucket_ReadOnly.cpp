//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "BucketMan.h"
#include "Bucket.h"

struct BucketNameTable
{
	char* pString[9];
};

BucketNameTable bnt[] =
{
	{"Bucket_0"},
	{"Bucket_1"},
	{"Bucket_2"},
	{"Bucket_3"},
	{"Bucket_4"},
	{"Bucket_5"},
	{"Bucket_6"},
	{"Bucket_7"},
	{"Bucket_8"},
	{"Bucket_9"}
};

Bucket::Bucket(const Bucket::name name)
	:pNext(nullptr),
	pPrev(nullptr),
	poHead(nullptr),
	Name(name),
	pMan(nullptr)
{
}

void Bucket::PrintComplete()
{
	this->Print();
	Item* pItem = this->poHead;
	while (pItem)
	{
		pItem->print();
		pItem = pItem->pNext;
	}
}

void Bucket::Print()
{
	Trace::out("---Bucket--- (%p): %s  \n", this, GetStringName(this));
	Trace::out("         next(%p): %s  \n", this->pNext, GetStringName(this->pNext));
	Trace::out("         prev(%p): %s  \n", this->pPrev, GetStringName(this->pPrev));
	Trace::out("  <item list>(%p): %s  \n", this->poHead, GetStringName(this->poHead));
	Trace::out("\n");
}

char* Bucket::GetStringName(const Item* pItem) const
{
	static char* pNull = "null    ";
	char* pName;

	if (pItem == nullptr)
	{
		pName = pNull;
	}
	else
	{
		pName = pItem->GetStringName(pItem);
	}

	return pName;
}

char* Bucket::GetStringName(const Bucket* pBucket) const
{
	static char* pNull = "null    ";
	char* pName;

	if (pBucket == nullptr)
	{
		pName = pNull;
	}
	else
	{
		pName = *bnt[(int)pBucket->Name].pString;
	}

	return pName;
}

void Bucket::Add(Item* pItem)
{
	assert(pItem);
	privAddToFront(pItem);
	pItem->pBucket = this;
}

void Bucket::privAddToFront(Item* pItem)
{
	assert(pItem != nullptr);

	if (this->poHead == nullptr)
	{
		// first and only
		this->poHead = pItem;
		pItem->pNext = nullptr;
		pItem->pPrev = nullptr;
	}
	else
	{
		// existing node... shove the new one in front
		this->poHead->pPrev = pItem;
		pItem->pNext = this->poHead;
		pItem->pPrev = nullptr;
		this->poHead = pItem;
	}
}

// --- End of File ---
