//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef Vect_M_SIMD_H
#define Vect_M_SIMD_H

#include <xmmintrin.h>
#include <smmintrin.h>  

class Matrix_M_SIMD;

// -----------------------------------------------------------------------
// Rules: 
//    No implementation in Header
//    No inline keyword
// -----------------------------------------------------------------------

class Vect_M_SIMD
{
public:
	Vect_M_SIMD() = default;
	Vect_M_SIMD(const Vect_M_SIMD &tmp) = default;
	Vect_M_SIMD &operator = (const Vect_M_SIMD &tmp) = default;
	~Vect_M_SIMD() = default;

	Vect_M_SIMD(const float tx, const float ty, const float tz, const float tw);

	void Print(const char* const p) const;

public:

	union
	{
		__m128	_m;

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
