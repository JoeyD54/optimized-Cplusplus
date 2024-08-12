//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------
//
// NO HEADERS... do the problem in this CPP file
//
// Do Problem 3 here:
// 
// Write a function that removes A GIVEN NODE in a linked list container
//	containing nodes of type LinkList.
// 
// Assume that each LinkList node and its data pointer were originally allocated
//	dynamically by NEW and is valid.
// 
// NO GLOBALS, all parameters need to be passed to the function.
//	
// Input: headList, node
// 
// Output: N/A
//
// 
// class LinkList
// {
//	public:
//		LinkList	*next;
//		LinkList	*prev;
//		Data		*data;
// };
// 
// LinkList *headList
// ---------------------------------------------------------------------------

enum RemoveNodeStatus
{
	NODE_REMOVED,
	NODE_NOT_FOUND
};

//function definition
//RemoveNodeStatus removeNode(LinkList const & headList, LinkList const & nodeToRemove);



RemoveNodeStatus removeNode(LinkList const & headList, LinkList const & nodeToRemove)
{
	LinkList * currNode = nullptr;	//to step through list
	currNode = headList;			//Set to top of list

	//Step through until curr is nullptr
	while (currNode)
	{
		if (currNode == nodeToRemove)
		{
			//We found the node, clear the data
			delete currNode->data;

			//Reset neighbor's pointers
			currNode->prev->next = currNode->next;
			currNode->next->prev = currNode->prev;

			//Clear our node's pointers
			currNode->next = nullptr;
			currNode->prev = nullptr;

			//Everything is cleared out, delete the node
			delete currNode;

			return RemoveNodeStatus::NODE_REMOVED;
		}
		currNode = currNode->next;
	}

	//We went through the entire list and didn't find the node
	return RemoveNodeStatus::NODE_NOT_FOUND;
}


// End of File
