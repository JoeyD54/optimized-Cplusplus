//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef Vect_Row_SIMD_H
#define Vect_Row_SIMD_H

#include <xmmintrin.h>
#include <smmintrin.h>  

class Matrix_Row_SIMD;

// -----------------------------------------------------------------------
// Rules: 
//    Implement for Row Major
//    No implementation in Header
//
//    Proxy (optional)
//    
//        Proxies are the only thing that can have the keyword "inline"
//            inline only for subsitution resolving.. that's it
//                No constructors or other operators... only proxy for substituion purpose
//            example:  (this is allowed)
//                inline vM operator * (const Vect_Row_SIMD &v, const Matrix_Row_SIMD &m)
//        No proxy implementation in header
//            conversion operator needs to be implemented in CPP file
//            proxy constructors are allowed in header (only exception)
// -----------------------------------------------------------------------

class Vect_Row_SIMD
{
public:
	Vect_Row_SIMD() = default;
	Vect_Row_SIMD(const Vect_Row_SIMD &tmp) = default;
	Vect_Row_SIMD &operator = (const Vect_Row_SIMD &tmp) = default;
	~Vect_Row_SIMD() = default;

	Vect_Row_SIMD(const float tx, const float ty, const float tz, const float tw);

	Vect_Row_SIMD operator * ( const Matrix_Row_SIMD &ma);

public:

	// anonymous union
	union
	{
		__m128	_m;

		// anonymous struct
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
};

#endif

// ---  End of File ---------------
