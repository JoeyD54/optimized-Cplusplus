//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "OList.h"
#include "Node.h"

// ----------------------------------
// -----> MODIFY This FILE <---------
// ----------------------------------

void OList::SetCutoffLength()
{
	// Yes HARD code your cutoff
	// CHANGE this number, by running experiments to find best value
	this->mCutoffLength = 32;
}

void OList::MergeSort()
{
	/*
	* Merge Sort:
	*	Split the double linked list in half
	*		Do repeatedly until there's only two items connected
	*	Sort the two numbers
	*	Reconnect one pair at a time
	*		sort while reconnecting
	*/

	//Make sure at least 2 nodes in list
	if (this->pHead && this->pHead->pNext)
	{
		//Calling my overloaded MergeSort to handle recursion
		this->pHead = MergeSort(this->pHead);
	}
	else
	{
		//Sort the two items
		this->InsertionSort();
	}
}

Node* OList::MergeSort(Node* headNode)
{
	if (!headNode || !headNode->pNext)
	{
		return headNode;
	}

	Node* secondNode = Split(headNode);

	headNode = MergeSort(headNode);
	secondNode = MergeSort(secondNode);

	return Merge(headNode, secondNode);
}

Node* OList::Split(Node* headNode)
{
	Node* fastNode = headNode;
	Node* slowNode = headNode;

	while (fastNode->pNext && fastNode->pNext->pNext)
	{
		fastNode = fastNode->pNext->pNext;
		slowNode = slowNode->pNext;
	}

	Node* tempNode = slowNode->pNext;
	slowNode->pNext = nullptr;
	return tempNode;
}

Node* OList::Merge(Node* firstNode, Node* secondNode)
{
	if (!firstNode)
	{
		return secondNode;
	}
	if (!secondNode)
	{
		return firstNode;
	}

	if (firstNode->key < secondNode->key)
	{
		firstNode->pNext = Merge(firstNode->pNext, secondNode);
		firstNode->pNext->pPrev = firstNode;
		firstNode->pPrev = nullptr;
		return firstNode;
	}
	else
	{
		secondNode->pNext = Merge(firstNode, secondNode->pNext);
		secondNode->pNext->pPrev = secondNode;
		secondNode->pPrev = nullptr;
		return secondNode;
	}
}

void OList::InsertionSort()
{
	/*
	* Insert sort will :
	*	step through the incoming linked list
	*	If current is a lower number than prev
	*		Shift it up
	*		Update pointers
	*	Repeat until all numbers are sorted
	*/
	Node* nextNode = nullptr;
	Node* currNode = this->pHead;
	Node* sortedNode = nullptr;

	while (currNode != nullptr)
	{	
		nextNode = currNode->pNext;
		currNode->pPrev = currNode->pNext = nullptr;

		SortedInsert(&sortedNode, currNode);

		currNode = nextNode;
	}
	this->pHead = sortedNode;
}

void OList::SortedInsert(Node** headNode, Node* newNode)
{
	Node* currNode;

	if (*headNode == nullptr)
	{
		*headNode = newNode;
	}
	//Node is placed in the beginning
	else if ((*headNode)->key >= newNode->key)
	{
		newNode->pNext = *headNode;
		newNode->pNext->pPrev = newNode;
		*headNode = newNode;
	}
	//Node is placed somewhere other than head
	else
	{
		currNode = *headNode;

		//Locate node after where new node is
		//to be placed
		while (currNode->pNext != nullptr &&
			currNode->pNext->key < newNode->key)
		{
			currNode = currNode->pNext;
		}

		newNode->pNext = currNode->pNext;

		//If new node not inserted at EOL
		if (currNode->pNext != nullptr)
		{
			newNode->pNext->pPrev = newNode;
		}

		currNode->pNext = newNode;
		newNode->pPrev = currNode;
	}
}

void OList::SwapData(Node* frontNode, Node* backNode)
{
	unsigned int tempX = frontNode->x;
	unsigned int tempY = frontNode->y;
	unsigned int tempZ = frontNode->z;
	unsigned int tempKey = frontNode->key;

	frontNode->x = backNode->x;
	frontNode->y = backNode->y;
	frontNode->z = backNode->z;
	frontNode->key = backNode->key;

	backNode->x = tempX;
	backNode->y = tempY;
	backNode->z = tempZ;
	backNode->key = tempKey;
}

