//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Heap.h"
#include "Mem.h"

Heap::Heap()
    : pUsedHead(nullptr),
    pFreeHead(nullptr),
    pNextFit(nullptr)
{
    peakNumUsed = 0;        // number of peak used allocations
    peakUsedMemory = 0;    // peak size of used memory

    currNumUsedBlocks = 0;  // number of current used allocations
    currUsedMem = 0;        // current size of the total used memory

    currNumFreeBlocks = 0;  // number of current free blocks
    currFreeMem = 0;        // current size of the total free memory

    pad0 = 0;                // pad

}

void Heap::SetFreeHead(FreeHdr* pFree)
{
    this->pFreeHead = pFree;
}



void Heap::SetNextFit(FreeHdr* pFree)
{
    this->pNextFit = pFree;
}



void Heap::SetUsed(UsedHdr* pUsed)
{
    this->pUsedHead = pUsed;
}


void Heap::AddFreeBlock(uint16_t BlockSize)
{
    //Add new block of free memory
    this->PrivAddFreeBlockCount();
    this->PrivAddFreeBlockSize(BlockSize);
}


void Heap::PrivAddFreeBlockCount()
{
    //Increase count
    this->currNumFreeBlocks++;
}


void Heap::PrivAddFreeBlockSize(uint16_t BlockSize)
{
    //Store current amount of free memory
    this->currFreeMem += BlockSize;
}


void Heap::AddUsedBlock(uint16_t BlockSize)
{
    //Add new block of used memory
    this->PrivAddUsedBlockCount();
    this->PrivAddUsedBlockSize(BlockSize);
}


void Heap::SubFreeBlock(uint16_t BlockSize)
{
    this->PrivSubFreeBlockCount();
    this->PrivSubFreeBlockSize(BlockSize);
}

void Heap::SubFreeMem(uint16_t BlockSize)
{
    this->PrivSubFreeBlockSize(BlockSize);
}


void Heap::SubUsedBlock(uint16_t BlockSize)
{
    this->PrivSubUsedBlcokCount();
    this->PrivSubUsedBlockSize(BlockSize);
}


void Heap::PrivAddUsedBlockCount()
{
    //Increase count
    this->currNumUsedBlocks++;

    //set new peak if curr is larger
    if (this->currNumUsedBlocks > this->peakNumUsed)
    {
        this->peakNumUsed = this->currNumUsedBlocks;
    }
}


void Heap::PrivAddUsedBlockSize(uint16_t BlockSize)
{
    //Store current amount of free memory
    this->currUsedMem += BlockSize;

    //Set new peak if needed
    if (this->currUsedMem > this->peakUsedMemory)
    {
        this->peakUsedMemory = this->currUsedMem;
    }
}


void Heap::PrivSubFreeBlockCount()
{
    this->currNumFreeBlocks--;
}


void Heap::PrivSubUsedBlcokCount()
{
    this->currNumUsedBlocks--;
}


void Heap::PrivSubFreeBlockSize(uint16_t BlockSize)
{
    this->currFreeMem -= BlockSize;
}


void Heap::PrivSubUsedBlockSize(uint16_t BlockSize)
{
    this->currUsedMem -= BlockSize;
}

// ---  End of File ---
