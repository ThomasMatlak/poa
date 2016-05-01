/*---simulation.h--------------------------------------------------------------
* Thomas Matlak
*
* Simulation Class
*
* Operations:
*	iterate()        - Iterate one step through the simulation
*	displayMap()     - Display a representation of the map
*	displayPlayers() - Display the information of the players in the simulation
*----------------------------------------------------------------------------*/

#pragma once

#include "Graph.h"
#include "Player.h"
#include <vector>

const int NUM_PLAYERS = 200;

enum WhichAlgorithm: int {SELFISH = 0, OPTIMAL = 1};

class Simulation
{
public:
	Simulation();
	~Simulation();

	/*---runSim()--------------------------------------------------------------
	* Iterate through the simulation using either the selfish or optimal
	*   version of the travelsal algorithm
	*
	* pre:  none
	* post: every player gets through the graph
	*------------------------------------------------------------------------*/
	float runSim(WhichAlgorithm greedyOrOptimal = SELFISH);

	/*---displayMap()----------------------------------------------------------
	* Display a representation of the map
	*
	* pre:  none
	* post: returns the average travel time for a player
	*------------------------------------------------------------------------*/
	void displayMap();

	/*---displayPlayers()------------------------------------------------------
	* Display the information of the players in the simulation
	*
	* pre:  none
	* post:
	*------------------------------------------------------------------------*/
	void displayPlayers();

	/*---resetGraph()----------------------------------------------------------
	* Reset the graph to prepare to run the simulation again
	*
	* pre:  none
	* post: the graph is reset
	*------------------------------------------------------------------------*/
	void resetGraph();
private:
	Graph simMap;
	std::vector<Player*> players;
	std::vector<int> travelTimes;
};
