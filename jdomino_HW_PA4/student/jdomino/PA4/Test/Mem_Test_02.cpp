//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "Mem.h"

//--------------------------------
//    DO NOT MODIFY this File
//--------------------------------

#define PTR_FIX(x)  (unsigned int)(x == 0) ? 0: ((unsigned int)x - (unsigned int)h) 

TEST(Mem2_Allocate_Everything, TestConfig::ALL)
{
#if Mem2_Allocate_Everything

	FILE_MODIFIED_CHECK("..\\PA4\\Mem.cpp", ".\\PA4\\PA4\\Mem.cpp", 0x6b66b832);

	{
		FileIO::Open("Student_", "Test_02");

		fprintf(FileIO::GetHandle(), "Test2: \n\n");
		fprintf(FileIO::GetHandle(), "1) allocate the biggest block                \n");
		fprintf(FileIO::GetHandle(), "     Mem mem(Mem::Guard::Type_A);   \n");
		fprintf(FileIO::GetHandle(), "     mem.initialize();                       \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(1);                           \n");
		fprintf(FileIO::GetHandle(), "     void *p = mem.malloc( 0xc7D8 );         \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(2);                           \n");

		Mem mem(Mem::Guard::Type_A);
		mem.initialize();
		mem.Print(1);

		void *p;
		p = mem.malloc(0xc7d8);
		mem.Print(2);

		FileIO::Close();
	}

	{
		// ----  GENERAL CHECK ------------------------------------------------------
		Mem mem(Mem::Guard::Type_A);
		mem.initialize();
		void *p = mem.malloc(0xc7d8);

		Heap *h = mem.GetHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(h->pFreeHead, nullptr);
		CHECK_EQUAL(h->pNextFit, nullptr);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x1C);

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
		// Above free
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
	}
	{
		// ----  Checking Guards ----

		Mem mem(Mem::Guard::Type_5);
		CHECK(true);
		mem.initialize();
		CHECK(true);
		void *p;
		p = mem.malloc(0xc7d8);
		CHECK(true);
	}

#endif
}  TEST_END

// ---  End of File ---
