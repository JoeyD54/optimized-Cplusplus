//--------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//--------------------------------------------------------

#include "ComparingStrings.h"

int StringCompare_1( const char  * const s1, const char * const s2)
{
	// using strcmp()
	return strcmp(s1, s2);
}

int StringCompare_2( const char  * const s1, const char * const s2)
{
	// using memcmp() & strlen()
	return memcmp(s1, s2, strlen(s1));
}

int StringCompare_3( const char  * const s1, const char * const s2)
{	
	//char* s1Internal = (char*) s1;
	// using char by char comparisions
	for (int i = 0; i < (int) strlen(s1); i++)
	{
		//Make sure not null
		if (s1)
		{
			if (s1[i] < s2[i])
			{
				return -1;
			}
			if (s1 == s2)
			{
				return 0;
			}
		}
		else
		{
			return 1;
		}
	}

	return 1;
}


// ---  End of File ---
