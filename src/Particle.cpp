#include "Particle.h"
#include "Behaviour.h"
#include <vector>
#include <math.h>

Particle::Particle()
{

}


void Particle::SetParameter(Parameters & parameters)
{
	m_P = parameters;
}
Particle::Parameters Particle::GetParameter() const
{
	return m_P;
}


Particle::Particle(float cpX, float cpY, float cvFin, float clifetime, float cangle,
	float crFin, float csFin, std::vector<Behaviour*> cb, sf::Texture& ctex)
{
	m_P.pX = cpX;
	m_P.pY = cpY;
	m_P.vFin = cvFin;
	m_P.lifetime = clifetime;
	m_P.angle = cangle;
	m_P.rFin = crFin;
	m_P.sFin = csFin;
	b = cb;

	m_P.time = 0.0f;

	shape = new sf::RectangleShape;
	shape->setSize(sf::Vector2f(m_P.sFin, m_P.sFin));
	shape->setOrigin(sf::Vector2f(m_P.sFin / 2, m_P.sFin / 2));
	shape->setPosition(sf::Vector2f(m_P.pX, m_P.pY));
	shape->setTexture(&ctex);

}

Particle::~Particle()
{
	delete shape;
	shape = nullptr;
}

void Particle::update()
{
	m_P.time += 1.0f / 60.0f;

	m_P.sCurr = m_P.sFin * b[1]->behave(m_P.time / m_P.lifetime);
	shape->setSize(sf::Vector2f(m_P.sCurr, m_P.sCurr));
	shape->setOrigin(sf::Vector2f(m_P.sCurr / 2, m_P.sCurr / 2));

	sf::Vector2f pos = shape->getPosition();
	m_P.vCurr = m_P.vFin * b[0]->behave(m_P.time / m_P.lifetime);
	pos.x += m_P.vCurr * cosf(m_P.angle * 3.1415926f / 180.0f);
	pos.y += m_P.vCurr * sinf(m_P.angle * 3.1415926f / 180.0f);
	shape->setPosition(pos);

	m_P.rCurr = m_P.rFin * b[2]->behave(m_P.time / m_P.lifetime);
	shape->setRotation(m_P.rCurr);
}

void Particle::draw(sf::RenderWindow& window)
{
	window.draw(*shape);
}