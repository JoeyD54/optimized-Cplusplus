//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef COLD_NODE_H
#define COLD_NODE_H

class Node;
class HotNode;

class ColdNode
{
public:
	// You CANNOT add additional data to this class
	HotNode	*pHot;
	char   aa;
	char   bb;
	char   cc;
	char   dd;
	float	x;
	float	y;
	float	z;
	float   w;
	Vect	A;
	Vect	B;
	Vect	C;
	Vect    D;
	Matrix	MA;
	Matrix	MB;
	Matrix	MC;
	Matrix	MD;
	Matrix  ME;
	char	name[Node::NAME_SIZE];
};


#endif

// ---  End of File ---

