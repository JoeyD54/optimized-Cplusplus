//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Monkey.h"

//int x;
//int y;
//char* pStatus;

//Initialize integers
int Monkey::numStringsCreated;
int Monkey::numStringsDestroyed;

Monkey::Monkey() 
{
	unsigned int stringLen = strlen("This string was initialized by a default constructor!") + 1;

	//the () means we're using the default constructor
	this->pStatus = new char[stringLen]();

	//Make sure the memory was allocated.
	assert(this->pStatus != nullptr);

	strcpy_s(this->pStatus, stringLen, "This string was initialized by a default constructor!");

	this->numStringsCreated += 1;

	this->x = 888;
	this->y = 999;
}


Monkey::~Monkey()
{
	delete[] this->pStatus;
	this->numStringsDestroyed += 1;
}

Monkey::Monkey(const Monkey& tempMonkey)
{
	unsigned int stringLen = strlen(tempMonkey.pStatus)+1;
	

	//the () means we're using the default constructor
	this->pStatus = new char[stringLen]();

	//Make sure the memory was allocated.
	assert(this->pStatus != nullptr);

	strcpy_s(this->pStatus, stringLen, tempMonkey.pStatus);

	this->x = tempMonkey.x;
	this->y = tempMonkey.y;
	this->numStringsCreated += 1;
}

Monkey::Monkey(int _x, int _y)
{
	unsigned int stringLen = strlen("ThIs tring was initilized by a clever user!") + 1;

	//the () means we're using the default constructor
	this->pStatus = new char[stringLen]();

	//Make sure the memory was allocated.
	assert(this->pStatus != nullptr);

	strcpy_s(this->pStatus, stringLen, "ThIs tring was initilized by a clever user!");

	this->x = _x;
	this->y = _y;
	this->numStringsCreated += 1;
}

Monkey & Monkey::operator = (const Monkey& tempMonkey)
{
	if (this != &tempMonkey)
	{


		delete[] this->pStatus;
		this->numStringsDestroyed += 1;

		unsigned int stringLen = strlen(tempMonkey.pStatus) + 1;

		//the () means we're using the default constructor
		this->pStatus = new char[stringLen]();

		//Make sure the memory was allocated.
		assert(this->pStatus != nullptr);

		strcpy_s(this->pStatus, stringLen, tempMonkey.pStatus);

		this->x = tempMonkey.x;
		this->y = tempMonkey.y;
		this->numStringsCreated += 1;
	}

	return *this;
}

int Monkey::getX()
{
	return this->x;
}

int Monkey::getY()
{
	return this->y;
}

char *Monkey::getStatus()
{
	return this->pStatus;
};

void Monkey::printStatus()
{
	Trace::out("Monkey (Status): %s\n", this->pStatus);
}


//---  End of File ---
