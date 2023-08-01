#include "objectMgr.hpp"

#include <iostream>

ShapeMgr::ShapeMgr()
{
}

void ShapeMgr::manageShapes()
{

	// Lock the mutex before accessing std::cin
	std::unique_lock<std::mutex> lock(cinMutex);

	std::cout << "********************" << std::endl << "Shape Management Tool" << std::endl;
	std::cout << "********************" << std::endl;
	

	int addOrDeleteShape;
	int shapeType;
	int amount;
	
	std::cout << std::endl << "What would you like to do?" << std::endl;
	std::cout << "1. Add Shape" << std::endl;
	std::cout << "2. Delete Shape" << std::endl;
	std::cin >> addOrDeleteShape;

	if (addOrDeleteShape == 1)
	{
		std::cout << "|  What shape would you like to add          |" << std::endl;
		std::cout << "|  1. Circle                                 |" << std::endl;
		std::cout << "|  2. Square                                 |" << std::endl;

		std::cin >> shapeType;

		std::cout << "How many would you like to add: " << std::endl;
		std::cin >> amount;


		if (shapeType == 1)
		{
			std::cout << "Adding " << amount << "Circles..." << std::endl;
			InitializeShapes(amount, circleObjs);
		}

		if (shapeType == 2)
		{
			std::cout << "Adding " << amount << "Squares..." << std::endl;
			InitializeShapes(amount, squareObjs);
		}
	}

	else if (addOrDeleteShape == 2)
	{
		std::cout << "Oops! This is not built yet, sorry" << std::endl;
	}

	else {
		std::cout << "Not an Option!" << std::endl;
	}
	//int shapeType;
	//int amount;

	//std::cout << "Shape Management Tool" << std::endl;
	//std::cout << "----------------------------------------------" << std::endl;
	//std::cout << "|  Which shape would you like to work with:  |" << std::endl;
	//std::cout << "|  1. Circle                                 |" << std::endl;
	//std::cout << "|  2. Square                                 |" << std::endl;

	//std::cin >> shapeType;

	//std::cout << "|  How many would you like to spawn in:      |" << std::endl;
	//std::cin >> amount;

	//if (shapeType == 1)
	//{
	//	InitializeShapes(amount, circleObjs);
	//	/*EnablePhysics(circleObjs);*/
	//}

	//if (shapeType == 2)
	//{
	//	InitializeShapes(amount, squareObjs);
	//	/*EnablePhysics(squareObjs);*/
	//}

}