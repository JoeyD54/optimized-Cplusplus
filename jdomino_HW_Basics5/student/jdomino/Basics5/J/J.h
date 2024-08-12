//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef J_H
#define J_H

class Dog
{
public:

	Dog();
	Dog(const Dog&);
	Dog(int val);
	~Dog();

	static int GetVal(Dog d);

private:
	int* pVal;
};

#endif

// End of File
