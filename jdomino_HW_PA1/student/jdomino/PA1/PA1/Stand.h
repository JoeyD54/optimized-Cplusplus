//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef STAND_H
#define STAND_H

// Add files include as needed
#include "Names.h"
#include "Order.h"

class Stand
{
public:
	// add code here (add more methods if desired)

	//Default Constructor
	Stand();

	//Assignment Operator
	Stand& operator = (const Stand& tempStand);

	~Stand();

	// Public Methods (Required)
	void Remove(const Name name);
	void Add(Order * const pOrder);
	int GetCurrOrders() const;
	int GetPeakOrders() const;
	
	// Methods used for Testing and Internals (Required)
	Order * const GetHead();


private:
	// Data: ---------------------------
	//        add data here
	Order* currentOrder;
	Order* headOrder;

	int countOrders;
	int peakOrders;


};

#endif

//---  End of File ---
