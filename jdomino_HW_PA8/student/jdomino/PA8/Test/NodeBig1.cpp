

#include "_UnitTestConfiguration.h"
#include "Boustrophedonic.h"
#include "Tree.h"


TEST_WITH_TEARDOWN(DeleteBig1_Test_Enable, TestConfig::ALL)
{
#if DeleteBig1_Test_Enable


	Node* pN00 = new Node(), * pN01 = new Node(), * pN02 = new Node(), * pN03 = new Node(), * pN04 = new Node(), * pN05 = new Node();
	Node* pN10 = new Node(), * pN11 = new Node(), * pN12 = new Node(), * pN13 = new Node(), * pN14 = new Node(), * pN15 = new Node();
	Node* pN20 = new Node(), * pN21 = new Node(), * pN22 = new Node(), * pN23 = new Node(), * pN24 = new Node(), * pN25 = new Node();
	Node* pN30 = new Node(), * pN31 = new Node(), * pN32 = new Node(), * pN33 = new Node(), * pN34 = new Node(), * pN35 = new Node();
	Node* pN40 = new Node(), * pN41 = new Node(), * pN42 = new Node(), * pN43 = new Node(), * pN44 = new Node(), * pN45 = new Node();
	Node* pN50 = new Node(), * pN51 = new Node(), * pN52 = new Node(), * pN53 = new Node(), * pN54 = new Node(), * pN55 = new Node();


	// Set standard path
	pN00->pEast = pN01;
	pN01->pEast = pN02;
	pN02->pEast = pN03;
	pN03->pEast = pN04;
	pN04->pEast = pN05;

	pN05->pSouth = pN15;

	pN15->pWest = pN14;
	pN14->pWest = pN13;
	pN13->pWest = pN12;
	pN12->pWest = pN11;
	pN11->pWest = pN10;

	pN10->pSouth = pN20;

	pN20->pEast = pN21;
	pN21->pEast = pN22;
	pN22->pEast = pN23;
	pN23->pEast = pN24;
	pN24->pEast = pN25;

	pN25->pSouth = pN35;

	pN35->pWest = pN34;
	pN34->pWest = pN33;
	pN33->pWest = pN32;
	pN32->pWest = pN31;
	pN31->pWest = pN30;

	pN30->pSouth = pN40;

	pN40->pEast = pN41;
	pN41->pEast = pN42;
	pN42->pEast = pN43;
	pN43->pEast = pN44;
	pN44->pEast = pN45;

	pN45->pSouth = pN55;

	pN55->pWest = pN54;
	pN54->pWest = pN53;
	pN53->pWest = pN52;
	pN52->pWest = pN51;
	pN51->pWest = pN50;



	// Set Ups and downs

	pN10->pNorth = pN00;
	pN12->pNorth = pN02;
	pN14->pNorth = pN04;

	pN21->pNorth = pN11;
	pN23->pNorth = pN13;
	pN25->pNorth = pN15;

	pN30->pNorth = pN20;
	pN32->pNorth = pN22;
	pN34->pNorth = pN24;

	pN41->pNorth = pN31;
	pN43->pNorth = pN33;
	pN45->pNorth = pN35;

	pN50->pNorth = pN40;
	pN52->pNorth = pN42;
	pN54->pNorth = pN44;

	pN01->pSouth = pN11;
	pN03->pSouth = pN13;

	pN12->pSouth = pN22;
	pN14->pSouth = pN24;

	pN21->pSouth = pN31;
	pN23->pSouth = pN33;

	pN32->pSouth = pN42;
	pN34->pSouth = pN44;

	pN41->pSouth = pN51;
	pN43->pSouth = pN53;


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
	CHECK_EQUAL(pN03->pEast, pN04);
	CHECK_EQUAL(pN03->pWest, nullptr);

	CHECK_EQUAL(pN04->pNorth, nullptr);
	CHECK_EQUAL(pN04->pSouth, nullptr);
	CHECK_EQUAL(pN04->pEast, pN05);
	CHECK_EQUAL(pN04->pWest, nullptr);

	CHECK_EQUAL(pN05->pNorth, nullptr);
	CHECK_EQUAL(pN05->pSouth, pN15);
	CHECK_EQUAL(pN05->pEast, nullptr);
	CHECK_EQUAL(pN05->pWest, nullptr);

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

	CHECK_EQUAL(pN14->pNorth, pN04);
	CHECK_EQUAL(pN14->pSouth, pN24);
	CHECK_EQUAL(pN14->pEast, nullptr);
	CHECK_EQUAL(pN14->pWest, pN13);

	CHECK_EQUAL(pN15->pNorth, nullptr);
	CHECK_EQUAL(pN15->pSouth, nullptr);
	CHECK_EQUAL(pN15->pEast, nullptr);
	CHECK_EQUAL(pN15->pWest, pN14);

	//---------------------------------

	CHECK_EQUAL(pN20->pNorth, nullptr);
	CHECK_EQUAL(pN20->pSouth, nullptr);
	CHECK_EQUAL(pN20->pEast, pN21);
	CHECK_EQUAL(pN20->pWest, nullptr);

	CHECK_EQUAL(pN21->pNorth, pN11);
	CHECK_EQUAL(pN21->pSouth, pN31);
	CHECK_EQUAL(pN21->pEast, pN22);
	CHECK_EQUAL(pN21->pWest, nullptr);

	CHECK_EQUAL(pN22->pNorth, nullptr);
	CHECK_EQUAL(pN22->pSouth, nullptr);
	CHECK_EQUAL(pN22->pEast, pN23);
	CHECK_EQUAL(pN22->pWest, nullptr);

	CHECK_EQUAL(pN23->pNorth, pN13);
	CHECK_EQUAL(pN23->pSouth, pN33);
	CHECK_EQUAL(pN23->pEast, pN24);
	CHECK_EQUAL(pN23->pWest, nullptr);

	CHECK_EQUAL(pN24->pNorth, nullptr);
	CHECK_EQUAL(pN24->pSouth, nullptr);
	CHECK_EQUAL(pN24->pEast, pN25);
	CHECK_EQUAL(pN24->pWest, nullptr);

	CHECK_EQUAL(pN25->pNorth, pN15);
	CHECK_EQUAL(pN25->pSouth, pN35);
	CHECK_EQUAL(pN25->pEast, nullptr);
	CHECK_EQUAL(pN25->pWest, nullptr);

	//---------------------------------

	CHECK_EQUAL(pN30->pNorth, pN20);
	CHECK_EQUAL(pN30->pSouth, pN40);
	CHECK_EQUAL(pN30->pEast, nullptr);
	CHECK_EQUAL(pN30->pWest, nullptr);

	CHECK_EQUAL(pN31->pNorth, nullptr);
	CHECK_EQUAL(pN31->pSouth, nullptr);
	CHECK_EQUAL(pN31->pEast, nullptr);
	CHECK_EQUAL(pN31->pWest, pN30);

	CHECK_EQUAL(pN32->pNorth, pN22);
	CHECK_EQUAL(pN32->pSouth, pN42);
	CHECK_EQUAL(pN32->pEast, nullptr);
	CHECK_EQUAL(pN32->pWest, pN31);

	CHECK_EQUAL(pN33->pNorth, nullptr);
	CHECK_EQUAL(pN33->pSouth, nullptr);
	CHECK_EQUAL(pN33->pEast, nullptr);
	CHECK_EQUAL(pN33->pWest, pN32);

	CHECK_EQUAL(pN34->pNorth, pN24);
	CHECK_EQUAL(pN34->pSouth, pN44);
	CHECK_EQUAL(pN34->pEast, nullptr);
	CHECK_EQUAL(pN34->pWest, pN33);

	CHECK_EQUAL(pN35->pNorth, nullptr);
	CHECK_EQUAL(pN35->pSouth, nullptr);
	CHECK_EQUAL(pN35->pEast, nullptr);
	CHECK_EQUAL(pN35->pWest, pN34);

	//---------------------------------

	CHECK_EQUAL(pN40->pNorth, nullptr);
	CHECK_EQUAL(pN40->pSouth, nullptr);
	CHECK_EQUAL(pN40->pEast, pN41);
	CHECK_EQUAL(pN40->pWest, nullptr);

	CHECK_EQUAL(pN41->pNorth, pN31);
	CHECK_EQUAL(pN41->pSouth, pN51);
	CHECK_EQUAL(pN41->pEast, pN42);
	CHECK_EQUAL(pN41->pWest, nullptr);

	CHECK_EQUAL(pN42->pNorth, nullptr);
	CHECK_EQUAL(pN42->pSouth, nullptr);
	CHECK_EQUAL(pN42->pEast, pN43);
	CHECK_EQUAL(pN42->pWest, nullptr);

	CHECK_EQUAL(pN43->pNorth, pN33);
	CHECK_EQUAL(pN43->pSouth, pN53);
	CHECK_EQUAL(pN43->pEast, pN44);
	CHECK_EQUAL(pN43->pWest, nullptr);

	CHECK_EQUAL(pN44->pNorth, nullptr);
	CHECK_EQUAL(pN44->pSouth, nullptr);
	CHECK_EQUAL(pN44->pEast, pN45);
	CHECK_EQUAL(pN44->pWest, nullptr);

	CHECK_EQUAL(pN45->pNorth, pN35);
	CHECK_EQUAL(pN45->pSouth, pN55);
	CHECK_EQUAL(pN45->pEast, nullptr);
	CHECK_EQUAL(pN45->pWest, nullptr);

	//---------------------------------

	CHECK_EQUAL(pN50->pNorth, pN40);
	CHECK_EQUAL(pN50->pSouth, nullptr);
	CHECK_EQUAL(pN50->pEast, nullptr);
	CHECK_EQUAL(pN50->pWest, nullptr);

	CHECK_EQUAL(pN51->pNorth, nullptr);
	CHECK_EQUAL(pN51->pSouth, nullptr);
	CHECK_EQUAL(pN51->pEast, nullptr);
	CHECK_EQUAL(pN51->pWest, pN50);

	CHECK_EQUAL(pN52->pNorth, pN42);
	CHECK_EQUAL(pN52->pSouth, nullptr);
	CHECK_EQUAL(pN52->pEast, nullptr);
	CHECK_EQUAL(pN52->pWest, pN51);

	CHECK_EQUAL(pN53->pNorth, nullptr);
	CHECK_EQUAL(pN53->pSouth, nullptr);
	CHECK_EQUAL(pN53->pEast, nullptr);
	CHECK_EQUAL(pN53->pWest, pN52);

	CHECK_EQUAL(pN54->pNorth, pN44);
	CHECK_EQUAL(pN54->pSouth, nullptr);
	CHECK_EQUAL(pN54->pEast, nullptr);
	CHECK_EQUAL(pN54->pWest, pN53);

	CHECK_EQUAL(pN55->pNorth, nullptr);
	CHECK_EQUAL(pN55->pSouth, nullptr);
	CHECK_EQUAL(pN55->pEast, nullptr);
	CHECK_EQUAL(pN55->pWest, pN54);

	//---------------------------------

	//---- TEST below here --------------------

	Trace::out("remove:---> (4,4) \n");
	Remove(pN00, 4, 4);

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
	CHECK_EQUAL(pN03->pEast, pN04);
	CHECK_EQUAL(pN03->pWest, nullptr);

	CHECK_EQUAL(pN04->pNorth, nullptr);
	CHECK_EQUAL(pN04->pSouth, nullptr);
	CHECK_EQUAL(pN04->pEast, pN05);
	CHECK_EQUAL(pN04->pWest, nullptr);

	CHECK_EQUAL(pN05->pNorth, nullptr);
	CHECK_EQUAL(pN05->pSouth, pN15);
	CHECK_EQUAL(pN05->pEast, nullptr);
	CHECK_EQUAL(pN05->pWest, nullptr);

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

	CHECK_EQUAL(pN14->pNorth, pN04);
	CHECK_EQUAL(pN14->pSouth, pN24);
	CHECK_EQUAL(pN14->pEast, nullptr);
	CHECK_EQUAL(pN14->pWest, pN13);

	CHECK_EQUAL(pN15->pNorth, nullptr);
	CHECK_EQUAL(pN15->pSouth, nullptr);
	CHECK_EQUAL(pN15->pEast, nullptr);
	CHECK_EQUAL(pN15->pWest, pN14);

	//---------------------------------

	CHECK_EQUAL(pN20->pNorth, nullptr);
	CHECK_EQUAL(pN20->pSouth, nullptr);
	CHECK_EQUAL(pN20->pEast, pN21);
	CHECK_EQUAL(pN20->pWest, nullptr);

	CHECK_EQUAL(pN21->pNorth, pN11);
	CHECK_EQUAL(pN21->pSouth, pN31);
	CHECK_EQUAL(pN21->pEast, pN22);
	CHECK_EQUAL(pN21->pWest, nullptr);

	CHECK_EQUAL(pN22->pNorth, nullptr);
	CHECK_EQUAL(pN22->pSouth, nullptr);
	CHECK_EQUAL(pN22->pEast, pN23);
	CHECK_EQUAL(pN22->pWest, nullptr);

	CHECK_EQUAL(pN23->pNorth, pN13);
	CHECK_EQUAL(pN23->pSouth, pN33);
	CHECK_EQUAL(pN23->pEast, pN24);
	CHECK_EQUAL(pN23->pWest, nullptr);

	CHECK_EQUAL(pN24->pNorth, nullptr);
	CHECK_EQUAL(pN24->pSouth, nullptr);
	CHECK_EQUAL(pN24->pEast, pN25);
	CHECK_EQUAL(pN24->pWest, nullptr);

	CHECK_EQUAL(pN25->pNorth, pN15);
	CHECK_EQUAL(pN25->pSouth, pN35);
	CHECK_EQUAL(pN25->pEast, nullptr);
	CHECK_EQUAL(pN25->pWest, nullptr);

	//---------------------------------

	CHECK_EQUAL(pN30->pNorth, pN20);
	CHECK_EQUAL(pN30->pSouth, pN40);
	CHECK_EQUAL(pN30->pEast, nullptr);
	CHECK_EQUAL(pN30->pWest, nullptr);

	CHECK_EQUAL(pN31->pNorth, nullptr);
	CHECK_EQUAL(pN31->pSouth, nullptr);
	CHECK_EQUAL(pN31->pEast, nullptr);
	CHECK_EQUAL(pN31->pWest, pN30);

	CHECK_EQUAL(pN32->pNorth, pN22);
	CHECK_EQUAL(pN32->pSouth, pN42);
	CHECK_EQUAL(pN32->pEast, nullptr);
	CHECK_EQUAL(pN32->pWest, pN31);

	CHECK_EQUAL(pN33->pNorth, nullptr);
	CHECK_EQUAL(pN33->pSouth, nullptr);
	CHECK_EQUAL(pN33->pEast, nullptr);
	CHECK_EQUAL(pN33->pWest, pN32);

	CHECK_EQUAL(pN34->pNorth, pN24);
	CHECK_EQUAL(pN34->pSouth, pN54);
	CHECK_EQUAL(pN34->pEast, nullptr);
	CHECK_EQUAL(pN34->pWest, pN33);

	CHECK_EQUAL(pN35->pNorth, nullptr);
	CHECK_EQUAL(pN35->pSouth, nullptr);
	CHECK_EQUAL(pN35->pEast, nullptr);
	CHECK_EQUAL(pN35->pWest, pN34);

	//---------------------------------

	CHECK_EQUAL(pN40->pNorth, nullptr);
	CHECK_EQUAL(pN40->pSouth, nullptr);
	CHECK_EQUAL(pN40->pEast, pN41);
	CHECK_EQUAL(pN40->pWest, nullptr);

	CHECK_EQUAL(pN41->pNorth, pN31);
	CHECK_EQUAL(pN41->pSouth, pN51);
	CHECK_EQUAL(pN41->pEast, pN42);
	CHECK_EQUAL(pN41->pWest, nullptr);

	CHECK_EQUAL(pN42->pNorth, nullptr);
	CHECK_EQUAL(pN42->pSouth, nullptr);
	CHECK_EQUAL(pN42->pEast, pN43);
	CHECK_EQUAL(pN42->pWest, nullptr);

	CHECK_EQUAL(pN43->pNorth, pN33);
	CHECK_EQUAL(pN43->pSouth, pN53);
	CHECK_EQUAL(pN43->pEast, pN45);
	CHECK_EQUAL(pN43->pWest, nullptr);
	/*
	CHECK_EQUAL(pN44->pNorth, nullptr);
	CHECK_EQUAL(pN44->pSouth, nullptr);
	CHECK_EQUAL(pN44->pEast, pN45);
	CHECK_EQUAL(pN44->pWest, nullptr);
	*/
	CHECK_EQUAL(pN45->pNorth, pN35);
	CHECK_EQUAL(pN45->pSouth, pN55);
	CHECK_EQUAL(pN45->pEast, nullptr);
	CHECK_EQUAL(pN45->pWest, nullptr);

	//---------------------------------

	CHECK_EQUAL(pN50->pNorth, pN40);
	CHECK_EQUAL(pN50->pSouth, nullptr);
	CHECK_EQUAL(pN50->pEast, nullptr);
	CHECK_EQUAL(pN50->pWest, nullptr);

	CHECK_EQUAL(pN51->pNorth, nullptr);
	CHECK_EQUAL(pN51->pSouth, nullptr);
	CHECK_EQUAL(pN51->pEast, nullptr);
	CHECK_EQUAL(pN51->pWest, pN50);

	CHECK_EQUAL(pN52->pNorth, pN42);
	CHECK_EQUAL(pN52->pSouth, nullptr);
	CHECK_EQUAL(pN52->pEast, nullptr);
	CHECK_EQUAL(pN52->pWest, pN51);

	CHECK_EQUAL(pN53->pNorth, nullptr);
	CHECK_EQUAL(pN53->pSouth, nullptr);
	CHECK_EQUAL(pN53->pEast, nullptr);
	CHECK_EQUAL(pN53->pWest, pN52);

	CHECK_EQUAL(pN54->pNorth, pN34);
	CHECK_EQUAL(pN54->pSouth, nullptr);
	CHECK_EQUAL(pN54->pEast, nullptr);
	CHECK_EQUAL(pN54->pWest, pN53);

	CHECK_EQUAL(pN55->pNorth, nullptr);
	CHECK_EQUAL(pN55->pSouth, nullptr);
	CHECK_EQUAL(pN55->pEast, nullptr);
	CHECK_EQUAL(pN55->pWest, pN54);

	//---------------------------------


	delete pN00;
	delete pN01;
	delete pN02;
	delete pN03;
	delete pN04;
	delete pN05;

	delete pN10;
	delete pN11;
	delete pN12;
	delete pN13;
	delete pN14;
	delete pN15;

	delete pN20;
	delete pN21;
	delete pN22;
	delete pN23;
	delete pN24;
	delete pN25;

	delete pN30;
	delete pN31;
	delete pN32;
	delete pN33;
	delete pN34;
	delete pN35;

	delete pN40;
	delete pN41;
	delete pN42;
	delete pN43;
	//delete pN44;
	delete pN45;

	delete pN50;
	delete pN51;
	delete pN52;
	delete pN53;
	delete pN54;
	delete pN55;

#endif
}  TEST_END

TEST_TEARDOWN(DeleteBig1_Test_Enable)
{

}

// ---  End of File ---------------
