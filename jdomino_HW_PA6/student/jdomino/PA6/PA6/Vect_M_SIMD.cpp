//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_M_SIMD.h"
#include "Matrix_M_SIMD.h"

Vect_M_SIMD::Vect_M_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

void Vect_M_SIMD::Print(const char* const p) const
{
	Trace::out("%s: %3.8g %3.8g %3.8g %3.8g\n", p, this->x, this->y, this->z, this->w);
}

// ---  End of File ---------------


