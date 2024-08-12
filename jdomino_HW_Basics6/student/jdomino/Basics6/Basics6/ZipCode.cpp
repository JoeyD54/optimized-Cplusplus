//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "ZipCode.h"

// ----------------------------------
// MODIFY this file
// ----------------------------------

// add code here if you want

// Just stubbed out
bool ZipCode::operator < (const ZipCode& ) const
{
// Hint: do some work


	return(true);
}

bool ZipCode::operator==(const ZipCode& in)
{
	if (strcmp(this->s, in.s) == 0 && this->zip == in.zip)
	{
		return true;
	}
	return false;
}


// ---  End of File ---
