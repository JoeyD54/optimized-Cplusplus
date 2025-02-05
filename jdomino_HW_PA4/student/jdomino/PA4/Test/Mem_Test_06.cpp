//----------------------------------------------------------------------------
// Copyright 2010, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "Mem.h"

//--------------------------------
//    DO NOT MODIFY this File
//--------------------------------

#define PTR_FIX(x)  (unsigned int)(x == 0) ? 0: ((unsigned int)x - (unsigned int)h) 

TEST(Mem6_Allocate_3_bottom_up_free, TestConfig::ALL)
{
#if Mem6_Allocate_3_bottom_up_free	

	FILE_MODIFIED_CHECK("..\\PA4\\Mem.cpp", ".\\PA4\\PA4\\Mem.cpp", 0x6b66b832);

	{
		FileIO::Open("Student_", "Test_06");

		fprintf(FileIO::GetHandle(), "Test6: \n\n");

		fprintf(FileIO::GetHandle(), " 1) used                  \n");
		fprintf(FileIO::GetHandle(), " 2) used                  \n");
		fprintf(FileIO::GetHandle(), " 3) used                  \n");
		fprintf(FileIO::GetHandle(), " 4) bottom up free        \n\n");
		fprintf(FileIO::GetHandle(), "     Mem mem(Mem::Guard::Type_A); \n");
		fprintf(FileIO::GetHandle(), "     mem.initialize();                     \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(1);                         \n");
		fprintf(FileIO::GetHandle(), "     void *a = mem.malloc( 0x200 );        \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(2);                         \n");
		fprintf(FileIO::GetHandle(), "     void *b = mem.malloc( 0x200 );        \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(3);                         \n");
		fprintf(FileIO::GetHandle(), "     void *c = mem.malloc( 0x200 );        \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(4);                         \n");
		fprintf(FileIO::GetHandle(), "     mem.free( c );                        \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(5);                         \n");
		fprintf(FileIO::GetHandle(), "     mem.free( b );                        \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(6);                         \n");
		fprintf(FileIO::GetHandle(), "     mem.free( a );                        \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(7);                         \n");

		// Part A:
		Mem mem1(Mem::Guard::Type_A);
		mem1.initialize();
		mem1.Print(1);

		void *a1 = mem1.malloc(0x200);
		mem1.Print(2);

		void *b1 = mem1.malloc(0x200);
		mem1.Print(3);

		void *c1 = mem1.malloc(0x200);
		mem1.Print(4);

		// Part B:
		mem1.free(c1);
		mem1.Print(5);

		// Part C:
		mem1.free(b1);
		mem1.Print(6);

		// Part D:
		mem1.free(a1);
		mem1.Print(7);

		FileIO::Close();
	}

	{
		// ----  GENERAL CHECK ------------------------------------------------------

		// ---- Part A: -------------------------------------------------------------

		Mem mem(Mem::Guard::Type_A);
		mem.initialize();

		void *a = mem.malloc(0x200);
		void *b = mem.malloc(0x200);
		void *c = mem.malloc(0x200);


		// ---- Verify A: -----------------------------------------------------------

		Heap *h = mem.GetHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x640);
		CHECK_EQUAL(PTR_FIX(h->pNextFit), 0x640);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x434);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->peakNumUsed, 3);
		CHECK_EQUAL(h->peakUsedMemory, 3 * 0x200);

		CHECK_EQUAL(h->currNumUsedBlocks, 3);
		CHECK_EQUAL(h->currUsedMem, 3 * 0x200);

		CHECK_EQUAL(h->currNumFreeBlocks, 1);
		CHECK_EQUAL(h->currFreeMem, 0xc1b4);

		// ---- Heap Walk ------------------------------------------------------

		// ----  Block walk ------------------------------------------------------

		uint32_t hdrStart;
		uint32_t hdrEnd;
		uint32_t blkStart;
		uint32_t blkEnd;

		// ---- USED HDR 1 -------------------------------------------

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
		CHECK_EQUAL(PTR_FIX(used->pUsedPrev), 0x228);
		// Next
		CHECK_EQUAL(used->pUsedNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(UsedHdr));

		// ---- USED BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(a), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x228);
		CHECK_EQUAL(used->mBlockSize, 0x200);

		// ---- Used HDR 2 -------------------------------------------

		// Check type
		used = (UsedHdr *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Block::Used);

		// Above free
		CHECK_EQUAL(used->mAboveBlockFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(UsedHdr);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x228);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x234);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pUsedPrev), 0x434);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pUsedNext), 0x1c);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(UsedHdr));

		// ---- used BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(b), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x434);
		CHECK_EQUAL(used->mBlockSize, 0x200);

		// ---- Used HDR 3 -------------------------------------------

		// Check type
		used = (UsedHdr *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Block::Used);

		// Above free
		CHECK_EQUAL(used->mAboveBlockFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(UsedHdr);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x434);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x440);
		// Prev
		CHECK_EQUAL(used->pUsedPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pUsedNext), 0x228);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(UsedHdr));

		// ---- used BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(c), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x640);
		CHECK_EQUAL(used->mBlockSize, 0x200);


		// ---- free HDR 4 -------------------------------------------

		// Check type
		FreeHdr *free = (FreeHdr *)blkEnd;
		// Should be USED
		CHECK_EQUAL(free->mType, Block::free);

		// Above free
		CHECK_EQUAL(free->mAboveBlockFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(FreeHdr);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x640);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x64c);
		// Prev
		CHECK_EQUAL(free->pFreePrev, nullptr);
		// Next
		CHECK_EQUAL(free->pFreeNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(FreeHdr));

		// ---- free BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mBlockSize, 0xc1b4);

		// ---- Part B: -------------------------------------------------------------

		mem.free(c);

		// ---- Verify B: -----------------------------------------------------------

		h = mem.GetHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x434);
		CHECK_EQUAL(PTR_FIX(h->pNextFit), 0x434);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x228);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->peakNumUsed, 3);
		CHECK_EQUAL(h->peakUsedMemory, 3 * 0x200);

		CHECK_EQUAL(h->currNumUsedBlocks, 2);
		CHECK_EQUAL(h->currUsedMem, 2 * 0x200);

		CHECK_EQUAL(h->currNumFreeBlocks, 1);
		CHECK_EQUAL(h->currFreeMem, 0xc3c0);

		// ---- Heap Walk ------------------------------------------------------

		// ----  Block walk ------------------------------------------------------

		// ---- USED HDR 1 -------------------------------------------

		// Check type
		used = (UsedHdr *)(h + 1);
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
		CHECK_EQUAL(PTR_FIX(used->pUsedPrev), 0x228);
		// Next
		CHECK_EQUAL(used->pUsedNext, 0x0);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(UsedHdr));

		// ---- USED BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(a), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x228);
		CHECK_EQUAL(used->mBlockSize, 0x200);

		// ---- Used HDR 2 -------------------------------------------

		// Check type
		used = (UsedHdr *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Block::Used);

		// Above free
		CHECK_EQUAL(used->mAboveBlockFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(UsedHdr);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x228);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x234);
		// Prev
		CHECK_EQUAL(used->pUsedPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pUsedNext), 0x1c);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(UsedHdr));

		// ---- used BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(b), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x434);
		CHECK_EQUAL(used->mBlockSize, 0x200);

		// ---- Used free 3 -------------------------------------------

		// Check type
		free = (FreeHdr *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Block::free);

		// Above free
		CHECK_EQUAL(free->mAboveBlockFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(UsedHdr);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x434);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x440);
		// Prev
		CHECK_EQUAL(free->pFreePrev, nullptr);
		// Next
		CHECK_EQUAL(free->pFreeNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(FreeHdr));

		// ---- used BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mBlockSize, 0xc3c0);

		// ---- Part C: -------------------------------------------------------------

		mem.free(b);

		// ---- Verify C: -----------------------------------------------------------

		h = mem.GetHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x228);
		CHECK_EQUAL(PTR_FIX(h->pNextFit), 0x228);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x1c);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->peakNumUsed, 3);
		CHECK_EQUAL(h->peakUsedMemory, 3 * 0x200);

		CHECK_EQUAL(h->currNumUsedBlocks, 1);
		CHECK_EQUAL(h->currUsedMem, 0x200);

		CHECK_EQUAL(h->currNumFreeBlocks, 1);
		CHECK_EQUAL(h->currFreeMem, 0xc5cc);

		// ---- Heap Walk ------------------------------------------------------

		// ----  Block walk ------------------------------------------------------


		// ---- used HDR 1 -------------------------------------------

		// Check type
		used = (UsedHdr *)(h + 1);
		// Should be free
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

		// ---- used BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(a), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x228);
		CHECK_EQUAL(used->mBlockSize, 0x200);

		// ---- free hdr 2 -------------------------------------------

		// Check type
		free = (FreeHdr *)blkEnd;
		// Should be free
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

		// ---- used BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mBlockSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mBlockSize, 0xc5cc);


		// ---- Part D: -------------------------------------------------------------

		mem.free(a);

		// ---- Verify D: -----------------------------------------------------------

		h = mem.GetHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x1c);
		CHECK_EQUAL(PTR_FIX(h->pNextFit), 0x1c);
		CHECK_EQUAL(h->pUsedHead, nullptr);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->peakNumUsed, 3);
		CHECK_EQUAL(h->peakUsedMemory, 0x600);

		CHECK_EQUAL(h->currNumUsedBlocks, 0);
		CHECK_EQUAL(h->currUsedMem, 0x0);

		CHECK_EQUAL(h->currNumFreeBlocks, 1);
		CHECK_EQUAL(h->currFreeMem, 0xc7d8);

		// ---- Heap Walk ------------------------------------------------------

		// ----  Block walk ------------------------------------------------------

		// ---- FREE HDR 1 -------------------------------------------

		// Check type
		free = (FreeHdr *)(h + 1);
		// Should be free
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

		// ---- free BLOCK ----------------------------------------------------

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
		void *a = mem.malloc(0x200);
		CHECK(true);
		void *b = mem.malloc(0x200);
		CHECK(true);
		void *c = mem.malloc(0x200);
		CHECK(true);
		mem.free(c);
		CHECK(true);
		mem.free(b);
		CHECK(true);
		mem.free(a);
		CHECK(true);
	}

#endif
}  TEST_END

// ---  End of File ---
