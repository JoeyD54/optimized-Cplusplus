//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef HOT_H
#define HOT_H

class Node;

class Hot
{
public:
	Hot() = default;
	Hot(const Hot &) = default;
	Hot &operator = (const Hot &) = default;
	~Hot() = default;

	// ------------------------------------------
	// Data:  (do not add or modify the data)
	// ------------------------------------------

	Hot *pNext;
	unsigned int key;
	Node *pData;
};

#endif

// ---  End of File ---
