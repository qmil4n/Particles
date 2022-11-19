#include "ParticleHandler.hpp"
#include "../util/physics.hpp"

namespace ps
{
	ParticleHandler::ParticleHandler()
	{
		points = new sf::VertexArray(sf::Points);
		particles = new std::vector<Particle>;
	}

	void ParticleHandler::update(float dt)
	{
		int x = 0;
		for (std::vector<Particle>::iterator it = particles->begin(); it < particles->end(); it++)
		{
			it->update(dt);
			(*points)[x].position = it->position;
			x++;
		}
	}
	void ParticleHandler::pull(float dt, sf::Vector2i pos)
	{
		for (std::vector<Particle>::iterator it = particles->begin(); it < particles->end(); it++)
		{
			sf::Vector2f dist{ it->position.x - pos.x, it->position.y - pos.y };
			normalize(dist);

			it->velocity.x -= dist.x * 1000 * dt;
			it->velocity.y -= dist.y * 1000 * dt;
		}
	}

	void ParticleHandler::draw(sf::RenderWindow* window)
	{
		window->draw(*points);
	}
	
	void ParticleHandler::add(Particle p)
	{
		particles->push_back(p); 
		points->append(p.position); 
	}
	
	void ParticleHandler::clear()
	{
		particles->clear(); 
		points->clear();
	}
}