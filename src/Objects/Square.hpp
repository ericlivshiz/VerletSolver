#pragma once

#include <SFML/Graphics.hpp>

class Square {
public:
    Square(sf::Vector2f position);

    // Function to update the position of the square using Verlet Integration
    void updatePosition(sf::Vector2f newPosition);

    // Function to get the shape (square)
    sf::RectangleShape& getShape();

    // Function to set the acceleration of the square
    void setAcceleration(sf::Vector2f acceleration);

    // Function to get the acceleration of the square
    sf::Vector2f getAcceleration();

    // Function to set the previous position of the square
    void setPreviousPosition(sf::Vector2f previousPosition);

    // Function to get the previous position of the square
    sf::Vector2f getPreviousPosition();

    // Velocity functions
    sf::Vector2f getVelocity() const { return velocity; }

    void setVelocity(sf::Vector2f vel) { velocity = vel; }

    int velStrength = -3;


private:
    sf::RectangleShape square;
    sf::Vector2f acceleration;
    sf::Vector2f previousPosition;
    sf::Vector2f velocity;

};
