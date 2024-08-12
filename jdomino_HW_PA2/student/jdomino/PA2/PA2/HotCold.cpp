//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// Users
#include "Bloated.h"
#include "Node.h"
#include "hotcold.h"



	//Count the nodes in bloated
	//Create a chunk of hots = count of bloated
	//Create chunk of colds = count of bloated
	//
	// Go through again, read one node at a time
	// Populate hot and cold nodes
	// Set next and prev hots
	// 
	// Each hot points to their cold
	// Their cold points back to their hot
	// 
	// NOTE
	//Set up new structures
	//Hot holds the key info
	//Cold holds the extra bits
	//Keep hot nodes next to each other

HotCold::HotCold(const Bloated * const pBloated)
{
	if (pBloated)
	{
		unsigned int bloatCount = 0;

		HotNode* pNewHot = nullptr;
		HotNode* pPrevHot = nullptr;
		HotNode* pCurrHot = nullptr;
		ColdNode* pCurrCold = nullptr;
		ColdNode* pNewCold = nullptr;
		

		Node* tempBloatNode = pBloated->GetListHead();
		while (tempBloatNode != nullptr)
		{
			//increment count for next loop
			bloatCount++;
			tempBloatNode = tempBloatNode->pNext;
		}

		//make bloatCount amount of new hots
		pCurrHot = new HotNode[bloatCount]();
		this->pHotHead = pCurrHot;

		//Make bloatCount amount of new colds
		pCurrCold = new ColdNode[bloatCount]();
		this->pColdHead = pCurrCold;

		tempBloatNode = pBloated->GetListHead();

		HotNode* pFirst = pCurrHot;
		HotNode* pLast = pCurrHot + bloatCount - 1;
		
		pNewHot = pCurrHot;
		pNewCold = pCurrCold;

		//Step through hot list, set up variables
		//With each hot, point to and go into it's cold and set those variables
		//Point cold back to hot, repeat
		//Do this bloatCount amount of times
		for(unsigned int i = 0; i < bloatCount; ++i)
		{
			pNewHot->key   = tempBloatNode->key;
			pNewHot->pCold = pNewCold;

			pNewCold->pHot = pNewHot;
			pNewCold->aa   = tempBloatNode->aa;
			pNewCold->bb   = tempBloatNode->bb;
			pNewCold->cc   = tempBloatNode->cc;
			pNewCold->dd   = tempBloatNode->dd;
			pNewCold->x    = tempBloatNode->x;
			pNewCold->y    = tempBloatNode->y;
			pNewCold->z    = tempBloatNode->z;
			pNewCold->w    = tempBloatNode->w;
			pNewCold->A    = tempBloatNode->A;
			pNewCold->B    = tempBloatNode->B;
			pNewCold->C    = tempBloatNode->C;
			pNewCold->D    = tempBloatNode->D;
			pNewCold->MA   = tempBloatNode->MA;
			pNewCold->MB   = tempBloatNode->MB;
			pNewCold->MC   = tempBloatNode->MC;
			pNewCold->MD   = tempBloatNode->MD;
			pNewCold->ME   = tempBloatNode->ME;
			strcpy_s(pNewCold->name, sizeof(tempBloatNode->name), tempBloatNode->name);	

			pCurrHot->pNext = pNewHot;
			pPrevHot = pCurrHot;
			pCurrHot = pNewHot;
			pCurrHot->pPrev = pPrevHot;
			

			tempBloatNode = tempBloatNode->pNext;
			pNewHot = (pNewHot + 1);
			pNewCold = (pNewCold + 1);
		}


		pFirst->pPrev = nullptr;
		pLast->pNext = nullptr;
	}
}

HotCold::~HotCold()
{
	// HINT - do something here

	//Clear out the pointers
	//Delete the chunk of memory
	this->pHotHead->pNext = nullptr;
	this->pHotHead->pNext = nullptr;
	this->pHotHead->pCold = nullptr;
	this->pColdHead->pHot = nullptr;
	delete[] this->pHotHead;
	delete[] this->pColdHead;
}

//----------------------------------------------------------------------------------
// Find Key using linked lists (pointers only) 
//    Hint: use ->pNext
//    YOU MUST - iterate through the nodes in a linked list fashion or 0 credit
//
// Return true if you find the node
// Return the pointer in the argument list to the HotNode and ColdNode (if found)
//----------------------------------------------------------------------------------
bool HotCold::FindKey(int key, ColdNode *&pFoundColdNode, HotNode *&pFoundHotNode)
{
	//Start by sorting through hot
	if (this->pHotHead)
	{
		//Store the head to step with
		HotNode* tempHotNode = this->pHotHead;
		//ColdNode* tempColdNode = this->pColdHead;

		//Step through node from head until key is found
		while (tempHotNode != nullptr)
		{
			if (tempHotNode->key == key)
			{
				//return the node and true
				pFoundHotNode = tempHotNode;
				pFoundColdNode = tempHotNode->pCold;
				return true;
			}
			tempHotNode = tempHotNode->pNext;
		}
	}
	return false;
}

HotNode *HotCold::GetHotHead() const
{
	return this->pHotHead;
}

// ---  End of File ---

