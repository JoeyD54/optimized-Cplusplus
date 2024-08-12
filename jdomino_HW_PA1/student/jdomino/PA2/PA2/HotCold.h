//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef HOTCOLD_H
#define HOTCOLD_H

#include "ColdNode.h"
#include "HotNode.h"

class HotCold
{
public:
	HotCold() = delete;
	HotCold(const HotCold &) = delete;
	HotCold & operator = (const HotCold &) = delete;

	//void Add(HotNode* tempHotNode);
	//void Add(ColdNode* tempColdNode);

	HotCold( const Bloated * const pBloated );	
	~HotCold();

	bool FindKey(int key, ColdNode *&pFoundColdNode, HotNode *&pFoundHotNode);
	HotNode *GetHotHead() const;

private:
	// -----------------------------------------------------------------
	// NO varaibles that have Count or number of nodes in list allowed
	// -----------------------------------------------------------------
	// You CANNOT add additional data to this class
	HotNode		*pHotHead;
	ColdNode	*pColdHead;
};

#endif

// ---  End of File ---

