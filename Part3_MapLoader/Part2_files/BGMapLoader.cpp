#include <iostream>
#include "BGMapLoader.h"
#include "Node.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

BGMapLoader::~BGMapLoader()
{
	for (Node* i : listOfNodes)
	{
		delete i;
	}
}

BGMapLoader::BGMapLoader()
{
}

void BGMapLoader::addNode(Node* node)
{
	listOfNodes.push_back(node);
}

vector<Node*> BGMapLoader::getNodes()
{
	return listOfNodes;
}

void BGMapLoader::printMap()
{

	for (Node* nodeValue : listOfNodes) {

		Node* top = nodeValue->getTop();
		Node* left = nodeValue->getLeft();
		Node* right = nodeValue->getRight();
		Node* bottom = nodeValue->getBottom();

		nodeValue->printDetails();
		cout << "Adjacent Nodes: " << endl;
		cout << "\tTop Node: ";

		if (top != NULL)
		{
			top->printDetails();
		}
		else {
			cout << endl;
		}
		cout << "\tLeft Node: ";
		if (left != NULL)
		{
			left->printDetails();
		}
		else {
			cout << endl;
		}
		cout << "\tRight Node: ";
		if (right != NULL)
		{
			right->printDetails();
		}
		else {
			cout << endl;
		}
		cout << "\tBottom Node: ";
		if (bottom != NULL)
		{
			bottom->printDetails();
		}
		else {
			cout << endl;
		}
		cout << endl;

	}
}



BGMapLoader* BGMapLoader::readMap(string filename)
{
	string file;
	string line;
	BGMapLoader* map = new BGMapLoader();
	ifstream input;

	input.open(filename);

	if (!input.is_open())
	{
		cout << "Error with opening file : " << endl;

	}

	while (input)
	{
		getline(input, line);
		input >> ws;

		if (!input) {
			break;
		}
		file += line;
	}

	input.close();

	string start_Delimiter;
	string end_Delimiter;
	string element;
	string tileId;
	string adjacentTiles;
	string adjacentTileId;



	start_Delimiter = "<BoardMap>";
	end_Delimiter = "</BoardMap>";
	element = getDelimitedSubString(file, start_Delimiter, end_Delimiter);

	start_Delimiter = "<BoardElement>";
	end_Delimiter = "</BoardElement>";
	vector<string> boardElementslist = getRepeatedDelimitedSubString(element, start_Delimiter, end_Delimiter);

	for (string boardElement : boardElementslist)
	{
		// get TILE ID
		start_Delimiter = "<TileId>";
		end_Delimiter = "</TileId>";
		tileId = getDelimitedSubString(boardElement, start_Delimiter, end_Delimiter);

		//cout << "TILE ID: " << stoi(tileId) << endl;


		map->addNode(new Node(stoi(tileId))); // All Ids are passed into map

	}


	vector<Node*> tempListOfNodes = map->getNodes();

	for (string boardElement : boardElementslist)
	{
		// get TILE ID
		start_Delimiter = "<TileId>";
		end_Delimiter = "</TileId>";
		tileId = getDelimitedSubString(boardElement, start_Delimiter, end_Delimiter);

		//cout << "TILE ID:\n " << tileId << endl;

		//AdjacenTiles
		start_Delimiter = "<AdjacentTiles>";
		end_Delimiter = "</AdjacentTiles>";
		adjacentTiles = getDelimitedSubString(boardElement, start_Delimiter, end_Delimiter);

		//cout << "adj ID: " << adjacentTiles << endl;

		start_Delimiter = "<AdjacentTile>";
		end_Delimiter = "</AdjacentTile>";
		vector<string>adjacentTileList = getRepeatedDelimitedSubString(boardElement, start_Delimiter, end_Delimiter);


		int count = 0;
		for (string adjacentTileData : adjacentTileList)
		{
			start_Delimiter = "<Id>";
			end_Delimiter = "</Id>";
			adjacentTileId = getDelimitedSubString(adjacentTileData, start_Delimiter, end_Delimiter);


			if (adjacentTileId.find("null") == std::string::npos)
			{
				int tileValue = stoi(tileId);
				int adjacentTileValue = stoi(adjacentTileId);
				if (count == 0)
				{

					tempListOfNodes[tileValue]->setTop(tempListOfNodes[adjacentTileValue]);
				}
				else if (count == 1)
				{
					tempListOfNodes[tileValue]->setLeft(tempListOfNodes[adjacentTileValue]);
				}
				else if (count == 2)
				{
					tempListOfNodes[tileValue]->setRight(tempListOfNodes[adjacentTileValue]);
				}
				else if (count == 3)
				{
					tempListOfNodes[tileValue]->setBottom(tempListOfNodes[adjacentTileValue]);
				}

				count += 1;
			}
			else {
				count += 1;

			}
		}
	}
	return map;
}

string BGMapLoader::getDelimitedSubString(string fullString, string startDelimiter, string endDelimiter)
{
	unsigned first = fullString.find(startDelimiter);
	unsigned end_first = first + startDelimiter.length();
	unsigned last = fullString.find(endDelimiter);

	return fullString.substr(end_first, last - end_first);
}

vector<string> BGMapLoader::getRepeatedDelimitedSubString(string fullString, string startDelimiter, string endDelimiter)
{
	vector<string> subStringPairs;
	string leftOverString = fullString;
	unsigned first;
	unsigned end_first;
	unsigned last;

	while (true)
	{
		if (leftOverString.find(startDelimiter) == std::string::npos)
		{
			break;
		}
		first = leftOverString.find(startDelimiter);
		end_first = first + startDelimiter.length();

		if (leftOverString.find(endDelimiter) == std::string::npos)
		{
			break;
		}
		last = leftOverString.find(endDelimiter);

		string tempString = leftOverString.substr(end_first, last - end_first);
		subStringPairs.push_back(tempString);
		leftOverString = leftOverString.substr(last + endDelimiter.length());

	}

	return subStringPairs;
}
