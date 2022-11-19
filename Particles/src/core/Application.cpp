#include "Application.hpp"

namespace ps
{
	Application::Application()
	{
		window = new Window(1280, 720, "Particles SImulation");
		handler = new ParticleHandler();
	}

	Application::~Application()
	{
		delete window;
	}

	void Application::run()
	{
		srand(int(time(0)));

		//for (int i = 0; i < 10000; i++)
		//	handler->add(Particle(sf::Vector2f(500, 500)));

		sf::Clock clock;
		float c{0};
		while (window->running())
		{
			float dt = clock.restart().asSeconds();
			window->pollEvent();
			window->clear();

			mouse_pos = sf::Mouse::getPosition(*window->getDisplay());

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				for (int i = 0; i < 1; i++)
					handler->add(Particle(sf::Vector2f(mouse_pos.x, mouse_pos.y)));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				handler->pull(dt, mouse_pos);


			handler->update(dt);
			handler->draw(window->getDisplay());

			window->display();

			c += dt;
			if (c < 0.1) continue;
			LOG("\x1B[2J\x1B[H" << "\r");
			LOG(1.f / dt);
			LOG(handler->particles->size());
			c = 0;
		}
	}
}