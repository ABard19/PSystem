#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

class Particle;
class Behaviour;

class ParticleSystem
{
public:
	ParticleSystem();
	ParticleSystem(float pX, float pY, float vCurr_min, float vCurr_max, float lifetime_min, float lifetime_max,
		float angle_min, float angle_max, float rCurr_min, float rCurr_max, float sCurr, float init_number, std::vector<Behaviour*> b, sf::Texture& tex);
	~ParticleSystem();

	void update();
	void draw(sf::RenderWindow& window);


	float pX;
	float pY;
	float vCurr_min;
	float vCurr_max;
	float lifetime_min;
	float lifetime_max;
	float angle_min;
	float angle_max;
	float rCurr_min;
	float rCurr_max;
	float init_number;
	float sCurr;
	sf::Texture tex;

private:
	std::vector<Particle*> p;
	std::vector<Behaviour*> b;

	void reset(int i);
	void addParticle();
};