//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Vect4D.h"


Vect4D::Vect4D()
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
	this->w = 1.0;
}

Vect4D::Vect4D(float tx, float ty, float tz, float tw)
{
	this->x = tx;
	this->y = ty;
	this->z = tz;
	this->w = tw;
}

Vect4D::~Vect4D()
{
	// nothing to delete
}

void Vect4D::norm(Vect4D &out)
{
	float mag = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);

	if(0.0f < mag)
	{
		out.x = this->x / mag;
		out.y = this->y / mag;
		out.z = this->z / mag;
		out.w = 1.0;
	}
}

Vect4D Vect4D::operator + (Vect4D t)
{
	return Vect4D(x + t.x, y + t.y, z + t.z);
}

float &Vect4D::operator[](Vect e)
{
	switch(e)
	{
	case Vect::x:
		return x;
		break;
	case Vect::y:
		return y;
		break;
	case Vect::z:
		return z;
		break;
	case Vect::w:
		return w;
		break;
	default:
		assert(0);
		return x;
	}
}

Vect4D Vect4D::operator *(float s)
{
	return Vect4D(x * s, y * s, z * s);
}

Vect4D Vect4D::operator - (Vect4D t)
{
	return Vect4D(x - t.x, y - t.y, z - t.z);
}

void Vect4D::Cross(Vect4D &vin, Vect4D &vout)
{
	vout.x = this->y * vin.z - vin.y * this->z;
	vout.y = this->z * vin.x - vin.z * this->x;
	vout.z = this->x * vin.y - vin.x * this->y;
	vout.w = 1.0f;

	/*return Vect4D(this->y * vin.z - vin.y * this->z,
		this->z * vin.x - vin.z * this->x,
		this->x * vin.y - vin.x * this->y,
		0.0f
	);*/
	//Vect4D A;
	//Vect4D B;
	//Vect4D T1;
	//Vect4D C;
	//Vect4D D;
	//Vect4D T2;
	//Vect4D E;

	////Shift A to be Aw, Ax, Az, Ay
	//A._m = _mm_shuffle_ps(this->_m, this->_m, _MM_SHUFFLE(3, 0, 2, 1));

	////Shift B to be Bw, By, Bx, Bz
	//B._m = _mm_shuffle_ps(vin._m, vin._m, _MM_SHUFFLE(3, 1, 0, 2));

	////Multiply Aw*Bw, Ax*By, Az*Bx, Ay*Bz
	//T1._m = _mm_mul_ps(A._m, B._m);

	////Do the same as above
	//C._m = _mm_shuffle_ps(vin._m, vin._m, _MM_SHUFFLE(3, 0, 2, 1));
	//D._m = _mm_shuffle_ps(this->_m, this->_m, _MM_SHUFFLE(3, 1, 0, 2));
	//T2._m = _mm_mul_ps(C._m, D._m);

	////Subtract the values
	//E._m = _mm_sub_ps(T1._m, T2._m);

	//vout.x = E.x;
	//vout.y = E.y;
	//vout.z = E.z;
	//vout.w = E.w;
}

void Vect4D::set(float tx, float ty, float tz, float tw)
{
	this->x = tx;
	this->y = ty;
	this->z = tz;
	this->w = tw;
}

// --- End of File ---
