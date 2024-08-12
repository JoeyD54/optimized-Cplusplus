//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef STL_SORT_H
#define STL_SORT_H

#include <vector>
#include "vData.h"

void SortMe(const std::vector< vData >& vIn,
				  std::vector< vData >& vOut);

void SortStruct(vData & vIn);

#endif

// ---  End of File ---
