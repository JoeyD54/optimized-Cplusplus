//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Row_SIMD.h"
#include "Matrix_Row_SIMD.h"

Vect_Row_SIMD::Vect_Row_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

Vect_Row_SIMD Vect_Row_SIMD::operator * ( const Matrix_Row_SIMD &ma)
{
	Vect_Row_SIMD A;
	Vect_Row_SIMD B;
	Vect_Row_SIMD C;
	Vect_Row_SIMD D;
	Vect_Row_SIMD Tx;
	Vect_Row_SIMD Ty;
	Vect_Row_SIMD Tz;
	Vect_Row_SIMD Tw;

	Tx._m = _mm_set1_ps(this->x);
	Ty._m = _mm_set1_ps(this->y);
	Tz._m = _mm_set1_ps(this->z);
	Tw._m = _mm_set1_ps(this->w);

	A._m = _mm_mul_ps(Tx._m, ma.v0._m);
	B._m = _mm_mul_ps(Ty._m, ma.v1._m);
	C._m = _mm_mul_ps(Tz._m, ma.v2._m);
	D._m = _mm_mul_ps(Tw._m, ma.v3._m);

	Vect_Row_SIMD T1;
	Vect_Row_SIMD T2;
	Vect_Row_SIMD Tout;

	T1._m = _mm_add_ps(A._m, B._m);
	T2._m = _mm_add_ps(C._m, D._m);
	Tout._m = _mm_add_ps(T1._m, T2._m);

	return Tout;
};


// ---  End of File ---------------


