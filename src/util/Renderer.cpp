#include "Renderer.hpp"

#include "Window.hpp"

#include "../Objects/objectMgr.hpp"

#include <SFML/Graphics/Color.hpp>

void Renderer::preRender()
{
	static const sf::Color CLEAR_COLOR{ sf::Color::Black };
	window.clear(CLEAR_COLOR);
}

void Renderer::postRender()
{
	window.display();
}

void Renderer::render(const ShapeMgr& shapeMgr)
{
	for (int i = 0; i < ShapeMgr::circleObjs.size(); i++)
	{
		window.draw(ShapeMgr::circleObjs[i].getShape());
	}

	for (int i = 0; i < ShapeMgr::squareObjs.size(); i++)
	{
		window.draw(ShapeMgr::squareObjs[i].getShape());
	}


}