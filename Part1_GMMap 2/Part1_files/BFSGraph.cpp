#include <iostream>
#include <list>
#include "BFSGraph.h"
#include "Node.h"

using namespace std;


BFSGraph::~BFSGraph()
{

}

BFSGraph::BFSGraph()
{

}



bool BFSGraph::listChecker(vector<Node*> closedList, vector<Node*>openList, Node* child)
{


	for (Node* i : closedList)
	{
		if (i->getId() == child->getId())
			return true;
	}
	for (Node* i : openList)
	{
		if (i->getId() == child->getId())
			return true;
	}


	return false;
}

void BFSGraph::BFSSearch(vector<Node*> boardNodes)
{
	vector <Node*> openList;
	vector <Node*> closeList;


	Node* top = boardNodes[0]->getTop();
	Node* left = boardNodes[0]->getLeft();
	Node* right = boardNodes[0]->getRight();
	Node* bottom = boardNodes[0]->getBottom();


	if (top != NULL)
		openList.push_back(top);

	if (left != NULL)
		openList.push_back(left);

	if (right != NULL)
		openList.push_back(right);

	if (bottom != NULL)
		openList.push_back(bottom);

	closeList.push_back(boardNodes[0]);

	while (openList.size() != 0)
	{
		Node* firstTemp = openList.front();


		Node* top = firstTemp->getTop();
		Node* left = firstTemp->getLeft();
		Node* right = firstTemp->getRight();
		Node* bottom = firstTemp->getBottom();





		if (top != NULL && !listChecker(closeList, openList, top))
			openList.push_back(top);

		if (left != NULL && !listChecker(closeList, openList, left))
			openList.push_back(left);

		if (right != NULL && !listChecker(closeList, openList, right))
			openList.push_back(right);

		if (bottom != NULL && !listChecker(closeList, openList, bottom))
			openList.push_back(bottom);

		openList.erase(openList.begin());

		closeList.push_back(firstTemp);

	}
	cout << "After traversal... There are " << closeList.size() << " connected nodes\n" << endl;;

	if (boardNodes.size() != closeList.size()) 
	{
		cout << "There exists a node that is not connected to the rest!" << endl;
	}
	else {
		cout << "All of the nodes are connected! " << endl;
	}
}




