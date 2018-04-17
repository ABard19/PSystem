#pragma once

class Particle;

class Behaviour
{
public:
	virtual float behave(float f) { return 0; };
};

class Uniform : public Behaviour
{
public:
	virtual float behave(float f);
};

class EaseOutCubic : public Behaviour
{
public:
	virtual float behave(float f);
};

class LinearDown : public Behaviour
{
public:
	virtual float behave(float f);
};

class EaseInOutExpo : public Behaviour
{
public:
	virtual float behave(float f);
};

class EaseInOut : public Behaviour
{
public:
	virtual float behave(float f);
};