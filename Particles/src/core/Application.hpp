#pragma once
#include "../util/stdain.hpp"
#include "Window.hpp"
#include "../particles/Particle.hpp"
#include "../particles/ParticleHandler.hpp"

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

namespace ps
{
	class Application
	{
	public:
		Application();
		~Application();

		void run();

	private:
		Window* window;
		ParticleHandler* handler;

		sf::Vector2i mouse_pos;
	};
}

#endif // !APPLICATION_HPP