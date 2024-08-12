//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Mem.h"
#include "Heap.h"
#include "Block.h"

// To help with coalescing... not required
struct SecretPtr
{
	FreeHdr *pFree;
};

// ----------------------------------------------------
//  Initialized the Memory block:
//  Update the Heap
//  Create a free block
//  Heap structure links to free hdr
//-----------------------------------------------------
void Mem::initialize()
{
	// Add magic here

	//Get given heap
	Heap* pHeap = this->poHeap;

	//Create FreeHdr and init it

	//Get Free start of header by searching + 1 size of pHeap
	FreeHdr *pFreeStart = (FreeHdr *)(pHeap + 1);

	//Get Free end of header by searching + 1 size of pFreeStart
	FreeHdr* pFreeEnd = pFreeStart + 1;


	//Convert size of free memory block into int and store
	unsigned int BlockSize = (unsigned int) this->pBottomAddr - (unsigned int) pFreeEnd;

	//Set fresh Free memory in heap
	FreeHdr* pFree = new(pHeap + 1) FreeHdr(BlockSize);


	//Update Heap Header
	pHeap->SetFreeHead(pFree);
	pHeap->SetNextFit(pFree);
	pHeap->SetUsed(nullptr);

	pHeap->AddFreeBlock(pFree->mBlockSize);
}

// ----------------------------------------------------
//  Do your Magic here:
//  Find a free block that fits
//  Change it to used (may require subdivision)
//  Correct the heap Links (used,free) headers 
//  Update stats
//  Return pointer to block
//-----------------------------------------------------
void *Mem::malloc( const uint32_t _size )
{
	Heap* pHeap = this->poHeap;
	int* pUsedEnd;
	FreeHdr* tempCurrFree = this->poHeap->pNextFit;
	uint32_t blockEnd, blockStart, hdrStart, hdrEnd;


	/* This loop does the following (it's a lot)
	*	Search through the list of free slots
	*		Starting from "Next Fit"
	*	If the incomming block <= free block
	*		Clear out free and fix pointers
	*		Create a new used
	*		Add it to top of used DLL
	*	Else
	*		Mem does not equal size
	*		Remove current free (or change it to used with a new blocksize)
	*			Fix pointers when removing/moving
	*		Create used at old free's location
	*		Store used to start of used list
	*		Create new free of smaller size (or update pointers of shrunk free)
	*			The smaller size needs to include the size of used's header
	*		Set pointers of old free the pointers of new free
	*
	*	Return the new used's memory block (pUsed + 1)
	*/


	//Step through free list until a position is big enough to take size
	while (tempCurrFree != nullptr)
	{
		//Free block found
		/*if (_size <= (unsigned int) tempCurrFree + 1)
		{*/
			unsigned int BlockSize = (unsigned int) _size;
			
			unsigned int freeMinusBlock = tempCurrFree->mBlockSize - BlockSize;

			//If 0 when subbing JUST the size and not the header
			//It means we have a perfect match
			if (freeMinusBlock == 0)
			{
				UsedHdr* pUsed = new(tempCurrFree) UsedHdr(BlockSize);

				//This chunk gets the proper size of the memory block
				hdrStart = (uint32_t)pUsed;
				hdrEnd = (uint32_t)pUsed + sizeof(UsedHdr);
				blockStart = hdrEnd;
				blockEnd = blockStart + pUsed->mBlockSize;

				//Trace::out("New Used space size is %x\n", blockEnd - hdrStart);


				//May need to rework. Used will always be set to to top
				if (pHeap->pUsedHead == nullptr)
				{
					pHeap->SetUsed(pUsed);
					pHeap->AddUsedBlock(pUsed->mBlockSize);
				}

				//Clear out free (Same as how you've deleted before)
				if (tempCurrFree->pFreeNext == nullptr && tempCurrFree->pFreePrev == nullptr)
				{
					pHeap->SetFreeHead(nullptr);
					pHeap->SetNextFit(nullptr);

					pHeap->SubFreeBlock((uint16_t)BlockSize);
				}
				//Check for other edge cases later. 

				//Return the memory, not the header
				return pUsed + 1;
			}
			//Otherwise, We need to split free and place it below the new used.
			else if (freeMinusBlock > 0)
			{

				unsigned int currFreeBlockSize = tempCurrFree->mBlockSize;

				//the new used will overwrite all currentFree data. 
				//Update free before allocting used

				pHeap->SubFreeBlock((uint16_t) currFreeBlockSize);

				//Clear current free from heap if only free in list
				if (tempCurrFree->pFreeNext == nullptr && tempCurrFree->pFreePrev == nullptr)
				{
					pHeap->SetFreeHead(nullptr);
					pHeap->SetNextFit(nullptr);
				}

				UsedHdr* pUsed = new(tempCurrFree) UsedHdr(BlockSize);

				pHeap->SetUsed(pUsed);
				pHeap->AddUsedBlock(pUsed->mBlockSize);

				//This chunk gets the proper size of the memory block
				hdrStart = (uint32_t)pUsed;
				hdrEnd = (uint32_t)pUsed + sizeof(UsedHdr);
				blockStart = hdrEnd;
				blockEnd = blockStart + pUsed->mBlockSize;

				//Trace::out("New Used space size is %x\n", blockEnd - hdrStart);

				pUsedEnd = (int*)blockEnd;

				//Create a new free after the new used of size 
				FreeHdr* newFree = new(pUsedEnd) FreeHdr(currFreeBlockSize - (blockEnd - hdrStart));

				//If this is the only free
				if (tempCurrFree->pFreeNext == nullptr && tempCurrFree->pFreePrev == nullptr)
				{
					pHeap->SetFreeHead(newFree);
					pHeap->SetNextFit(newFree);

					pHeap->AddFreeBlock(newFree->mBlockSize);
				}

				//Return the memory, not the header
				return pUsed + 1;
			}
		//}
		tempCurrFree = tempCurrFree->pFreeNext;
	}
	return nullptr;
}

