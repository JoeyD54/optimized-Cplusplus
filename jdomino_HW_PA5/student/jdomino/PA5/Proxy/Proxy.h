//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef PROXY_H
#define PROXY_H

// Modify This File

class Vect2D
{
public:
	Vect2D(const Vect2D &tmp) = default;
	Vect2D &operator =( const Vect2D &tmp) = default;
	Vect2D() = default;
	~Vect2D() = default;

	Vect2D(const float inX, const float inY);

	void setX(const float inX);
	void setY(const float inY);
	void set(const float inX, const float inY);

	float getX() const;
	float getY() const;

	//-----------------------------------------------
	// Rules   this function cannot be inlined 
	//         or implemented directly
	//-----------------------------------------------
	//  Vect2D operator + (const Vect2D &tmp) const;
	//-----------------------------------------------

private:
	float x;
	float y;

	//-----------------------------------------------
	// Add friends here... if you want (hint)
	//-----------------------------------------------

	friend struct VaddV;
	friend struct VaddVaddV;
	friend struct Vadd4V;
	friend struct Vadd5V;
	friend struct Vadd6V;
	friend struct Vadd7V;
	friend struct Vadd8V;
	friend struct Vadd9V;
	friend struct Vadd10V;
};

struct VaddV
{
	const Vect2D& v1;
	const Vect2D& v2;

	VaddV(const Vect2D& tempV1, const Vect2D& tempV2)
		:v1(tempV1), v2(tempV2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x,
			v1.y + v2.y);
	}
};

inline VaddV operator + (const Vect2D& vect1, const Vect2D& vect2)
{
	return VaddV(vect1, vect2);
}


//Adding a third argument

struct VaddVaddV
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;

	VaddVaddV(const VaddV& tempVaddV1, const Vect2D& tempV2)
		:v1(tempVaddV1.v1), v2(tempVaddV1.v2), v3(tempV2)  {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x,
			v1.y + v2.y + v3.y);
	}
};

inline VaddVaddV operator + (const VaddV& vaddV1, const Vect2D& vect2)
{
	return VaddVaddV(vaddV1, vect2);
}


//4 arguments

struct Vadd4V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;

	Vadd4V(const VaddVaddV& tempVaddVaddV1, const Vect2D& tempV2)
		:v1(tempVaddVaddV1.v1), v2(tempVaddVaddV1.v2), v3(tempVaddVaddV1.v3), v4(tempV2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x,
			v1.y + v2.y + v3.y + v4.y);
	}
};

inline Vadd4V operator + (const VaddVaddV& vaddVaddV1, const Vect2D& vect2)
{
	return Vadd4V(vaddVaddV1, vect2);
}

//5 arguments

struct Vadd5V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;
	const Vect2D& v5;

	Vadd5V(const Vadd4V& tempVadd4V1, const Vect2D& tempV2)
		:v1(tempVadd4V1.v1), v2(tempVadd4V1.v2), v3(tempVadd4V1.v3), v4(tempVadd4V1.v4), v5(tempV2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x,
			v1.y + v2.y + v3.y + v4.y + v5.y);
	}
};

inline Vadd5V operator + (const Vadd4V& vadd4V1, const Vect2D& vect2)
{
	return Vadd5V(vadd4V1, vect2);
}


//6 arguments

struct Vadd6V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;
	const Vect2D& v5;
	const Vect2D& v6;

	Vadd6V(const Vadd5V& tempVadd5V1, const Vect2D& tempV2)
		:v1(tempVadd5V1.v1), v2(tempVadd5V1.v2), v3(tempVadd5V1.v3), v4(tempVadd5V1.v4), v5(tempVadd5V1.v5),
		v6(tempV2){};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x + v6.x,
			v1.y + v2.y + v3.y + v4.y + v5.y + v6.y);
	}
};

inline Vadd6V operator + (const Vadd5V& vadd5V1, const Vect2D& vect2)
{
	return Vadd6V(vadd5V1, vect2);
}


