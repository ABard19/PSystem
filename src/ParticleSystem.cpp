#include "ParticleSystem.h"
#include "Particle.h"
#include "Behaviour.h"
#include <iostream>
ParticleSystem::ParticleSystem()
{

}


ParticleSystem::ParticleSystem(float cpX, float cpY, float cvCurr_min, float cvCurr_max, float clifetime_min, float clifetime_max,
	float cangle_min, float cangle_max, float crCurr_min, float crCurr_max, float csCurr, float cinit_number, std::vector<Behaviour*> cb, sf::Texture& ctex)
{
	pX = cpX;
	pY = cpY;
	vCurr_min = cvCurr_min;
	vCurr_max = cvCurr_max;
	lifetime_min = clifetime_min;
	lifetime_max = clifetime_max;
	angle_min = cangle_min;
	angle_max = cangle_max;
	rCurr_min = crCurr_min;
	rCurr_max = crCurr_max;
	sCurr = csCurr;
	init_number = cinit_number;
	b = cb;
	tex = ctex;

	for (int i = 0; i < this->init_number; i++)
	{
		float vCurr =1+ (rand() % ((int)(vCurr_max) - (int)(vCurr_min)) /vCurr_min);
		float lifetime =1+ (rand() % ((int)(lifetime_max) - (int)(lifetime_min)) /lifetime_min);
		float angle =1+ (rand() % ((int)(angle_max) - (int)(angle_min)) /  angle_min);
		float rCurr =1+ (rand() % ((int)(rCurr_max) - (int)(rCurr_min)) / rCurr_min);

		Particle* particle = new Particle(pX, pY, vCurr, lifetime, angle, rCurr, sCurr, b, tex);
		p.push_back(particle);
	}



}

ParticleSystem::~ParticleSystem()
{
	for (int i = 0; i < p.size(); i++)
	{
		Particle* temp = p[i];
		p.erase(p.begin() + i);
		delete temp;
		temp = nullptr;
	}
}

void ParticleSystem::update()
{
	addParticle();
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i]->GetParameter().time<= p[i]->GetParameter().lifetime)
		{
			p[i]->update();
		}
		else
		{
			reset(i);
		}
	}
}

void ParticleSystem::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < p.size(); i++)
	{
		p[i]->draw(window);
	}
}

void ParticleSystem::reset(int i)
{
	// TODO check access bounds for i in p[];

	float vFin = 1 + rand() % 7; 
	float life_end = 1 + rand() % 7;
	float angle = -120 + rand() % 120;
	float rFin= -120 + rand() % 120;
	float sFin = 3+rand()%10; 

	if (i == 1)
	{
		angle = 30;
	}

	Particle::Parameters nP(pX, pY, vFin, life_end, angle, rFin, sFin);
	nP.time = 0;
	p[i]->SetParameter(nP);
	p[i]->shape->setSize(sf::Vector2f(0, 0));
	p[i]->shape->setOrigin(sf::Vector2f(0, 0));
	p[i]->shape->setPosition(nP.pX, nP.pY);


	//Values getting muddled here. vCurrocity -10000 something and same for a couple of others
		

}

void ParticleSystem::addParticle()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
	{
		float vCurr =1+ rand() % ((int)(vCurr_max ) - (int)(vCurr_min)) /  vCurr_min;
		float lifetime =1+ rand() % ((int)(lifetime_max) - (int)(lifetime_min )) /  lifetime_min;
		float angle =1+ rand() % ((int)(angle_max ) - (int)(angle_min )) /  angle_min;
		float rCurr =1+ rand() % ((int)(rCurr_max) - (int)(rCurr_min)) /  rCurr_min;

		Particle* particle = new Particle(pX, pY, vCurr, lifetime, angle, rCurr, sCurr, b, tex);
		p.push_back(particle);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
	{
		if (p.size() >= 1)
		{
			int i = (int)p.size() - 1;
			Particle* temp = p[i];
			p.erase(p.begin() + i);
			delete temp;
			temp = nullptr;
		}
	}
}