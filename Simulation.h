/*---simulation.h--------------------------------------------------------------
* Thomas Matlak
*
* Simulation Class
*
* Operations:
*	runSim()         - Iterate through the simulation
*	displayMap()     - Display a representation of the map
*	displayPlayers() - Display the information of the players in the simulation
*   resetGraph()     - Reset the graph to its starting state
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
	* greedyOrOptimal - which version of the graph traversal to use
	*   Options are SELFISH or OPTIMAL
	*   Default is SELFISH
	* pre:  none
	* post: he average travel time is returned
	*------------------------------------------------------------------------*/
	float runSim(WhichAlgorithm greedyOrOptimal = SELFISH);

	/*---displayMap()----------------------------------------------------------
	* Display information about the graph
	*
	* pre:  none
	* post: graph information is printed
	*------------------------------------------------------------------------*/
	void displayMap();

	/*---displayPlayers()------------------------------------------------------
	* Display the information of the players in the simulation
	*
	* pre:  none
	* post: player information is printed
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
