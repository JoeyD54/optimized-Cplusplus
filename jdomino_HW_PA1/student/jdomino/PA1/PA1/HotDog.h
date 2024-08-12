//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef HOTDOG_H
#define HOTDOG_H

// Add files include as needed
#include "Condiments.h"

class HotDog
{
public:
	// add code here (add more methods if desired)
	
	//Default Constructor
	HotDog();

	//Copy Constructor
	HotDog(const HotDog& tempHotDog);

	//Assignment Operator
	HotDog & operator = (const HotDog& tempHotDog);

	//Destructor
	~HotDog();

	//For Order.cpp
	void AddUnsigned(unsigned int condiment);
	void MinusUnsigned(unsigned int condiment);

	 
	// Public Methods (Required)
	void Minus(const Condiments condiment);
	void Add(const Condiments condiment);

	// Methods for Testing and Internals (Required)
	unsigned int GetCondiments() const;
	HotDog * const GetNext() const;
	HotDog * const GetPrev() const;
	void SetNext(HotDog * const pDog);
	void SetPrev(HotDog * const pDog);
	
	// Debugging
	void Print(int num = -1, int numTabs = 0) const;

private:
	// Data: ---------------------------
	//        add data here
	//
	// add links (next/prev)... 
	//
	// use the condiments unsigned integer provided
	// no additional data for condiments
	//

	//Nodes for prev/next
	HotDog* nextHotDog;
	HotDog* prevHotDog;

	//DO NOT CHANGE THIS
	unsigned int condiments;
};

#endif

//---  End of File ---
