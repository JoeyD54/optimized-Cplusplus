//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef HODOR_H
#define HODOR_H

#include "WMS_Corp.h"

class FoodTruck : public WMS_Corp
{
public:
    FoodTruck();
    FoodTruck(const FoodTruck &) = delete;
    FoodTruck& operator = (const FoodTruck&) = delete;
   ~FoodTruck();

    virtual void Add(Candy* const pNode);
    virtual void Print();

    // ------------------------------------------
    // Data:  (do not add or modify the data)
    // ------------------------------------------
public:
    Candy* poFirst;
};

#endif

// --- End of File ---
