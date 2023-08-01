#include "Circle.hpp"

Circle::Circle(sf::Vector2f position)
    : acceleration(sf::Vector2f(0.0f, 0.0f)), previousPosition(position)
{
    circle.setRadius(mediumRadius);
    circle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    circle.setPosition(position);
}

void Circle::updatePosition(sf::Vector2f newPosition)
{
    circle.setPosition(newPosition);
}

sf::CircleShape& Circle::getShape()
{
    return circle;
}

void Circle::setAcceleration(sf::Vector2f acceleration)
{
    this->acceleration = acceleration;
}

sf::Vector2f Circle::getAcceleration()
{
    return acceleration;
}

void Circle::setPreviousPosition(sf::Vector2f previousPosition)
{
    this->previousPosition = previousPosition;
}

sf::Vector2f Circle::getPreviousPosition()
{
    return previousPosition;
}
