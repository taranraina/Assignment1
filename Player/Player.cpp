#include <iostream>
#include <vector>
#include "Player.h"

Player::Player(HarvestTileDeck &harvestTileDeck, BuildingTileDeck &buildingTileDeck, Hand &hand,Board& gameBoard) {

    /*Initialize the players harvest tile hand
     * In the actual full implementation the pointer that is storing the Harvest Tiles would be calling the draw function from Part5
     * For simplicty, 2 harvest tiles are being hard-coded for the player.
     */

    playerHarvestTile=new HarvestTile[2];

    playerHarvestTile[0]=HarvestTile("wheat", "timber", "stone", "timber");
    playerHarvestTile[1]=(HarvestTile("timber", "stone", "wheat", "wheat"));

    /*Initialize the players Building tile hand
     * In reality the pointer that is storing the Building Tiles would be calling the draw function from Part5
     * For simplicty, 6 building tiles are being hard-coded for the player.
     */
    playerBuildingTile=new BuildingTile[6];
    playerBuildingTile[0]=(BuildingTile(1, "timber"));
    playerBuildingTile[1]=(BuildingTile(3, "stone"));
    playerBuildingTile[2]=(BuildingTile(4, "stone"));
    playerBuildingTile[3]=(BuildingTile(3, "wheat"));
    playerBuildingTile[4]=(BuildingTile(6, "stone"));
    playerBuildingTile[5]=(BuildingTile(6, "sheep"));

    //TODO : IN REALITY THIS WILL CALL THE DRAW FUNCTION THAT IS IN PART 5, AND THAT WILL RETURN HARVEST TILES
    //TODO: BASED ON THE WAY THAT IT IS IMPLEMENTED

    this->gameBoard = &gameBoard; //make sure all the players have the reference to the same game board
    harvestTileDeckPtr = &harvestTileDeck; //make sure all the players have the reference to the same harvest tile deck
    buildingTileDeckPtr = &buildingTileDeck; //make sure all the players have the reference to the same building tile deck
    handPtr = &hand; //hand pointer for referencing the resource marker
    villageBoard = Village(); //Unique village board that belongs to each player
    buildingScore = BuildingScores(); //implemented in part 6
    gatheredResources = GatheredResources(); //implemented in part 6
}

Player::~Player(){
    delete[] playerHarvestTile;
    playerHarvestTile=nullptr;

    delete[] playerBuildingTile;
    playerBuildingTile=nullptr;
}


void Player::placeHarvestTile(int index, int degrees,int rowOfBoard, int colOfBoard) {
    /*
     * This method will only allow you to place a harvest tile, if where you are placing the tile is
     * free. The board will have a reference to the harvest tile but here a simple * is place on the index of
     * the board if it is being occupied by a harvest tile
     */
    handPtr->reset();
    if (degrees != 0)
       playerHarvestTile[index-1] = playerHarvestTile[index-1].orientation(degrees);//takes care of the orientation part
    if (gameBoard->placeHarvestTileOnBoard(rowOfBoard - 1, colOfBoard - 1, *(playerHarvestTile +index - 1),*handPtr)) {  //if there is nothing on board only then you can place it
        CalculateResources(playerHarvestTile[index-1], rowOfBoard,
                           colOfBoard); //call resource calculator from part 6 to calculate the resources accumulated orthogonally
        playerHarvestTile[index-1] = DrawHarvestTile(); //add a new Harvest tile to player
    }
    else GameBoardPrompt();
}

