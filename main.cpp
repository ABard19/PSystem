#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <time.h>

#include "ParticleManager.h"

int main()
{
	srand((unsigned)time(0));
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Particle System");
	float accumulatedTime = 0.0f;
	ParticleManager* ps = new ParticleManager();


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		float dt = clock.restart().asSeconds();
		accumulatedTime += dt;

		while (accumulatedTime >= 1.0f / 60.0f)
		{
			ps->update_state();
			accumulatedTime -= 1.0f / 60.0f;
		}
		ps->render_frame(window);
		window.display();
	}

	delete ps;
	ps = nullptr;

	return 0;
}