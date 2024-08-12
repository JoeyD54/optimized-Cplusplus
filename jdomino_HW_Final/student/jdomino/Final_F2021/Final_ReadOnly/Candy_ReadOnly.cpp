//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "Candy.h"

Candy::Candy(const char *const name)
{
    unsigned int size = strlen(name) + 1;
    this->poType = new char[size];
    strcpy_s(this->poType, size, name);
    this->pNext = nullptr;
}


// --- End of File ---
