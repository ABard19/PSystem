#include "ParticleSystem.h"
#include "ParticleManager.h"
#include "Behaviour.h"
#include <stdio.h>




ParticleManager::ParticleManager()
{
	for (int i = 0; i < 3; i++)
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

	tex1.loadFromFile("C:/Users/Akshay/Desktop/PS/resources/t1.png");
	tex2.loadFromFile("C:/Users/Akshay/Desktop/PS/resources/t2.png");
	tex3.loadFromFile("C:/Users/Akshay/Desktop/PS/resources/t3.png");

	//Random generation of values for PSystem

	float pX = 50 + rand() % 750; float pY = 50 + rand() % 750; float pX1 = 50 + rand() % 750; float pY1 = 50 + rand() % 750; float pX2 = 50 + rand() % 750; float pY2 = 50 + rand() % 750;
	float vMin = 1 + rand() % 7; float vMax = vMin + 1+rand() % 5; float vMin1 = 1 + rand() % 7; float vMax1 = vMin1 + 1+rand() % 5; float vMin2 = 1 + rand() % 7; float vMax2 = vMin2 + 1+rand() % 5;
	float lMin= 1 + rand() % 7; float lMax = vMin + 1 + rand() % 5; float lMin1 = 1 + rand() % 7; float lMax1 = vMin1 + 1 + rand() % 5; float lMin2 = 1 + rand() % 7; float lMax2 = vMin2 + 1 + rand() % 5;
	float nop = 20 + rand() % 50; float nop1 = 20 + rand() % 50; float nop2 = 20 + rand() % 50;
	float sMin = 3 + rand() % 25; float sMax = sMin + 1 + rand() % 10; float sMin1 = 7 + rand() % 25; float sMax1 = sMin1 + 1 + rand() % 10; float sMin2 = 5 + rand() % 25; float sMax2 = sMin2 + 1 + rand() % 10;
	
	ParticleSystem* pm1 = new ParticleSystem(250, 250, vMin, vMax, lMin, lMax, 0, 360, 0, 90, sMin, nop, b_collection[0], tex1);
	pm.push_back(pm1);
	ParticleSystem* pm2 = new ParticleSystem(500, 500, vMin1, vMax1, lMin1, lMax1, -90, 90, -120, 120, sMin1,  nop1, b_collection[1], tex2);
	pm.push_back(pm2);
	ParticleSystem* pm3 = new ParticleSystem(350, 350, vMin2, vMax2, lMin2, lMax2, 10, 30, -120, 120, sMin2,  nop2, b_collection[2], tex3);
	pm.push_back(pm3);


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

void ParticleManager::Update()
{
	for (int i = 0; i < pm.size(); i++)
	{
		pm[i]->update();
	}
}

void ParticleManager::Draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	for (int i = 0; i < pm.size(); i++)
	{
		pm[i]->draw(window);
	}
}