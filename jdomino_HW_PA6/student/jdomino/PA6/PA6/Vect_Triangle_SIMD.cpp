//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_TRIANGLE_SIMD.h"



Vect_TRIANGLE_SIMD::Vect_TRIANGLE_SIMD(const float tx, const float ty, const float tz, const float tw)
	:x(tx),y(ty),z(tz),w(tw)
{

}

float Vect_TRIANGLE_SIMD::Length() const
{
	//Length = sqrt(x^2 + y^2 + z^2)

	Vect_TRIANGLE_SIMD A;

	// [Ax | Ay | Az| Aw ]
	// [Ax | Ay | Az| Aw ]
	// [Ax*Ax | Ay*Ay | Az*Az | Aw*Aw ]

	//Square the values
	A._m = _mm_mul_ps(this->_m, this->_m);

	//Add them together
	// [Ax*Ax + Ay*Ay | Az*Az + Aw*Aw | Ax*Ax + Ay*Ay | Az*Az + Aw*Aw ]
	A._m = _mm_hadd_ps(A._m, A._m);

	//[Ax*Ax + Ay*Ay + Az*Az + Aw*Aw | Ax*Ax + Ay*Ay + Az*Az + Aw*Aw | Ax*Ax + Ay*Ay + Az*Az + Aw*Aw | Ax*Ax + Ay*Ay + Az*Az + Aw*Aw ]
	A._m = _mm_hadd_ps(A._m, A._m);

	//Square root them to get length
	A._m = _mm_sqrt_ss(A._m);

	return A.x;
}


/*
* Cross Product:
* 
* C.x = AyBz - ByAz
* C.y = AzBx - BzAx
* C.z = AxBy - BxAy
*/

Vect_TRIANGLE_SIMD Vect_TRIANGLE_SIMD::Cross(const Vect_TRIANGLE_SIMD &R) const
{
	Vect_TRIANGLE_SIMD A;
	Vect_TRIANGLE_SIMD B;
	Vect_TRIANGLE_SIMD T1;
	Vect_TRIANGLE_SIMD C;
	Vect_TRIANGLE_SIMD D;
	Vect_TRIANGLE_SIMD T2;
	Vect_TRIANGLE_SIMD E;

	//Shift A to be Aw, Ax, Az, Ay
	A._m = _mm_shuffle_ps(this->_m, this->_m, _MM_SHUFFLE(3, 0, 2, 1));

	//Shift B to be Bw, By, Bx, Bz
	B._m = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 1, 0, 2));

	//Multiply Aw*Bw, Ax*By, Az*Bx, Ay*Bz
	T1._m = _mm_mul_ps(A._m, B._m);

	//Do the same as above
	C._m = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 0, 2, 1));
	D._m = _mm_shuffle_ps(this->_m, this->_m, _MM_SHUFFLE(3, 1, 0, 2));
	T2._m = _mm_mul_ps(C._m, D._m);

	//Subtract the values
	E._m = _mm_sub_ps(T1._m, T2._m);

	return E;
}


/*
* Area of triangle
* 0.5 * length of Cross(T,R) 
*/
float Vect_TRIANGLE_SIMD::Area(const Vect_TRIANGLE_SIMD &T, const Vect_TRIANGLE_SIMD &R) 
{
	Vect_TRIANGLE_SIMD A;
	Vect_TRIANGLE_SIMD B;
	Vect_TRIANGLE_SIMD T1;
	Vect_TRIANGLE_SIMD C;
	Vect_TRIANGLE_SIMD D;
	Vect_TRIANGLE_SIMD T2;
	Vect_TRIANGLE_SIMD E;

	//Shift A to be Aw, Ax, Az, Ay
	A._m = _mm_shuffle_ps(T._m, T._m, _MM_SHUFFLE(3, 0, 2, 1));

	//Shift B to be Bw, By, Bx, Bz
	B._m = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 1, 0, 2));

	//Multiply Aw*Bw, Ax*By, Az*Bx, Ay*Bz
	T1._m = _mm_mul_ps(A._m, B._m);

	//Do the same as above
	C._m = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 0, 2, 1));
	D._m = _mm_shuffle_ps(T._m, T._m, _MM_SHUFFLE(3, 1, 0, 2));
	T2._m = _mm_mul_ps(C._m, D._m);

	//Subtract the values
	E._m = _mm_sub_ps(T1._m, T2._m);

	//Now find the length

	// [Ax | Ay | Az| Aw ]
	// [Ax | Ay | Az| Aw ]
	// [Ax*Ax | Ay*Ay | Az*Az | Aw*Aw ]

	//Square the values
	E._m = _mm_mul_ps(E._m, E._m);

	//Add them together
	// [Ax*Ax + Ay*Ay | Az*Az + Aw*Aw | Ax*Ax + Ay*Ay | Az*Az + Aw*Aw ]
	E._m = _mm_hadd_ps(E._m, E._m);

	//Add again to get everything together
	//[Ax*Ax + Ay*Ay + Az*Az + Aw*Aw | Ax*Ax + Ay*Ay + Az*Az + Aw*Aw | Ax*Ax + Ay*Ay + Az*Az + Aw*Aw | Ax*Ax + Ay*Ay + Az*Az + Aw*Aw ]
	E._m = _mm_hadd_ps(E._m, E._m);

	//Square root them to get length
	E._m = _mm_sqrt_ss(E._m);

	return 0.5f * E.x;

}

void Vect_TRIANGLE_SIMD::Print(const char* const p) const
{
	Trace::out("%s: %g %g %g %g\n", p, this->x, this->y, this->z, this->w);
}


// ---  End of File ---

