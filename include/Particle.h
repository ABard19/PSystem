#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

class Behaviour;

class Particle
{
public:

	struct Parameters
	{
		float pX;
		float pY;
		float vFin;
		float vCurr;
		float angle;
		float rFin;
		float rCurr = 0;
		float sFin;
		float sCurr = 0;
		float lifetime;
		float time;
		Parameters() {};

		Parameters(float cpX, float cpY, float cvFin, float clifetime, float cangle,
			float crFin, float csFin):
			pX(cpX),pY(cpY),vFin(cvFin),lifetime(clifetime),angle(cangle),rFin(crFin),sFin(csFin)
		{
		}
		void Print()
		{
			std::cout << "pX " << pX << std::endl;
			std::cout << "pY " << pY << std::endl;
			std::cout << "vFin " << vFin << std::endl;
			std::cout << "sFin " << sFin << std::endl;
			std::cout << "time " << time << std::endl;
			std::cout << "rFin "  << rFin << std::endl;
			std::cout << "angle  " << angle << std::endl;
			std::cout << "lifetime " << lifetime << std::endl;
			
		}

	};

	Particle();
	Particle(float pX, float pY, float vFin, float lifetime, float angle,
		float rFin, float sFin, std::vector<Behaviour*> b, sf::Texture& tex);
	~Particle();

	void update();
	void draw(sf::RenderWindow& window);
	void SetParameter(Parameters & parameters);
	Parameters GetParameter() const;

	std::vector<Behaviour*> b;
	sf::RectangleShape* shape;
private:
	Parameters m_P;

};