//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef CANDY_H
#define CANDY_H

class Candy
{
public:
    Candy() = delete;
    Candy(const Candy&) = delete;
    Candy& operator = (const Candy&) = delete;
   ~Candy();

    Candy(const char* const type);

    // ------------------------------------------
    // Data:  (do not add or modify the data)
    // ------------------------------------------

public:
    Candy *pNext;
    char  *poType;
};

#endif

// --- End of File ---
