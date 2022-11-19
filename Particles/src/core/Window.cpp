#include "Window.hpp"

namespace ps
{
	Window::Window(uint16_t w, uint16_t h, std::string t)
		:width (w),
		height (h),
		title (t)
	{
		videoMode = new sf::VideoMode(width, height, 32);
		window = new sf::RenderWindow(*videoMode, title, sf::Style::Close, sf::ContextSettings(24, 8, 0));
	}

	Window::~Window()
	{
		delete videoMode;
		delete window;
	}

	void Window::pollEvent()
	{
		sf::Event ev;
		while (window->pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			default:
				break;
			}
		}
	}
}