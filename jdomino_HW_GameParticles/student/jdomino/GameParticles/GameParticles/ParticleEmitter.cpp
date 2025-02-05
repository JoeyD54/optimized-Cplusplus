//---------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "OpenGLDevice.h"
#include "ParticleEmitter.h"
#include "Settings.h"

PerformanceTimer globalTimer;

ParticleEmitter::ParticleEmitter()
:	//start_position( 0.0f, 2.0f, 2.0f ),
	//start_velocity( -4.0f, 4.0f, 0.0f), 
	//spawn_frequency(0.00001f),		
	last_spawn(globalTimer.GetGlobalTime()),		
	last_loop(globalTimer.GetGlobalTime()),
	//max_life( MAX_LIFE ),
	//max_particles( NUM_PARTICLES ),
	last_active_particle(-1),
	//bufferCount(0),
	headParticle(nullptr),
	vel_variance(15.0f, 0.70f, -1.0f),
	pos_variance(1.50f, 0.50f, 10.0f),
	scale_variance(3.0f)
	//particle_list(NUM_PARTICLES)
{
	// nothing to do
	//bufferCount = 0;
}

ParticleEmitter::~ParticleEmitter()
{
	Particle *pTmp = this->headParticle;
	Particle* pDeleteMe = nullptr;
	while (pTmp != nullptr)
	{
		pDeleteMe = pTmp;
		pTmp = pTmp->next;
		delete pDeleteMe;
	}
}

void ParticleEmitter::SpawnParticle()
{
	// create another particle if there are ones free
	if (last_active_particle < NUM_PARTICLES - 1)
	{

		// create new particle
		Particle* newParticle = new Particle();
		//ColdParticle* newCold = new ColdParticle();

		newParticle->life = 0.0f;
		newParticle->next = nullptr;
		newParticle->prev = nullptr;
		//newParticle->pCold = nullptr;

		newParticle->position = { 0.0f, 0.0f, -10.0f };
		newParticle->velocity = { -3.0f, 0.0f, 0.0f  };
		newParticle->scale	  = { 1.0f, 1.0f, 1.0f };
		newParticle->rotation = 0.0f;

		//newParticle->pCold = newCold;
		//newCold->pParticle = newParticle;

		// initialize the particle
		newParticle->life = 0.0f;
		newParticle->position = { 0.0f, 2.0f, 2.0f };
		newParticle->velocity = { 4.0f, 4.0f, 0.0f };
		newParticle->scale = { -1.0, -1.0, -1.0, 1.0 };

		// apply the variance
		this->Execute(newParticle->position, newParticle->velocity, newParticle->scale);

		// increment count
		last_active_particle++;

		// add to list
		this->addParticleToList( newParticle );
	}
}

void ParticleEmitter::update()
{
	// get current time
	float current_time = globalTimer.GetGlobalTime();

	// spawn particles
	float time_elapsed = current_time - last_spawn;
	
	float spawn_frequency = 0.00001f;

	// update
	while(spawn_frequency < time_elapsed )
	{
		// spawn a particle
		this->SpawnParticle();
		// adjust time
		time_elapsed -= spawn_frequency;
		// last time
		last_spawn = current_time;
	}


	
	// total elapsed
	time_elapsed = current_time - last_loop;

	Particle *p = this->headParticle;
	// walk the particles

	while( p != nullptr )
	{
		// call every particle and update its position 
		p->Update(time_elapsed);

		// if life is greater that the max_life 
		// and there is some left on the list
		// remove node
		if((last_active_particle > 0) && (p->life > MAX_LIFE))
		{
			// particle to remove
			Particle *s = p;

			// need to squirrel it away.
			p=p->next;

			// remove last node
			this->removeParticleFromList( s );

			// update the number of particles
			last_active_particle--;
		}
		else
		{
			// increment to next point
			p = p->next;
		}
	}

	//move a copy to vector for faster iterations in draw
	//p = this->headParticle;
	//bufferCount = 0;

	//// clear the buffer
	//drawBuffer.clear();

	//// walk the pointers, add to list
	//while(p != 0)
	//{
	//	// add to buffer
	//	drawBuffer.push_back(*p);

	//	// advance ptr
	//	p = p->next;

	//	// track the current count
	//	bufferCount++;
	//}

	//// make sure the counts track (asserts go away in release - relax Christos)
	//assert(bufferCount == (last_active_particle+1));
	last_loop = current_time;
}
	   
