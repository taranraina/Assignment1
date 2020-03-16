#pragma once
#include "Node.h"
#include<iostream >

using namespace std;

Node::~Node()
{


}

Node::Node(int setID)
{
	id = setID;
	left = NULL;
	right = NULL;
	top = NULL;
	bottom = NULL;
	data = NULL;
}

int Node::getId()
{
	return id;
}

void Node::setId(int passedID)
{
	id = passedID;
}

Node* Node::getTop()
{
	return top;
}

Node* Node::getLeft()
{
	return left;
}

Node* Node::getRight()
{
	return right;
}

Node* Node::getBottom()
{
	return bottom;
}

void Node::setTop(Node* nodeTop)
{
	top = nodeTop;
}

void Node::setLeft(Node* nodeLeft)
{
	left = nodeLeft;
}

void Node::setRight(Node* nodeRight)
{
	right = nodeRight;
}

void Node::setBottom(Node* nodeBottom)
{
	bottom = nodeBottom;
}

void Node::setData(Card* addedCard)
{
	data = addedCard;
}

Card* Node::getData()
{
	return data;
}

void Node::printDetails()
{
	cout << "ID: " << id << endl;
}
