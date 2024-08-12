//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Mem.h"
#include "Heap.h"
#include "Block.h"

//--------------------------------
//    DO NOT MODIFY this File
//--------------------------------

#define HEAP_ALIGNMENT			16
#define HEAP_ALIGNMENT_MASK		(HEAP_ALIGNMENT-1)

#define ALLOCATION_ALIGNMENT		16
#define ALLOCATION_ALIGNMENT_MASK	(ALLOCATION_ALIGNMENT-1)
#define HEAP_HEADER_GUARDS  64
#define HEAP_TOTAL_SIZE (50 * 1024)


#ifdef _DEBUG
	#define HEAP_SET_BOTTOM_A_GUARDS uint32_t *pF = (uint32_t *)((uint32_t)poRawMem + HEAP_TOTAL_SIZE); \
								*pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; \
								*pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; \
								*pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA;	\
								*pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA; *pF++ = 0xAAAAAAAA;

	#define HEAP_TEST_BOTTOM_A_GUARDS	uint32_t *pF = (uint32_t *)((uint32_t)poRawMem + HEAP_TOTAL_SIZE); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA); \
								assert(*pF++ == 0xAAAAAAAA); assert(*pF++ == 0xAAAAAAAA);

	#define HEAP_SET_BOTTOM_5_GUARDS uint32_t *pF = (uint32_t *)((uint32_t)poRawMem + HEAP_TOTAL_SIZE); \
								*pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555; \
								*pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555; \
								*pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555;	\
								*pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555; *pF++ = 0x55555555;

	#define HEAP_TEST_BOTTOM_5_GUARDS	uint32_t *pF = (uint32_t *)((uint32_t)poRawMem + HEAP_TOTAL_SIZE); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555); \
								assert(*pF++ == 0x55555555); assert(*pF++ == 0x55555555);

#else
	#define HEAP_SET_BOTTOM_A_GUARDS  	
	#define HEAP_TEST_BOTTOM_A_GUARDS	
	#define HEAP_SET_BOTTOM_5_GUARDS  	
	#define HEAP_TEST_BOTTOM_5_GUARDS
#endif
							
Mem::~Mem()
{
	// do not modify this function
	if (this->type == Guard::Type_A)
	{
		HEAP_TEST_BOTTOM_A_GUARDS
	}
	else
	{
		HEAP_TEST_BOTTOM_5_GUARDS
	}
	_aligned_free(this->poRawMem);
}

Heap *Mem::GetHeap()
{
	return this->poHeap;
}

Mem::Mem(Guard _type)
{
	// now initialize it.
	this->poHeap = nullptr;
	this->poRawMem = nullptr;
	this->type = _type;

	// Do a land grab --- get the space for the entire heap
	// Since OS have Different Alignments... I forced it to 16 byte aligned
	poRawMem = _aligned_malloc(HEAP_TOTAL_SIZE + HEAP_HEADER_GUARDS, HEAP_ALIGNMENT);

	// verify alloc worked
	assert(poRawMem != nullptr);
	
	if (this->type == Guard::Type_A)
	{
		HEAP_SET_BOTTOM_A_GUARDS
	}
	else
	{
		HEAP_SET_BOTTOM_5_GUARDS
	}

	// Guarantee alignemnt
	assert( ((uint32_t)poRawMem & HEAP_ALIGNMENT_MASK) == 0x0 ); 

	this->pTopAddr = (void *)((unsigned int)poRawMem + sizeof(Heap));
	this->pBottomAddr = (void *)((unsigned int)poRawMem + HEAP_TOTAL_SIZE);

	Heap *p = new(poRawMem) Heap();
	assert(p);

	// update it
	this->poHeap = p;

}

void Mem::Print(int count)
{

	fprintf(FileIO::GetHandle(),"\n------- Print %d -------------\n\n",count);

	fprintf(FileIO::GetHandle(), "heapStart: 0x%p     \n", this->poHeap );
	fprintf(FileIO::GetHandle(), "  heapEnd: 0x%p   \n\n", (void *)((uint32_t)this->poHeap+(uint32_t)HEAP_TOTAL_SIZE) );
	fprintf(FileIO::GetHandle(), "pUsedHead: 0x%p     \n", this->poHeap->pUsedHead );
	fprintf(FileIO::GetHandle(), "pFreeHead: 0x%p     \n", this->poHeap->pFreeHead );
	fprintf(FileIO::GetHandle(), " pNextFit: 0x%p   \n\n", this->poHeap->pNextFit);

	fprintf(FileIO::GetHandle(),"Heap Hdr   s: %p  e: %p                            size: 0x%x \n",(void *)this->poHeap, this->poHeap+1, sizeof(Heap) );

	uint32_t p = (uint32_t)(poHeap+1);

	char *blocktype;
	char *typeHdr;

	while( p < ((uint32_t)poHeap+(uint32_t)HEAP_TOTAL_SIZE) )
	{
		UsedHdr *used = (UsedHdr *)p;
		if( used->mType == Block::Used )
		{
			typeHdr = "USED HDR ";
			blocktype = "USED     ";
		}
		else
		{
			typeHdr = "FREE HDR ";
			blocktype    = "FREE     ";
		}

		uint32_t hdrStart = (uint32_t)used;
		uint32_t hdrEnd   = (uint32_t)used + sizeof(UsedHdr);
		fprintf(FileIO::GetHandle(),"%s  s: %p  e: %p  p: %p  n: %p  size: 0x%x    AF: %d \n",typeHdr, (void *)hdrStart, (void *)hdrEnd, used->pUsedPrev, used->pUsedNext, sizeof(UsedHdr), used->mAboveBlockFree );
	
		uint32_t blkStart = hdrEnd;
		uint32_t blkEnd   = blkStart + used->mBlockSize; 
		fprintf(FileIO::GetHandle(),"%s  s: %p  e: %p                            size: 0x%x \n",blocktype, (void *)blkStart, (void *)blkEnd, used->mBlockSize );

		p = blkEnd;
	}
}

// ---  End of File ---
