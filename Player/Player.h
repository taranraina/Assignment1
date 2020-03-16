
#ifndef PLAYER_PLAYER_H
#define PLAYER_PLAYER_H
#include "Test.h"


class Player{
public:
    Player(){}
    Player(HarvestTileDeck &harvestTileDeck, BuildingTileDeck &buildingTileDeck1, Hand &hand,Board& gameBoard);
    ~Player();
    void placeHarvestTile(int index, int degrees,int rowOfBoard, int colOfBoard);
    BuildingTile DrawBuilding();
    HarvestTile DrawHarvestTile();
    void ResourceTracker(BuildingTile& placedBuildingTile);
    void BuildVillage(int index, int rowOfGameBoard, int colOfGameBoard,bool isOnTop);
    void CalculateResources(HarvestTile& tile, int rowOfBoard, int colOfBoard);
    HarvestTile& getHarvestTile(int index);
    BuildingTile& getBuildingTile(int index);
    Hand* getHandPtr() const;

private:
    HarvestTile* playerHarvestTile;
    BuildingTile* playerBuildingTile;
    HarvestTileDeck* harvestTileDeckPtr;
    BuildingTileDeck* buildingTileDeckPtr;
    Board* gameBoard;
    Village villageBoard;
    Hand* handPtr;
    //TODO
    BuildingScores buildingScore;
    GatheredResources gatheredResources;
    void VillageBoardPrompt();
    void GameBoardPrompt();
};

#endif //PLAYER_PLAYER_H
