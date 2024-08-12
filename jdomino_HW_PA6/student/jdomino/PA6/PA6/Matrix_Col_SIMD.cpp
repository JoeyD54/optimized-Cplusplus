//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Col_SIMD.h"
#include "Matrix_Col_SIMD.h"

Matrix_Col_SIMD::Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
								 const Vect_Col_SIMD &tV1,
								 const Vect_Col_SIMD &tV2,
								 const Vect_Col_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

Vect_Col_SIMD Matrix_Col_SIMD::operator * (const Vect_Col_SIMD &vb)
{
	AZUL_REPLACE_ME(vb);
	return Vect_Col_SIMD();
}

Matrix_Col_SIMD Matrix_Col_SIMD::operator * (const Matrix_Col_SIMD &mb)
{
	AZUL_REPLACE_ME(mb);
	return Matrix_Col_SIMD();
}

//Need poxies for each matrix until a vector is found

struct MM
{
	const Matrix_Col_SIMD m1;
	const Matrix_Col_SIMD m2;

	MM(const Matrix_Col_SIMD m1In, const Matrix_Col_SIMD& m2In)
		: m1(m1In), m2(m2In) {};
};

struct M2M
{
	const Matrix_Col_SIMD m1;
	const Matrix_Col_SIMD m2;
	const Matrix_Col_SIMD m3;
	
	M2M(const MM& mmIn, const Matrix_Col_SIMD& mIn)
		: m1(mmIn.m1), m2(mmIn.m2), m3(mIn) {};
};

struct M3M
{
	const Matrix_Col_SIMD m1;
	const Matrix_Col_SIMD m2;
	const Matrix_Col_SIMD m3;
	const Matrix_Col_SIMD m4;

	M3M(const M2M& m2mIn, const Matrix_Col_SIMD& mIn)
		: m1(m2mIn.m1), m2(m2mIn.m2), m3(m2mIn.m3), m4(mIn) {};
};

struct M4M
{
	const Matrix_Col_SIMD m1;
	const Matrix_Col_SIMD m2;
	const Matrix_Col_SIMD m3;
	const Matrix_Col_SIMD m4;
	const Matrix_Col_SIMD m5;

	M4M(const M3M& m3mIn, const Matrix_Col_SIMD& mIn)
		: m1(m3mIn.m1), m2(m3mIn.m2), m3(m3mIn.m3), m4(m3mIn.m4), m5(mIn) {};
};

struct M5V
{
	const Matrix_Col_SIMD m1;
	const Matrix_Col_SIMD m2;
	const Matrix_Col_SIMD m3;
	const Matrix_Col_SIMD m4;
	const Matrix_Col_SIMD m5;
	const Vect_Col_SIMD v;

	M5V(const M4M& m4mIn, Vect_Col_SIMD& vIn)
		: m1(m4mIn.m1), m2(m4mIn.m2), m3(m4mIn.m3), m4(m4mIn.m4), m5(m4mIn.m5), v(vIn) {};
};




// ---  End of File ---------------
