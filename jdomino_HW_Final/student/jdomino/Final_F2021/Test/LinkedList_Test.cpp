//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"

#include "BucketMan.h"
#include "Bucket.h"
#include "Item.h"
#include "Data.h"

TEST_WITH_TEARDOWN(LinkedList_Test_Enable, TestConfig::ALL)
{
#if LinkedList_Test_Enable

	// PLACE HOLDER - you don't get TESTS for your FINAL!
	CHECK(true);

	//BucketMan* pMan = new BucketMan();
	//Bucket* pB3 = new Bucket(Bucket::name::B3);
	//Bucket* pB2 = new Bucket(Bucket::name::B2);
	//Bucket* pB1 = new Bucket(Bucket::name::B1);
	//Bucket* pB0 = new Bucket(Bucket::name::B0);
	//pMan->Add(pB3);
	//pMan->Add(pB2);
	//pMan->Add(pB1);
	//pMan->Add(pB0);
	//Item* p0 = new Item(Item::name::I3, Data::name::A);
	//Item* p1 = new Item(Item::name::I2, Data::name::B);
	//Item* p2 = new Item(Item::name::I1, Data::name::C);
	//Item* p3 = new Item(Item::name::I0, Data::name::D);
	//pB0->Add(p0);
	//pB0->Add(p1);
	//pB0->Add(p2);
	//pB0->Add(p3);
	//Item* p4 = new Item(Item::name::I1, Data::name::E);
	//Item* p5 = new Item(Item::name::I3, Data::name::F);
	//Item* p6 = new Item(Item::name::I4, Data::name::G);
	//pB1->Add(p4);
	//pB1->Add(p5);
	//pB1->Add(p6);
	//Item* p7 = new Item(Item::name::I5, Data::name::H);
	//Item* p8 = new Item(Item::name::I2, Data::name::I);
	//Item* p9 = new Item(Item::name::I7, Data::name::J);
	//Item* p10 = new Item(Item::name::I3, Data::name::K);
	//Item* p11 = new Item(Item::name::I6, Data::name::L);
	//pB2->Add(p7);
	//pB2->Add(p8);
	//pB2->Add(p9);
	//pB2->Add(p10);
	//pB2->Add(p11);
	//Item* p12 = new Item(Item::name::I4, Data::name::M);
	//Item* p13 = new Item(Item::name::I7, Data::name::N);
	//Item* p14 = new Item(Item::name::I1, Data::name::O);
	//Item* p15 = new Item(Item::name::I3, Data::name::P);
	//Item* p16 = new Item(Item::name::I0, Data::name::Q);
	//pB3->Add(p12);
	//pB3->Add(p13);
	//pB3->Add(p14);
	//pB3->Add(p15);
	//pB3->Add(p16);

	////Delete some items
	//pB3->PrintComplete();
	//delete p14;
	//pB3->PrintComplete();
	//delete p15;
	//pB3->PrintComplete();

	////Delete somet buckets
	//delete pB2;

	//delete pB1;

	////Delete the bucket manager
	//pMan->poHead->PrintComplete();
	//delete pMan;

#endif
} TEST_END

TEST_TEARDOWN(LinkedList_Test_Enable)
{

}

// ---  End of File ---

