//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Particle.h"
#include "Matrix.h"

#define ROTATION_VELOCITY -0.25f

Particle::Particle()
{
	// construtor
	/*this->life = 0.0f;
	this->next = nullptr;
	this->prev = nullptr;
	this->pCold = nullptr;*/
	//this->pCold->position.set( 0.0f, 0.0f,  -10.0f );
	//this->pCold->velocity.set( -3.0f, 0.0f,  0.0f );
	//this->pCold->scale.set(1.0f, 1.0f, 1.0f);
	//this->pCold->rotation = 0.0f;
	//this->pCold->rotation_velocity = -0.25f;
	
}

Particle::~Particle()
{
	// nothing to do
}

//void Particle::CopyDataOnly( Particle *p )
//{
//	// copy the data only
//	// this way of copying data is more efficient that element by element
//	this->pCold->position = p->pCold->position;
//	this->pCold->velocity = p->pCold->velocity;
//	this->pCold->scale = p->pCold->scale;
//	this->pCold->rotation = p->pCold->rotation;
//	this->life     = p->life;
//}

void Particle::Update(const float & time_elapsed)
{
	// serious math below - magic secret sauce
	life += time_elapsed;
	position = position + (velocity * time_elapsed);
	Vect4D z_axis(0.0f, 0.0f, 3.0f);
	Vect4D v(2, 2, 0);
	position.Cross(z_axis, v);
	v.norm(v);
	/*pCold->position.Cross( z_axis);
	Vect4D v = pCold->position.Cross( z_axis);
	v.norm(v);*/
	position = position + v * 0.05f * life;

	rotation = rotation + ROTATION_VELOCITY * time_elapsed * 2;
}

// --- End of File ---
