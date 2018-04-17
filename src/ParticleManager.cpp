#include "ParticleSystem.h"
#include "ParticleManager.h"
#include "Behaviour.h"
#include <stdio.h>

ParticleManager::ParticleManager()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (rand() % 5)
			{
			case 0:
				b[j] = new EaseInOutExpo();
				break;
			case 1:
				b[j] = new EaseOutCubic();
				break;
			case 2:
				b[j] = new LinearDown();
				break;
			case 3:
				b[j] = new Uniform();
				break;
			case 4:
				b[j] = new EaseInOut();
				break;
			}
			b_collection[i].push_back(b[j]);
		}
	}

	tex1.loadFromFile("C:/Users/Akshay/Desktop/CBoot/t1.png");
	tex2.loadFromFile("C:/Users/Akshay/Desktop/CBoot/t2.png");
	tex3.loadFromFile("C:/Users/Akshay/Desktop/CBoot/t3.png");


	ParticleSystem* pm1 = new ParticleSystem(300, 300, 2, 6, 3, 5, 0, 360, 0, 90, 20, 50, b_collection[0], tex1);
	pm.push_back(pm1);
	ParticleSystem* pm2 = new ParticleSystem(800, 500, 2, 4, 2, 6, -180, 0, -120, 0, 100, 30, b_collection[1], tex2);
	pm.push_back(pm2);


}

ParticleManager::~ParticleManager()
{
	for (int i = 0; i < pm.size(); i++)
	{
		ParticleSystem* temp = pm[i];
		pm.erase(pm.begin() + i);
		delete temp;
		temp = nullptr;
	}
	for (int i = 0; i < 3; i++)
	{
		delete b[i];
		b[i] = nullptr;
	}
}

void ParticleManager::update_state()
{
	for (int i = 0; i < pm.size(); i++)
	{
		pm[i]->update();
	}
}

void ParticleManager::render_frame(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	for (int i = 0; i < pm.size(); i++)
	{
		pm[i]->draw(window);
	}
}