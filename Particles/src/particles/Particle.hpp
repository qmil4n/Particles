#pragma once
#include "../util/stdain.hpp"

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle
{
public:
	Particle(sf::Vector2f p);

	void update(float dt);

	sf::Vector2f position;
	sf::Vector2f velocity;
};

#endif // !PARTICLE_HPP