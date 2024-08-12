

#include "_UnitTestConfiguration.h"
#include "Boustrophedonic.h"
#include "Tree.h"


TEST_WITH_TEARDOWN(DeleteExtra10_Test_Enable, TestConfig::ALL)
{
#if DeleteExtra10_Test_Enable


	Node* pN00 = new Node(), * pN01 = new Node(), * pN02 = new Node(), * pN03 = new Node();
	Node* pN10 = new Node(), * pN11 = new Node(), * pN12 = new Node(), * pN13 = new Node();
	Node* pN20 = new Node(), * pN21 = new Node(), * pN22 = new Node(), * pN23 = new Node();


	// Set standard path
	pN00->pEast = pN01;
	pN01->pEast = pN02;
	pN02->pEast = pN03;

	pN03->pSouth = pN13;

	pN13->pWest = pN12;
	pN12->pWest = pN11;
	pN11->pWest = pN10;

	pN10->pSouth = pN20;

	pN20->pEast = pN21;
	pN21->pEast = pN22;
	pN22->pEast = pN23;

	// Set Ups and downs

	pN10->pNorth = pN00;
	pN12->pNorth = pN02;
	pN21->pNorth = pN11;
	pN23->pNorth = pN13;

	pN01->pSouth = pN11;
	pN12->pSouth = pN22;


	// Make sure we have a good initial tree

	//-----------------------------------
	CHECK_EQUAL(pN00->pNorth, nullptr);
	CHECK_EQUAL(pN00->pSouth, nullptr);
	CHECK_EQUAL(pN00->pEast, pN01);
	CHECK_EQUAL(pN00->pWest, nullptr);

	CHECK_EQUAL(pN01->pNorth, nullptr);
	CHECK_EQUAL(pN01->pSouth, pN11);
	CHECK_EQUAL(pN01->pEast, pN02);
	CHECK_EQUAL(pN01->pWest, nullptr);

	CHECK_EQUAL(pN02->pNorth, nullptr);
	CHECK_EQUAL(pN02->pSouth, nullptr);
	CHECK_EQUAL(pN02->pEast, pN03);
	CHECK_EQUAL(pN02->pWest, nullptr);

	CHECK_EQUAL(pN03->pNorth, nullptr);
	CHECK_EQUAL(pN03->pSouth, pN13);
	CHECK_EQUAL(pN03->pEast, nullptr);
	CHECK_EQUAL(pN03->pWest, nullptr);

	//---------------------------------

	CHECK_EQUAL(pN10->pNorth, pN00);
	CHECK_EQUAL(pN10->pSouth, pN20);
	CHECK_EQUAL(pN10->pEast, nullptr);
	CHECK_EQUAL(pN10->pWest, nullptr);

	CHECK_EQUAL(pN11->pNorth, nullptr);
	CHECK_EQUAL(pN11->pSouth, nullptr);
	CHECK_EQUAL(pN11->pEast, nullptr);
	CHECK_EQUAL(pN11->pWest, pN10);

	CHECK_EQUAL(pN12->pNorth, pN02);
	CHECK_EQUAL(pN12->pSouth, pN22);
	CHECK_EQUAL(pN12->pEast, nullptr);
	CHECK_EQUAL(pN12->pWest, pN11);

	CHECK_EQUAL(pN13->pNorth, nullptr);
	CHECK_EQUAL(pN13->pSouth, nullptr);
	CHECK_EQUAL(pN13->pEast, nullptr);
	CHECK_EQUAL(pN13->pWest, pN12);

	//---------------------------------

	CHECK_EQUAL(pN20->pNorth, nullptr);
	CHECK_EQUAL(pN20->pSouth, nullptr);
	CHECK_EQUAL(pN20->pEast, pN21);
	CHECK_EQUAL(pN20->pWest, nullptr);

	CHECK_EQUAL(pN21->pNorth, pN11);
	CHECK_EQUAL(pN21->pSouth, nullptr);
	CHECK_EQUAL(pN21->pEast, pN22);
	CHECK_EQUAL(pN21->pWest, nullptr);

	CHECK_EQUAL(pN22->pNorth, nullptr);
	CHECK_EQUAL(pN22->pSouth, nullptr);
	CHECK_EQUAL(pN22->pEast, pN23);
	CHECK_EQUAL(pN22->pWest, nullptr);

	CHECK_EQUAL(pN23->pNorth, pN13);
	CHECK_EQUAL(pN23->pSouth, nullptr);
	CHECK_EQUAL(pN23->pEast, nullptr);
	CHECK_EQUAL(pN23->pWest, nullptr);

	//---------------------------------

	//---- TEST below here --------------------

	Trace::out("remove:---> (1,0) \n");
	Remove(pN00, 1, 0);

	// ------- CHECK LIST ---------------------

		//-----------------------------------
	CHECK_EQUAL(pN00->pNorth, nullptr);
	CHECK_EQUAL(pN00->pSouth, nullptr);
	CHECK_EQUAL(pN00->pEast, pN01);
	CHECK_EQUAL(pN00->pWest, nullptr);

	CHECK_EQUAL(pN01->pNorth, nullptr);
	CHECK_EQUAL(pN01->pSouth, pN11);
	CHECK_EQUAL(pN01->pEast, pN02);
	CHECK_EQUAL(pN01->pWest, nullptr);

	CHECK_EQUAL(pN02->pNorth, nullptr);
	CHECK_EQUAL(pN02->pSouth, nullptr);
	CHECK_EQUAL(pN02->pEast, pN03);
	CHECK_EQUAL(pN02->pWest, nullptr);

	CHECK_EQUAL(pN03->pNorth, nullptr);
	CHECK_EQUAL(pN03->pSouth, pN13);
	CHECK_EQUAL(pN03->pEast, nullptr);
	CHECK_EQUAL(pN03->pWest, nullptr);

	//---------------------------------
	/*
	CHECK_EQUAL(pN10->pNorth, pN00);
	CHECK_EQUAL(pN10->pSouth, pN20);
	CHECK_EQUAL(pN10->pEast, nullptr);
	CHECK_EQUAL(pN10->pWest, nullptr);
	*/
	CHECK_EQUAL(pN11->pNorth, nullptr);
	CHECK_EQUAL(pN11->pSouth, nullptr);
	CHECK_EQUAL(pN11->pEast, nullptr);
	CHECK_EQUAL(pN11->pWest, nullptr);

	CHECK_EQUAL(pN12->pNorth, pN02);
	CHECK_EQUAL(pN12->pSouth, pN22);
	CHECK_EQUAL(pN12->pEast, nullptr);
	CHECK_EQUAL(pN12->pWest, pN11);

	CHECK_EQUAL(pN13->pNorth, nullptr);
	CHECK_EQUAL(pN13->pSouth, nullptr);
	CHECK_EQUAL(pN13->pEast, nullptr);
	CHECK_EQUAL(pN13->pWest, pN12);

	//---------------------------------

	CHECK_EQUAL(pN20->pNorth, nullptr);
	CHECK_EQUAL(pN20->pSouth, nullptr);
	CHECK_EQUAL(pN20->pEast, pN21);
	CHECK_EQUAL(pN20->pWest, nullptr);

	CHECK_EQUAL(pN21->pNorth, pN11);
	CHECK_EQUAL(pN21->pSouth, nullptr);
	CHECK_EQUAL(pN21->pEast, pN22);
	CHECK_EQUAL(pN21->pWest, nullptr);

	CHECK_EQUAL(pN22->pNorth, nullptr);
	CHECK_EQUAL(pN22->pSouth, nullptr);
	CHECK_EQUAL(pN22->pEast, pN23);
	CHECK_EQUAL(pN22->pWest, nullptr);

	CHECK_EQUAL(pN23->pNorth, pN13);
	CHECK_EQUAL(pN23->pSouth, nullptr);
	CHECK_EQUAL(pN23->pEast, nullptr);
	CHECK_EQUAL(pN23->pWest, nullptr);

	//---------------------------------


	delete pN00;
	delete pN01;
	delete pN02;
	delete pN03;

	//delete pN10;
	delete pN11;
	delete pN12;
	delete pN13;

	delete pN20;
	delete pN21;
	delete pN22;
	delete pN23;

#endif
}  TEST_END

TEST_TEARDOWN(DeleteExtra10_Test_Enable)
{

}

// ---  End of File ---------------
