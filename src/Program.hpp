#pragma once

#include "util/Renderer.hpp"
#include "util/Window.hpp"
#include "util/Physics.h"
#include "util/Verlet.hpp"
#include "util/ThreadPool.h"
#include "Objects/objectMgr.hpp"


class Program
{
	// public methods
public:
	Program();

	void start();

	// private methods
private:

	void programLoop();

	void handleInput();
	void update();
	void display();

	void stop();


	// private members
private:
	Window window;
	Renderer renderer{ window };
	Physics physics;
	ShapeMgr shapeMgr;
	ThreadPool threadPool;
	Verlet verlet;

	int iterator = 0;
	sf::Clock clock;
	bool isRunning{ false };

};