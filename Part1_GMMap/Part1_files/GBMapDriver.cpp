
#include <iostream>
#include <vector>
#include"Node.h"
#include"GBMap.h"
#include "BFSGraph.h"

using namespace std;


int main()
{ 
	int gamers;

	cout <<" How many players are playing" << endl;
	cin >> gamers;

	GBMap* Map = new GBMap();

	Map->createMap(gamers);

	vector<Node*> boardMap = Map->getBoardMap();

	cout << "How many nodes are active in the Map?" << endl;
	cout << boardMap.size() << endl;
	
	cout << "Traversing through connected nodes..." << endl;

	BFSGraph connectedTraverse;

	connectedTraverse.BFSSearch(boardMap);


	
	

	for (int i = 0; i < boardMap.size(); i++) {


		Node* top = boardMap[i]->getTop();
		Node* left = boardMap[i]->getLeft();
		Node* right = boardMap[i]->getRight();
		Node* bottom = boardMap[i]->getBottom();



		cout << "Tile: " << boardMap[i]->getId() << endl;
		cout << "\tTop: " << (top != NULL ? to_string(top->getId()) : "null") << endl;
		cout << "\tLeft: " << (left != NULL ? to_string(left->getId()) : "null") << endl;
		cout << "\tRight: " << (right != NULL ? to_string(right->getId()) : "null") << endl;
		cout << "\tBottom: " << (bottom != NULL ? to_string(bottom->getId()) : "null") << endl;
		

	}

	
	delete Map;
	boardMap.clear();

	return 0;


		

}

