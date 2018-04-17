#include "ParticleSystem.h"
#include "Particle.h"
#include "Behaviour.h"
#include <iostream>
ParticleSystem::ParticleSystem()
{

}

ParticleSystem::ParticleSystem(float pX, float pY, float vCurr_min, float vCurr_max, float lifetime_min, float lifetime_max,
	float angle_min, float angle_max, float rCurr_min, float rCurr_max, float sCurr, float init_number, std::vector<Behaviour*> b, sf::Texture& tex)
{
	this->pX = pX;
	this->pY = pY;
	this->vCurr_min = vCurr_min;
	this->vCurr_max = vCurr_max;
	this->lifetime_min = lifetime_min;
	this->lifetime_max = lifetime_max;
	this->angle_min = angle_min;
	this->angle_max = angle_max;
	this->rCurr_min = rCurr_min;
	this->rCurr_max = rCurr_max;
	this->sCurr = sCurr;
	this->init_number = init_number;
	this->b = b;
	this->tex = tex;

	for (int i = 0; i < this->init_number; i++)
	{
		float vCurr = rand() % ((int)(vCurr_max * 10) - (int)(vCurr_min * 10)) / 10.0f + vCurr_min;
		float lifetime = rand() % ((int)(lifetime_max * 10) - (int)(lifetime_min * 10)) / 10.0f + lifetime_min;
		float angle = rand() % ((int)(angle_max * 10) - (int)(angle_min * 10)) / 10.0f + angle_min;
		float rCurr = rand() % ((int)(rCurr_max * 10) - (int)(rCurr_min * 10)) / 10.0f + rCurr_min;

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
	add_particle();
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
	float vFin = rand() % ((int)(vCurr_max * 10) - (int)(vCurr_min * 10)) / 10.0f + vCurr_min;
	float life_end = rand() % ((int)(lifetime_max * 10) - (int)(lifetime_min * 10)) / 10.0f + lifetime_min;
	float angle = rand() % ((int)(angle_max * 10) - (int)(angle_min * 10)) / 10.0f + angle_min;
	float rFin = rand() % ((int)(rCurr_max * 10) - (int)(rCurr_min * 10)) / 10.0f + rCurr_min;
	float sFin = p[i]->GetParameter().sFin;
	Particle::Parameters nP(pX, pY, vFin, life_end, angle, rFin, sFin);

	p[i]->SetParameter(nP);
	p[i]->shape->setSize(sf::Vector2f(0, 0));
	p[i]->shape->setOrigin(sf::Vector2f(0, 0));
	p[i]->shape->setPosition(pX, pY);

	//Values getting muddled here. vCurrocity -10000 something and same for a couple of others
	std::cout << "Am here \n";
	

}

void ParticleSystem::add_particle()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		float vCurr = rand() % ((int)(vCurr_max * 10) - (int)(vCurr_min * 10)) / 10.0f + vCurr_min;
		float lifetime = rand() % ((int)(lifetime_max * 10) - (int)(lifetime_min * 10)) / 10.0f + lifetime_min;
		float angle = rand() % ((int)(angle_max * 10) - (int)(angle_min * 10)) / 10.0f + angle_min;
		float rCurr = rand() % ((int)(rCurr_max * 10) - (int)(rCurr_min * 10)) / 10.0f + rCurr_min;

		Particle* particle = new Particle(pX, pY, vCurr, lifetime, angle, rCurr, sCurr, b, tex);
		p.push_back(particle);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
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