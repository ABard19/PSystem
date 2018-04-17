#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include "Behaviour.h"

class ParticleSystem;


class ParticleManager
{
public:
	ParticleManager();
	~ParticleManager();

	void Update();
	void Draw(sf::RenderWindow& window);

private:
	std::vector<ParticleSystem*> pm;

	Behaviour* b[5];
	std::vector<Behaviour*> b_collection[5];

	sf::Texture tex1;
	sf::Texture tex2;
	sf::Texture tex3;
};