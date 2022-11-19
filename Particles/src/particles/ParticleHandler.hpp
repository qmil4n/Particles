#pragma once
#include "../util/stdain.hpp"
#include "Particle.hpp"

#ifndef PARTICLEHANDLER_HPP
#define PARTICLEHANDLER_HPP

namespace ps
{
	class ParticleHandler
	{
	public:
		ParticleHandler();

		void update(float dt);
		void pull(float dt, sf::Vector2i pos);
		void draw(sf::RenderWindow* window);
		void add(Particle p);
		void clear();

		std::vector<Particle>* particles;

	private:
		sf::VertexArray* points;
	};
}

#endif // !PARTICLEHANDLER_HPP