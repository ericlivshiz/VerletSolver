#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace sf
{
	class Color;
	class Drawable;
}

class Window
{
	// public methods
public:
	Window(const std::string& name, int style);

	void update();

	bool isFocused() const { return focused; }
	bool isOpen() const { return window.isOpen(); }

	unsigned getWidth() const { return window.getSize().x; }
	unsigned getHeight() const { return window.getSize().y; }
	const sf::RenderWindow& getWindow() const { return window; }

public:
	static constexpr unsigned STARTING_WIDTH{ 1000 };
	static constexpr unsigned STARTING_HEIGHT{ 800 };

	// private methods
private:
	void pollEvents();

	// private members
private:
	sf::RenderWindow window;

	bool focused{ true };

	// methods soley for Renderer's use
private:
	void clear(const sf::Color& clearColor);
	void draw(const sf::Drawable& object);
	void display();

	// friend class means that that class can access the private
	// methods and members of this class (Renderer can access Window)
	// This is because the Renderer outputs to the window and are coupled
	friend class Renderer;
};