#include "pch.h"
#include "Scoring.h"
#include <iostream>



int main()
{

	//----------------Part 6 i)------------------------//


	GameMap first;


	/*//Test A
	first.placeResources(3, 'F', 'M', 'W', 'M');
	first.placeResources(4, 'W', 'W', 'W', 'F');
	first.placeResources(8, 'W', 'M', 'W', 'W');
	first.placeResources(9, 'W', 'M', 'W', 'F');
	first.placeResources(14, 'W', 'F', 'M', 'F');
	
	first.calculate(14);

	//Test B
	first.placeResources(20, 'M', 'M', 'M', 'Q');
	first.placeResources(21, 'M', 'F', 'Q', 'Q');
	first.placeResources(25, 'M', 'Q', 'M', 'W');

	first.calculate(21);


	//Test C
	first.placeResources(28, 'Q', 'Q', 'W', 'F');
	first.placeResources(29, 'Q', 'Q', 'F', 'W');
	first.placeResources(34, 'F', 'W', 'Q', 'Q');

	first.calculate(34);

	//Test D
	first.placeResources(17, 'F', 'Q', 'F', 'M');

	first.calculate(17);*/




//----------------Part 6 ii)------------------------//

VillageMap second;

second.placeBuildings(0, true, 'F');
second.placeBuildings(1, true, 'F');
second.placeBuildings(4, true, 'M');
second.placeBuildings(6, true, 'Q');
second.placeBuildings(7, true, 'F');
second.placeBuildings(8, true, 'F');
second.placeBuildings(10, true, 'M');
second.placeBuildings(12, true, 'Q');
second.placeBuildings(13, true, 'Q');
second.placeBuildings(14, true, 'W');
second.placeBuildings(15, true, 'M');
second.placeBuildings(16, true, 'M');
second.placeBuildings(18, true, 'W');
second.placeBuildings(19, true, 'W');
second.placeBuildings(20, true, 'W');
second.placeBuildings(21, true, 'M');
second.placeBuildings(22, true, 'M');
second.placeBuildings(24, true, 'W');
second.placeBuildings(30, true, 'W');
second.placeBuildings(31, true, 'W');



second.displayVillageBoard();
std::cout << "\n\nFrom this village map we scored " << second.villageScoring()<<"\n\n";



return 0;

}