//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "Node.h"

Node::Node()
{
	this->pNext = nullptr;
	this->privFillBuff();
	this->key = this->privGetInt();
}

void Node::privFillBuff()
{
	unsigned char *p = this->buffer;
	for(int i = 0; i < COUNT; i++)
	{
		*p++ = this->privGetChar();
	}
}

unsigned int Node::privGetInt()
{
	unsigned char a = privGetChar();
	unsigned char b = privGetChar();
	unsigned char c = privGetChar();
	unsigned char d = privGetChar();

	unsigned int var = (unsigned int) (d << 24 | c << 16 | b << 8 | a);
	return var;
}

unsigned char Node::privGetChar() const
{
	// Generate 0x00-0xFF
	unsigned char var = static_cast<unsigned char> (rand() % 256);
	return var;
}

// ---  End of File ---
