
#include <iostream>
#include "Player.h"

void printTiles(Player& player);
void printTile(Player& player,int index);
void printBuildings(Player& player);
void printBuilding(Player& player,int index);
void printResources(Player& player);
int main() {

    HarvestTileDeck harvestTileDeck;
    BuildingTileDeck buildingDeck;
    Hand hand;
    Board gameBoard;

    //Create building objects
    Player p1(harvestTileDeck, buildingDeck, hand, gameBoard);
    Player p2(harvestTileDeck, buildingDeck, hand, gameBoard);
    //print the resources at start

    std::cout << "Value of Resources at the start of a turn" << std::endl;
    printResources(p1);
    std::cout << std::endl;

    std::cout << "---------------------------------------------" << std::endl;
    //print player 1's harvest tiles
    std::cout << "Player 1 harvest tiles" << std::endl;
    printTiles(p1);
    //player 1 placing their harvest tiles

    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Player 1 placing their harvest tile..............." << std::endl;

    int tileValue;
    std::cout << "Which harvest tile from your hand would you like to place: 1 or 2? " << std::endl;
    std::cin >> tileValue;

    //make sure the card index is an acceptable value
    while (tileValue < 1 || tileValue > 2) {
        std::cout << "Invalid tile, please enter 1 or 2" << std::endl;
        std::cin >> tileValue;
    }

    int row;
    int col;
    std::cout
            << "Where on the board would you like to place your harvest tile? Enter the row followed by the column (5x5)"
            << std::endl;
    std::cin >> row;
    std::cin >> col;

    while ((row < 0 || row > 4) || (col < 0 || col > 4)) {
        std::cout << "Incorrect value for row or col " << std::endl;
        std::cin >> row;
        std::cin >> col;
    }

    std::cout << "Chosen Harvest Tile" << std::endl;
    printTile(p1, tileValue );

    p1.placeHarvestTile(tileValue, 90, row, col); // 2,90,3,4;
    //show update of resources after placing a tile
    std::cout << "Star is the location on where the harvest tile is placed!!" << std::endl;
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Resource Markers allocation after Player one Places their tile" << std::endl;
    printResources(p1);
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    //after a new tile is drawn this will print the update of their hand
    std::cout << "Player 1's new harvest tile hand" << std::endl;
    printTiles(p1);

    std::cout << "---------------------------------------------" << std::endl;

    //print their building tiles
    std::cout << "Player 1's building tiles" << std::endl;
    printBuildings(p1);

    std::cout << "---------------------------------------------" << std::endl;

    //placing a tile on the the village board, and the update of the resource markers based on that
    std::cout << "Player 1's Village Board after placing a building....." << std::endl;
    std::cout << std::endl;

    int buildNo;
    std::cout << "Which building tile from your hand would you like to place: 1-6? " << std::endl;
    std::cin >> buildNo;

    //make sure the card index is an acceptable value
    while (buildNo < 1 || buildNo > 6) {
        std::cout << "Invalid building tile, please enter a value 1-6" << std::endl;
        std::cin >> buildNo;
    }

    std::cout << "You have chosen building tile: " << std::endl;
    printBuilding(p1, buildNo);

    std::cout
            << "Where on the village board would you like to place your building tile? Enter the row followed by the column (6x5)"
            << std::endl;
    std::cin >> row;
    std::cin >> col;


    while ((row < 1 || row > 6) || (col < 1 || col > 5)) {
        std::cout << "Incorrect value for row or col " << std::endl;
        std::cin >> row;
        std::cin >> col;
    }

    p1.BuildVillage(buildNo, row, col, true); //3,4,4,true

    //stone gets updated to 1 (5-4)

    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Resource Update after Player 1 builds village" << std::endl;
    printResources(p1);
    std::cout << std::endl;

    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Player 1's New building tiles (Calling Drawn)" << std::endl;
    printBuildings(p1);
    std::cout << "---------------------------------------------" << std::endl;


    std::cout << "Player 2 building tiles" << std::endl;
    printBuildings(p2);
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Player 2 trying to use the resources set by player 1" << std::endl;

    std::cout << "Player 2 placing their 6th building tile down face down at (1,1): ";
    printBuilding(p2, 6);
    std::cout << "Player 2's board after placing their building tile" << std::endl;
    p2.BuildVillage(6, 1, 1, false); //here the value of tile should be 5 and not 3

    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Player 2 new building tiles" << std::endl;
    printBuildings(p2);
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Resource Update after Player 2 builds village" << std::endl;
    printResources(p2);
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Player 2 harvest tiles" << std::endl;
    printTiles(p2);

    std::cout << "Player 2's trying to place where it is already placed" << std::endl;
    p2.placeHarvestTile(2, 90, 3, 4); //1,1,1,1
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Player 2 harvest tiles" << std::endl;
    printTiles(p2);

    std::cout << "Resource Update after Player 2 places tile" << std::endl;
    printResources(p2);
    std::cout << std::endl;

    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Player 2's trying to place a building tile of a mismatching value.." << std::endl;
    std::cout << "Player 2 is trying to place a card face up of value one, on the position of 2.." << std::endl;
    std::cout << std::endl;
    std::cout << "Will correct: Placing value three, on the position of three.. Choose card 2" << std::endl;
    printBuilding(p2,2);

    p2.BuildVillage(2, 2, 2, true); // 1,1,1

    std::cout << "Player 2's board with new Building" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Resource Update after Player 2 places building tile" << std::endl;
    printResources(p2);
    std::cout << std::endl;
    return 0;
}



void printTiles(Player& player) {
    for (int i = 0; i < 2; i++) {
        std::cout<<"Tile :"<<i+1<<std::endl;
        HarvestTile tile = player.getHarvestTile(i);
        for (int j = 0; j < 4; j++) {
            std::cout << tile.getResourceArray().at(j) << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printTile(Player& player,int index){
    HarvestTile tile = player.getHarvestTile(index-1);
    for (int j = 0; j < 4; j++) {
        std::cout << tile.getResourceArray().at(j) << '\t';
    }
    std::cout << std::endl;
}
void printBuilding(Player& player,int index){
    BuildingTile tile = player.getBuildingTile(index-1);
    std::cout << tile.getType() << ", " << tile.getValue() << '\t' << std::endl;
    std::cout << std::endl;

}

void printBuildings(Player& player) {
    for (int i = 0; i < 6; i++) {
        BuildingTile tile = player.getBuildingTile(i);
        std::cout << tile.getType() << ", " << tile.getValue() << '\t' << std::endl;
    }
    std::cout << std::endl;
}

void printResources(Player& player) {
    std::cout << "Resources" << std::endl;
    std::cout << "Sheep: " << player.getHandPtr()->getSheep() << std::endl;
    std::cout << "Wheat: "<<player.getHandPtr()->getWheat() << std::endl;
    std::cout << "Stone: "<<player.getHandPtr()->getStone() << std::endl;
    std::cout<< "Timber: "<<player.getHandPtr()->getTimber() << std::endl;

};