//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef RVO_H
#define RVO_H

// Modify This File

class Vect2D
{
public:
	Vect2D();
	~Vect2D();

	Vect2D(const float inX, const float inY);

	Vect2D(const Vect2D &tmp) = default;

	void setX(const float inX);
	void setY(const float inY);

	void set(const float inX, const float inY);

	float getX() const;
	float getY() const;

	//*********************************************************************
	// Convert these methods to Return Value Optimization
	//*********************************************************************

	Vect2D operator + (const Vect2D &tmp) const;
	Vect2D operator - (const Vect2D &tmp) const;
	Vect2D operator * (const float scale) const;
	Vect2D operator / (const float scale) const;

private:
	float x;
	float y;

};

#endif

// ---  End of File ---------------
