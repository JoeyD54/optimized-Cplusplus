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
    mBlockSize((uint16_t)BlockSize),
    pFreeNext(nullptr),
    pFreePrev(nullptr)
{

}

FreeHdr::FreeHdr(unsigned int BlockSize, bool AboveFreeFlag)
	: mAboveBlockFree(AboveFreeFlag),
	mType(Block::free),
	mBlockSize((uint16_t)BlockSize),
	pFreeNext(nullptr),
	pFreePrev(nullptr)
{

}


/**************************************************************************
* 
* Function: Append Free
* 
* Arguments: FreeHdr*
* 
* Use: This function will take in the current free location (nextFit)
*		and use it to store our new free within the free list
*				CURRENTLY APPENDS TO EOL, FIX IT
* 
* Return: NA
* 
**************************************************************************/

void FreeHdr::AppendFree(FreeHdr* pCurrFree)
{
	while (pCurrFree != nullptr)
	{
		//We are higher in the mem block, store above
		if (this < pCurrFree)
		{
			this->pFreePrev = pCurrFree->pFreePrev;
			this->pFreeNext = pCurrFree;

			if (pCurrFree->pFreePrev)
			{
				pCurrFree->pFreePrev->pFreeNext = this;
			}

			pCurrFree->pFreePrev = this;

			break;
		}
		pCurrFree = pCurrFree->pFreeNext;
	}
}


/**************************************************************************
*
* Function: FuseFree
*
* Arguments: FreeHdr*, FreeHdr*
*
* Use: This function will take two FreeHdr blocks and fuse their memory blocks
*		into one. This also removes the lower Free's header block
*
* Return: NA Store new fused item into "this"
*
**************************************************************************/

FreeHdr* FreeHdr::FuseFree(FreeHdr* pUpperFree, FreeHdr* pLowerFree)
{
	
	if (pLowerFree->pFreeNext == nullptr )
	{
		pLowerFree->pFreeNext = pUpperFree->pFreeNext;
	}
	if (pLowerFree->pFreeNext == pLowerFree)
	{
		pLowerFree->pFreeNext = nullptr;
	}
	if (pLowerFree->pFreePrev == nullptr)
	{
		pLowerFree->pFreePrev = pUpperFree->pFreePrev;
	}
	else if (pLowerFree->pFreePrev == pUpperFree)
	{
		pLowerFree->pFreePrev = nullptr;
	}

	FreeHdr* pFuseFree = new(pUpperFree)
		FreeHdr((unsigned int)pLowerFree->mBlockSize + (unsigned int)pUpperFree->mBlockSize + sizeof(FreeHdr));


	//First reset our pointers
	if (pLowerFree->pFreeNext && pLowerFree != pFuseFree)
	{
		pFuseFree->pFreeNext = pLowerFree->pFreeNext;
	}
	if (pLowerFree->pFreePrev && pLowerFree != pFuseFree)
	{
		pFuseFree->pFreePrev = pLowerFree->pFreePrev;
	}

	//Now reset the pointers of our pointers
	if (pLowerFree->pFreeNext && pLowerFree->pFreeNext != pFuseFree)
	{
		pFuseFree->pFreeNext->pFreePrev = pFuseFree;
	}
	else if(pLowerFree->pFreeNext == pFuseFree)
	{
		pFuseFree->pFreeNext->pFreePrev = nullptr;
	}
	if (pLowerFree->pFreePrev && pLowerFree->pFreePrev != pFuseFree)
	{
		pFuseFree->pFreePrev->pFreeNext = pFuseFree;
	}
	else if(pLowerFree->pFreePrev == pFuseFree)
	{
		pFuseFree->pFreeNext->pFreeNext = nullptr;
	}

	return pFuseFree;

	//Make another function to check upper/lower for frees?
}


// ---  End of File ---
