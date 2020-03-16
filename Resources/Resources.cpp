#include <array>
#include <random>
#include <iostream>
#include "Resources.h"
std::random_device rd;
std::mt19937 gen(rd());


Resource::Resource() {

}
void Resource::setType(Type type) {
    //sets the enum type of resource;
    resource = type;

}
Type Resource::getType() {
    //returns the enum type of resource;
    return resource;
}
std::string Resource::getResourceName() {
    //For readability all enums have been returned as their string name
    switch (resource) {
        case wheat: return "wheat";
        case timber: return "timber";
        case sheep: return "sheep";
        case stone: return "stone";
    }
}


HarvestTile::HarvestTile() {
    /*std::cout << "creating\n";
    resource = new Resource[4];
    resource[0].setType(wheat);
    resource[1].setType(sheep);
    resource[2].setType(wheat);
    resource[3].setType(stone); */
}
void HarvestTile::setHarvestTile(Type resource1, Type resource2, Type resource3, Type resource4) {
    //setting of the Harvest Tiles resource array (4 quadrants) to the resource type
    resource = new Resource[4];
    resource[0].setType(resource1);
    resource[1].setType(resource2);
    resource[2].setType(resource3);
    resource[3].setType(resource4);

}

HarvestTile::HarvestTile(const HarvestTile &harvestTile) {
    //copy constructor
    resource = new Resource[4];

    for (int i = 0; i<4; i++) {
        resource[i].setType((harvestTile.resource + i)->getType());
    }
}

HarvestTile& HarvestTile::operator=(const HarvestTile &harvestTile) {
    //Operator overloading
    if (&harvestTile == this)
        return *this;
    resource = new Resource[4];
    for (int i = 0; i<4; i++) {
        resource[i].setType((harvestTile.resource + i)->getType());
    }
    return *this;
}

HarvestTile::~HarvestTile() {
    //Destructor to delete the HarvestTile

    delete[] resource;
    resource = nullptr;
}

Resource* HarvestTile::getResources() {
    return resource;
}

