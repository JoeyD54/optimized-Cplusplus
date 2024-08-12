//--------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//--------------------------------------------------------

#include "CopyingStrings.h"

char *StringCopy_1( char * const dest, const char * const input)
{
	// using strcpy()
	strcpy_s(dest, strlen(input)+1, input);
	return dest;
}

char *StringCopy_2( char  * const dest, const char * const input)
{
	// using memcpy() and strlen()
	size_t destSize = strlen(input)+1;
	memcpy(dest, input, destSize);
	return dest;
}

char* StringCopy_3(char* const dest, const char* const input)
{
	char* inputPtr = (char*) input;

	for (int i = 0; i < (int)strlen(input); i++)
	{
		dest[i] = (char)inputPtr[i];

		dest[i + 1] = '\0';
	}

	inputPtr = nullptr;
	return dest;
}


// ---  End of File ---
