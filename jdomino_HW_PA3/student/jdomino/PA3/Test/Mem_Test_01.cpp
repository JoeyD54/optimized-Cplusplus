//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "Mem.h"

//--------------------------------
//    DO NOT MODIFY this File
//--------------------------------

#define PTR_FIX(x)  (unsigned int)(x == 0) ? 0 : ((unsigned int)x - (unsigned int)h) 


TEST(Mem1_Initialize, TestConfig::ALL)
{
#if Mem1_Initialize

	{
		FileIO::Open("Student_", "Test_01");

		fprintf(FileIO::GetHandle(), "Test 1: \n\n");
		fprintf(FileIO::GetHandle(), "     Mem mem(Mem::Guard::Type_A);  \n");
		fprintf(FileIO::GetHandle(), "     mem.initialize();                      \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(1);                          \n");

		Mem mem(Mem::Guard::Type_A);
		mem.initialize();
		mem.Print(1);

		FileIO::Close();
	}

	{
		// ----  GENERAL CHECK ------------------------------------------------------
		Mem mem(Mem::Guard::Type_A);
		mem.initialize();
		Heap *h = mem.GetHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(h->pUsedHead, nullptr);
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x1C);
		CHECK_EQUAL(PTR_FIX(h->pNextFit), 0x1C);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->peakNumUsed, 0);
		CHECK_EQUAL(h->peakUsedMemory, 0);

		CHECK_EQUAL(h->currNumUsedBlocks, 0);
		CHECK_EQUAL(h->currUsedMem, 0);

		CHECK_EQUAL(h->currNumFreeBlocks, 1);
		CHECK_EQUAL(h->currFreeMem, 0xc7d8);

		// ---- Heap Walk ------------------------------------------------------

		// ----  Block walk ------------------------------------------------------

		uint32_t hdrStart;
		uint32_t hdrEnd;
		uint32_t blkStart;
		uint32_t blkEnd;

		// ---- HDR -------------------------------------------

		// Check type
		FreeHdr *free = (FreeHdr *)(h + 1);
		// Should be FREE
		CHECK_EQUAL(free->mType, Block::free);
		// Above free
		CHECK_EQUAL(free->mAboveBlockFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(FreeHdr);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1C);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x28);
		// Prev
		CHECK_EQUAL(free->pFreePrev, nullptr);
		// Next
		CHECK_EQUAL(free->pFreeNext, nullptr);

		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(FreeHdr));

		// ---- BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mBlockSize, 0xc7d8);
	}

	{
		// ----  Checking Guards ----

		Mem mem(Mem::Guard::Type_5);
		CHECK(true);
		mem.initialize();
		CHECK(true);
	}

#endif
} TEST_END


// ---  End of File ---