void OList::MergeComboSort(int CutoffLength)
{
	//Merge sort
	//Merge until we reach the cutofflength
	//Then use insert sort on that merge chunk

	Node* nextNode = nullptr;
	Node* currNode = this->pHead;
	Node* sortedNode = nullptr;
	int nodeCount = 0;

	while (currNode != nullptr)
	{
		if (nodeCount <= CutoffLength)
		{
			nextNode = currNode->pNext;
			currNode->pPrev = currNode->pNext = nullptr;

			SortedInsert(&sortedNode, currNode);
		}
		else
		{
			currNode = MergeSort(currNode);
			sortedNode = Merge(sortedNode, currNode);
			break;
		}
		//this->pHead = sortedNode;
		currNode = nextNode;
		nodeCount++;
	}
	this->pHead = sortedNode;

}

void OList::WriteToFile(const char * const pFileName)
{
	// Do your magic

	// Make sure you close the file after you fill it
	// Use fopen,fwrite,ftell,...,fclose

	// Hint: Open the file, write the nodes into the file 

	// Grads - You need to do the Load-In-Place technique
	//         You cannot have more than 2 new functions in this method

	// Ungrads - You need to store the data and reconstruct the linked list
	//           You can use as many new/deletes as needed

	// Everyone - Fill in your CustomDestructCommand::Command() that will be used 
	//            in the destructor..

	// Quick sample code... remove this code and replace with your own

	//Step 1: Open file
	FILE* pFileHandle = nullptr;

	assert(pFileName);
	errno_t status;
	status = fopen_s(&pFileHandle, pFileName, "wb");
	assert(pFileHandle);
	assert(status == 0);

	//Open is good
	//Step 2: write into file
	char* buffer = new char[NumNodes * sizeof(Node)];
	Node* currNode = this->pHead;
	Node* nodeBuffer = (Node*)buffer;

	int i = 0;
	while (i < NumNodes)
	{
		memcpy(nodeBuffer + i, currNode, sizeof(Node));
		currNode = currNode->pNext;
		i++;
	}
	fwrite(buffer, sizeof(Node), (size_t) NumNodes, pFileHandle);
	
	//Step 3: close file
	fclose(pFileHandle);

	delete buffer;
}

OList::OList(const char * const pFileName, int numNodes)
{
	// Leave the next 5 lines...
	this->SetCutoffLength();
	this->pHead = nullptr;
	this->mCutoffLength = this->GetCutoffLength();
	this->NumNodes = numNodes;
	this->privFunctor = nullptr;
	
	// Do your magic here:

	// Create the Linked List... You cannot use the original code
	// The input file, and numNodes is all you need to recreate the OList
	
	// Hint: Open the file, read and create new nodes, 
	//       fill them with the data from the file

	// Grads - You need to do the Load-In-Place technique
	//         You cannot have more than 2 new functions in this method
	     
	// Ungrads - You need to store the data and reconstruct the linked list
	//           You can use as many new/deletes as needed

	// Everyone - Fill in your CustomDestructCommand::Command() that will be used 
	//            in the destructor.

	// Quick sample code... remove this code and replace with your own

 	FILE *pFileHandle;
 
	errno_t status;
	assert(pFileName);
	status = fopen_s(&pFileHandle, pFileName, "rb");
	assert(pFileHandle);
	assert(status == 0);
 
	//char* inBuffer = new char[NumNodes * sizeof(Node)];

	char* inBuffer = new char[NumNodes * sizeof(Node)];

	fread(inBuffer, (size_t) sizeof(Node), (size_t) this->NumNodes, pFileHandle);


	this->pHead = (Node*)inBuffer;

	Node* inNode = this->pHead;

	//Node* currNode = inNode;
	//Node* nextNode = currNode + 1;

	//Start of list, null the pointers
	inNode->pPrev = nullptr;
	inNode->pNext = nullptr;

	int i = 1;

	while(i < NumNodes)
	{
		////Current's next is next pointer
		//currNode->pNext = nextNode;
		////Next previous is current
		//nextNode->pPrev = currNode;
		//
		////Shift up
		//currNode = nextNode;

		////Get next
		//nextNode += 1;

		(inNode + i - 1)->pNext = (inNode + i);
		(inNode + i)->pPrev = (inNode + i - 1);

		i++;
	}

	(inNode + i - 1)->pNext = nullptr;

	//nextNode->pNext = nullptr;

	

	fclose(pFileHandle);
}

// ---  End of File ---------------