// ----------------------------------------------------
//  Do your Magic here:
//  Return the free block to the system
//  May require Coalescing
//  Correct the heap Links (used,free) headers 
//  Update stats
//-----------------------------------------------------
void Mem::free( void * const data )
{
	//Convert a used block to a free block

	//Get memory block beneath the header.
	Heap* pHeap = this->poHeap;
	UsedHdr* tempCurrUsed = this->poHeap->pUsedHead;
	uint32_t blockEnd, blockStart, hdrStart, hdrEnd;
	//int* pFreeEnd;

	//FreeHdr* pNextFitFree = pHeap->pNextFit;

	while(tempCurrUsed != nullptr)
	{
		//data is a pointer to a mem block. Check if we hit it
		//Using + 1 to find the memory block after the header
		if (tempCurrUsed + 1 == data)
		{
			//Clear out used before setting new free
			if (tempCurrUsed->pUsedPrev == nullptr && tempCurrUsed->pUsedNext == nullptr)
			{
				pHeap->SubUsedBlock(tempCurrUsed->mBlockSize);
				pHeap->SetUsed(nullptr);
			}
			//I'll handle other edge cases later


			//Free up found memory
			//You free it by storying used into free, overwritting the location
			//You'll need to handle pointers of the old used later
			FreeHdr* pNewFree = new(tempCurrUsed) FreeHdr(tempCurrUsed->mBlockSize);

			//This chunk gets the proper size of the memory block
			hdrStart = (uint32_t)pNewFree;
			hdrEnd = (uint32_t)pNewFree + sizeof(FreeHdr);
			blockStart = hdrEnd;
			blockEnd = blockStart + pNewFree->mBlockSize;

			//Trace::out("New Free space size is %x\n", blockEnd - hdrStart);

			//Now that free took over used, we need to look at the location beneath it
			//To see if it's a free. If so, update ITS "above free" bool

			//Need to check for other free's before setting the head
			//If this is the only free
			if (pHeap->pFreeHead == nullptr)
			{
				pHeap->SetFreeHead(pNewFree);
				pHeap->SetNextFit(pNewFree);
			}

			pHeap->AddFreeBlock(pNewFree->mBlockSize);

			//Point to next item in list, but check if there is extra space
			if (pHeap->currFreeMem != pNewFree->mBlockSize)
			{
				//Look at next in list (might not be a free)
				FreeHdr* pNextFree = (FreeHdr*) blockEnd;

				//Check if it is free
				if (pNextFree->mType == Block::free)
				{
					pNextFree->mAboveBlockFree = true;
				}

				if (pNextFree->mAboveBlockFree)
				{
					//We have two free's next to each other, FUSE THEM


					//Clear to be removed's pointers
					pNextFree->pFreeNext = nullptr;
					pNextFree->pFreePrev = nullptr;

					//Need to also reset the free's AROUND this one
					//I'll do that later

					hdrStart = (uint32_t)pNewFree;
					hdrEnd = (uint32_t)pNewFree + sizeof(FreeHdr);
					blockStart = hdrEnd;
					blockEnd = blockStart + pNextFree->mBlockSize;


					//Calculate storage of space after first free header to bottom of next free memory
					//Trace::out("New fused Free space size is %x\n", pNextFree->mBlockSize + pNewFree->mBlockSize) ;

					//FreeHdr* newFree = new(pUsedEnd) FreeHdr(currFreeBlockSize - (blockEnd - hdrStart));

					pHeap->SubFreeBlock(pNewFree->mBlockSize);
					pHeap->SubFreeBlock(pNextFree->mBlockSize);

					FreeHdr* pFuseFree = new(pNewFree) 
						FreeHdr((unsigned int) pNextFree->mBlockSize + (unsigned int) pNewFree->mBlockSize + sizeof(FreeHdr));

					//If either is the head, change head to fused
					if (pHeap->pFreeHead == pNewFree || pHeap->pFreeHead == pNextFree)
					{
						pHeap->SetFreeHead(pFuseFree);
						pHeap->SetNextFit(pFuseFree);
						pHeap->AddFreeBlock(pFuseFree->mBlockSize);
					}
					
				}

			}


			//Handle fusion of free's



			//Get out of loop
			break;
		}

		//Increment through list
		tempCurrUsed = tempCurrUsed->pUsedNext;
	}
} 
 

// ---  End of File ---
