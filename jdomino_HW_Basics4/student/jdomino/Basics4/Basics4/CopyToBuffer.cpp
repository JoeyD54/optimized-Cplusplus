//--------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//--------------------------------------------------------

#include "CopyToBuffer.h"

// retrieve the message
char * Dog::GetMessage()
{
	return this->buff;
}
	
// user sets the message
void Dog::SetMessage( const char * const inMessage )
{
	// Do the copy to internal variable buff
	// make sure it's safe
	// ----> do work here

	this->buff[0] = '\0';

	if (inMessage)
	{
		for (int i = 0; i < this->BUFF_SIZE-1; i++)
		{
			//newChar[i] = inMessage[i];
			this->buff[i] = inMessage[i];
			
			//newChar[i + 1] = '\0';
			this->buff[i+1] = '\0';
		}
	}


	//AZUL_REPLACE_ME(inMessage);
}

// prints the mesage
void Dog::Print()
{
	Trace::out2("message: %s\n",this->buff);
}

Dog::Dog()
{
	memset( this->buff, 0xaa, BUFF_SIZE );
}

Dog::~Dog()
{
	memset( this->buff, 0xaa, BUFF_SIZE );
}


// ---  End of File ---
