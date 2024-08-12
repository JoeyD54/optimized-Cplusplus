//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "HotList.h"
#include "Hot.h"
#include "List.h"
#include "Node.h"

//---------------------------------------------------------------
// Rules:
// 
// You cannot count anywhere in your creation of the list
//     (walk the list and create Hot objects on the fly)
// Do not use placement new or new array...
//     (create each Hot object individually)
// You will create 1000s of Hot objects...
//     (make sure you clean it up in the destructor)
// You cannot add or change data in Hot, HotList, List, Node
//     (no need for any data changes... make it work as-is)
//
//---------------------------------------------------------------
//
// Add the constructor, destructor and find method here:
// 
//     HotList(const List *const pList);
//     ~HotList();
//     Hot *Find(unsigned int _key);
//
//---------------------------------------------------------------

HotList::HotList(const List *const pList)
{
	Hot* p;
	Hot* pTmp;

	Node* pNodeTmp = pList->poHead;

	p = new Hot();
	this->poHead = p;
	p->pData = pNodeTmp;
	p->key = pNodeTmp->key;
	pTmp = p;

	pNodeTmp = pNodeTmp->pNext;

	int count = 1;

	while(pNodeTmp)
	{
		p = new Hot();
		p->pData = pNodeTmp;
		p->key = pNodeTmp->key;

		pNodeTmp = pNodeTmp->pNext;
		pTmp->pNext = p;
		pTmp = p;

		count++;
	}
	p->pNext = nullptr;
}

HotList::~HotList()
{
	Hot* pTmp = this->poHead;
	Hot* pDeleteMe = pTmp;

	while (pTmp != nullptr)
	{
		//Trace::out("p:%p\n", pTmp);

		//clear the pointer to list before deletion
		pTmp->pData = nullptr;

		//Delete it
		pDeleteMe = pTmp;
		pTmp = pTmp->pNext;
		delete pDeleteMe;
	}
}

Hot *HotList::Find(unsigned int _key)
{
	Hot* pTmp = this->poHead;

	while (pTmp != nullptr)
	{
		if (_key == pTmp->key)
		{
			break;
		}
		pTmp = pTmp->pNext;
	}
	return pTmp;
}

// ---  End of File ---
