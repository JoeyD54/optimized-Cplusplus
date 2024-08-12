//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_M_SIMD.h"
#include "Matrix_M_SIMD.h"

Matrix_M_SIMD::Matrix_M_SIMD(const Vect_M_SIMD &tV0,
							 const Vect_M_SIMD &tV1,
							 const Vect_M_SIMD &tV2,
							 const Vect_M_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

/*
* Matrix * Matrix
* 
* 
*/

Matrix_M_SIMD Matrix_M_SIMD::operator * (const Matrix_M_SIMD &mb) const
{ 	
	//This needs to multiply two matrices together
	//All matrices here will be 4x4.

	Vect_M_SIMD A;
	Vect_M_SIMD B;
	Vect_M_SIMD C;
	Vect_M_SIMD D;
	Vect_M_SIMD Tx;
	Vect_M_SIMD Ty;
	Vect_M_SIMD Tz;
	Vect_M_SIMD Tw;
	
	//First row

	Tx._m = _mm_set1_ps(this->v0.x);
	Ty._m = _mm_set1_ps(this->v0.y);
	Tz._m = _mm_set1_ps(this->v0.z);
	Tw._m = _mm_set1_ps(this->v0.w);

	A._m = _mm_mul_ps(Tx._m, mb.v0._m);
	B._m = _mm_mul_ps(Ty._m, mb.v1._m);
	C._m = _mm_mul_ps(Tz._m, mb.v2._m);
	D._m = _mm_mul_ps(Tw._m, mb.v3._m);

	Vect_M_SIMD Tout;

	Tout._m = _mm_add_ps(
				_mm_add_ps(
					_mm_add_ps(A._m, B._m), C._m), D._m);

	Matrix_M_SIMD finalMatrix;

	finalMatrix.v0 = Tout;

	//2nd Row

	Tx._m = _mm_set1_ps(this->v1.x);
	Ty._m = _mm_set1_ps(this->v1.y);
	Tz._m = _mm_set1_ps(this->v1.z);
	Tw._m = _mm_set1_ps(this->v1.w);

	A._m = _mm_mul_ps(Tx._m, mb.v0._m);
	B._m = _mm_mul_ps(Ty._m, mb.v1._m);
	C._m = _mm_mul_ps(Tz._m, mb.v2._m);
	D._m = _mm_mul_ps(Tw._m, mb.v3._m);

	Tout._m = _mm_add_ps(
		_mm_add_ps(
			_mm_add_ps(A._m, B._m), C._m), D._m);

	finalMatrix.v1 = Tout;

	//3rd row

	Tx._m = _mm_set1_ps(this->v2.x);
	Ty._m = _mm_set1_ps(this->v2.y);
	Tz._m = _mm_set1_ps(this->v2.z);
	Tw._m = _mm_set1_ps(this->v2.w);

	A._m = _mm_mul_ps(Tx._m, mb.v0._m);
	B._m = _mm_mul_ps(Ty._m, mb.v1._m);
	C._m = _mm_mul_ps(Tz._m, mb.v2._m);
	D._m = _mm_mul_ps(Tw._m, mb.v3._m);

	Tout._m = _mm_add_ps(
		_mm_add_ps(
			_mm_add_ps(A._m, B._m), C._m), D._m);

	finalMatrix.v2 = Tout;

	//4th row

	Tx._m = _mm_set1_ps(this->v3.x);
	Ty._m = _mm_set1_ps(this->v3.y);
	Tz._m = _mm_set1_ps(this->v3.z);
	Tw._m = _mm_set1_ps(this->v3.w);

	A._m = _mm_mul_ps(Tx._m, mb.v0._m);
	B._m = _mm_mul_ps(Ty._m, mb.v1._m);
	C._m = _mm_mul_ps(Tz._m, mb.v2._m);
	D._m = _mm_mul_ps(Tw._m, mb.v3._m);

	Tout._m = _mm_add_ps(
		_mm_add_ps(
			_mm_add_ps(A._m, B._m), C._m), D._m);

	finalMatrix.v3 = Tout;

	return finalMatrix;
}


// ---  End of File ---------------
