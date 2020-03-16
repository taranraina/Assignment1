#pragma once

//----------------Part 6 i)------------------------//
class Node {
private:

	int *position;								//position of Node on the game board

	bool *beenThere;							//check if the current location has already been vistited

	char *resource;								//resources of the harvest tile on the village board (will be replaced with
												//pointer to harvest tile object)


public:


	Node();										//default constructor

	Node(int val);								//parameterized constructor

	~Node();									//destructor

	Node(const Node &V);						//copy constructor

	Node & operator=(const Node &V);			//assignment operator overload

	int getPosition();							//getters and setters

	char getResource(int x);

	void setResource(char a, char b, char c, char d);

	void setBeenThere(int x, bool been);

	bool getBeenThere(int x);


};



class GameMap {
private:
	Node *gameBoard;												//the gameboard
																	
public:																
	GameMap();														//default constructor
																	
	~GameMap();														//destructor

	void placeResources(int x, char a, char b, char c, char d);		//places resource tile on a node, where x is the node and a-d are the resources 
																	//(will be replaced and implemented by pointing to a harvest tile object)

	void calculate(int x);											//calculate the resources gathered starting from node x

	void addPoint(char type);										//addpoint if checking the right resource type

	int check(int x, char type, int location);						//used by calculate method to check surrounding nodes

};





//----------------Part 6 ii)------------------------//

class Vertex {
private:

	int *value;									//value of the location on village board

	int *position;								//position of vertex on the village board

	bool *isOccupied;							//is the villageboard space occupied 

	bool *isFaceUp;								//is the building tile face up(will be replaced with pointer to 
												//actual building tile object)

	char *resource;								//the building tile resoruce (will be replaced with pointer to 
												//actual building tile object)

public:

	Vertex();									//default constructor

	Vertex(int val, int pos);					//parameterized constructor value and position parameters

	~Vertex();									//destructor

	Vertex(const Vertex &V);					//copy constructor

	Vertex & operator=(const Vertex &V);		//assignment operator overload 

	

	int getValue();								//getters and setters

	int getPosition();

	bool getIsOccupied();

	bool getIsFaceUp();

	char getResource();

	void setIsOccupied(bool empty);

	void setIsFaceUp(bool empty);

	void setResource(char res);
};



class VillageMap {
private:
	int **adjMatrix;
	Vertex *villageBoard;

public:
	VillageMap();								//default constructor

	~VillageMap();								//destructor

	void addEdges();							//update adjacency matrix

	bool checkAdjacency(int i, int j);			//check to see if two vertices are adjacent

	void displayVillageBoard();					//print out the villageboard

	void displayAdjMatrix();					//print out the adjacency matrix showing which vertices haves 
												//connecting edges

	void placeBuildings(int x, bool f, char r); //places building tile on a node, where x is the node f is a boolean for face up and r is the resource of the building  
												//(will be replaced and implemented by pointing to a building tile object)

	int villageScoring();						//used to calculate points from village board
	


};

