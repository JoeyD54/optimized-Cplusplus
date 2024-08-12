//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "FoodTruck.h"

FoodTruck::FoodTruck()
{
    this->poFirst = nullptr;
}

void FoodTruck::Add(Candy *const pNode)
{
    this->InventoryCount++;

    if(poFirst != nullptr)
    {
        pNode->pNext = this->poFirst;
    }
    this->poFirst = pNode;
}

void FoodTruck::Print()
{
    Trace::out("\tInventoryCount: %d\n", this->InventoryCount);
    Candy *pTmp = this->poFirst;
    while(pTmp != nullptr)
    {
        Trace::out("\t\t%s\n", pTmp->poType);
        pTmp = pTmp->pNext;
    }
}

// --- End of File ---
