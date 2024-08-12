//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef PROXY_H
#define PROXY_H

#include "Vect.h"

// -------------------------------------------------------
// Must use CDM::Sqrt() for sqrt in Vect or Proxy class
//--------------------------------------------------------

// Add proxy here

//struct VectProxy
//{
//	VectProxy(float xIn, float yIn, float zIn)
//		:x(xIn), y(yIn), z(zIn)
//	{
//		//Trace::out("Proxy: Constructor\n");
//		length = x * x + y * y + z * z;
//
//	};
//
//	//This is to return the length
//	operator float()
//	{
//		return CDM::Sqrt(length);
//	}
//
//
//	bool operator == (const VectProxy& r)
//	{
//		//Trace::out("Proxy: operator == called\n");
//		return (this->length == r.length);
//	}
//	bool operator != (const VectProxy& r)
//	{
//		//Trace::out("Proxy: operator != called\n");
//		return (this->length != r.length);
//	}
//	bool operator > (const VectProxy& r)
//	{
//		//Trace::out("Proxy: operator > called\n");
//		return (this->length > r.length);
//	}
//	bool operator >= (const VectProxy& r)
//	{
//		//Trace::out("Proxy: operator >= called\n");
//		return (this->length >= r.length);
//	}
//	bool operator < (const VectProxy& r)
//	{
//		//Trace::out("Proxy: operator < called\n");
//		return (this->length < r.length);
//	}
//	bool operator <= (const VectProxy& r)
//	{
//		//Trace::out("Proxy: operator <= called\n");
//		return (this->length <= r.length);
//	}
//
//
//	//Vect vp1;
//	float x;
//	float y;
//	float z;
//	float length;
//};

#endif

// ---  End of File ---