//7 arguments

struct Vadd7V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;
	const Vect2D& v5;
	const Vect2D& v6;
	const Vect2D& v7;

	Vadd7V(const Vadd6V& tempVadd6V1, const Vect2D& tempV2)
		:v1(tempVadd6V1.v1), v2(tempVadd6V1.v2), v3(tempVadd6V1.v3), v4(tempVadd6V1.v4), v5(tempVadd6V1.v5),
		v6(tempVadd6V1.v6), v7(tempV2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x + v6.x + v7.x,
			v1.y + v2.y + v3.y + v4.y + v5.y + v6.y + v7.y);
	}
};

inline Vadd7V operator + (const Vadd6V& vadd6V1, const Vect2D& vect2)
{
	return Vadd7V(vadd6V1, vect2);
}


//8 arguments

struct Vadd8V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;
	const Vect2D& v5;
	const Vect2D& v6;
	const Vect2D& v7;
	const Vect2D& v8;

	Vadd8V(const Vadd7V& tempVadd7V1, const Vect2D& tempV2)
		:v1(tempVadd7V1.v1), v2(tempVadd7V1.v2), v3(tempVadd7V1.v3), v4(tempVadd7V1.v4), v5(tempVadd7V1.v5),
		v6(tempVadd7V1.v6), v7(tempVadd7V1.v7), v8(tempV2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x + 
			v6.x + v7.x + v8.x,
			
			v1.y + v2.y + v3.y + v4.y + v5.y + v6.y + 
			v7.y + v8.y);
	}
};

inline Vadd8V operator + (const Vadd7V& vadd7V1, const Vect2D& vect2)
{
	return Vadd8V(vadd7V1, vect2);
}


//9 arguments

struct Vadd9V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;
	const Vect2D& v5;
	const Vect2D& v6;
	const Vect2D& v7;
	const Vect2D& v8;
	const Vect2D& v9;

	Vadd9V(const Vadd8V& tempVadd8V1, const Vect2D& tempV2)
		:v1(tempVadd8V1.v1), v2(tempVadd8V1.v2), v3(tempVadd8V1.v3), v4(tempVadd8V1.v4), v5(tempVadd8V1.v5),
		v6(tempVadd8V1.v6), v7(tempVadd8V1.v7), v8(tempVadd8V1.v8), v9(tempV2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x +
			v6.x + v7.x + v8.x + v9.x,

			v1.y + v2.y + v3.y + v4.y + v5.y + v6.y +
			v7.y + v8.y + v9.y);
	}
};

inline Vadd9V operator + (const Vadd8V& vadd8V1, const Vect2D& vect2)
{
	return Vadd9V(vadd8V1, vect2);
}

//10 arguments

struct Vadd10V
{
	const Vect2D& v1;
	const Vect2D& v2;
	const Vect2D& v3;
	const Vect2D& v4;
	const Vect2D& v5;
	const Vect2D& v6;
	const Vect2D& v7;
	const Vect2D& v8;
	const Vect2D& v9;
	const Vect2D& v10;

	Vadd10V(const Vadd9V& tempVadd9V1, const Vect2D& tempV2)
		:v1(tempVadd9V1.v1), v2(tempVadd9V1.v2), v3(tempVadd9V1.v3), v4(tempVadd9V1.v4), v5(tempVadd9V1.v5),
		v6(tempVadd9V1.v6), v7(tempVadd9V1.v7), v8(tempVadd9V1.v8), v9(tempVadd9V1.v9), v10(tempV2) {};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x +
			v6.x + v7.x + v8.x + v9.x + v10.x,

			v1.y + v2.y + v3.y + v4.y + v5.y + v6.y +
			v7.y + v8.y + v9.y + v10.y);
	}
};

inline Vadd10V operator + (const Vadd9V& vadd9V1, const Vect2D& vect2)
{
	return Vadd10V(vadd9V1, vect2);
}



#endif

// ---  End of File ---------------