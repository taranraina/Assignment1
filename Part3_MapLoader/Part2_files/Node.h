#pragma once
#include<string>
#include<vector>
#include <iostream>
#include"Card.h"

using namespace std;

class Node
{

public:
	~Node();
	Node(int);
	int getId(); 
	void setId(int);
	Node* getTop();
	Node* getLeft();
	Node* getRight();
	Node* getBottom();
	void setTop(Node*);
	void setLeft(Node*);
	void setRight(Node*);
	void setBottom(Node*);
	void setData(Card*);
	Card* getData();
	void printDetails();
	int id; // store title location


private:
	Node* left, * right, * top, * bottom;

	Card* data; // The node data i.e. Should be from Card class: Harvest or Pond

};

