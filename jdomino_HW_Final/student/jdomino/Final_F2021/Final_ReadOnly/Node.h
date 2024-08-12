//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef NODE_H
#define NODE_H

class Node
{
public:
	static const unsigned int COUNT = 512;
public:
	Node();
	Node(const Node &) = delete;
	Node &operator = (const Node &) = delete;
	~Node() = default;


private:
	void privFillBuff();
	unsigned int privGetInt();
	unsigned char privGetChar() const;

	// ------------------------------------------
	// Data:  (do not add or modify the data)
	// ------------------------------------------
public:
	Node *pNext;
	unsigned char buffer[Node::COUNT];
	unsigned int  key;

};

#endif

// ---  End of File ---
