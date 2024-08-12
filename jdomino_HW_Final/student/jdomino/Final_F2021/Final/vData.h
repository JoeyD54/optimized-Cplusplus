//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef V_DATA_H
#define V_DATA_H

struct vData
{
	vData() = default;
	vData(const vData &) = default;
	vData& operator = (const vData &) = default;
   ~vData() = default;

	// Add methods here:

// ------------------------------------------
// Data:  (do not add or modify the data)
// ------------------------------------------
	int a;
	int b;
	int c;
	int d;
	int e;
};

#endif

// ---  End of File ---
