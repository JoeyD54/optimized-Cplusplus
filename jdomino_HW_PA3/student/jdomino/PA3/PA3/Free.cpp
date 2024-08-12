//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Used.h"
#include "Free.h"
#include "Block.h"

// Add magic here

FreeHdr::FreeHdr(unsigned int BlockSize)
    : mAboveBlockFree(false),
    mType(Block::free),
    mBlockSize((uint16_t) BlockSize),
    pFreeNext(nullptr),
    pFreePrev(nullptr)
{

}


// ---  End of File ---
