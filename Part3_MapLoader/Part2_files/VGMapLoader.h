#pragma once
#include < vector>
#include <string>
#include "Node.h"
#include "VGMap.h"

using namespace std;

class VGMapLoader
{
public:
	~VGMapLoader();
	VGMapLoader();
	void addVertex(Vertex*);
	void addNode(Node*);
	vector<Node*> getNodes();
	vector<Vertex*> getVertices();
	void printMap();
	static  VGMapLoader* readMap(string);

private:
	VGMapLoader* vgnap;
	vector<Vertex*> listOfVertices;
	vector<Node*> listOfNodes;
	static string getDelimitedSubString(string, string, string);
	static vector<string> getRepeatedDelimitedSubString(string, string, string);

};
