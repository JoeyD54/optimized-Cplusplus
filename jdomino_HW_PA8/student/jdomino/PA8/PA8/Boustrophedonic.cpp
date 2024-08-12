//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Boustrophedonic.h"


/*
* Remove will:
*	Find the node based off of row and col
*	Starting from the head of the 4d Linked List
*	
*	Once the node is found
*		Correct pointers of adjacent nodes
*		Remove the found node
*			Remove via DELETE
*
*
*	TRAVERSAL LAYOUT
*		Head only points right
*		Every node at location (row even, column odd) points up, down and right
*			Unnless last in list, it just points up and down
*		Every node at location (row even, column even) points right
*		Every node at location (row odd, column odd) points left
*		Every node at location (row odd, column even) points up, down and left
*			Unless first in list, it just points up and down		
*/
void Remove(Node *&pHead, int inRow, int inCol)
{
	int myRowCount = 0;
	int myColCount = 0;
	
	bool EOL = false;
	bool movingLeft = false;

	Node* currNode = pHead;

	//This is to aid pointer resets
	Node* foundNode = nullptr;
	Node* eastNode = nullptr;
	Node* westNode = nullptr;
	Node* northNode = nullptr;
	Node* southNode = nullptr;

	//Start from head and shift right
	//First shifts right will find out max # of cols
	//This will be used for a loop when shifting left
	while (!EOL)
	{
		if (myRowCount == inRow && myColCount == inCol)
		{
			//Found the node, store it for pointer resets later
			foundNode = currNode;

			//We found the node, can we grab any pointers around it?
			if (foundNode->pEast)
			{
				eastNode = foundNode->pEast;
			}
			if (foundNode->pWest)
			{
				westNode = foundNode->pWest;
			}
			if (foundNode->pNorth)
			{
				northNode = foundNode->pNorth;
			}
			if (foundNode->pSouth)
			{
				southNode = foundNode->pSouth;
			}
		}
		//Before traversing the list
		//Let's see if the current node points to our desired node
		//Use the Row Col as reference. We don't know if node has been found yet.

		//Look up and down first.
		if (myColCount == inCol && myRowCount - 1 == inRow && currNode->pNorth)
		{
			//Found south node. save for pointer resets
			southNode = currNode;

		}
		else if (myColCount == inCol && myRowCount + 1 == inRow && currNode->pSouth)
		{
			//Found north node. save for pointer resets
			northNode = currNode;
		}



		//Traversing the list
		if (currNode->pEast && !movingLeft)
		{
			
			if (myColCount + 1 == inCol && myRowCount == inRow)
			{
				//Store this for pointer resets below
				westNode = currNode;
			}

			//Move right
			currNode = currNode->pEast;
			myColCount++;
		}
		else if (currNode->pWest && movingLeft)
		{
			if (myColCount - 1 == inCol && myRowCount == inRow)
			{
				//Found east node. save for pointer resets
				eastNode = currNode;
			}

			//Move left
			currNode = currNode->pWest;
			myColCount--;
		}
		else if(currNode->pSouth)
		{
			myRowCount++;


			//We can't move either direction, move down
			currNode = currNode->pSouth;

			//If we're at the farthest right
			if (myColCount != 0)
			{
				movingLeft = true;
			}
			else
			{
				movingLeft = false;
			}
		}
		//Can't move left, can't move right, can't move down
		else
		{
			//We are at EOL
			EOL = true;
		}
	}

	if (foundNode)
	{
		//We have a found node, reset pointers of adjacent nodes
		if (northNode)
		{
			if (northNode->pSouth == foundNode)
			{
				northNode->pSouth = southNode;
			}
			else
			{
				northNode->pSouth = nullptr;
			}
		}
		if (eastNode)
		{
			if(eastNode->pWest == foundNode)
			{
				eastNode->pWest = westNode;
			}
			else
			{
				eastNode->pWest = foundNode->pWest;
			}
		}
		if (westNode)
		{
			if (westNode->pEast == foundNode)
			{
				westNode->pEast = eastNode;
			}
			else
			{
				westNode->pEast = foundNode->pEast;
			}
		}
		if (southNode)
		{
			if (southNode->pNorth == foundNode)
			{
				southNode->pNorth = northNode;
			}
			else
			{
				southNode->pNorth = nullptr;
			}
		}

		if (foundNode == pHead)
		{
			pHead = foundNode->pEast;
		}
		//Then delete
		delete foundNode;
	}
}


// ---  End of File ---------------
