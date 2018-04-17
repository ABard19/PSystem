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

	void update_state();
	void render_frame(sf::RenderWindow& window);

private:
	std::vector<ParticleSystem*> pm;

	Behaviour* b[6];
	std::vector<Behaviour*> b_collection[6];

	sf::Texture tex1;
	sf::Texture tex2;
	sf::Texture tex3;
};