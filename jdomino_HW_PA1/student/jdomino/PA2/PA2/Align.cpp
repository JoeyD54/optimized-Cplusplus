//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Align.h"

//-------------------------------------------------------------
// PrintME()
//
// Write your alignment printing function here
//-------------------------------------------------------------

Align::Info Align::PrintME(void *pData, int StructSize, char *pString)
{
	// Use Trace::out2(...) to display the data layout and padding

        // NOTE:   out2() NOT out()
        //         it won't be graded without out2()

	// Mimic the KeenanSampleOutput_Debug.txt

        // EXACtLY or the grading system will give a 0
	
	/*Output like so :
	* 
	* data (pData):				
	*   0x00: 00 00 00 00		//NOTE: two spaces at start of hex
	*   0x04: 00 00 00 00		//Increment hex count with a count or some other way
	*	0x08: 00 00 00 00		//and so on...until
	* ------------------------	//Copied from Ed's output. Need exact amount of dashes
	* size : 0  padding : 0		//Get the padding size by counting the 'aa's
	* 
	* store size and padding into given variables
	* 	int NumTotalBytes;
	*	int NumBytesOfPadding;
	*   
	*/

	int padCount = 0;

	unsigned char* pDataPoint;

	pDataPoint = (unsigned char*) pData;

	//Start the print layout
	Trace::out2("%s:", pString);

	//Step through structure to display and count size & pad
	for (int i = 0; i < StructSize; i++)
	{
		if (i % 4 == 0)
		{
			Trace::out2("\n  0x%02x: ", i);
		}

		Trace::out2("%02x ", pDataPoint[i]);

		if (pDataPoint[i] == 170)
		{
			padCount++;
		}
	}

	Trace::out2("\n------------------------\n");
	Trace::out2("size : %d  padding : %d\n", StructSize, padCount);

	Info info;
	info.NumBytesOfPadding = padCount;
	info.NumTotalBytes = StructSize;

	return info;
}

// ---  End of File ---

