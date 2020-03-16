#include "pch.h"
#include "VGMap.h"
#include <iostream>



int main()
{		
	VillageMap first;
	

	std::cout << "\n\n";
	first.displayVillageBoard();
	std::cout << "\n\n";
	first.displayAdjMatrix();
	std::cout << "\n\n";

	std::cout << "\nCheck if these two vertices 20 and 26 are adjacent\n";	
	std::cout<<first.checkAdjacency(20,26) <<"\n";
	
	std::cout << "\nCheck if these two vertices 1 and 12 are adjacent\n";
	std::cout << first.checkAdjacency(1, 12) << "\n";
	
	std::cout << "\nCheck if these two vertices 5 and 6 are adjacent\n";
	std::cout << first.checkAdjacency(5, 6) << "\n\n";

	
	return 0;


}