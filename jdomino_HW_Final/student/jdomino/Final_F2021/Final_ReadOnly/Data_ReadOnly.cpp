//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "Bucket.h"
#include "Item.h"
#include "Data.h"

struct DataNameTable
{
	char* pString[9];
};

DataNameTable DataTable[] =
{
	{"Data_A"},
	{"Data_B"},
	{"Data_C"},
	{"Data_D"},
	{"Data_E"},
	{"Data_F"},
	{"Data_G"},
	{"Data_H"},
	{"Data_I"},
	{"Data_J"},
	{"Data_K"},
	{"Data_L"},
	{"Data_M"},
	{"Data_N"},
	{"Data_O"},
	{"Data_P"},
	{"Data_Q"}

};

Data::Data(const Data::name name)
	:Name(name)
{
}

void Data::print()
{
	Trace::out("           ---Data--- (%p): %s  \n", this, GetStringName(this));
	Trace::out("\n");
}

char* Data::GetStringName(const Data* pData) const
{
	static char* pNull = "null    ";
	char* pName;

	if (pData == nullptr)
	{
		pName = pNull;
	}
	else
	{
		pName = *DataTable[(int)pData->Name].pString;
	}

	return pName;
}

// --- End of File ---
