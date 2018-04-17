#include <math.h>
#include "Behaviour.h"
#include "Particle.h"

float Uniform::behave(float f)
{
	return 1;
}

float EaseOutCubic::behave(float f)
{
	return   1 + (--f) * f * f;;
}

float LinearDown::behave(float f)
{
	return 1 - f;
}

float EaseInOutExpo::behave(float f)
{

	if (f < 0.5) {
		return (pow(2, 16 * f) - 1) / 510;
	}
	else {
		return 1 - 0.5 * pow(2, -16 * (f - 0.5));
	}
}

float EaseInOut::behave(float f)
{
	float PI = 3.1415926f;
	return 0.5 * (1 + sin(PI * (f - 0.5)));
}