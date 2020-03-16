#pragma once
#include "Node.h"
#include <list>

using namespace std;

class BFSGraph
{
private:

	int vertices;



public:
	~BFSGraph();
	BFSGraph();
	void BFSSearch(vector<Node*>);
	bool listChecker(vector<Node*>, vector<Node*>, Node*);

};
