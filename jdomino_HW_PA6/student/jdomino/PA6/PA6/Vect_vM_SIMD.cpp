//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_vM_SIMD.h"
#include "Matrix_vM_SIMD.h"

Vect_vM_SIMD::Vect_vM_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

//------------------------------
// For No proxy:
//------------------------------

Vect_vM_SIMD Vect_vM_SIMD::operator * (const Matrix_vM_SIMD &ma) const
{
	Vect_vM_SIMD A;
	Vect_vM_SIMD B;
	Vect_vM_SIMD C;
	Vect_vM_SIMD D;
	Vect_vM_SIMD Tx;
	Vect_vM_SIMD Ty;
	Vect_vM_SIMD Tz;
	Vect_vM_SIMD Tw;
	
	Tx._m = _mm_set1_ps(this->x);
	Ty._m = _mm_set1_ps(this->y);
	Tz._m = _mm_set1_ps(this->z);
	Tw._m = _mm_set1_ps(this->w);

	A._m = _mm_mul_ps(Tx._m, ma.v0._m);
	B._m = _mm_mul_ps(Ty._m, ma.v1._m);
	C._m = _mm_mul_ps(Tz._m, ma.v2._m);
	D._m = _mm_mul_ps(Tw._m, ma.v3._m);

	Vect_vM_SIMD T1;
	Vect_vM_SIMD T2;
	Vect_vM_SIMD Tout;

	T1._m = _mm_add_ps(A._m, B._m);
	T2._m = _mm_add_ps(C._m, D._m);
	Tout._m = _mm_add_ps(T1._m, T2._m);

	return Tout;
};

void Vect_vM_SIMD::Print(const char* p) const
{
	Trace::out("%s: %3.9g %3.9g %3.9g %3.9g\n", p, this->x, this->y, this->z, this->w);
}


// ---  End of File ---------------


