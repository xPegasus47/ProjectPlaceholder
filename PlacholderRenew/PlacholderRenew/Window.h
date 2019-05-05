#pragma once
#include "stdafx.h"


class Window {
public:
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();

	void beginDraw(); // Clear the window.
	void endDraw(); // Display the changes.

	void update();

	bool isDone();
	bool isFullscreen();
	sf::Vector2u getWindowSize();

	void toggleFullscreen();

	void draw(sf::Drawable& l_drawable);
private:
	void setup(const std::string& l_title, const sf::Vector2u& l_size);
	void destroy();
	void create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
};