//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef FREE_H
#define FREE_H

#include "Block.h"

class UsedHdr;

class FreeHdr
{
public:

    FreeHdr(unsigned int BlockSize);

    // ---------------------------------------------------------
    // Do not reorder, change or add data fields
    //     --> any changes to the data... 0 given to the assignment
    // You can add methods if you wish
    // ---------------------------------------------------------

    bool     mAboveBlockFree;   // AboveBlock flag:
                                // if(AboveBlock is type free) -> true 
                                // if(AboveBlock is type used) -> false
    Block    mType;             // block type 
    uint16_t mBlockSize;        // size of block 4 bytes
    FreeHdr *pFreeNext;        // next free block 4 bytes
    FreeHdr *pFreePrev;        // prev free block 4 bytes

};

#endif 

// ---  End of File ---
