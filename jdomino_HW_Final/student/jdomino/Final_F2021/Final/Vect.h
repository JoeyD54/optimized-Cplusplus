//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef VECT_H
#define VECT_H

#include "CDM.h"
#include "Proxy.h"

// --------------------------------------------------------------------------------------------------------------------------------------
//  Please REFACTOR Vect class, feel free to add/delete/modify any method.
//          Add a Proxy structures/classes to accomplish the goal:
//                Len() method should _NOT_ call CDM::Sqrt() for comparison operators
//                                  ==, !=, >, >=, <, <=     (no sqrt() calls allowed)
//                float val = A.Len();    ( is allowed to call CDM::Sqrt() )
//          You will need to change the existing code and refactor.
// ---------------------------------------------------------------------------------------------------------------------------------------

struct VectProxy
{
	VectProxy(float xIn, float yIn, float zIn)
		:x(xIn), y(yIn), z(zIn)
	{
		//Trace::out("Proxy: Constructor\n");
		length = x * x + y * y + z * z; 

	};

	//This is to return the length
	operator float()
	{
		return CDM::Sqrt(length);
	}


	bool operator == (const VectProxy& r)
	{
		//Trace::out("Proxy: operator == called\n");
		return (this->length == r.length);
	}
	bool operator != (const VectProxy& r)
	{
		//Trace::out("Proxy: operator != called\n");
		return (this->length != r.length);
	}
	bool operator > (const VectProxy &r)
	{
		//Trace::out("Proxy: operator > called\n");
		return (this->length > r.length);
	}
	bool operator >= (const VectProxy& r)
	{
		//Trace::out("Proxy: operator >= called\n");
		return (this->length >= r.length);
	}
	bool operator < (const VectProxy& r)
	{
		//Trace::out("Proxy: operator < called\n");
		return (this->length < r.length);
	}
	bool operator <= (const VectProxy& r)
	{
		//Trace::out("Proxy: operator <= called\n");
		return (this->length <= r.length);
	}


	//Vect vp1;
	float x;
	float y;
	float z;
	float length;
};

// -------------------------------------------------------
// Must use CDM::Sqrt() for sqrt in Vect or Proxy class
//--------------------------------------------------------
class Vect
{
public:
	Vect() = default;
	Vect(const Vect &) = default;
	Vect &operator = (const Vect &) = default;
	~Vect() = default;

	Vect(float a, float b, float c);

	// -------------------------------------------------------
	// Must use CDM::Sqrt() for sqrt in Vect or Proxy class
	//--------------------------------------------------------

	// Add or modify methods here:
	//float Len();
	VectProxy Len();
	

// ------------------------------------------
// Data:  (do not add or modify the data)
// ------------------------------------------
private:
	float x;
	float y;
	float z;

	friend struct VectProxy;

};

#endif

// ---  End of File ---

