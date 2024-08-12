//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------
//
// NO HEADERS... do the problem in this CPP file
//
// Do Problem 4 here:
// 
// The findMaxDistance() function calculates the max distance between
//	any two players in teh passed-in player array.
// 
// Refactor it so that it ALSO calculates the minimum distance between
//	any two players.
// 
// You may change the signature of the function and the contents
//	of the function, but do not change the Vect_t structure.
//
// ---------------------------------------------------------------------------

#include <math.h>

struct Vect  // Vector struct for positions
{
	float x;
	float y;
	float z;
}; 
 
//Used to handle return codes for findDistance
enum DistStatus
{
	NO_CHANGE,
	MIN_CHANGED,
	MAX_CHANGED,
	MIN_AND_MAX_CHANGED
};

/***********************************************************************
*
*  Function: findMaxDistance()
*
*  Input:
*       int			nPlayers		- number of players
*       Vect		*playerArray	- the array of players
*		float		&outMaxDist		- reference to be updated with new max
*		float		&outMinDist		- reference to be updated with new min	
* 
*  Output:
*		DistStatus	returnStatus	- enum stating if min, max, or both were changed
*
***********************************************************************/

//function definition
//DistStatus findDistance(int nPlayers, Vect* playerArray, float& outMaxDist, float& outMinDist);

//Changed float to DistStatus
//Added DistStatus enum above
//Adding two arguments to function
//	float & inMaxDist
//	float & inMinDist
DistStatus findDistance( int nPlayers, Vect *playerArray, float &outMaxDist, float &outMinDist)
{
	int i,j;          // counter variables
	Vect tmpVect;     // temporary vector
	float tmpDist;    // temporary distance
	float maxDist;    // current max distance
	float minDist;    // current min distance

	//Create status for return. default to no change.
	DistStatus returnStatus;
	returnStatus = DistStatus::NO_CHANGE;

	bool maxChanged = false;
	bool minChanged = false;

	// initialize the max and min distance to zero
	maxDist = 0.0f;
	minDist = 0.0f;

	for( i = 0; i < nPlayers; i++ )
	{
		for( j = 0; j < nPlayers; j++ )
		{
			// Find a vector between point i and j
			tmpVect.x = playerArray[i].x - playerArray [j].x;
			tmpVect.y = playerArray[i].y - playerArray [j].y;
			tmpVect.z = playerArray[i].z - playerArray [j].z;

			// Get its length
			tmpDist = (float)sqrt( tmpVect.x * tmpVect.x 
				+ tmpVect.y * tmpVect.y 
				+ tmpVect.z * tmpVect.z );

			// determine if it’s a new maximum length
			if( tmpDist > maxDist)
			{
				// yes so keep it and change flag
				maxDist = tmpDist;
				maxChanged = true;
			}

			//do we have a new min?
			if (tmpDist < minDist)
			{
				//Yes, store it and change flag
				minDist = tmpDist;
				minChanged = true;
			}

		} //for(j)
	} // for(i)


	//Check bools to update inMax and inMin distances
	//As well as the return status.
	if (maxChanged)
	{
		returnStatus = DistStatus::MAX_CHANGED;
		outMaxDist = maxDist;
	}

	if (minChanged)
	{
		returnStatus = DistStatus::MIN_CHANGED;
		outMinDist = minDist;
	}

	//Change return status if both flags are true
	if (maxChanged && minChanged)
	{
		returnStatus = DistStatus::MIN_AND_MAX_CHANGED;
	}

	return returnStatus;

} // End of findMaxDistance()

// End of File
