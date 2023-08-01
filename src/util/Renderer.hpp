#pragma once

class Window;

class ShapeMgr;

class Renderer
{
	// public methods
public:
	Renderer(Window& window)
		:
		window{ window }
	{}

	void preRender();
	void postRender();

	void render(const ShapeMgr& shapeMgr);

	// private members
private:
	Window& window;
};