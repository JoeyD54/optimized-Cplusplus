//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ALIGN_DATA_H
#define ALIGN_DATA_H

// -----------------------------------------------------------
// Add default constructor to each structure
// Initialize all variables to 0
// Do NOT rearrange any data layout...
// These are the classes used with Align::PrintMe();
// -----------------------------------------------------------


//8 bytes 4 byte align
struct A 
{
	A()
		:a0(0), a1(0)
	{

	}
	int  a0;
	char a1;
};




//16 bytes 4 byte align
struct B
{
	B()
		:b0(0), b1(0), b2(0), b3(0)
	{

	}
	float b0;
	float b1;
	bool  b2;
	float b3;
};

//24 bytes 8 byte aligned
struct C
{
	C()
		:c0(0), c1(0), c2(0)
	{

	}
	char   c0;		//1 byte
	double c1;		//8 bytes
	char   c2;		//1 byte
};

//64 bytes align 8 bytes
struct D
{
	D()
		:d1(0),d3(0)
	{

	}
	A      d0;		//8 bytes 4 align
	double d1;		//8 bytes
	B      d2;		//12 bytes 4 align
	char   d3;		//1 byte
	C      d4;		//24 8 align
};

//56 bytes 8 byte align
struct E
{
	E()
		:aa(0)
	{

	}
	A    a0;		//8 bytes 4 align
	C    c0;		//24 bytes 8 byte align
	char aa;		//1 byte
	B    b0;		//8 bytes 4 byte align
};

#endif

// ---  End of File ---

