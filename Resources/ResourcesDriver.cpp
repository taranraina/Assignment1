
#include <iostream>
#include "Resources.h"
int main() {

    HarvestTileDeck deck;
    BuildingTileDeck building;

    std::cout << "Drawing entire harvest tile deck :" << std::endl;
    deck.viewHarvestDeck();

    std::cout << std::endl;

    std::cout << "Drawing 2 harvest tiles :" << std::endl;
    for (int i = 0; i<2; i++) {
        deck.draw()->printHarvestTile();
    }
    std::cout << std::endl;

    std::cout<<"Notice how the draw function does not call the same tiles from the deck anymore..."<<std::endl;
    std::cout << "Drawing 2 harvest tiles :" << std::endl;
    for (int i = 0; i<2; i++) {
        deck.draw()->printHarvestTile();
    }
    std::cout << std::endl;

    std::cout<<"Last call with new values again!!"<<std::endl;
    std::cout << "Drawing 2 harvest tiles :" << std::endl;
    for (int i = 0; i<2; i++) {
        deck.draw()->printHarvestTile();
    }    std::cout << std::endl;



    std::cout << "Drawing entire building tile deck :" << std::endl;
    building.viewBuildingDeck();
    std::cout << std::endl;


    std::cout << "Drawing 6 Building tiles :" << std::endl;
    for (int i = 0; i<6; i++) {
        building.draw().printBuildingTile();
    }
    std::cout << std::endl;


    std::cout << "Drawing another 6 Building tiles (Cannot repeat!):" << std::endl;
    for (int i = 0; i<6; i++) {
        building.draw().printBuildingTile();
    }
    std::cout << std::endl;

    std::cout<<"Let us change the orientation of one of the tiles drawn: 35"<<std::endl;
    std::cout<<"Original Harvest Tile 35"<<std::endl;
    int tileNo=35;
    deck.getHarvestTile(tileNo-1).printHarvestTile();
    std::cout<<"Rotated Harvest Tile 35 a 90 degrees"<<std::endl;
    deck.orientation(90,tileNo-1).printHarvestTile(); //index card you draw -1
    std::cout<<"Rotated Harvest Tile 35 a 180 degrees"<<std::endl;
    deck.orientation(180,tileNo-1).printHarvestTile(); //index card you draw -1
    std::cout<<"Rotated Harvest Tile 35 a 270 degrees"<<std::endl;
    deck.orientation(270,tileNo-1).printHarvestTile(); //index card you draw -1
    return 0;

}