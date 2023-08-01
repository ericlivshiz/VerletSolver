#include "Square.hpp"

Square::Square(sf::Vector2f position)
    : acceleration(sf::Vector2f(0.0f, 0.0f)), previousPosition(position)
{
    square.setSize(sf::Vector2f(50.0f, 50.0f));
    square.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    square.setPosition(position);
}

void Square::updatePosition(sf::Vector2f newPosition)
{
    square.setPosition(newPosition);
}

sf::RectangleShape& Square::getShape()
{
    return square;
}

void Square::setAcceleration(sf::Vector2f acceleration)
{
    this->acceleration = acceleration;
}

sf::Vector2f Square::getAcceleration()
{
    return acceleration;
}

void Square::setPreviousPosition(sf::Vector2f previousPosition)
{
    this->previousPosition = previousPosition;
}

sf::Vector2f Square::getPreviousPosition()
{
    return previousPosition;
}