BuildingTile Player::DrawBuilding() {
    //based on the amount of buildings placed, draw that many buildings
        return (buildingTileDeckPtr->draw());
}
HarvestTile Player::DrawHarvestTile(){
    //add harvest tile to your hand to replenish missing tiles
    return (harvestTileDeckPtr->draw());
}
void Player::ResourceTracker(BuildingTile& placedBuildingTile) {
    //based on the type of the building tile, when player builds their village this method is called in order to
    //take away the values of the resource markers that were set from the CalculateResources() function
   std::string resource = placedBuildingTile.getType();
   int value = placedBuildingTile.getValue();
   if(resource=="wheat") handPtr->exchange(-1 * value, 0, 0, 0);
   else if(resource=="stone") handPtr->exchange(0, -1 * value, 0, 0);
   else if(resource=="sheep")handPtr->exchange(0, 0, -1 * value, 0);
   else if(resource=="timber") handPtr->exchange(0, 0, 0, -1 * value);
}
HarvestTile& Player::getHarvestTile(int index) {
    return playerHarvestTile[index];
}
BuildingTile& Player::getBuildingTile(int index) {
    return playerBuildingTile[index];
}
Hand* Player::getHandPtr() const{
    return handPtr;
}
void Player::BuildVillage(int index, int rowOfVillageBoard, int colOfVillageBoard,bool isOnTop) {
    /*
     * This method is what allows you to build your village. the building tile chosen must be of the same value
     * as the location on the board on which they are placing it. If this is not true then user will receive a prompt asking them
     * to
     */
    BuildingTile &tile = playerBuildingTile[index - 1];
    std::string tileType = tile.getType();
    //if tile is placed face down, change the value of the tile to the row of village board (for resource tracker later)
    if (!isOnTop) {
        tile.setValue(rowOfVillageBoard);
    }
    int tileValue = tile.getValue();
//as long as the building tile to be placed down has a value less than the marker you can place the building
    if ((tileType == "wheat" && tileValue <= handPtr->getWheat()) ||
        (tileType == "stone" && tileValue <= handPtr->getStone()) ||
        (tileType == "sheep" && tileValue <= handPtr->getSheep()) ||
        (tileType == "timber" && tileValue <= handPtr->getTimber())) {
        if (villageBoard.placeBuilding(rowOfVillageBoard, colOfVillageBoard, tile, isOnTop)) {
            ResourceTracker(tile);
            buildingScore.BuildingScore(villageBoard);
            playerBuildingTile[index - 1]= DrawBuilding();
        } else {
            VillageBoardPrompt();
        }

    } else {
        //todo REMOVE FROM CODE!
        char userResponse='a';
        std::cout
                << "You do not have enough resources to build your village if you would like to end your turn enter 'Y else 'N'"<< std::endl;
        std::cin >> userResponse;
        if (userResponse =='N'||userResponse=='n') {
            VillageBoardPrompt();
        }
        else return;
    }

}
void Player::CalculateResources(HarvestTile& tile, int rowOfBoard, int colOfBoard){
    //this method will imitate the call to the resource calculator in part 6
    gatheredResources.GatherResources(tile,*gameBoard,rowOfBoard,colOfBoard); //the 100 value on all resources imitates part 6
    //Hard coded a value of 5 to all of the resources this should be done by PART 6! //TODO
    handPtr->exchange(5,5,5,5);
}

void Player:: VillageBoardPrompt(){
    int newIndex;
    int newRowOfBoard;
    int newColOfBoard;
    bool newIsOnTop;


    //make sure the card index is an acceptable value

    std::cout << "Please enter the building number you would like to play: "<<std::endl;
    std::cin >> newIndex;

    while(newIndex<1 || newIndex>6) {
        std::cout << "Invalid building tile, please enter a value 1-6" << std::endl;
        std::cin >> newIndex;
    }
    std::cout<<"Please enter the row of the Village board you want to place your Building Tile"<<std::endl;
    std::cin>>newRowOfBoard;
    std::cout<<"Please enter the column of the Village board you want to place your Building Tile"<<std::endl;
    std::cin>>newColOfBoard;

    while((newRowOfBoard<1 || newRowOfBoard>6)||(newColOfBoard<1 || newColOfBoard>5)){
        std::cout<<"Incorrect value for row or col re-enter row followed by col  "<<std::endl;
        std::cin>>newRowOfBoard;
        std::cin>>newColOfBoard;
    }
    std::cout<<"If you would like to place the building tile face up, enter 1, if face down enter 0 : "<<std::endl;
    std::cin >> newIsOnTop;
    BuildVillage(newIndex,newRowOfBoard,newColOfBoard,newIsOnTop);
}

void Player::GameBoardPrompt(){
int newIndex;
int newDegrees;
int newRowOfBoard;
int newColOfBoard;

std::cout << "Please enter the card number you would like to play: "<<std::endl;
std::cin >> newIndex;

    while(newIndex<1 || newIndex>2) {
        std::cout << "Invalid Harvest tile, please enter a value 1-2" << std::endl;
        std::cin >> newIndex;
    }

std::cout<<"Please enter the orientation degree: "<<std::endl;
std::cin >> newDegrees;
std::cout<<"Please enter the row of the Game board you want to place your Harvest Tile"<<std::endl;
std::cin>>newRowOfBoard;
std::cout<<"Please enter the column of the Game board you want to place your Harvest Tile"<<std::endl;
std::cin>>newColOfBoard;
    while((newRowOfBoard<1 || newRowOfBoard>5)||(newColOfBoard<1 || newColOfBoard>5)){
        std::cout<<"Incorrect value for row or col re-enter row followed by col  "<<std::endl;
        std::cin>>newRowOfBoard;
        std::cin>>newColOfBoard;
    }
    placeHarvestTile(newIndex,newDegrees,newRowOfBoard,newColOfBoard);
}