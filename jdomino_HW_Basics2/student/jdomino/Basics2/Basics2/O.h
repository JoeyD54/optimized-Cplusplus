//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef O_H
#define O_H

#include "M.h"

// ----------------------------------------------------------------------
//
// Problem 4
//
// Related files:  M.h, N.h, O.h, P.h
//
// Rules: 
//     Modify the classes to pass tests
//     The class should be in a diamond inheritance pattern
//     Only one variable in (M: a,b,c,d ) no duplicates or replicas
//
//     Modify P overload constructor to pass test
//     No body allowed in P's constructor
//
//     1) Do NOT modify class M in any way
//     2) Refactor class N to pass tests
//     3) Refactor class O to pass tests
//     4) Refactor class P to pass tests
//
// ----------------------------------------------------------------------

// -----------------------------------------------------
// REFACTOR class N,O,P - MODIFY this FILE
// -----------------------------------------------------

class O : virtual public M
{
public:
	O();

	O(int aVal, int cVal);

	void foo();

	int c;
};

#endif

// --- End of File ---
