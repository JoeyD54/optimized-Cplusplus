//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef NYBLE_H
#define NYBLE_H

// Feel free to add extra methods in the class
// You need to explicitly define and implement the Big four operators
// Do not add extra data in class
// Do not add code here (that goes in *.cpp)

class Nyble
{
public:
	// insert your code here

	//Default constructor
	Nyble();

	//Copy Constructor
	Nyble(const Nyble&);
	
	//Assignment operator
	Nyble& operator = (const Nyble& tempNyble);

	//Specialized Constructor
	Nyble(unsigned int x);
	
	//Destructor
	~Nyble();

	//Add in Binary operators

	//Nyble + constant
	friend Nyble operator + (const Nyble& passedNyble, const int x);
	//constant + Nyble
	friend Nyble operator + (const int x, const Nyble & passedNyble);
	//Nyble + Nyble
	friend Nyble operator + (const Nyble & passedNyble, const Nyble & passedNyble2);
	//Nyble += Nyble
	friend Nyble operator += (Nyble & passedNyble, const Nyble & passedNyble2);

	//Add in Unary operators

	//~operator
	friend Nyble operator ~ (const Nyble& passedNyble);

	//+operator
	friend Nyble operator + (const Nyble & passedNyble);
	
	//casting operator to an unsigned int
	operator unsigned int() const;

	//pre-increment ++
	friend Nyble& operator ++ (Nyble & passedNyble);
	//post-increment ++
	friend Nyble operator ++ (Nyble & passedNyble, int);
	//operator <<
	friend Nyble operator << (const Nyble& passedNyble, int amountToShift);


	unsigned char getData();

private:

	//for bitmask checks
	//unsigned int top4Bits = 240;
    // Do not change this data
	unsigned char data;

};

#endif

//---  End of File ---
