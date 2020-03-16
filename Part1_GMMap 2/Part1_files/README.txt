-----------------------------------------------
Assignment 1 Part 1
-----------------------------------------------

// All functions and its attributes can be tested by commenting and uncommenting.

// Required files:
#include"Node.h"
#include"GBMap.h"
#include "BFSGraph.h"
#include "Card.h"

// The number of players is prompted in GBMapDriver in CMD.
// Number of active tiles(nodes) will be created based on # of players using the GBMap class.
// Depending on the number of players , it will create multiple instantiations of Nodes objects that are Connected
// BFSGraph is called to check the connected nodes by traversing in BFS manner.

// In void GBMap::createMap(int players)
// Tile 10 is not connected to any adjacent nodes as they are commented out
// Uncomment codes in function code to run as a connected Graph.