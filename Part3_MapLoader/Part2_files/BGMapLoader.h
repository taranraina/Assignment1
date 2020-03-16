#pragma once
#include < vector>
#include <string>
#include "Node.h"

using namespace std;

class BGMapLoader
{
public:
	~BGMapLoader();
	BGMapLoader();
	void addNode(Node*);
	vector<Node*> getNodes();
	void printMap();
	static  BGMapLoader* readMap(string);

private:
	vector<Node*> listOfNodes;
	static string getDelimitedSubString(string, string, string);
	static vector<string> getRepeatedDelimitedSubString(string, string, string);

};
