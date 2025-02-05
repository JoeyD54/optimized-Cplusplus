//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef Vect4D_H
#define Vect4D_H

// includes
#include "Enum.h"
#include <xmmintrin.h>
#include <smmintrin.h> 

// Foward Declarations
class Matrix;

// class
class Vect4D : public Align16
{
public:
	friend class Matrix;

	Vect4D();
	Vect4D(float tx, float ty, float tz, float tw = 1.0f);
	~Vect4D();

	void Cross(Vect4D &vin, Vect4D &vout);
	float &operator[](Vect e);
	void norm(Vect4D &out);
	void set(float tx, float ty, float tz, float tw = 1.0f);

	Vect4D operator * (float scale);
	Vect4D operator - (Vect4D t);
	Vect4D operator + (Vect4D t);

public:
	union
	{
		__m128 _m;

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

// --- End of File ---
