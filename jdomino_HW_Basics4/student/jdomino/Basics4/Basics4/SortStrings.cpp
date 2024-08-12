//--------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//--------------------------------------------------------

#include "SortStrings.h"


int ReOrder(const void* first, const void* second)
{
	const char* firstChar = *(const char**)first;
	const char* secondChar = *(const char**)second;

	//int firstCharLen = strlen(firstChar);
	//int secondCharLen = strlen(secondChar);

	int order = 0;

	order = strcmp(firstChar, secondChar);

	return order;


	/*if (firstCharLen != secondCharLen) 
	{
		return strcmp(firstChar, secondChar);
	}
	else
	{

	}*/

	//if (firstChar > secondChar)
	//{
	//	return +1;
	//}
	//else if (firstChar < secondChar)
	//{
	//	return -1;
	//}
	//else
	//{
	//	return 0;
	//}
}


void ReorderAlphabetical(const char * const inString, char * const outString )
{
	// 1) reorder the words in the string, words are separated with spaces
	// 2) sort words on alphabetical order, (a begin, z end)
	// 3) you don't know how many words 
	// 4) if dynamically create any buffers inside this routine, clean them up
	// 5) use strtok and strcat in your answer
	// 6) YOU need to use qsort() - might be a good function to know

	//Steps to do this
	//Separate words in a loop using strtok
	//Qsort them in the order desired
		//Reapply them with strcat inside qsort?


	//Step 1. Split up the words by spaces
	char* inString2 = new char[strlen(inString)+1];
	strcpy_s(inString2, strlen(inString)+1, inString);

	//size_t inStringSize = strlen(inString) + 1;
	char* token = nullptr;
	char* next_token;
	char* tokenArray[sizeof(inString)+1];


	token = strtok_s(inString2, " ", &next_token);
	tokenArray[0] = token;

	int i = 1;

	while (token != nullptr)
	{
		token = strtok_s(nullptr, " ", &next_token);

		tokenArray[i] = token;
		tokenArray[i + 1] = '\0';

		i++;
	}

	//next_token = nullptr;

	int arraySize = sizeof(tokenArray) / sizeof(tokenArray[0]);

	Trace::out("In string is %s\n", inString);

	//Step 2. Sort them with qSort
	qsort(tokenArray, (size_t)arraySize, sizeof(tokenArray[0]), ReOrder);

	
	//Step 3. use strcat to store into output.
	i = 0;
	outString[i] = '\0';
	size_t outSize = strlen(inString) + 1;;

	while (tokenArray[i] != nullptr)
	{
		strcat_s(outString, outSize, tokenArray[i]);
		if (tokenArray[i + 1] != nullptr)
		{
			strcat_s(outString, outSize, " ");
		}

		i++;
	}
	
	Trace::out("Out string is now %s\n", outString);

	//Cleanup
	delete inString2;
	token = nullptr;
	inString2 = nullptr;
	next_token = 0;

	free(tokenArray);

	//i = 0;
	//while (i < arraySize)
	//{
	//	tokenArray[i] = 0;
	//	i++;
	//}

}



void ReorderWordLength(const char * const inString, char * const outString )
{
	// 1) reorder the words in the string, words are separated with spaces
	// 2) sort words on their word length order, (short, longest)
	// 3) you don't know how many words 
	// 4) if dynamically create any buffers inside this routine, clean them up
	// 5) use strtok and strcat in your answer
	// 6) You need to use qsort() - might be a good function to know

	AZUL_REPLACE_ME(outString);
	AZUL_REPLACE_ME(inString);
}


// ---  End of File ---
