//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "P.h"

// Add code here if needed

P::P()
	: d(44)
{
}

P::P(int aVal, int bVal, int cVal, int dVal)
	: M(aVal), N(aVal, bVal), O(aVal, cVal), d(dVal)
{
	// No body allowed
	// Only initialize with initializer list
}

void P::foo()
{
}

// --- End of File ---
