#include <math.h>
#include "Behaviour.h"
#include "Particle.h"

float Uniform::behave(float f)
{
	return 1;
}

float LinearUp::behave(float f)
{
	return f;
}

float LinearDown::behave(float f)
{
	return 1 - f;
}

float EaseIn::behave(float f)
{
	return f * f;
}

float EaseOut::behave(float f)
{
	float PI = 3.1415926f;
	return cosf(PI / 2 * f);
}