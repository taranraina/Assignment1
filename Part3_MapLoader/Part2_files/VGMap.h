#pragma once
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

	Vertex(int val, int pos);					//parameterized constructor

	~Vertex();									//destructor

	Vertex(const Vertex &V);					//copy constructor

	Vertex & operator=(const Vertex &V);		//operator=, assignment 

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
	VillageMap();

	~VillageMap();

	void addEdges();

	bool checkAdjacency(int i, int j);
	
	void displayVillageBoard();

	void displayAdjMatrix();
};