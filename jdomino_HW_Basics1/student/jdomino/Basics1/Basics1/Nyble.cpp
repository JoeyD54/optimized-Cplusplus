//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Nyble.h"

//Default Constructor
Nyble::Nyble()
{
	this->data = (unsigned int)0;
}

//Specialized Constructor
Nyble::Nyble(unsigned int x)
{
	//240 is 11110000 in binary. Mask against that
	this->data = (unsigned int)0;
	this->data |= (unsigned char) x;
	this->data &= ~(unsigned char) 240;
}


//Copy Constructor
Nyble::Nyble(const Nyble& tempNyble)
{
	this->data = tempNyble.data;
}

//Assignment operator
Nyble & Nyble::operator = (const Nyble& tempNyble)
{
	this->data = (unsigned int)0;
	this->data |= tempNyble.data;

	return *this;
}

//Destructor
Nyble::~Nyble()
{
	this->data = (unsigned char)0;
}

//Nyble + constant
Nyble operator + (const Nyble& passedNyble, const int x)
{
	unsigned int temp = 0;

	temp |= (unsigned int)passedNyble.data;
	temp |= x;

	//240 is 1111 0000 in binary.
	//This is to make sure you don't go over halfword
	temp &= ~(unsigned int)240;

	return (unsigned char) temp;
}

//constant + Nyble
Nyble operator + (const int x, const Nyble& passedNyble)
{
	unsigned int temp = 0;

	temp |= (unsigned int)passedNyble.data;
	temp += x;

	//240 is 1111 0000 in binary.
	//This is to make sure you don't go over halfword
	temp &= ~(unsigned int)240;

	return (unsigned char)temp;
}

//Nyble + Nyble
Nyble operator + (const Nyble & passedNyble, const Nyble & passedNyble2)
{
	unsigned int tempNyble = passedNyble.data;
	tempNyble += passedNyble2.data;
	tempNyble &= ~(unsigned int)240;
	
	return (unsigned char) tempNyble;
}

//+= Nyble operator
Nyble operator += (Nyble& passedNyble, const Nyble & passedNyble2)
{
	unsigned int nyble1 = passedNyble.data;
	nyble1 += passedNyble2.data;
	nyble1 &= ~(unsigned int)240;

	passedNyble.data = (unsigned char) nyble1;
	


	return passedNyble;
}

//~ operator
Nyble operator ~ (const Nyble & passedNyble)
{
	unsigned int complementBit;

	complementBit = (unsigned int) ~passedNyble.data;

	return complementBit;
}

//+operator
Nyble operator + (const Nyble & passedNyble)
{	
	unsigned int temp = passedNyble.data;

	temp = temp + 3;

	return temp;
}

//casting operator to an unsigned int
Nyble::operator unsigned int() const
{
	unsigned int temp = this->data;

	temp -= 3;

	return (unsigned int) temp;
}

//pre-increment ++
Nyble & operator ++(Nyble & passedNyble)
{
	passedNyble.data++;
	//240 is 1111 0000 in binary.
	//This is to make sure you don't go over halfword
	passedNyble.data &= ~(unsigned int)240;

	return passedNyble;
}

//post-increment ++
Nyble operator ++ (Nyble & passedNyble, int)
{	
	unsigned int temp = passedNyble.data;
	++passedNyble;

	//240 is 1111 0000 in binary.
	//This is to make sure you don't go over halfword
	passedNyble.data &= ~(unsigned int)240;

	return temp;
}

//operator <<
Nyble operator << (const Nyble& passedNyble, int amountToShift)
{

	//Check for wraparounds
	// Do so by catching 240 like above
	// If caught, remove it
	// append 1

	unsigned int shiftedBit;
	unsigned int wrapChecker = 16;

	shiftedBit = passedNyble.data;

	//Check for need to wrap
	for (int i = 1; i <= amountToShift; i++)
	{
		//Step through. Shift one at a time
		shiftedBit = shiftedBit << 1;

		//Can't be 10000. WRAP TIME!!
		if (shiftedBit >= 16)
		{
			//Clear the 16 bit
			shiftedBit -= wrapChecker;

			//Add 1
			shiftedBit++;
		}
	}

	//return shifted data
	return shiftedBit;
}



unsigned char Nyble::getData()
{
	return this->data;
}


//---  End of File ---
