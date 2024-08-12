//--------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//--------------------------------------------------------

#include"LengthOfStrings.h"

size_t LengthOfString_1( const char  * const input)
{
	// using strlen()
	return strlen(input);
}

size_t LengthOfString_2( const char  * const input)
{
	int count = 0;

	// using char by char
	for (int i = 0; i < (int)strlen(input); i++)
	{
		count++;
	}

	return (size_t)count;
}


// ---  End of File ---