void ParticleEmitter::addParticleToList(Particle *p )
{
	assert(p);
	if( this->headParticle == nullptr )
	{ // first on list
		this->headParticle = p;
		p->next = nullptr;
		p->prev = nullptr;
	}
	else 
	{ // add to front of list
		headParticle->prev = p;
		p->next = headParticle;
		p->prev = nullptr;
		headParticle = p;
	}

}

void ParticleEmitter::removeParticleFromList( Particle *p )
{
	// make sure we are not screwed with a null pointer
	assert(p);

	if (p->prev == nullptr && p->next == nullptr)
	{ // only one on the list
		this->headParticle = nullptr;
	}
	else if (p->prev == nullptr && p->next != nullptr)
	{ // first on the list
		p->next->prev = nullptr;
		this->headParticle = p->next;
	}
	else if (p->prev != nullptr && p->next == nullptr)
	{ // last on the list 
		p->prev->next = nullptr;
	}
	else//( p->next != nullptr  && p->prev !=nullptr )
	{ // middle of the list
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}


	//Delete the associated cold node if it's there
	//It always should be though
	/*if (p->pCold)
	{
		p->pCold->pParticle = nullptr;
		delete p->pCold;
		p->pCold = nullptr;
	}*/

	//if (p->prev)
	//{
	//	p->prev->next = p->next;
	//}
	//if (p->next)
	//{
	//	p->next->prev = p->prev;
	//}

	//p->next = nullptr;
	//p->prev = nullptr;
	
	// bye bye
	delete p;
}

void ParticleEmitter::draw()
{
	// initialize the camera matrix
	Matrix cameraMatrix;
	cameraMatrix.setIdentMatrix();

	// setup the translation matrix
	Matrix transMatrix;
	Vect4D trans(0.0f, 5.0f, 40.0f);
	transMatrix.setTransMatrix(&trans);
	//Trace::out("TransMatrix calling TransMatrix\n Values: %f, %f, %f\n", trans.x, trans.y, trans.z, trans.w);

	Matrix tmp;
	// multiply them together
	tmp = cameraMatrix * transMatrix;

	// get the inverse matrix
	Matrix inverseCameraMatrix;
	tmp.Inverse(inverseCameraMatrix);

	// get the position from this matrix
	Vect4D camPosVect;
	inverseCameraMatrix.get(Matrix::MatrixRow::MATRIX_ROW_3, &camPosVect);

	// camera position
	Matrix transCamera;
	transCamera.setTransMatrix(&camPosVect);
	//Trace::out("TransCamera calling TransMatrix \n Values: %f, %f, %f\n", camPosVect.x, camPosVect.y, camPosVect.z, camPosVect.w);

	// iterate throught the list of particles
	//std::list<Particle>::iterator it;
	//for( it = drawBuffer.begin(); it != drawBuffer.end(); ++it)

	Particle* pParticle = this->headParticle;
	//Life is to try and catch when pParticle has garbage data.
	while(pParticle != nullptr)
	{

		// get the position from this matrix
		Vect4D camPosVect;
		inverseCameraMatrix.get(Matrix::MatrixRow::MATRIX_ROW_3, &camPosVect);

		// camera position
		Matrix transCamera;
		transCamera.setTransMatrix(&camPosVect);
		//Trace::out("particle life: %f\n", pParticle->life);
		//Trace::out("particle Position.x: %f\n", pParticle->position.x);
		// particle position
		Matrix transParticle;
		transParticle.setTransMatrix( &pParticle->position);
		//Trace::out("TransParticle calling TransMatrix \n Values: %f, %f, %f\n", pParticle->position.x, pParticle->position.y, pParticle->position.z, pParticle->position.w);

		// rotation matrix
		Matrix rotParticle;
		rotParticle.setRotZMatrix(pParticle->rotation );

		// pivot Point
		Matrix pivotParticle;
		Vect4D pivotVect;
		pivotVect = Vect4D(1.0f, 0.0f, -10.0f) * -20.0f * pParticle->life;
		pivotParticle.setTransMatrix( &pivotVect );
		//Trace::out("pivotParticle calling TransMatrix \n Values: %f, %f, %f\n", pivotVect.x, pivotVect.y, pivotVect.z, pivotVect.w);

		// scale Matrix
		Matrix scaleMatrix;
		scaleMatrix.setScaleMatrix( &pParticle->scale );

		// total transformation of particle
		tmp = scaleMatrix * transCamera * transParticle * rotParticle * scaleMatrix;
		// ------------------------------------------------
		//  Set the Transform Matrix and Draws Triangle
		//  Note: 
		//       this method is using doubles... 
		//       there is a float version (hint)
		// ------------------------------------------------
		//OpenGLDevice::SetTransformMatrixDouble((const double *)&tmp);

		OpenGLDevice::SetTransformMatrixFloat((const float*)&tmp);

		// squirrel away matrix for next update
		/*tmp.get(Matrix::MatrixRow::MATRIX_ROW_0, &it->pCold->curr_Row0);
		tmp.get(Matrix::MatrixRow::MATRIX_ROW_1, &it->pCold->curr_Row1);
		tmp.get(Matrix::MatrixRow::MATRIX_ROW_2, &it->pCold->curr_Row2);
		tmp.get(Matrix::MatrixRow::MATRIX_ROW_3, &it->pCold->curr_Row3);*/

		// difference vector
		/*it->pCold->diff_Row0 = it->pCold->curr_Row0 - it->pCold->prev_Row0;
		it->pCold->diff_Row1 = it->pCold->curr_Row1 - it->pCold->prev_Row1;
		it->pCold->diff_Row2 = it->pCold->curr_Row2 - it->pCold->prev_Row2;
		it->pCold->diff_Row3 = it->pCold->curr_Row3 - it->pCold->prev_Row3;*/

		if (pParticle->next)
		{
			pParticle = pParticle->next;
		}
		else
		{
			pParticle = nullptr;
		}
		

	}

	// delete the buffer
	/*for( size_t i = 0; i < drawBuffer.size(); i++ )
	{
		drawBuffer.pop_back();
	}*/

	// done with buffer, clear it.
	//drawBuffer.clear();
}

