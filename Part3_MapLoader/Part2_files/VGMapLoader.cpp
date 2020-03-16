#include <iostream>
#include "Node.h"
#include "VGMapLoader.h"
#include "VGMap.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

VGMapLoader::~VGMapLoader()
{
	for (Node* i : listOfNodes)
	{
		delete i;
	}
	listOfNodes.clear();

	for (Vertex* i : listOfVertices)
	{
		delete i;
	}
	listOfVertices.clear();
}

VGMapLoader::VGMapLoader()
{
}

void VGMapLoader::addVertex(Vertex* temp)
{
	listOfVertices.push_back(temp);
}

void VGMapLoader::addNode(Node* vertex)
{
	listOfNodes.push_back(vertex);
}

vector<Node*> VGMapLoader::getNodes()
{
	return listOfNodes;
}

vector<Vertex*> VGMapLoader::getVertices()
{
	return listOfVertices;
}

void VGMapLoader::printMap()
{


	for (int i = 0; i < listOfNodes.size(); i++)
	{
		Node* top = listOfNodes[i]->getTop();
		Node* left = listOfNodes[i]->getLeft();
		Node* right = listOfNodes[i]->getRight();
		Node* bottom = listOfNodes[i]->getBottom();

		listOfNodes[i]->printDetails();
		cout << "value: " << listOfVertices[i]->getValue() << endl;
		cout << "Adjacent Vertex: " << endl;
		cout << "\tTop Vertex: ";

		if (top != NULL)
		{
			top->printDetails();
		}
		else {
			cout << endl;
		}
		cout << "\tLeft Vertex: ";
		if (left != NULL)
		{
			left->printDetails();
		}
		else {
			cout << endl;
		}
		cout << "\tRight Vertex: ";
		if (right != NULL)
		{
			right->printDetails();
		}
		else {
			cout << endl;
		}
		cout << "\tBottom Vertex: ";
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



VGMapLoader* VGMapLoader::readMap(string fileName)
{
	string file;
	string line;
	ifstream input;
	VGMapLoader* vgMap = new VGMapLoader();
	input.open(fileName);

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
	string vertexId;
	string valueId;
	string adjacentVertices;
	string adjacentVertexId;

	start_Delimiter = "<VGBoard>";
	end_Delimiter = "</VGBoard>";
	element = getDelimitedSubString(file, start_Delimiter, end_Delimiter);



	start_Delimiter = "<MapElement>";
	end_Delimiter = "</MapElement>";
	vector<string> villageElementsList = getRepeatedDelimitedSubString(element, start_Delimiter, end_Delimiter);

	for (string villageElement : villageElementsList)
	{
		start_Delimiter = "<VertexId>";
		end_Delimiter = "</VertexId>";
		vertexId = getDelimitedSubString(villageElement, start_Delimiter, end_Delimiter);

		//cout << "vertex ID: " << stoi(vertexId) << endl;

		start_Delimiter = "<Value>";
		end_Delimiter = "</Value>";
		valueId = getDelimitedSubString(villageElement, start_Delimiter, end_Delimiter);

		//cout << "\tvalue : " << stoi(valueId) << endl;

		vgMap->addVertex((new Vertex(stoi(valueId), stoi(vertexId))));
		vgMap->addNode(new Node(stoi(vertexId)));
	}

	vector<Node*> tempListOfNodes = vgMap->getNodes();
	vector<Vertex*> tempListOfVertices = vgMap->getVertices();



	for (string villageElement : villageElementsList)
	{
		start_Delimiter = "<VertexId>";
		end_Delimiter = "</VertexId>";
		vertexId = getDelimitedSubString(villageElement, start_Delimiter, end_Delimiter);

		start_Delimiter = "<AdjacentVertices>";
		end_Delimiter = "</AdjacentVertices>";
		adjacentVertices = getDelimitedSubString(villageElement, start_Delimiter, end_Delimiter);

		start_Delimiter = "<AdjacentVertex>";
		end_Delimiter = "</AdjacentVertex>";
		vector<string> adjacentVertexList = getRepeatedDelimitedSubString(villageElement, start_Delimiter, end_Delimiter);

		int count = 0;
		for (string adjacentVertex : adjacentVertexList)
		{
			start_Delimiter = "<Id>";
			end_Delimiter = "</Id>";
			adjacentVertexId = getDelimitedSubString(adjacentVertex, start_Delimiter, end_Delimiter);

			if (adjacentVertexId.find("null") == std::string::npos)
			{
				int vertexIndex = stoi(vertexId);
				int adjacentVertexIndex = stoi(adjacentVertexId);

				if (count == 0) {

					tempListOfNodes[vertexIndex]->setTop(tempListOfNodes[adjacentVertexIndex]);

				}
				else if (count == 1) {

					tempListOfNodes[vertexIndex]->setLeft(tempListOfNodes[adjacentVertexIndex]);
				}
				else if (count == 2) {

					tempListOfNodes[vertexIndex]->setRight(tempListOfNodes[adjacentVertexIndex]);
				}
				else if (count == 3) {

					tempListOfNodes[vertexIndex]->setBottom(tempListOfNodes[adjacentVertexIndex]);
				}

				count += 1;
			}
			else
			{
				count += 1;
			}
		}
	}
	return vgMap;
}

string VGMapLoader::getDelimitedSubString(string fullString, string startDelimiter, string endDelimiter)
{
	unsigned first = fullString.find(startDelimiter);
	unsigned end_first = first + startDelimiter.length();
	unsigned last = fullString.find(endDelimiter);

	return fullString.substr(end_first, last - end_first);
}

vector<string> VGMapLoader::getRepeatedDelimitedSubString(string fullString, string startDelimiter, string endDelimiter)
{
	vector<string> subStringPairs;
	string leftOver = fullString;
	unsigned first;
	unsigned end_first;
	unsigned last;

	while (true)
	{
		if (leftOver.find(startDelimiter) == std::string::npos)
		{
			break;
		}
		first = leftOver.find(startDelimiter);
		end_first = first + startDelimiter.length();

		if (leftOver.find(endDelimiter) == std::string::npos)
		{
			break;
		}
		last = leftOver.find(endDelimiter);

		string temp = leftOver.substr(end_first, last - end_first);
		subStringPairs.push_back(temp);
		leftOver = leftOver.substr(last + endDelimiter.length());

	}




	return subStringPairs;
}
