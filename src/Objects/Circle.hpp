#pragma once

#include <SFML/Graphics.hpp>

class Circle {
public:
    Circle(sf::Vector2f position);

    // Function to update the position of the circle using Verlet Integration
    void updatePosition(sf::Vector2f newPosition);

    // Function to get the shape (circle)
    sf::CircleShape& getShape();

    // Function to set the acceleration of the circle
    void setAcceleration(sf::Vector2f acceleration);

    // Function to get the acceleration of the circle
    sf::Vector2f getAcceleration();

    // Function to set the previous position of the circle
    void setPreviousPosition(sf::Vector2f previousPosition);

    // Function to get the previous position of the circle
    sf::Vector2f getPreviousPosition();

    // Velocity functions
    sf::Vector2f getVelocity() const { return this->velocity; }

    void setVelocity(sf::Vector2f vel) { this->velocity = vel; }

    int velStrength = -3;

private:
    sf::CircleShape circle;
    sf::Vector2f acceleration;
    sf::Vector2f previousPosition;
    sf::Vector2f velocity;

    const int smallRadius = 5;
    static inline constexpr int mediumRadius = 15;
    static inline constexpr int largeRadius = 35;
};
