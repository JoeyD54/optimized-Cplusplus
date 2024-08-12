//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------
//
// NO HEADERS... do the problem in this CPP file
//
// Do Problem 2 here:
// 
// Write a standalone function (not a class/method) 
//	to create a unit vector from a 3D vector.
// 
// Write a function and simple structure for the Vector (no methods)
// 
// Unit vector means length of (x, y, z) = 1
// 
// ---------------------------------------------------------------------------

#include "math.h"

struct vector
{
	float x;
	float y;
	float z;
};

struct uVector
{
	float x;
	float y;
	float z;
};

//Used for return codes
enum uVectorStatus
{
	INIT,
	FAIL_X_IS_0,
	FAIL_Y_IS_0,
	FAIL_Z_IS_0,
	FAIL_LEN_NOT_1,
	UNIT_VECTOR_CREATED
};

//Function definition
//uVectorStatus CreateUVector(float x, float y, float z, uVector &outVector);


//Get the length. if it's one, it's a unit vector
uVectorStatus CreateUVector(const vector & inVect, uVector &outVector)
{
	//init returnStatus for checks later
	uVectorStatus returnStatus;
	returnStatus = uVectorStatus::INIT;

	float x = inVect.x;
	float y = inVect.y;
	float z = inVect.z;

	//hard coded 8th decimal place for no reason other than 
	//I dunno how else to check it better
	float checkVars = 0.00000001;

	//check each var against an 8 decimal float. We'll count that close enough to 0.
	if (fabsf(x) < checkVars)
	{
		returnStatus = uVectorStatus::FAIL_X_IS_0;
	}
	if (fabsf(y) < checkVars)
	{
		returnStatus = uVectorStatus::FAIL_Y_IS_0;
	}
	if (fabsf(z) < checkVars)
	{
		returnStatus = uVectorStatus::FAIL_Z_IS_0;
	}


	//Continue if X, Y, and Z didn't shit the bed.
	if (returnStatus == uVectorStatus::INIT)
	{
		float length = 0.0;
		length = (float)sqrt(x * x + y * y + z * z);

		if (length == 1)
		{
			//WE'RE A UNIT VECTOR BABY!
			returnStatus = uVectorStatus::UNIT_VECTOR_CREATED;

			outVector.x = x;
			outVector.y = y;
			outVector.z = z;
		}
		else
		{
			returnStatus = uVectorStatus::FAIL_LEN_NOT_1;
		}
	}

	return returnStatus;
}


// End of File
