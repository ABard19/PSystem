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

class LinearUp : public Behaviour
{
public:
	virtual float behave(float f);
};

class LinearDown : public Behaviour
{
public:
	virtual float behave(float f);
};

class EaseIn : public Behaviour
{
public:
	virtual float behave(float f);
};

class EaseOut : public Behaviour
{
public:
	virtual float behave(float f);
};