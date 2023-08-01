#pragma once

#include <SFML/Graphics.hpp>

#include "../Objects/objectMgr.hpp"

#include <cstdlib>

#include <ctime>

class Physics {
public:
	Physics()
	{
		// Initialize random seed
		std::srand(static_cast<unsigned int>(std::time(nullptr)));

		// Initialize the timer
		timer.restart();
	}

	template <typename T>
	sf::Vector2f Gravity(T& object, int index)
	{
		sf::Vector2f pos = object.getShape().getPosition();

		velocity.y += 0.1;
		pos.y += velocity.y;

		ShapeMgr::updateShapePos(pos, object);
		return pos;
	}

	template <typename T>
	sf::Vector2f RandomMoveShape(T& object)
	{

		sf::Vector2f pos = object.getShape().getPosition();

		

		if (!randomMoveMade)
		{
			// Generate random velocity components in the range [-1, 1]
			float randomVelX = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f;
			float randomVelY = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f;

			// Set the velocity vector with the random components
			velocity = sf::Vector2f(randomVelX, randomVelY);
			object.setVelocity(velocity);
			/*velocity.x = randomVelX;
			velocity.y = randomVelY;*/

			// Adjust the magnitude of the velocity if needed
			float speed = 3;// Adjust this value to control the speed of the shape
			velocity = normalize(object.getVelocity()) * speed;

			// Restart the timer
			timer.restart();
			randomMoveMade = true;
		}

		// Update the position of the shape based on the velocity
		sf::Vector2f updatedPos = pos + object.getVelocity();
		object.updatePosition(updatedPos);

		ShapeMgr::updateShapePos(updatedPos, object);
		return updatedPos;

		

	}

	// TODO:
	// Finish this function
	template <typename T>
	bool sameObjectCollision(std::vector<T>& shapeObjs) {
		for (int i = 0; i < shapeObjs.size() - 1; i++) {
			for (int j = i + 1; j < shapeObjs.size(); j++) {
				// Get the bounding rectangles of the shapes
				sf::FloatRect rectA = shapeObjs[i].getShape().getGlobalBounds();
				sf::FloatRect rectB = shapeObjs[j].getShape().getGlobalBounds();

				sf::Vector2f posA = shapeObjs[i].getShape().getPosition();
				sf::Vector2f posB = shapeObjs[j].getShape().getPosition();

				// Check if the bounding rectangles intersect
				if (rectA.intersects(rectB)) {
					// Collision detected between shapeObjs[i] and shapeObjs[j]
					// Handle the collision as needed
					sf::Vector2f velocityA = sf::Vector2f((shapeObjs[i].getVelocity().x * -1), (shapeObjs[i].getVelocity().y * -1));
					sf::Vector2f velocityB = sf::Vector2f((shapeObjs[j].getVelocity().x * -1), (shapeObjs[j].getVelocity().y * -1));

					shapeObjs[i].setVelocity(velocityA);
					shapeObjs[j].setVelocity(velocityB);

					sf::Vector2f updatedPosA = posA + shapeObjs[i].getVelocity();
					sf::Vector2f updatedPosB = posB + shapeObjs[j].getVelocity();

					shapeObjs[i].updatePosition(updatedPosA);
					shapeObjs[j].updatePosition(updatedPosB);

					ShapeMgr::updateShapePos(updatedPosA, shapeObjs[i]);
					ShapeMgr::updateShapePos(updatedPosB, shapeObjs[j]);

					// Return true to indicate a collision occurred
					return true;
				}
			}
		}

		// No collisions found
		return false;
	}

	template <typename T, typename K>
	bool diffObjectCollision(std::vector<T>& shapeObjA, std::vector<K>& shapeObjB)
	{

	}

	template <typename T>
	bool CheckWindowCollision(T& object)
	{
		sf::Vector2f pos = object.getShape().getPosition();
		//std::cout << "Pos x: " << pos.x << std::endl;
		//std::cout << "Pos y: " << pos.y << std::endl;
		bool collision = false;
		
		// Check window boundaries for x-axis
		if (pos.x <= 5 || pos.x >= 990)
		{
			//velocity.x = -velocity.x; // Reverse the x-direction
			//object.setVelocity(velocity);
			collision = true;
		}

		// Check window boundaries for y-axis
		//if (pos.y <= 1)
		//{
		//	if (object.velStrength == -5)
		//	{
		//		std::cout << "Starting animation part called" << std::endl;
		//		velocity.y = -(object.velStrength * 1.5);
		//		velocity.x = -(object.velStrength * 1.5);
		//		object.setVelocity(velocity);
		//		sf::Vector2f updatedPos = pos += velocity;
		//		ShapeMgr::updateShapePos(pos, object);
		//	}
		//	

		//}

		if (pos.y >= 790)
		{
			if (object.velStrength != 0)
			{
				velocity.x = -object.velStrength * 0.5;
				velocity.y = object.velStrength;
				object.velStrength++;
				object.setVelocity(velocity);
			}
			else {
				velocity.x = 0;
				velocity.y = 0;
				object.setVelocity(velocity);
			}
			
			collision = true;
		}

		// If there was a collision, update the position of the object
		if (collision)
		{
			/*velocity.x *= 1.01;
			velocity.y *= 1.01;*/
			// Apply the reversed velocity to avoid the object getting stuck at the boundary
			sf::Vector2f updatedPos = pos += velocity;

			// Make sure the shape stays within the window
			if (pos.x <= 5) pos.x = 5;
			else if (pos.x >= 990) pos.x = 990;

			if (pos.y <= 5) pos.y = 5;
			else if (pos.y >= 790) pos.y = 790;

			ShapeMgr::updateShapePos(pos, object);
		}

		return collision;
	}


private:
	sf::Vector2f velocity;
	sf::Clock timer;
	bool randomMoveMade = false;

	// Helper function to normalize a vector
	sf::Vector2f normalize(sf::Vector2f& v)
	{
		float length = std::sqrt(v.x * v.x + v.y * v.y);
		if (length != 0.0f)
			return sf::Vector2f(v.x / length, v.y / length);
		return v;
	}
};