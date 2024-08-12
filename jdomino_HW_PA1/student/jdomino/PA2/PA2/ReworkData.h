//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef REWORK_DATA_H
#define REWORK_DATA_H

//Need to padd out the storage for each structure based off of the longest variable in each


//16 bytes 8 byte aligned
struct DataA
{
	double r;		//8 bytes
	char a;			//1 byte
	char b;			//1 bytes
	char pad0;		//Need to padd out 6 bytes to fit the rest of the 8byte length
	char pad1;
	char pad2;
	char pad3;
	char pad4;
	char pad5;
};

//24 bytes 8 byte aligned
struct DataB
{
	DataA da;		//16 bytes
	int i;			//4 bytes
	char a;			//1 byte
	char b;			//1 byte
	char pad0;		//padd 2 bytes
	char pad1;		
};

//12 byte 4 byte aligned
struct DataC
{
	int j;			//4 bytes
	int i;			//4 bytes
	char a;			//1 byte
	bool f;			//1 byte
	char pad0;		//padd 2 bytes
	char pad1;
};

//16 byte 8 byte aligned
struct DataD
{
	double r;		//8 bytes
	int i;			//4 bytes
	char a;			//1 bytes
	char b;			//1 byte
	char pad0;		//padd 2 bytes
	char pad2;
};

//24 byte 8 byte aligned
struct DataE
{
	double r;		//8 bytes
	char name[12];	//4 bytes
	int x;			//4 bytes
	int* p;			//4 bytes
	char a;			//1 byte
	char c;			//1 byte
	char pad0;		//pad 2 bytes
	char pad1;
};

//20 byte 4 byte aligned
struct Vect
{
	float vx;		//4 bytes
	float vy;		//4 bytes
	float vz;		//4 bytes
	float vw;		//4 bytes
	char a;			//1 byte
	char b;			//1 byte
	char pad0;		//pad 2
	char pad1;
};

//32 bytes 4 byte align
struct DataF
{
	Vect v;			//20 bytes 
	int i;			//4 bytes
	int j;			//4 bytes
	char c;			//1 byte
	char b;			//1 byte
	char pad0;		//pad 2 bytes
	char pad1;
};

//56 bytes 8 byte align
struct DataG
{
	double d0;		//8 bytes
	double d1;		//8 bytes
	DataA a0;		//16 bytes
	Vect  v;		//20 bytes
	char  b0;		//1 byte
	char  c0;		//1 byte
	char pad0;		//pad 2 bytes
	char pad1;

};



#endif

// ---  End of File ---

