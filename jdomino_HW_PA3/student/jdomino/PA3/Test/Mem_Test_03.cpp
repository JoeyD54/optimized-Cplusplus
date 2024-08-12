//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "Mem.h"

//--------------------------------
//    DO NOT MODIFY this File
//--------------------------------

#define PTR_FIX(x)  (unsigned int)(x == 0) ? 0: ((unsigned int)x - (unsigned int)h) 

TEST(Mem3_Allocate_Everything_Free_it, TestConfig::ALL)
{
#if Mem3_Allocate_Everything_Free_it

	{
		FileIO::Open("Student_", "Test_03");

		fprintf(FileIO::GetHandle(), "Test3: \n\n");

		fprintf(FileIO::GetHandle(), " 1) allocate the biggest block             \n");
		fprintf(FileIO::GetHandle(), " 2) free it                                \n");
		fprintf(FileIO::GetHandle(), "                                           \n");
		fprintf(FileIO::GetHandle(), "     Mem mem(Mem::Guard::Type_A); \n");
		fprintf(FileIO::GetHandle(), "     mem.initialize();                     \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(1);                         \n");
		fprintf(FileIO::GetHandle(), "     void *p = mem.malloc( 0xc7d8 );       \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(2);                         \n");
		fprintf(FileIO::GetHandle(), "     mem.free( p );                        \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(3);                         \n");

		// Part A:
		Mem mem1(Mem::Guard::Type_A);
		mem1.initialize();
		mem1.Print(1);

		void *p1 = mem1.malloc(0xc7d8);
		mem1.Print(2);

		// Part B:
		mem1.free(p1);
		mem1.Print(3);

		FileIO::Close();
	}

	{
		// ----  GENERAL CHECK ------------------------------------------------------

		// ---- Part A: -------------------------------------------------------------

		Mem mem(Mem::Guard::Type_A);
		mem.initialize();
		void *p = mem.malloc(0xc7d8);

		// ---- Verify A: -----------------------------------------------------------

		Heap *h = mem.GetHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(h->pFreeHead, nullptr);
		CHECK_EQUAL(h->pNextFit, nullptr);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x1c);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->peakNumUsed, 1);
		CHECK_EQUAL(h->peakUsedMemory, 0xc7d8);

		CHECK_EQUAL(h->currNumUsedBlocks, 1);
		CHECK_EQUAL(h->currUsedMem, 0xc7d8);

		CHECK_EQUAL(h->currNumFreeBlocks, 0);
		CHECK_EQUAL(h->currFreeMem, 0x0);


		// ---- Heap Walk ------------------------------------------------------

		// ----  Block walk ------------------------------------------------------

		uint32_t hdrStart;
		uint32_t hdrEnd;
		uint32_t blkStart;
		uint32_t blkEnd;

		// ---- HDR -------------------------------------------

		// Check type
		UsedHdr *used = (UsedHdr *)(h + 1);
		// Should be USED
		CHECK_EQUAL(used->mType, Block::Used);
		// Above free?
		CHECK_EQUAL(used->mAboveBlockFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(UsedHdr);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x28);
		// Prev
		CHECK_EQUAL(used->pUsedPrev, nullptr);
		// Next
		CHECK_EQUAL(used->pUsedNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(UsedHdr));

		// ---- BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(p), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(used->mBlockSize, 0xc7d8);

		// ---- Part B: -------------------------------------------------------------

		mem.free(p);

		// ---- Verify B: -----------------------------------------------------------

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(h->pUsedHead, nullptr);
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x1c);
		CHECK_EQUAL(PTR_FIX(h->pNextFit), 0x1c);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->peakNumUsed, 1);
		CHECK_EQUAL(h->peakUsedMemory, 0xc7d8);

		CHECK_EQUAL(h->currNumUsedBlocks, 0);
		CHECK_EQUAL(h->currUsedMem, 0x0);

		CHECK_EQUAL(h->currNumFreeBlocks, 1);
		CHECK_EQUAL(h->currFreeMem, 0xc7d8);

		// ---- Heap Walk ------------------------------------------------------

		// ----  Block walk ------------------------------------------------------

		// ---- HDR -------------------------------------------

		// Check type
		FreeHdr *free = (FreeHdr *)(h + 1);
		// Should be USED
		CHECK_EQUAL(free->mType, Block::free);
		// Above free
		CHECK_EQUAL(free->mAboveBlockFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(FreeHdr);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1c);
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
		CHECK_EQUAL(used->mBlockSize, 0xc7d8);
	}
	{
		// ----  Checking Guards ----

		Mem mem(Mem::Guard::Type_5);
		CHECK(true);
		mem.initialize();
		CHECK(true);
		void *p = mem.malloc(0xc7d8);
		CHECK(true);
		mem.free(p);
		CHECK(true);
	}

#endif
}  TEST_END


// ---  End of File ---
