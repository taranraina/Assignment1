
#include <iostream>
#include <vector>
#include"Node.h"
#include"VGMap.h"
#include"BGMapLoader.h"
#include"VGMapLoader.h"

using namespace std;

int main()
{
	BGMapLoader* newBGMap = BGMapLoader::readMap("Boardmap.map");
	VGMapLoader* newVGMap = VGMapLoader::readMap("VGBoard.map");



	//cout << newVGMap.getNodes().size() << endl;
	cout << "BoardMap tile information:\n" << endl;
	newBGMap->printMap();
	cout << "===============================" << endl;
	cout << "VillageMap tile information:\n" << endl;
	newVGMap->printMap();

	delete newVGMap;
	delete newBGMap;

	return 0;



}
