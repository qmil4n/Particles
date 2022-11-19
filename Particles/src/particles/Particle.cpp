#include "Particle.hpp"

Particle::Particle(sf::Vector2f p)
	:position {p},
	velocity{ (rand() % 1000 - 500) / 10.f, (rand() % 1000 - 500) / 10.f }
{
}

void Particle::update(float dt)
{
	velocity.x -= velocity.x / 2 * dt;
	velocity.y -= velocity.y / 2 * dt;
	position.x += velocity.x * dt;
	position.y += velocity.y * dt;
}
