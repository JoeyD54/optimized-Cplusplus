//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Free.h"
#include "Used.h"

// Add code here

UsedHdr::UsedHdr(unsigned int BlockSize)
    : mAboveBlockFree(false),
    mType(Block::Used),
    mBlockSize((uint16_t)BlockSize),
    pUsedNext(nullptr),
    pUsedPrev(nullptr)
{

}

// ---  End of File ---

