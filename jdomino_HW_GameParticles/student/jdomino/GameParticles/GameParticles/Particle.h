//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef PARTICLE_H
#define PARTICLE_H

// include
#include "Vect4D.h"


class Particle : Align16
{
public:
	friend class ParticleEmitter;
	
	Particle();	
	~Particle();
	void Update(const float& time_elapsed);
	//void CopyDataOnly( Particle *p );
private:
	Particle	  *next;
	Particle	  *prev;
	//ColdParticle  *pCold;

	Vect4D		  position;
	Vect4D		  velocity;
	Vect4D		  scale;

	float		  rotation;

	float		  life;

};

#endif 

// --- End of File ---