void ParticleEmitter::Execute(Vect4D& pos, Vect4D& vel, Vect4D& sc)
{
	// Ses it's ugly - I didn't write this so don't bitch at me
	// Sometimes code like this is inside real commerical code ( so know you now how it feels )
	
	// x - variance
	float var = static_cast<float>(rand() % 1000) * 0.001f;
	float sign = static_cast<float>(rand() % 2);
	float *t_pos = reinterpret_cast<float*>(&pos);
	float *t_var = &pos_variance[Vect::x];
	if(sign == 0.0f)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;

	// y - variance
	var = static_cast<float>(rand() % 1000) * 0.001f;
	sign = static_cast<float>(rand() % 2);
	t_pos++;
	t_var++;
	if(sign == 0.0f)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;
	
	// z - variance
	var = static_cast<float>(rand() % 1000) * 0.001f;
	sign = static_cast<float>(rand() % 2);
	t_pos++;
	t_var++;
	if(sign == 0.0f)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;
	
	var = static_cast<float>(rand() % 1000) * 0.001f;
	sign = static_cast<float>(rand() % 2);
	
	// x  - add velocity
	t_pos = &vel[Vect::x];
	t_var = &vel_variance[Vect::x];
	if(sign == 0.0f)
	{
		var *= -1.0f;
	}
	*t_pos += *t_var * var;
	
	// y - add velocity
	var = static_cast<float>(rand() % 1000) * 0.001f;
	sign = static_cast<float>(rand() % 2);
	t_pos++;
	t_var++;
	if(sign == 0.0f)
	{
		var *= -2.0f;
	}
	*t_pos += *t_var * var;
	
	// z - add velocity
	var = static_cast<float>(rand() % 1000) * 0.001f;
	sign = static_cast<float>(rand() % 2);
	t_pos++;
	t_var++;
	if(sign == 0.0f)
	{
		var *= -2.0f;
	}
	*t_pos += *t_var * var;
	
	// correct the sign
	var = 2.0f * static_cast<float>(rand() % 1000) * 0.001f;
	sign = static_cast<float>(rand() % 2);
	
	if(sign == 0.0f)
	{
		var *= -2.0f;
	}
	sc = sc * var;
}

// --- End of File ---
