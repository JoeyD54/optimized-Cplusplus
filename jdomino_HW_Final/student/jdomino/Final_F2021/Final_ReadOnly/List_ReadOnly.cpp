//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "List.h"
#include "Node.h"

List::List()
{
	srand(2021);

	Node *p;
	Node *pTmp;

	p = new Node();
	this->poHead = p;
	pTmp = p;

	for(int i = 0; i < 100000; i++)
	{
		p = new Node();
		pTmp->pNext = p;
		pTmp = p;
	}
	p->pNext = nullptr;

	//Trace::out("p:key:%x\n", p->key);
}

List::	~List()
{
	Node *pTmp = this->poHead;
	Node *pDeleteMe = pTmp;

	while(pTmp != nullptr)
	{
		//Trace::out("p:%p\n", pTmp);
		pDeleteMe = pTmp;
		pTmp = pTmp->pNext;
		delete pDeleteMe;
	}

}

Node *List::Find(unsigned int _key)
{
	Node *pTmp = this->poHead;
	while(pTmp != nullptr)
	{
		if(_key == pTmp->key)
		{
			break;
		}

		pTmp = pTmp->pNext;
	}
	return pTmp;
}

// ---  End of File ---
