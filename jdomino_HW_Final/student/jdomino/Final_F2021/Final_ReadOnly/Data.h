//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef DATA_H
#define DATA_H

class Data
{
public:
	enum class name
	{
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q
	};

public:
	Data() = delete;
	Data(const Data::name name);
	Data(const Data&) = delete;
	Data& operator = (const Data&) = delete;

	// ------------------------------------------------
	// Do All work in the destructor
	// ------------------------------------------------
	~Data();

	void print();
	char* GetStringName(const Data* pData) const;

	// ------------------------------------------------
	// NOTE:  CANNOT ADD DATA to Linked List class
	// ------------------------------------------------

public:
	name   Name;
};

#endif

// --- End of File ---

