//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef D_H
#define D_H

#include <string.h>

// REFACTOR this header to make it work
//     HINT: a few very small little changes are needed

// minimum of two values of any type (call-by-reference)
template <typename T>
const T &minD(T const& a, T const& b)
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

// minimum of two C-strings (call-by-pointer)
const char * const& minD(const char * const& a,const char * const& b)
{
	if (strcmp(a, b) > 0)
	{
		return b;
	}
	else
	{
		return a;
	}
}

// minimum of three values of any type (call-by-reference)
template <typename T>
const T &minD(T const &a, T const &b, T const &c)
{
	return minD(minD(a, b), c);
}


#endif

// ---  End of File ---------------
