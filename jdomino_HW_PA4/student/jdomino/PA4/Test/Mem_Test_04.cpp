//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "Mem.h"

//--------------------------------
//    DO NOT MODIFY this File
//--------------------------------

#define PTR_FIX(x)  (unsigned int)(x == 0) ? 0: ((unsigned int)x - (unsigned int)h) 

TEST(Mem4_Partial_allocate, TestConfig::ALL)
{
#if Mem4_Partial_allocate

	FILE_MODIFIED_CHECK("..\\PA4\\Mem.cpp", ".\\PA4\\PA4\\Mem.cpp", 0x6b66b832);

	{
		FileIO::Open("Student_", "Test_04");

		fprintf(FileIO::GetHandle(), "Test4: \n\n");

		fprintf(FileIO::GetHandle(), " 1) allocate regular size block            \n");
		fprintf(FileIO::GetHandle(), "     Mem mem(Mem::Guard::Type_A); \n");
		fprintf(FileIO::GetHandle(), "     mem.initialize();                     \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(1);                         \n");
		fprintf(FileIO::GetHandle(), "     void *p = mem.malloc( 200 );          \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(2);                         \n");

		Mem mem1(Mem::Guard::Type_A);
		mem1.initialize();
		mem1.Print(1);

		void *p1 = mem1.malloc(0x200);
		mem1.Print(2);

		// Shut up warnings
		AZUL_UNUSED_VAR(p1);

		FileIO::Close();
	}

	{
		// ----  GENERAL CHECK ------------------------------------------------------

		// ---- Part A: -------------------------------------------------------------

		Mem mem(Mem::Guard::Type_A);
		mem.initialize();
		void *p = mem.malloc(0x200);

		// ---- Verify A: -----------------------------------------------------------

		Heap *h = mem.GetHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x228);
		CHECK_EQUAL(PTR_FIX(h->pNextFit), 0x228);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x1c);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->peakNumUsed, 1);
		CHECK_EQUAL(h->peakUsedMemory, 0x200);

		CHECK_EQUAL(h->currNumUsedBlocks, 1);
		CHECK_EQUAL(h->currUsedMem, 0x200);

		CHECK_EQUAL(h->currNumFreeBlocks, 1);
		CHECK_EQUAL(h->currFreeMem, 0xc5cc);

		// ---- Heap Walk ------------------------------------------------------

		// ----  Block walk ------------------------------------------------------

		uint32_t hdrStart;
		uint32_t hdrEnd;
		uint32_t blkStart;
		uint32_t blkEnd;

		// ---- USED HDR -------------------------------------------

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

		// ---- USED BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x228);
		CHECK_EQUAL(PTR_FIX(p), PTR_FIX(hdrEnd));
		CHECK_EQUAL(used->mBlockSize, 0x200);

		// ---- FREE HDR -------------------------------------------

		// Check type
		FreeHdr *free = (FreeHdr *)blkEnd;
		// Should be USED
		CHECK_EQUAL(free->mType, Block::free);
		// Above free
		CHECK_EQUAL(free->mAboveBlockFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(FreeHdr);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x228);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x234);
		// Prev
		CHECK_EQUAL(free->pFreePrev, nullptr);
		// Next
		CHECK_EQUAL(free->pFreeNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(FreeHdr));

		// ---- FREE BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mBlockSize, 0xc5cc);
	}
	{
		// ----  Checking Guards ----

		Mem mem(Mem::Guard::Type_5);
		CHECK(true);
		mem.initialize();
		CHECK(true);
		void *p;
		p = mem.malloc(0x200);
		CHECK(true);

	}

#endif
}  TEST_END


// ---  End of File ---
