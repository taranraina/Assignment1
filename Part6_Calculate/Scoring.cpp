#include "pch.h"
#include "Scoring.h"
#include <iostream>
#include <iomanip>



//----------------Part 6 i)------------------------//

static int wheatfield = 0, quarry = 0, meadow = 0, forest = 0;			//resource markers

Node::Node() {															//default constructor

	position = new int;

	resource = new char[4];												//4 resources per node 	(will be replaced by resource/harvest tile)

	beenThere = new bool[4];
	for (int i = 0; i < 4; i++) {
		resource[i] = ' ';
		beenThere[i] = false;
	}
}

	
Node::Node(int pos) {													//parameterized constructor
																			
	position = new int(pos);												
	beenThere = new bool[4];												
	resource = new char[4];													
	for (int i = 0; i < 4; i++) {											
		resource[i] = ' ';													
		beenThere[i] = false;												
	}																		
}																			
																			
																			
Node::~Node() {																//destructor
																			
	delete position;														
	position = nullptr;														
	delete[] resource;														
	resource = nullptr;														
	delete[] beenThere;														
	beenThere = nullptr;													
																			
}																			
																			
																			
Node::Node(const Node &V)													//Copy constructor
{																			
	position = new int(*(V.position));										
	resource = new char(*(V.resource));										
	beenThere = new bool(*(V.beenThere));									
	for (int i = 0; i < 4; i++) {											
		resource[i] = V.resource[i];										
		beenThere[i] = V.beenThere[i];										
	}																		
}																			
																			
Node& Node::operator=(const Node &V)										//assignmet operator overload
{

	if (this == &V) {
		return *this;
	}

	else {

		*this->position = *V.position;
		*this->resource = *V.resource;

	}
	return *this;
}

int Node::getPosition()														//getter for position
{
	return *position;
}

char Node::getResource(int x)												//getter for resource
{
	return resource[x];
}

void Node::setResource(char a, char b, char c, char d)						//setter for resource
{
	resource[0] = a;
	resource[1] = b;
	resource[2] = c;
	resource[3] = d;
}

void Node::setBeenThere(int x, bool been) {									//setter for beenthere

	beenThere[x] = been;

}

bool Node::getBeenThere(int x) {											//setter for beenthere

	return beenThere[x];

}




GameMap::GameMap() {						//Constructor

	gameBoard = new Node[35];

	for (int i = 0; i < 35; i++)
	{
		gameBoard[i] = Node(i);
	}


}


GameMap::~GameMap() {						//destructor

	delete[] gameBoard;
	gameBoard = nullptr;
}



void GameMap::placeResources(int x, char a, char b, char c, char d)		//place resources on a node in the game board
																		//where x is the node and chars a-d are the resources 
{
	gameBoard[x].setResource(a, b, c, d);
}



void GameMap::calculate(int x)												//calculate resources gathered from a starting node
{
	wheatfield = 0; quarry = 0; meadow = 0; forest = 0;						//reset the resource markers 
	char res;

	for (int i = 0; i < 4; i++) {											//for each of the 4 resources on the harverst tile call the check function
		res = gameBoard[x].getResource(i);

		check(x, res, i);

	}

	std::cout << "\nThe points for quarry are: " << quarry;
	std::cout << "\nThe points for forest are: " << forest;
	std::cout << "\nThe points for meadow are: " << meadow;
	std::cout << "\nThe points for wheatfield are: " << wheatfield;
	std::cout << "\n\n\n";

	for (int i = 0; i < 35; i++) {												//reset the beenthere variable for each node
		for (int j = 0; j < 4; j++) {
			gameBoard[i].setBeenThere(j, false);
		}
	}
}


void GameMap::addPoint(char type)												//addpoint to resource marker depending on type
{
	switch (type) {
	case 'W': wheatfield++;
		break;
	case 'Q': quarry++;
		break;
	case 'F': forest++;
		break;
	case 'M': meadow++;
		break;
	}
}

int GameMap::check(int x, char type, int location){													//recursive method that keeps checking adjacent harvest tiles
																									//x is the node, type is the resource and location is the index of 
																									//of the resource being checked
												
	if (x > 34 || x < 0)
		return 0;

	if (gameBoard[x].getResource(location) == ' ' || !(gameBoard[x].getResource(location) == type)  //break recursiveve loop if a node is empty, not a matching resource,
			|| gameBoard[x].getBeenThere(location))													//or have examined that location
		return 0;

	if (gameBoard[x].getResource(location) == type && !gameBoard[x].getBeenThere(location)) {		//otherwise add a point and set that location to visited
		addPoint(type);
		gameBoard[x].setBeenThere(location, true);
	}
																									//for each location, call the check function with appropriate parameters		
	if (location == 0) {
		check(x, type, 1);
		check(x, type, 2);
		if (x != 5 && x != 10 && x != 15 && x != 20 && x != 25 && x != 30) {
			check(x - 1, type, 1);
		}
		check(x - 5, type, 2);
	}

	if (location == 1) {
		check(x, type, 0);
		check(x, type, 3);
		if (x != 4 && x != 9 && x != 14 && x != 19 && x != 24 && x != 29) {
			check(x + 1, type, 0);
		}
		check(x - 5, type, 3);
	}

	if (location == 2) {
		check(x, type, 0);
		check(x, type, 3);
		if (x != 5 && x != 10 && x != 15 && x != 20 && x != 25 && x != 30) {
			check(x - 1, type, 3);
		}
		check(x + 5, type, 0);
	}

	if (location == 3) {
		check(x, type, 1);
		check(x, type, 2);
		if (x != 4 && x != 9 && x != 14 && x != 19 && x != 24 && x != 29) {
			check(x + 1, type, 2);
		}
		check(x + 5, type, 1);
	}


	return 0;
}




