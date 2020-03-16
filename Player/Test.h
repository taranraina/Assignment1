//
// Created by Taran Raina on 2020-02-12.
//

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H
#include <array>
#include <vector>

class HarvestTile{
public:
    HarvestTile();
    HarvestTile(std::string resource1,std::string resource2, std::string resource3,std::string resource4);
    HarvestTile orientation(int degrees);
    bool getIsInitialized();
    void setIsInitialized(bool isInitialized);
    std::array<std::string,4> getResourceArray();

private:
    std::array<std::string,4> resourceArray;
    bool isInitialized;
};

class BuildingTile{
public:
    BuildingTile(){}
    BuildingTile(int value,std::string type);
    void setValue(int value);
    int getValue();
    void setIsOnTop(bool isOnTop);
    std::string getType();
    bool getIsInitialized();
    void setIsInitialized(bool isInitialized);
private:
    int value;
    std::string type;
    bool isOnTop;
    bool isInitialized = false;
};

class HarvestTileDeck {
public:
    HarvestTileDeck();
    HarvestTile draw();
private:
    std::vector<HarvestTile> harvestTileDeck;
};

class BuildingTileDeck {
public:
    BuildingTileDeck();
    BuildingTile draw();
private:
    std::vector<BuildingTile> buildingTileDeck;
};

class Hand{
public:
    Hand();
    void reset();
    void exchange(int wheatCount,int stoneCount,int sheepCount, int timberCount);
    int getWheat();
    int getStone();
    int getSheep();
    int getTimber();
private:
    int wheat;
    int stone;
    int sheep;
    int timber;
};

class Village{
public:
    Village();
    bool placeBuilding(int i, int j, BuildingTile& tile,bool isOnTop);
private:
    BuildingTile villageBoard[6][5];
};

class Board{
public:
    Board();
    bool placeHarvestTileOnBoard(int i, int j, HarvestTile tile,Hand& hand);
private:
    HarvestTile gameBoard [5][5];
};

class GatheredResources{
public:
    void GatherResources(HarvestTile& tile,Board& gameBoard, int row,int col){}

};

class BuildingScores{
public:
    void BuildingScore(Village& villageBoard){}

};
#endif //PLAYER_TEST_H
