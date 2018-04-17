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

	tex1.loadFromFile("C:/Users/Akshay/Desktop/CBoot/t1.png");
	tex2.loadFromFile("C:/Users/Akshay/Desktop/CBoot/t2.png");
	tex3.loadFromFile("C:/Users/Akshay/Desktop/CBoot/t3.png");

	//Random generation of values for PSystem

	float pX = 50 + rand() % 750; float pY = 50 + rand() % 750; float pX1 = 50 + rand() % 750; float pY1 = 50 + rand() % 750; float pX2 = 50 + rand() % 750; float pY2 = 50 + rand() % 750;
	float vMin = 1 + rand() % 7; float vMax = vMin + 1+rand() % 5; float vMin1 = 1 + rand() % 7; float vMax1 = vMin1 + 1+rand() % 5; float vMin2 = 1 + rand() % 7; float vMax2 = vMin2 + 1+rand() % 5;
	float lMin= 1 + rand() % 7; float lMax = vMin + 1 + rand() % 5; float lMin1 = 1 + rand() % 7; float lMax1 = vMin1 + 1 + rand() % 5; float lMin2 = 1 + rand() % 7; float lMax2 = vMin2 + 1 + rand() % 5;
	float size = 1 + rand() % 25; float size1 = 1 + rand() % 25; float size2 = 1 + rand() % 25;
	float nop = 20 + rand() % 50; float nop1 = 20 + rand() % 50; float nop2 = 20 + rand() % 50;
	
	ParticleSystem* pm1 = new ParticleSystem(pX, pY, vMin, vMax, lMin, lMax, 0, 360, 0, 90, size, nop, b_collection[0], tex1);
	pm.push_back(pm1);
	ParticleSystem* pm2 = new ParticleSystem(pX1, pY1, vMin1, vMax1, lMin1, lMax1, -180, 0, -120, 120, size1, nop1, b_collection[1], tex2);
	pm.push_back(pm2);
	ParticleSystem* pm3 = new ParticleSystem(pX2, pY2, vMin2, vMax2, lMin2, lMax2, -180, 0, -120, 120, size2, nop2, b_collection[2], tex3);
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