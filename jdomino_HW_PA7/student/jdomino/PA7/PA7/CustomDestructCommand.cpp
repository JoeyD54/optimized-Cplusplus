//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "CustomDestructCommand.h"
#include "OList.h"

CustomDestructCommand::CustomDestructCommand(OList *pInList)
{
	assert(pInList != nullptr);
	this->pList = pInList;
}

// This function is called in the destructor
// Use this as a reference when you create your own functor
void CustomDestructCommand::Command()
{
    // Add your code here
	delete[] this->pList->GetHead();

}

// End of File
