//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Mem.h"
#include "Heap.h"
#include "Block.h"

// To help with coalescing... not required
struct SecretPtr
{
	FreeHdr* pFree;
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

	uint32_t blkEnd, blkStart;

	//Get given heap
	Heap* pHeap = this->poHeap;

	//Create FreeHdr and init it

	//Get Free start of header by searching + 1 size of pHeap
	FreeHdr* pFreeStart = (FreeHdr*)(pHeap + 1);

	//Get Free end of header by searching + 1 size of pFreeStart
	FreeHdr* pFreeEnd = pFreeStart + 1;


	//Convert size of free memory block into int and store
	unsigned int BlockSize = (unsigned int)this->pBottomAddr - (unsigned int)pFreeEnd;

	//Set fresh Free memory in heap
	FreeHdr* pFree = new(pHeap + 1) FreeHdr(BlockSize);

	blkStart = (uint32_t)(pFree + 1);
	blkEnd = blkStart + BlockSize;


	SecretPtr* pSecret = (SecretPtr*)blkEnd;
	pSecret--;
	pSecret->pFree = pFree;

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
void* Mem::malloc(const uint32_t _size)
{
	//int* pUsedEnd;
	Heap* pHeap = this->poHeap;
	FreeHdr* tempCurrFree = pHeap->pNextFit;
	FreeHdr* oldFreeLoc;
	UsedHdr* tempUsedHead = pHeap->pUsedHead;
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
		//Lets Try a different implementation. Clean up the mess.

		unsigned int blockSize = (unsigned int)_size;

		//First we find a free block
		if (tempCurrFree->mBlockSize >= blockSize)
		{
			//Move free before setting used
			hdrStart = (uint32_t)tempCurrFree;
			hdrEnd = (uint32_t)tempCurrFree + sizeof(UsedHdr);
			blockStart = hdrEnd;
			blockEnd = blockStart + blockSize;

			//Move free's pointer below new used location
			oldFreeLoc = tempCurrFree;

			//We need to shrink free
			if (tempCurrFree->mBlockSize > blockSize)
			{
				//set temp to it's new location with an updated size
				tempCurrFree = new((FreeHdr*)blockEnd) FreeHdr(tempCurrFree->mBlockSize - (blockEnd - hdrStart));

				//Reset pointers

				//Reset prev/next pointers to point to new temp loc
				if (oldFreeLoc->pFreeNext != nullptr)
				{
					tempCurrFree->pFreeNext = oldFreeLoc->pFreeNext;
					oldFreeLoc->pFreeNext->pFreePrev = tempCurrFree;

					oldFreeLoc->pFreeNext = nullptr;
				}
				if (oldFreeLoc->pFreePrev != nullptr)
				{
					tempCurrFree->pFreePrev = oldFreeLoc->pFreePrev;
					oldFreeLoc->pFreePrev->pFreeNext = tempCurrFree;

					oldFreeLoc->pFreePrev = nullptr;
				}

				if (oldFreeLoc == pHeap->pFreeHead)
				{
					pHeap->SetFreeHead(tempCurrFree);
				}
				if (oldFreeLoc == pHeap->pNextFit)
				{
					pHeap->SetNextFit(tempCurrFree);
				}

				uint32_t blkFreeStart = (uint32_t)(tempCurrFree + 1);
				uint32_t blkFreeEnd = blkFreeStart + tempCurrFree->mBlockSize;

				//Reset secret free pointer
				SecretPtr* pFreeSecretPtr = (SecretPtr*)blkFreeEnd;
				pFreeSecretPtr--;
				pFreeSecretPtr->pFree = tempCurrFree;

				pHeap->SubFreeMem((uint16_t)blockSize + sizeof(UsedHdr));
			}
			//We're removing the block
			else
			{
				//Reset prev/next pointers to point to new temp loc
				if (oldFreeLoc->pFreeNext != nullptr)
				{
					oldFreeLoc->pFreeNext->pFreePrev = oldFreeLoc->pFreePrev;
					//oldFreeLoc->pFreeNext = nullptr;
				}
				if (oldFreeLoc->pFreePrev != nullptr)
				{
					oldFreeLoc->pFreePrev->pFreeNext = oldFreeLoc->pFreeNext;
					//oldFreeLoc->pFreePrev = nullptr;
				}

				//If this free is the head, we're removing the last free block
				if (oldFreeLoc == pHeap->pFreeHead)
				{
					pHeap->SetFreeHead(nullptr);
				}
				if (oldFreeLoc == pHeap->pNextFit)
				{
					pHeap->SetNextFit(nullptr);
				}

				if(blockEnd < (uint32_t) this->pBottomAddr)
				{
					UsedHdr* tempUsed = (UsedHdr*)blockEnd;

					tempUsed->mAboveBlockFree = false;
				}

				pHeap->SubFreeBlock((uint16_t)blockSize);
			}

			UsedHdr* pUsed = new(oldFreeLoc) UsedHdr(blockSize);

			//Every new used is the new head
			pHeap->SetUsed(pUsed);
			pHeap->AddUsedBlock(pUsed->mBlockSize);

			//Head is filled, point to next in list
			if (tempUsedHead != nullptr)
			{
				pUsed->pUsedNext = tempUsedHead;
				tempUsedHead->pUsedPrev = pUsed;
			}
			return pUsed + 1;
		}

		tempCurrFree = tempCurrFree->pFreeNext;

		//Reset to top of list
		if (tempCurrFree == nullptr && tempCurrFree != pHeap->pFreeHead)
		{
			tempCurrFree = pHeap->pFreeHead;
		}

		//We have done a full cycle
		if (tempCurrFree == pHeap->pNextFit)
		{
			break;
		}
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
void Mem::free(void* const data)
{
	//Convert a used block to a free block

	//Get memory block beneath the header.
	Heap* pHeap = this->poHeap;
	UsedHdr* tempCurrUsed = this->poHeap->pUsedHead;
	uint32_t blockEnd, blockStart, hdrStart, hdrEnd;
	//int* pFreeEnd;

	//FreeHdr* pNextFitFree = pHeap->pNextFit;

	while (tempCurrUsed != nullptr)
	{
		//data is a pointer to a mem block. Check if we hit it
		//Using + 1 to find the memory block after the header
		if (tempCurrUsed + 1 == data)
		{

			//Clear/reset pointers
			if (tempCurrUsed == pHeap->pUsedHead)
			{
				pHeap->SetUsed(tempCurrUsed->pUsedNext);
			}
			if (tempCurrUsed->pUsedNext)
			{
				tempCurrUsed->pUsedNext->pUsedPrev = tempCurrUsed->pUsedPrev;
			}
			if (tempCurrUsed->pUsedPrev)
			{
				tempCurrUsed->pUsedPrev->pUsedNext = tempCurrUsed->pUsedNext;
			}

			tempCurrUsed->pUsedNext = nullptr;
			tempCurrUsed->pUsedPrev = nullptr;

			pHeap->SubUsedBlock(tempCurrUsed->mBlockSize);

			
			FreeHdr* pNewFree = new(tempCurrUsed) FreeHdr(tempCurrUsed->mBlockSize, tempCurrUsed->mAboveBlockFree);


			//This chunk gets the proper size of the memory block
			hdrStart = (uint32_t)pNewFree;
			hdrEnd = (uint32_t)pNewFree + sizeof(FreeHdr);
			blockStart = hdrEnd;
			blockEnd = blockStart + pNewFree->mBlockSize;

			if (pHeap->pFreeHead == nullptr)
			{
				pHeap->SetFreeHead(pNewFree);
				pHeap->SetNextFit(pNewFree);
			}

			pHeap->AddFreeBlock(pNewFree->mBlockSize);

			SecretPtr* pFreeSecretPtr = (SecretPtr*)blockEnd;
			pFreeSecretPtr--;
			pFreeSecretPtr->pFree = pNewFree;

			FreeHdr* pNextFree = (FreeHdr*)blockEnd;

			if (pNextFree && pNextFree < this->pBottomAddr)
			{
				pNextFree->mAboveBlockFree = true;
			}

			//Point to next item in list, but check if there is extra space
			if (pHeap->currFreeMem != pNewFree->mBlockSize)
			{
				//Look at next in list (might not be a free)
				
				FreeHdr* pAboveFree = nullptr;

				if (pNewFree->mAboveBlockFree == true)
				{
					SecretPtr* pAboveSecretPtr = (SecretPtr*)pNewFree;
					pAboveSecretPtr--;

					if (pAboveSecretPtr->pFree)
					{
						pAboveFree = pAboveSecretPtr->pFree;
					}
					else
					{
						pAboveFree = nullptr;
					}
				}
			
				//Change this to while? We want to fuse every neighboring free
				if (pNextFree->mAboveBlockFree && pNextFree->mType == Block::free)
				{
					hdrStart = (uint32_t)pNewFree;
					hdrEnd = (uint32_t)pNewFree + sizeof(FreeHdr);
					blockStart = hdrEnd;
					blockEnd = blockStart + pNextFree->mBlockSize;

					pHeap->SubFreeBlock(pNewFree->mBlockSize);
					pHeap->SubFreeBlock(pNextFree->mBlockSize);


					FreeHdr* pFuseFree = pNewFree;
					pFuseFree = pFuseFree->FuseFree(pNewFree, pNextFree);
					

					//If either is the head, change head to fused
					if(pHeap->pFreeHead == pNewFree || pHeap->pFreeHead == pNextFree)
					{
						pHeap->SetFreeHead(pFuseFree);
					}
					
					if (pHeap->pNextFit == pNewFree || pHeap->pNextFit == pNextFree)
					{
						pHeap->SetNextFit(pFuseFree);
					}

					pHeap->AddFreeBlock(pFuseFree->mBlockSize);

					blockStart = (uint32_t)(pFuseFree + 1);
					blockEnd = blockStart + pFuseFree->mBlockSize;

					//Reset secret free pointer
					pFreeSecretPtr = (SecretPtr*)blockEnd;
					pFreeSecretPtr--;
					pFreeSecretPtr->pFree = pFuseFree;

					if (pHeap->pFreeHead != nullptr)
					{
						//Append to Free to correct location
						if (pHeap->pFreeHead != pNewFree)
						{
							FreeHdr* pFreeHead = pHeap->pFreeHead;

							//Try to store via Secret pointer FIRST
							if (pNextFree->mType == Block::free)
							{
								if (pNextFree->pFreeNext)
								{
									pFuseFree->pFreeNext = pNextFree->pFreeNext;
									pNextFree->pFreeNext->pFreePrev = pFuseFree;

									pNextFree->pFreeNext = nullptr;
								}
								if (pNextFree->pFreePrev)
								{
									pFuseFree->pFreePrev = pNextFree->pFreePrev;
									pNextFree->pFreePrev->pFreeNext = pFuseFree;

									pNextFree->pFreePrev = nullptr;
								}
							}
							//If those don't work, append via loop
							else
							{
								pFuseFree->AppendFree(pFreeHead);
							}

							if (pFuseFree < pFreeHead)
							{
								pHeap->SetFreeHead(pFuseFree);
							}
						}
						//We're the only free. Reset it
						else
						{
							pHeap->SetFreeHead(pFuseFree);
						}
					}
				}
				//Check for a free above us
				//Secret pointer set this. 
				//Fuse if not nullptr
				if (pAboveFree)
				{
					hdrStart = (uint32_t)pNewFree;
					hdrEnd = (uint32_t)pNewFree + sizeof(FreeHdr);
					blockStart = hdrEnd;
					blockEnd = blockStart + pAboveFree->mBlockSize;

					pHeap->SubFreeBlock(pNewFree->mBlockSize);
					pHeap->SubFreeBlock(pAboveFree->mBlockSize);

					//Assigned only to shut up compiler
					FreeHdr* pFuseFree = pNewFree;

					pFuseFree = pFuseFree->FuseFree(pAboveFree, pNewFree);

					//If either is the head, change head to fused
					if (pHeap->pFreeHead == pNewFree || pHeap->pFreeHead == pAboveFree)
					{
						pHeap->SetFreeHead(pFuseFree);
					}

					if (pHeap->pNextFit == pNewFree || pHeap->pNextFit == pAboveFree)
					{
						pHeap->SetNextFit(pFuseFree);
					}

					pHeap->AddFreeBlock(pFuseFree->mBlockSize);

					blockStart = (uint32_t)(pFuseFree + 1);
					blockEnd = blockStart + pFuseFree->mBlockSize;

					//Reset secret free pointer
					pFreeSecretPtr = (SecretPtr*)blockEnd;
					pFreeSecretPtr--;
					pFreeSecretPtr->pFree = pFuseFree;

					if (pHeap->pFreeHead != nullptr)
					{
						//Append to Free to correct location
						if (pHeap->pFreeHead != pAboveFree || pHeap->pFreeHead != pFuseFree)
						{
							FreeHdr* pFreeHead = pHeap->pFreeHead;

							//Check secret ptrs first
							if (pAboveFree->mType == Block::free)
							{
								if (pAboveFree->pFreeNext)
								{
									pFuseFree->pFreeNext = pAboveFree->pFreeNext;
									pAboveFree->pFreeNext->pFreePrev = pFuseFree;

									pAboveFree->pFreeNext = nullptr;
								}
								if (pAboveFree->pFreePrev)
								{
									pFuseFree->pFreePrev = pAboveFree->pFreePrev;
									pAboveFree->pFreePrev->pFreeNext = pFuseFree;

									pAboveFree->pFreePrev = nullptr;
								}
							}
							//If those dont work, use append
							else
							{
								pFuseFree->AppendFree(pFreeHead);
							}
				
							if (pFuseFree < pFreeHead)
							{
								pHeap->SetFreeHead(pFuseFree);
							}
						}
						//We're the only free. Reset it
						else
						{
							pHeap->SetFreeHead(pFuseFree);

							//Since we're the only free, remove any stragglers
							//Do so by checking if head is equal to the amount of free memory
							//That means no other free block SHOULD be in the list
							if (pHeap->pFreeHead->pFreeNext && pHeap->pFreeHead->mBlockSize == pHeap->currFreeMem)
							{
								pHeap->pFreeHead->pFreeNext = nullptr;
							}
						}
					}
				}
				//Appending JUST the newly freed block
				if(!pAboveFree && pNextFree->mType == Block::Used)
				{
					FreeHdr* pFreeHead = pHeap->pFreeHead;
					pNewFree->AppendFree(pFreeHead);

					if (pNewFree < pFreeHead)
					{
						pHeap->SetFreeHead(pNewFree);
					}
				}
			}
			break;
		}
		tempCurrUsed = tempCurrUsed->pUsedNext;
	}
}


// ---  End of File ---
