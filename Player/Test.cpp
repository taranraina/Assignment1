
#include <string>
#include <iostream>
#include "Test.h"

HarvestTile::HarvestTile(){
    isInitialized=false;
}

HarvestTile::HarvestTile(std::string resource1,std::string resource2, std::string resource3,std::string resource4 ){
    resourceArray={resource1,resource2,resource3,resource4};
}

BuildingTile::BuildingTile(int value,std::string type){
    this->value=value;
    this->type=type;
    isOnTop=true;
}

bool HarvestTile::getIsInitialized(){
    return isInitialized;
}

HarvestTileDeck::HarvestTileDeck(){
    harvestTileDeck.push_back(HarvestTile("wheat", "timber", "stone", "timber"));
    harvestTileDeck.push_back(HarvestTile("timber", "stone", "wheat", "wheat"));
}

std::array<std::string,4> HarvestTile::getResourceArray() {
    return resourceArray;
}


void BuildingTile::setValue(int value){
    this->value=value;
}
int BuildingTile::getValue() {
    return value;
}
void BuildingTile::setIsOnTop(bool isOnTop){
    this->isOnTop=isOnTop;
}

std::string BuildingTile::getType() {
    return type;
}

HarvestTile HarvestTile::orientation(int degrees) {
    return HarvestTile("timber", "wheat", "timber", "stone");
}

HarvestTile HarvestTileDeck::draw() {
    return HarvestTile("drawnCard", "drawnCard", "drawnCard", "drawnCard");
}

BuildingTileDeck::BuildingTileDeck() {
    buildingTileDeck.push_back(BuildingTile(1, "timber"));
    buildingTileDeck.push_back(BuildingTile(3, "stone"));
    buildingTileDeck.push_back(BuildingTile(4, "stone"));
    buildingTileDeck.push_back(BuildingTile(3, "wheat"));
    buildingTileDeck.push_back(BuildingTile(6, "stone"));
    buildingTileDeck.push_back(BuildingTile(6, "sheep"));
}

BuildingTile BuildingTileDeck::draw(){
    return BuildingTile(1000,"new card");
}

Hand::Hand(){
    wheat=0;
    stone=0;
    sheep=0;
    timber=0;
}
void Hand::reset() {
    wheat=0;
    stone=0;
    sheep=0;
    timber=0;
}
void Hand::exchange(int wheatCount, int stoneCount, int sheepCount, int timberCount) {
    wheat+=wheatCount;
    stone+=stoneCount;
    sheep+=sheepCount;
    timber+=timberCount;
}

int Hand::getSheep() {
    return sheep;
}

int Hand::getStone() {
    return stone;
}

int Hand::getWheat() {
    return wheat;
}

int Hand::getTimber() {
    return timber;
}

Village::Village() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            villageBoard[i][j] = BuildingTile();
        }
    }
}

bool BuildingTile::getIsInitialized() {
    return isInitialized;
}

void BuildingTile::setIsInitialized(bool isInitialized) {
    this->isInitialized = isInitialized;
}


bool Village::placeBuilding(int i, int j, BuildingTile& tile, bool isOnTop) {
    if(!isOnTop){
        tile.setValue(i);
    }

    if(isOnTop&&i!=tile.getValue()){
        std::cout<<"You cannot place a Building Tile Here since the value of your face up card does not match the row you are placing on"<<std::endl;
        return false;
    }
    if(villageBoard[i-1][j-1].getIsInitialized()){
        std::cout<<"Cannot place where already placed a tile"<<std::endl;
        return false;
    }
    else villageBoard[i-1][j-1] = tile;

    villageBoard[i-1][j-1].setIsInitialized(true);

    for (int iIdx = 0; iIdx < 6; iIdx++) {
        for (int jIdx = 0; jIdx < 5; jIdx++) {
            if(villageBoard[iIdx][jIdx].getIsInitialized()) {
                std::cout << "*\t";
            } else {
                std::cout << "-\t";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    return true;
}

Board::Board(){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            gameBoard[i][j] = HarvestTile();
        }
    }
}

void HarvestTile::setIsInitialized(bool isInitialized) {
    this->isInitialized = isInitialized;
}

bool Board::placeHarvestTileOnBoard(int i, int j, HarvestTile tile,Hand& hand) {
    if(!gameBoard[i][j].getIsInitialized()){
        gameBoard[i][j]=tile;
        gameBoard[i][j].setIsInitialized(true);
        for (int iIdx = 0; iIdx < 5; iIdx++) {
            for (int jIdx = 0; jIdx < 5; jIdx++) {
                if (!gameBoard[iIdx][jIdx].getIsInitialized()) {
                    std::cout << "-\t";
                } else {
                    std::cout << "*\t";
                }
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;

        return true;
    }
    else {
        std::cout<<"There is already a tile here! Place somewhere else! "<<std::endl;
        return false;
    }
}
