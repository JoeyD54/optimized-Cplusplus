//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef CDM_H
#define CDM_H

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

class CDM
{
public:
	CDM(const CDM &) = delete;
	CDM &operator = (const CDM &) = delete;
	~CDM() = default;

	static int GetSqrtCount();

	// USE this in Vect and Proxy classes
	static float Sqrt(float x);


	// ------------------------------------------
	// Data:  (do not add or modify the data)
	// ------------------------------------------
private:
	int sqrtCount;

	CDM();

	static CDM *psInstance;
	static CDM *GetInstance();

};

#endif

// ---  End of File ---

