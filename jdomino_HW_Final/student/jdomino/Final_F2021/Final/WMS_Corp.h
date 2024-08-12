//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef WYLIS_H
#define WYLIS_H

#include "Candy.h"

class WMS_Corp
{
public:
    WMS_Corp();
    WMS_Corp(const WMS_Corp&) = delete;
    WMS_Corp& operator = (const WMS_Corp&) = delete;
    virtual ~WMS_Corp() {};

    virtual void Print() = 0;
    virtual void Add(Candy * const pTmp) = 0;

    // ------------------------------------------
    // Data:  (do not add or modify the data)
    // ------------------------------------------
public:
    int InventoryCount;
};

#endif

// --- End of File ---
