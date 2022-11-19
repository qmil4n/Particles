#pragma once
#include "../util/stdain.hpp"

#ifndef WINDOW_HPP
#define WINDOW_HPP

namespace ps
{
	class Window
	{
	public:
		Window(uint16_t w, uint16_t h, std::string t);
		~Window();

		void pollEvent();
		void clear(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0) { window->clear(sf::Color(r, g, b)); };
		void draw(sf::Drawable& obj) { window->draw(obj); }
		void display() { window->display(); }

		sf::RenderWindow* getDisplay() { return window; }
		const bool running() const { return window->isOpen(); }

	private:
		sf::VideoMode* videoMode;
		sf::RenderWindow* window;

	private:
		uint16_t width, height;
		std::string title;
	};
}

#endif // !WINDOW_HPP