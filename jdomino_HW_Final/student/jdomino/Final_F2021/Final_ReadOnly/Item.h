//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef ITEM_H
#define ITEM_H

#include "Data.h"

// Forward Declaration
class Bucket;

class Item
{
public:
	enum class name
	{
		I0,
		I1,
		I2,
		I3,
		I4,
		I5,
		I6,
		I7,
		I8,
		I9
	};

public:
	Item() = delete;
	Item(const Item::name i_name, const Data::name d_name);
	Item(const Item &) = delete;
	Item & operator = (const Item &) = delete;

	// ------------------------------------------------
	// Do All work in the destructor
	// ------------------------------------------------
	~Item();

	void print();
	char* GetStringName(const Item * pItem) const;

	// ------------------------------------------------
	// NOTE:  CANNOT ADD DATA to Linked List class
	// ------------------------------------------------

public:
	Item   *pNext;
	Item   *pPrev;
	Data   *poData;
	name   Name;	
	Bucket *pBucket;
};

#endif

// --- End of File ---


