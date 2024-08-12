//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Mv_SIMD.h"
#include "Matrix_Mv_SIMD.h"

Matrix_Mv_SIMD::Matrix_Mv_SIMD(const Vect_Mv_SIMD &tV0,
							   const Vect_Mv_SIMD &tV1,
							   const Vect_Mv_SIMD &tV2,
							   const Vect_Mv_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

Vect_Mv_SIMD Matrix_Mv_SIMD::operator * (const Vect_Mv_SIMD &v) const
{

	//This will work the same as MxM, but the second M will be the same values over and over
	
//First row

	Vect_Mv_SIMD A;

	A._m = _mm_mul_ps(this->v0._m, v._m);
	A._m = _mm_hadd_ps(A._m, A._m);
	A._m = _mm_hadd_ps(A._m, A._m);

	Vect_Mv_SIMD finalVector;

	finalVector.x = A.x;

	A._m = _mm_mul_ps(this->v1._m, v._m);
	A._m = _mm_hadd_ps(A._m, A._m);
	A._m = _mm_hadd_ps(A._m, A._m);

	finalVector.y = A.y;

	A._m = _mm_mul_ps(this->v2._m, v._m);
	A._m = _mm_hadd_ps(A._m, A._m);
	A._m = _mm_hadd_ps(A._m, A._m);

	finalVector.z = A.z;

	A._m = _mm_mul_ps(this->v3._m, v._m);
	A._m = _mm_hadd_ps(A._m, A._m);
	A._m = _mm_hadd_ps(A._m, A._m);

	finalVector.w = A.w;

	return finalVector;

}


void Vect_Mv_SIMD::Print(const char* const p) const
{
	Trace::out("%s: %3.8g %3.8g %3.8g %3.8g\n", p, this->x, this->y, this->z, this->w);
}


// ---  End of File ---------------
