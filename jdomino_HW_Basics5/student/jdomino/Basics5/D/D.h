//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef D_H
#define D_H

// ----------------------------------------------------------------------
// Problem 7:
//
// Rules: Fix the code below to have the correct number of components in Car
// ----------------------------------------------------------------------

class Car
{
public:
	enum class Color
	{
		Green,
		Yellow,
		Blue,
		Red,
		Black,
		White
	};

	int	numDoors;
	int	wings;
	int	wheelDrive;
	Color color;
};

class Volkswagon : public Car
{
public:
	Volkswagon();
	~Volkswagon() = default;
};

class Audi : public Volkswagon
{
public:
	Audi();
	~Audi() = default;

};

#endif

// End of File
