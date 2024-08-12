//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// user headers
#include "bloated.h"
#include "Node.h"

//----------------------------------------------------------------------------------
// Find Key using linked lists (pointers only) 
//    Hint: use ->pNext
//    YOU MUST - iterate through the nodes in a linked list fashion or 0 credit
//               starting from the head until you find it
//
// Return true if you find the node
// Return the pointer in the argument list to the node (if found)
//----------------------------------------------------------------------------------

bool Bloated::FindKey(int key, Node *&foundNode) const
{
	//Store incomming node to parse
	
	//Make sure head is not nullptr
	if (this->pHead)
	{
		Node * tempNode = pHead;

		//Step through node from head until key is found
		while (tempNode != nullptr)
		{
			if (tempNode->key == key)
			{
				//return the node and true
				foundNode = tempNode;
				return true;
			}
			tempNode = tempNode->pNext;
		}
	}
	
	return false;
}

// ---  End of File ---

