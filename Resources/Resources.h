#ifndef RESOURCES_RESOURCES_H
#define RESOURCES_RESOURCES_H
#include <string>
#include <array>


enum Type { wheat, timber, stone, sheep };

class Resource {
public:
    Resource();
    void setType(Type type);
    Type getType();
    std::string getResourceName();
private:
    Type resource;
};

class HarvestTile {
public:
    HarvestTile();
    void setHarvestTile(Type resource1, Type resource2, Type resource3, Type resource4);
    HarvestTile(const HarvestTile& harvestTile);
    ~HarvestTile();
    HarvestTile& operator=(const HarvestTile &harvestTile);
    Resource* getResources();
    void printHarvestTile();
private:
    Resource* resource;
};

class BuildingTile {
public:
    BuildingTile();
    BuildingTile(int value, Type type);
    //BuildingTile(const BuildingTile &buildingTile);
    void setValue(int value);
    int getValue();
    //void setType(Type type);
    // Resource getType();
    void printBuildingTile();
private:
    int value;
    Resource resource;
};

class HarvestTileDeck {
public:
    HarvestTileDeck();
    ~HarvestTileDeck();
    HarvestTile* draw();
    void viewHarvestDeck();
    HarvestTile orientation(int degrees,int index);
    HarvestTile getHarvestTile(int index);
private:
    HarvestTile* deck;
    std::array<int, 60>draw_HarvestTileArray;
    int currentDrawnHarvestIndex = 0;
};

class BuildingTileDeck {
public:
    BuildingTileDeck();
    ~BuildingTileDeck();
    BuildingTile draw();
    void viewBuildingDeck();
private:
    BuildingTile* deck;
    std::array<int, 144>draw_BuildingTileArray;
    int currentDrawnBuildingIndex = 0;

};

class ResourceMarkers {
public:
    ResourceMarkers();
    void setWheatMarker(int wheatValue);
    int getWheatMarker();
    void setTimberMarker(int timberValue);
    int getTimberMarker();
    void setStoneMarker(int stoneValue);
    int getStoneMarker();
    void setSheepMarker(int sheepValue);
    int getSheepMarker();
    void exchange(int wheatCount, int stoneCount, int sheepCount, int timberCount);
private:
    int wheatMarker;
    int timberMarker;
    int stoneMarker;
    int sheepMarker;

};
#endif