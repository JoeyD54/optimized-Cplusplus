//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "HotDog.h"

// -----------------------------------------------
// AZUL_REPLACE_ME_STUB
// this is place holder for compiling purposes
// Delete each AZUL_REPLACE_ME_STUB line
// Replace with your own code
// -----------------------------------------------


//Default Constructor
HotDog::HotDog()
{
	this->condiments = (unsigned int) 0;
	this->nextHotDog = nullptr;
	this->prevHotDog = nullptr;
}

//Copy constructor
HotDog::HotDog(const HotDog& tempHotDog)
{
	this->condiments = (unsigned int) tempHotDog.condiments; 
	this->nextHotDog = nullptr;
	this->prevHotDog = nullptr;	
}

//Assignment operator
HotDog & HotDog::operator = (const HotDog& tempHotDog)
{
	this->condiments = (unsigned int) tempHotDog.condiments;
	this->nextHotDog = nullptr;
	this->prevHotDog = nullptr;

	return *this;
}

//Destructor
HotDog::~HotDog()
{

}

// Methods

void HotDog::Minus(const Condiments condiment)
{
	// Only use bit-wise operations
	unsigned int condimentBit = (unsigned int) condiment;
	this->condiments &= ~condimentBit;
}

void HotDog::MinusUnsigned(const unsigned int condimentBit)
{
	this->condiments &= ~condimentBit;
}

void HotDog::Add(const Condiments condiment)
{
	// Only use bit-wise operations
	unsigned int condimentBit = (unsigned int) condiment;
	this->condiments |= condimentBit;
}

void HotDog::AddUnsigned(unsigned int condimentBit)
{
	this->condiments |= condimentBit;
}

unsigned int HotDog::GetCondiments() const
{
	return this->condiments;
}

HotDog * const HotDog::GetNext() const
{
	return this->nextHotDog;
}

HotDog * const HotDog::GetPrev() const
{
	return this->prevHotDog;
}

void HotDog::SetNext(HotDog *pDog)
{
	this->nextHotDog = pDog;
}

void HotDog::SetPrev(HotDog *pDog)
{
	this->prevHotDog = pDog;
}


// ---  End of File ---------------