//----------------Part 6 ii)------------------------//



Vertex::Vertex() {									//default constructor

	value = new int;
	position = new int;
	isOccupied = new bool(false);

	//will be replaced by buildingtile object
	isFaceUp = new bool(false);
	resource = new char(' ');


}

Vertex::Vertex(int val, int pos) {						//parameterized constructor taking value and position parameters

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
	if(res == 'C')										//if the char is C for the points column or row, set it to C
		*resource = res;	


	else if (this->getIsFaceUp())						//if the building tile is being placed face up, make resource eqaul the resource type
		*resource = res;								//but if face down replace the resource with an *
	
	else
		*resource = '*';
}




VillageMap::VillageMap() {								//Constructor

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
														//with parameters based on position on map

	for (int i = 0; i < 41; i++)
	{
		if (i < 5)	villageBoard[i] = Vertex(6, i);

		if (i > 5 && i < 11)	villageBoard[i] = Vertex(5, i);

		if (i > 11 && i < 17)	villageBoard[i] = Vertex(4, i);

		if (i > 17 && i < 23) 	villageBoard[i] = Vertex(3, i);

		if (i > 23 && i <29) 	villageBoard[i] = Vertex(2, i);

		if (i > 29 && i < 35) 	villageBoard[i] = Vertex(1, i);

		//the following are all colonist/points positions indicated by the resource set to C
		//(to be modified when building tiles are available)
		if (i == 5) {
			villageBoard[i] = Vertex(6, i);
			villageBoard[i].setResource('C');
		}
		if (i ==11) {
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



bool VillageMap::checkAdjacency(int i, int j)			//check to see if two vertices are adjacent by checking the adjacency matrix
{
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
			std::cout << " (" << villageBoard[i].getValue() << " " << villageBoard[i].getResource() << ") ";
	}
}

void VillageMap::displayAdjMatrix() {						//print out adjacency matrix
	for (int i = 0; i < 41; i++) {
		std::cout << "\n" << std::setw(2) << i << " ";
		for (int j = 0; j < 41; j++)
			std::cout << " " << adjMatrix[i][j];
	}
}

void VillageMap::placeBuildings(int x, bool f, char r)
{
	villageBoard[x].setIsOccupied(true);
	villageBoard[x].setIsFaceUp(f);
	villageBoard[x].setResource(r);
}

int VillageMap::villageScoring()
{
	int totalpoints = 0;

	for (int i = 0; i < 31; i += 6) {										//check all rows first for points
		bool doublepoints = true;
		int points = 0;
		int j = 0;

		while (adjMatrix[i + j][i + j + 1]) {								//continue calculation if the two vertices are adjacent

			if (!villageBoard[i + j].getIsOccupied())						//if there is no building tile in a space, that row 
				break;														//cannot have points, break the loop for that row

			if (!villageBoard[i + j].getIsFaceUp())							//if any building tile is face down, double points is false
				doublepoints = false;

			if (villageBoard[i + j + 1].getResource() == 'C') {				//if you reach a tile with resource 'C', you have got to the
				points = villageBoard[i + j + 1].getValue();				//end of a row, so you get points
				break;
			}
			j++;
		}
		if (doublepoints)													//if all building were face up, double the points else just add points
			totalpoints = totalpoints + (2 * points);
		else
			totalpoints = totalpoints + points;								//add to the total points
	}

	for (int i = 0; i < 5; i++) {											//perform the same checks as before but now checking columns
		bool doublepoints = true;
		int points = 0;
		int j = 0;

		while (adjMatrix[i + j][i + j + 6]) {

			if (!villageBoard[i + j].getIsOccupied())						//if there is no building tile in a space, that column
				break;														//cannot have points, break the loop for that column

			if (!villageBoard[i + j].getIsFaceUp())							//if any building tile is face down, double points is false
				doublepoints = false;

			if (villageBoard[i + j + 6].getResource() == 'C') {				//if you reach a tile with resource 'C', you have got to the
				points = villageBoard[i + j + 6].getValue();				//end of a column, so you get points
				break;
			}
			j = j + 6;
		}

		if (doublepoints)													//if all building were face up, double the points else just add points
			totalpoints = totalpoints + (2 * points);
		else
			totalpoints = totalpoints + points;								//add to the total points
	}

	return totalpoints;
}



