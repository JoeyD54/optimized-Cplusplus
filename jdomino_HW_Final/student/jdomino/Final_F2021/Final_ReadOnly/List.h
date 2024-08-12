//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef LIST_H
#define LIST_H

class Node;

class List
{
public:
	List();
	List(const List &) = delete;
	List & operator = (const List &) = delete;
	~List();
	
	Node *Find(unsigned int _key);
	
	// ------------------------------------------
	// Data:  (do not add or modify the data)
	// ------------------------------------------
	Node *poHead;
};

#endif

// ---  End of File ---
