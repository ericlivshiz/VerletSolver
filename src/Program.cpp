#include "Program.hpp"

#include <SFML/Window/WindowStyle.hpp>

Program::Program()
	:
	window{ "Chess", sf::Style::Default},
	shapeMgr{},
	threadPool(std::thread::hardware_concurrency())
{}

void Program::start()
{
	isRunning = true;
	programLoop();


}

void Program::programLoop()
{
	while (isRunning)
	{
		handleInput();
		update();
		display();
	}
}

void Program::handleInput()
{
	/*std::cout << "Handle Input\n";*/
}

void Program::update()
{
	window.update();
	if (!window.isOpen())
		stop();

	//for (int i = 0; i < shapeMgr.circleObjs.size(); i++)
	//{
	//	sf::Vector2f pos = shapeMgr.circleObjs[i].getShape().getPosition();

	//	// Gravity function changes the position of the shape and returns the position it brought it to
	//	if (!physics.btmWindowTouched(pos))
	//	{
	//		pos = physics.Gravity(shapeMgr.circleObjs[i], i);
	//	}

	//}

	//for (int i = 0; i < shapeMgr.squareObjs.size(); i++)
	//{
	//	sf::Vector2f pos = shapeMgr.squareObjs[i].getShape().getPosition();

	//	// Gravity function changes the position of the shape and returns the position it brought it to

	//	physics.Gravity(shapeMgr.squareObjs[i], i);
	//	physics.CheckWindowCollision(shapeMgr.squareObjs[i]);

	//	std::cout << "Position: " << std::endl;
	//	std::cout << "X: Axis: " << pos.x << std::endl;
	//	std::cout << "Y: Axis: " << pos.y << std::endl;
	//}

	// Submit the task to the thread pool
	threadPool.enqueue([this]() { shapeMgr.manageShapes(); });

	float dt = clock.restart().asSeconds();

	verlet.applyGravity(shapeMgr.squareObjs, 9.81f);
	verlet.applyGravity(shapeMgr.circleObjs, 9.81f);

	verlet.updatePositions(shapeMgr.squareObjs, dt);
	verlet.updatePositions(shapeMgr.circleObjs, dt);

	verlet.sameObjectCollisions(shapeMgr.circleObjs);

	shapeMgr.addCircleObject();
	std::cout << "Number of circles: " << iterator++ << std::endl;

	/*verlet.handleWindowCollision(shapeMgr.squareObjs, sf::Vector2f(window.getWidth(), window.getHeight()));
	verlet.handleWindowCollision(shapeMgr.circleObjs, sf::Vector2f(window.getWidth(), window.getHeight()));*/


	//if (shapeMgr.squareObjs.size() != 0)
	//{
	//	for (int i{ 0 }; i < shapeMgr.squareObjs.size(); i++)
	//	{
	//		physics.CheckWindowCollision(shapeMgr.squareObjs[i]);
	//	}
	//}

	if (shapeMgr.circleObjs.size() != 0)
	{
		for (int i{ 0 }; i < shapeMgr.circleObjs.size(); i++)
		{
			physics.CheckWindowCollision(shapeMgr.circleObjs[i]);
		}
	}
	/*if (shapeMgr.squareObjs.size() != 0)
	{
		for (int i = 0; i < shapeMgr.squareObjs.size(); i++)
		{
			sf::Vector2f pos = shapeMgr.squareObjs[i].getShape().getPosition();
			physics.RandomMoveShape(shapeMgr.squareObjs[i]);
			physics.CheckWindowCollision(shapeMgr.squareObjs[i]);
			physics.sameObjectCollision(shapeMgr.squareObjs);
		}
	}

	if (shapeMgr.circleObjs.size() != 0)
	{
		for (int i = 0; i < shapeMgr.circleObjs.size(); i++)
		{
			sf::Vector2f pos = shapeMgr.circleObjs[i].getShape().getPosition();
			physics.RandomMoveShape(shapeMgr.circleObjs[i]);
			physics.CheckWindowCollision(shapeMgr.circleObjs[i]);
			physics.sameObjectCollision(shapeMgr.circleObjs);
		}
	}*/

}

void Program::display()
{
	renderer.preRender();

	renderer.render(shapeMgr);

	renderer.postRender();
}

void Program::stop()
{
	isRunning = false;
}

