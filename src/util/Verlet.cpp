#include "Verlet.hpp"

Verlet::Verlet() {
    // Constructor (if needed)
}


sf::Vector2f Verlet::calculateNextPosition(const sf::Vector2f& currentPosition,
    const sf::Vector2f& previousPosition,
    const sf::Vector2f& acceleration,
    float deltaTime) {
    // Calculate the next position using Verlet Integration formula
    // newPosition = 2 * currentPosition - previousPosition + acceleration * deltaTime^2
    sf::Vector2f nextPosition = 2.0f * currentPosition - previousPosition + acceleration * deltaTime * deltaTime;

    return nextPosition;
}



// Explicit instantiation of updatePosition function for Circle and Square classes
//template void Verlet::updatePosition<Circle>(Circle& object, float deltaTime);
//template void Verlet::updatePosition<Square>(Square& object, float deltaTime);
