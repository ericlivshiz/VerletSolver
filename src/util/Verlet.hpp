#pragma once

#include <SFML/Graphics.hpp>
#include "../Objects/objectMgr.hpp" // Include the ObjectMgr.hpp with updateShapePos
#include <vector>

class Verlet {
public:
    Verlet();

    // Function to update the positions of shapes using Verlet Integration
    template <typename T>
    void updatePositions(std::vector<T>& shapeObjs, float deltaTime) {
        for (T& shapeObj : shapeObjs) {
            updatePosition(shapeObj, deltaTime);
        }
    }

    // Function to apply gravitational forces to shapes
    template <typename T>
    void applyGravity(std::vector<T>& shapeObjs, float gravity) {
        sf::Vector2f acceleration(0.0f, gravity*20);

        for (T& shapeObj : shapeObjs) {
            // Apply the same acceleration to all shapes for this example
            shapeObj.setAcceleration(acceleration);
        }
    }

    
    void sameObjectCollisions(std::vector<Circle>& shapeObjs)
    {
        const float responseCoef = 0.75f;
        const int objectCount = shapeObjs.size();


        for (int i{ 0 }; i < objectCount; i++)
        {
            Circle& object1 = shapeObjs[i];
            for (int j{ i + 1 }; j < objectCount; j++)
            {
                Circle& object2 = shapeObjs[j];
                const sf::Vector2f collisionAxis = object1.getShape().getPosition() - 
                    object2.getShape().getPosition();

                const float dist2 = collisionAxis.x * collisionAxis.x + collisionAxis.y 
                    * collisionAxis.y;

                const float minDist = object1.getShape().getRadius() 
                    + object2.getShape().getRadius();

                if (dist2 < minDist * minDist)
                {
                    const float dist = sqrt(dist2);
                    const sf::Vector2f n = collisionAxis / dist;

                    const float overlap = 0.5f * (dist - minDist);
                    sf::Vector2f separation = overlap * n;

                    sf::Vector2f updatedPos1 = object1.getShape().getPosition() - separation;
                    sf::Vector2f updatedPos2 = object2.getShape().getPosition() + separation;

                    object1.getShape().setPosition(updatedPos1);
                    object2.getShape().setPosition(updatedPos2);

                }
            }
        }
    }

    // Implementation of handleWindowCollision function
    //template <typename T>
    //void handleWindowCollision(std::vector<T>& shapeObjs, sf::Vector2f windowSize) {
    //    for (T& shapeObj : shapeObjs) {
    //        sf::Vector2f currentPosition = shapeObj.getShape().getPosition();
    //        sf::Vector2f previousPosition = shapeObj.getPreviousPosition();
    //        sf::Vector2f velocity = shapeObj.getVelocity();
    //        /*std::cout << "Current position x: " << currentPosition.x << std::endl;
    //        std::cout << "Current position y: " << currentPosition.y << std::endl;
    //        std::cout << "Window size y: " << windowSize.y << std::endl;*/

    //        // Check if the shape's position is outside the window boundaries
    //        //if (currentPosition.x < 0 || currentPosition.x > windowSize.x) {
    //        //    // If the shape is outside the left or right edge of the window, reverse its x-velocity
    //        //    velocity.x = -velocity.x;
    //        //    // Update the position and velocity of the shape
    //        //    shapeObj.setVelocity(velocity);
    //        //    shapeObj.getShape().setPosition(currentPosition + velocity);
    //        //    shapeObj.setPreviousPosition(currentPosition);
    //        //}

    //        //if (currentPosition.y > windowSize.y - 10) {
    //        //    // If the shape is outside the top or bottom edge of the window, reverse its y-velocity
    //        //    // Update the position and velocity of the shape
    //        //    velocity.y = -(velocity.y * 0.5);
    //        //    shapeObj.setVelocity(velocity);
    //        //    sf::Vector2f updatedPos = currentPosition + velocity;
    //        //    shapeObj.getShape().setPosition(currentPosition + velocity);
    //        //    shapeObj.setPreviousPosition(currentPosition);

    //        //    ShapeMgr::updateShapePos(updatedPos, shapeObj);
    //        //}
    //    }
    //}


private:
    // Helper function to calculate the next position using Verlet Integration
    sf::Vector2f calculateNextPosition(const sf::Vector2f& currentPosition,
        const sf::Vector2f& previousPosition,
        const sf::Vector2f& acceleration,
        float deltaTime);

    // Helper function to update the position of a single shape
    template <typename T>
    void updatePosition(T& object, float deltaTime) {
        // Get the current position and previous position of the shape
        sf::Vector2f currentPosition = object.getShape().getPosition();
        sf::Vector2f previousPosition = object.getPreviousPosition();

        // Get the acceleration of the shape (previously set in applyGravity function)
        sf::Vector2f acceleration = object.getAcceleration();

        // Calculate the next position using Verlet Integration
        sf::Vector2f nextPosition = calculateNextPosition(currentPosition, previousPosition, acceleration, deltaTime);

        // Update the position of the shape
        object.getShape().setPosition(nextPosition);

        // Store the current position as the previous position for the next iteration
        object.setPreviousPosition(currentPosition);

        /*std::cout << "Just set the position using Verlet" << std::endl;*/
    }
};