void HarvestTile::printHarvestTile() {
    for (int i = 0; i<4; i++) {
        std::cout << (resource + i)->getResourceName() << '\t';
        if (i == 1) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}


//Building Tiles
BuildingTile::BuildingTile() {

}

BuildingTile::BuildingTile(int value, Type type) {
    //setting the value and type of the Building Tile
    this->value = value;
    resource.setType(type);
}
void BuildingTile::setValue(int value) {
    this->value = value;
}

int BuildingTile::getValue() {
    return value;
}

void BuildingTile::printBuildingTile() {
    std::cout << "Resource: " << resource.getResourceName() << std::endl << "Value: " << getValue() << std::endl;
}

//HarvestTile Deck Class
HarvestTileDeck::HarvestTileDeck() {
    //Setting the container deck of Harvest tiles to those actually in the game
    deck = new HarvestTile[60];
    deck[0].setHarvestTile(wheat, stone, wheat, stone);
    deck[1].setHarvestTile(timber, timber, timber, stone);
    deck[2].setHarvestTile(sheep, sheep, sheep, stone);
    deck[3].setHarvestTile(wheat, timber, wheat, stone);
    deck[4].setHarvestTile(timber, wheat, timber, wheat);
    deck[5].setHarvestTile(sheep, sheep, sheep, wheat);
    deck[6].setHarvestTile(timber, stone, timber, stone);
    deck[7].setHarvestTile(stone, wheat, stone, sheep);
    deck[8].setHarvestTile(stone, sheep, wheat, wheat);
    deck[9].setHarvestTile(sheep, stone, wheat, sheep);
    deck[10].setHarvestTile(timber, sheep, timber, stone);
    deck[11].setHarvestTile(wheat, sheep, wheat, timber);
    deck[12].setHarvestTile(timber, stone, sheep, timber);
    deck[13].setHarvestTile(stone, sheep, stone, stone);
    deck[14].setHarvestTile(sheep, stone, sheep, stone);
    deck[15].setHarvestTile(sheep, wheat, sheep, stone);
    deck[16].setHarvestTile(timber, wheat, timber, wheat);
    deck[17].setHarvestTile(timber, timber, wheat, stone);
    deck[18].setHarvestTile(sheep, wheat, sheep, wheat);
    deck[19].setHarvestTile(sheep, timber, sheep, sheep);
    deck[20].setHarvestTile(timber, wheat, timber, stone);
    deck[21].setHarvestTile(stone, sheep, stone, wheat);
    deck[22].setHarvestTile(stone, stone, stone, wheat);
    deck[23].setHarvestTile(sheep, stone, timber, sheep);
    deck[24].setHarvestTile(sheep, timber, wheat, sheep);
    deck[25].setHarvestTile(wheat, timber, stone, stone);
    deck[26].setHarvestTile(wheat, sheep, timber, wheat);
    deck[27].setHarvestTile(stone, stone, stone, timber);
    deck[28].setHarvestTile(timber, sheep, timber, sheep);
    deck[29].setHarvestTile(timber, wheat, wheat, stone);
    deck[30].setHarvestTile(sheep, stone, sheep, wheat);
    deck[31].setHarvestTile(wheat, timber, wheat, sheep);
    deck[32].setHarvestTile(stone, sheep, stone, timber);
    deck[33].setHarvestTile(timber, wheat, timber, sheep);
    deck[34].setHarvestTile(stone, timber, timber, wheat);
    deck[35].setHarvestTile(timber, wheat, wheat, wheat);
    deck[36].setHarvestTile(sheep, timber, sheep, wheat);
    deck[37].setHarvestTile(timber, timber, sheep, sheep);
    deck[38].setHarvestTile(wheat, wheat, wheat, sheep);
    deck[39].setHarvestTile(wheat, wheat, stone, wheat);
    deck[40].setHarvestTile(timber, sheep, timber, wheat);
    deck[41].setHarvestTile(stone, timber, stone, wheat);
    deck[42].setHarvestTile(stone, timber, sheep, sheep);
    deck[43].setHarvestTile(stone, timber, wheat, stone);
    deck[44].setHarvestTile(timber, stone, timber, sheep);
    deck[45].setHarvestTile(sheep, stone, sheep, stone);
    deck[46].setHarvestTile(stone, timber, stone, sheep);
    deck[47].setHarvestTile(timber, timber, wheat, timber);
    deck[48].setHarvestTile(sheep, wheat, sheep, wheat);
    deck[49].setHarvestTile(sheep, stone, wheat, wheat);
    deck[50].setHarvestTile(timber, wheat, sheep, timber);
    deck[51].setHarvestTile(stone, stone, wheat, wheat);
    deck[52].setHarvestTile(wheat, stone, wheat, timber);
    deck[53].setHarvestTile(sheep, stone, stone, timber);
    deck[54].setHarvestTile(stone, wheat, sheep, stone);
    deck[55].setHarvestTile(sheep, wheat, sheep, timber);
    deck[56].setHarvestTile(timber, timber, sheep, timber);
    deck[57].setHarvestTile(sheep, sheep, stone, timber);
    deck[58].setHarvestTile(wheat, stone, sheep, wheat);
    deck[59].setHarvestTile(timber, stone, timber, stone);

    //setting the draw_harvest tile array to values 0-59 and then shuffling it so that that is how we
    //receive the harvest tile when drawing it
    for (int i = 0; i<60; i++) {
        draw_HarvestTileArray[i] = i;
    }
    std::shuffle(draw_HarvestTileArray.begin(), draw_HarvestTileArray.end(), std::default_random_engine(1));
}
HarvestTile HarvestTileDeck:: getHarvestTile(int index){
    return deck[index];
}

HarvestTile HarvestTileDeck::orientation(int degrees,int index){

    //rotate tile based on the rotation degrees provided
    Type res1= deck[index].getResources()[0].getType();
    Type res2= deck[index].getResources()[1].getType();
    Type res3= deck[index].getResources()[2].getType();
    Type res4= deck[index].getResources()[3].getType();


    switch(degrees){
        case 0:
            return deck[index];
        case 90:
             deck[index].setHarvestTile(res3,res1,res4,res2);
             return deck[index];
        case 180:
            deck[index].setHarvestTile(res4,res3,res2,res1);
            return deck[index];

        case 270:
            deck[index].setHarvestTile(res2,res4,res1,res3);
            return deck[index];
    }

}

HarvestTileDeck::~HarvestTileDeck() {
    delete[] deck;
    deck = nullptr;
}

HarvestTile* HarvestTileDeck::draw() {
    //drawing the harvest tiles from a shuffled deck. Notice here because we actually choose a value from the
    //draw_HarvestTile deck which is only a deck of values from 0-59, and we have a value current drawnHarvest+1,
    //everytime that this is called we are always calling the next value in the draw_HarvestTile which will be a unique value,
    //and that specific value will end up being called from the deck.

    if(currentDrawnHarvestIndex>59){
    std::cout<<"You have drawn all Harvest Tiles! Nothing left to draw"<<std::endl;
    }
    else {
        std::cout << "You are drawing Harvest Tile: " << draw_HarvestTileArray[currentDrawnHarvestIndex] + 1
                  << std::endl;
        return &deck[draw_HarvestTileArray[currentDrawnHarvestIndex++]];
        //making sure that currentDrawnHarvestIndex is incremented at every single return so no repeats
    }
}
void HarvestTileDeck::viewHarvestDeck() {
    for (int i = 0; i<60; i++) {
        std::cout << "Harvest Tile: " << i + 1 << std::endl;
        (deck + i)->printHarvestTile();
    }
}
//Building Tile Class
BuildingTileDeck::BuildingTileDeck() {
    //setting the building tile to the 4 types of resources, with 6 values each
    //Set the values from 1-6, for each 36 tiles of every resource type.
    deck = new BuildingTile[144];
    int value = 1;
    for (int i = 0; i<36; i++) {
        if (value > 6) value = 1;
        deck[i] = (BuildingTile(value++, wheat));
    }
    for (int i = 36; i<72; i++) {
        if (value > 6) value = 1;
        deck[i] = (BuildingTile(value++, timber));
    }
    for (int i = 72; i<108; i++) {
        if (value > 6) value = 1;
        deck[i] = (BuildingTile(value++, sheep));
    }

    for (int i = 108; i<144; i++) {
        if (value > 6) value = 1;
        deck[i] = (BuildingTile(value++, stone));
    }
    for (int i = 0; i<144; i++) {
        draw_BuildingTileArray[i] = i;
    }
    //Make a draw_BuildingTileArray of values from 0-143 and shuffle that array. Every deck draw will be picking the
    //deck index from this array
    std::shuffle(draw_BuildingTileArray.begin(), draw_BuildingTileArray.end(), std::default_random_engine(2));
}

BuildingTileDeck::~BuildingTileDeck() {
    delete[] deck;
    deck = nullptr;
}
BuildingTile BuildingTileDeck::draw() {
    //Making sure that if all the Building Tiles have been drawn, then they cannot draw anymore.
    if(currentDrawnBuildingIndex>143){
        std::cout<<"You have drawn all Building Tiles! Nothing left to draw"<<std::endl;
    }
        //Drawing the Building tiles from a shuffled deck. Notice here because we actually choose a value from the
        //draw_BuildingTile deck which is only a deck of values from 0-143, and we have a value currentdrawnBuildingIndex+1,
        //Everytime that this is called we are actually also calling the next value in the draw_BuildingTile which will be a unique value,
        //and that specific value will end up being called from the deck.
    else {
        std::cout << "You are drawing Building Tile: " << draw_BuildingTileArray[currentDrawnBuildingIndex] + 1
                  << std::endl;
        return deck[draw_BuildingTileArray[currentDrawnBuildingIndex++]];
    }
}
void BuildingTileDeck::viewBuildingDeck() {
    for (int i = 0; i<144; i++) {
        std::cout << "Building Tile: " << i + 1 << std::endl;
        (deck + i)->printBuildingTile();
    }
}

//Resource Marker class

ResourceMarkers::ResourceMarkers() {
    wheatMarker, stoneMarker, sheepMarker, timberMarker = 0;
}
void ResourceMarkers::exchange(int wheatCount, int stoneCount, int sheepCount, int timberCount) {
    //Function that sets all the values of the resource markers
    //the parameters here are actually going to be values evaluated by part 6
    setWheatMarker(getWheatMarker() + wheatCount);
    setStoneMarker(getStoneMarker() + stoneCount);
    setSheepMarker(getSheepMarker() + sheepCount);
    setTimberMarker(getTimberMarker() + timberCount);
}

void ResourceMarkers::setWheatMarker(int wheatValue) {
    wheatMarker = wheatValue;
}
int  ResourceMarkers::getWheatMarker() {
    return wheatMarker;
}
void  ResourceMarkers::setTimberMarker(int timberValue) {
    timberMarker = timberValue;
}
int  ResourceMarkers::getTimberMarker() {
    return timberMarker;
}
void  ResourceMarkers::setStoneMarker(int stoneValue) {
    stoneMarker = stoneValue;
}
int  ResourceMarkers::getStoneMarker() {
    return stoneMarker;
}
void  ResourceMarkers::setSheepMarker(int sheepValue) {
    sheepMarker = sheepValue;
}
int  ResourceMarkers::getSheepMarker() {
    return sheepMarker;
}