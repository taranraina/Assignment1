#include "pch.h"
#include "VGMap.h"
#include <iostream>
#include <iomanip>


Vertex::Vertex() {							//default constructor

	value = new int;
	position = new int;
	isOccupied = new bool(false);
	
	//will be replaced by buildingtile object
	isFaceUp = new bool(false);
	resource = new char(' ');

}

Vertex::Vertex(int val, int pos) {			//parameterized constructor taking value and position parameters

	value = new int(val);
	position = new int(pos);
	isOccupied = new bool(false);

	//will be replaced by buildingtile object
	isFaceUp = new bool(false);
	resource = new char(' ');

}

Vertex::~Vertex() {										//destructor
	
	delete value;
	value = nullptr;
	delete position;
	position = nullptr;
	delete isOccupied;
	isOccupied = nullptr;
	delete isFaceUp;
	isFaceUp = nullptr;
	delete resource;
	resource = nullptr;
	
}

Vertex::Vertex(const Vertex &V) {							//Copy constructor

	value = new int(*(V.value));
	position = new int(*(V.position));
	isOccupied = new bool(*(V.isOccupied));
	isFaceUp = new bool(*(V.isFaceUp));
	resource = new char(*(V.resource));
}

Vertex& Vertex::operator=(const Vertex &V) {				//assignmet operator overload


	if (this == &V) {
		return *this;
	}
		
	else {
	
		*this->value = *V.value;
		
		*this->position = *V.position;

		*this->isOccupied = *V.isOccupied;

		*this->isFaceUp = *V.isFaceUp;

		*this->resource = *V.resource;
	}

	return *this;
}

int Vertex::getValue() 									//getter for value
{
	return *value;
}

int Vertex::getPosition()								//getter for position
{
	return *position;
}

bool Vertex::getIsOccupied() 							//getter for isOccupied
{	
	return *isOccupied;
}

bool Vertex::getIsFaceUp()								//getter for isFaceUp
{
	return *isFaceUp;
}

char Vertex::getResource()								//getter for resource
{
	return *resource;
}


void Vertex::setIsOccupied(bool empty)					//setter for isOccupied
{				
	*isOccupied = empty;
}

void Vertex::setIsFaceUp(bool empty)					//setter for isFaceUp
{
	*isFaceUp = empty;
}

void Vertex::setResource(char res)						//setter for resource
{
	*resource = res;
}




VillageMap::VillageMap() {								//Default constructor

	adjMatrix = new int*[41];							//create adjacency matrix, and initailize all elements to 0

	for (int i = 0; i < 41; i++) {
		adjMatrix[i] = new int[41];
	}

	for (int i = 0; i < 41; i++) {
		for (int j = 0; j < 41; j++)
		{
			adjMatrix[i][j] = 0;
		}
	}

	villageBoard = new Vertex[41];						//create an array that holds the vertices of the villageboard,
	for (int i = 0; i < 41; i++)						//with parameters based on position on map
	{
		if (i < 5)	villageBoard[i] = Vertex(6, i);

		if (i > 5 && i < 11)	villageBoard[i] = Vertex(5, i);

		if (i > 11 && i < 17)	villageBoard[i] = Vertex(4, i);

		if (i > 17 && i < 23) 	villageBoard[i] = Vertex(3, i);

		if (i > 23 && i < 29) 	villageBoard[i] = Vertex(2, i);

		if (i > 29 && i < 35) 	villageBoard[i] = Vertex(1, i);

		//the following are all colonist/points positions indicated by the resource set to C
		//(to be modified when building tiles are available)
		if (i == 5) {
			villageBoard[i] = Vertex(6, i);
			villageBoard[i].setResource('C');
		}
		if (i == 11) {
			villageBoard[i] = Vertex(5, i);
			villageBoard[i].setResource('C');
		}
		if (i == 17) {
			villageBoard[i] = Vertex(4, i);
			villageBoard[i].setResource('C');
		}
		if (i == 23) {
			villageBoard[i] = Vertex(3, i);
			villageBoard[i].setResource('C');
		}
		if (i == 29) {
			villageBoard[i] = Vertex(2, i);
			villageBoard[i].setResource('C');
		}
		if (i == 35) {
			villageBoard[i] = Vertex(1, i);
			villageBoard[i].setResource('C');
		}
		if (i == 36) {
			villageBoard[i] = Vertex(5, i);
			villageBoard[i].setResource('C');
		}
		if (i == 37) {
			villageBoard[i] = Vertex(4, i);
			villageBoard[i].setResource('C');
		}
		if (i == 38) {
			villageBoard[i] = Vertex(3, i);
			villageBoard[i].setResource('C');
		}
		if (i == 39) {
			villageBoard[i] = Vertex(4, i);
			villageBoard[i].setResource('C');
		}
		if (i == 40) {
			villageBoard[i] = Vertex(5, i);
			villageBoard[i].setResource('C');
		}
	}
	
	addEdges();										

}

VillageMap::~VillageMap() {

	for (int i = 0; i < 41; i++) {		
		delete[] adjMatrix[i];							//delete elements of adjacency matrix and free allocated memory
		adjMatrix[i] = nullptr;
	}
	delete[] adjMatrix;									//delete the adjacency matrix and free allocated memory
	adjMatrix = nullptr;


	delete[] villageBoard;								//delete the adjacency matrix and free allocated memory
	villageBoard = nullptr;
	
}


void VillageMap::addEdges() {							//add edges between the vertices based on their position
	
	for (int i = 0; i < 35; i++) {

		if (i != 5 && i != 11 && i != 17 && i != 23 && i != 29) {
		adjMatrix[villageBoard[i].getPosition()][villageBoard[i + 1].getPosition()] = 1;
		adjMatrix[villageBoard[i + 1].getPosition()][villageBoard[i].getPosition()] = 1;
	}
		adjMatrix[villageBoard[i].getPosition()][villageBoard[i + 6].getPosition()] = 1;
		adjMatrix[villageBoard[i + 6].getPosition()][villageBoard[i].getPosition()] = 1;
	}
}

bool VillageMap::checkAdjacency(int i, int j) {			//check to see if two vertices are adjacent by checking the adjacency matrix

	return adjMatrix[i][j];
}

void VillageMap::displayVillageBoard() {				//print out villageboard

	for (int i = 0; i < 41; i++) {
		
		if (i == 5 || i == 11 || i == 17 || i == 23 || i == 29 || i == 35)
			std::cout << "|" << " (" << villageBoard[i].getValue() << ") ";

		else if (i == 6 || i == 12 || i == 18 || i == 24 || i == 30)
			std::cout << "\n" << " (" << villageBoard[i].getValue() << " " << villageBoard[i].getResource() << ") ";

		else if (i == 36)
			std::cout << "\n------------------------------------\n" << " (" << villageBoard[i].getValue() << ")   ";

		else if (i == 37 || i == 38 || i == 39 || i == 40)
			std::cout << " (" << villageBoard[i].getValue() << ")   ";

		else
			std::cout << " (" << villageBoard[i].getValue() << " " << villageBoard[i].getResource()<<") ";
	}
}

void VillageMap::displayAdjMatrix() {					//print out adjacency matrix
	for (int i = 0; i < 41; i++) {

		std::cout << "\n" << std::setw(2) << i << " ";
		
		for (int j = 0; j < 41; j++)
		
			std::cout << " " << adjMatrix[i][j];
	}
}



