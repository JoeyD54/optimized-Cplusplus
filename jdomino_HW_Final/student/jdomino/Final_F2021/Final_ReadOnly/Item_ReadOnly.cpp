//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "Bucket.h"
#include "Item.h"
#include "Data.h"

struct ItemNameTable
{
	char *pString[9];
};

ItemNameTable itemTable[] =
{
	{"Item_0"},
	{"Item_1"},
	{"Item_2"},
	{"Item_3"},
	{"Item_4"},
	{"Item_5"},
	{"Item_6"},
	{"Item_7"},
	{"Item_8"},
	{"Item_9"}
};


Item::Item(const Item::name i_name, const Data::name d_name)
	:pNext(nullptr),
	pPrev(nullptr),
	poData{new Data(d_name)},
	Name(i_name),
	pBucket(nullptr)
{
}

void Item::print()
{
	Trace::out("    ---Item--- (%p): %s  \n", this, GetStringName(this));
	Trace::out("           next(%p): %s  \n", this->pNext, GetStringName(this->pNext));
	Trace::out("           prev(%p): %s  \n", this->pPrev, GetStringName(this->pPrev));
	Trace::out("           pData(%p): %s  \n", this->poData, this->poData->GetStringName(this->poData));
	Trace::out("\n");
	this->poData->print();

	Trace::out("\n");
}

char *Item::GetStringName(const Item *pItem) const
{
	static char *pNull = "null    ";
	char *pName;

	if(pItem == nullptr)
	{
		pName = pNull;
	}
	else
	{
		pName = *itemTable[(int) pItem->Name].pString;
	}

	return pName;
}

// --- End of File ---
