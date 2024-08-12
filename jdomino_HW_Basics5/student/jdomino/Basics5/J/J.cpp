//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "J.h"

// ----------------------------------------------------------------------
//
// J - Project
//
// Rules: Fix the code to correctly print the predicted output
//        no memory leak
//
// ----------------------------------------------------------------------

Dog::Dog()
{
	pVal = new int;
}

Dog::Dog(int val)
{
	pVal = new int;
	*pVal = val;
}

Dog::Dog(const Dog& oldDog)
{
	this->pVal = new int;
	*this->pVal = *oldDog.pVal;
}

Dog::~Dog()
{
	delete pVal;
}

// Do not modify this method
int Dog::GetVal(Dog d)
{
	return *(d.pVal);
}

// End of File
