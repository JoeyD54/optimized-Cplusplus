//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect.h"



// -------------------------------------------------------
// Must use CDM::Sqrt() for sqrt in Vect or Proxy class
//--------------------------------------------------------

//float Vect::Len()
//{
//	float len;
//	len = CDM::Sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
//	return len;
//}

VectProxy Vect::Len()
{
	//Trace::out("Work::Len()\n");
	return VectProxy(this->x, this->y, this->z);
};

Vect::Vect(float a, float b, float c)
	: x(a),
	y(b),
	z(c)
{

}

// ---  End of File ---

