#pragma once
#include<string>
#include<vector>
#include <iostream>
#include"Card.h"
#include"Node.h"

using namespace std;

class GBMap
{
public:
	~GBMap();
	GBMap();
	GBMap(int);
	int getNumberOfPlayers();
	void setNumberOfPlayers(int);
	void createMap(int);
	vector<Node*> getBoardMap();





private:
	int numberOfPlayers;
	vector<Node*> boardMap;


};

