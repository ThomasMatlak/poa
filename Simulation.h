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

const int NUM_PLAYERS = 10;

class Simulation
{
public:
	Simulation();
	~Simulation();

	/*---iterate()-------------------------------------------------------------
	* Iterate one step through the simulation
	*
	* pre:  none
	* post:
	*------------------------------------------------------------------------*/
	void iterate();

	/*---displayMap()----------------------------------------------------------
	* Display a representation of the map
	*
	* pre:  none
	* post:
	*------------------------------------------------------------------------*/
	void displayMap();

	/*---displayPlayers()------------------------------------------------------
	* Display the information of the players in the simulation
	*
	* pre:  none
	* post:
	*------------------------------------------------------------------------*/
	void displayPlayers();
private:
	Graph simMap;
	std::vector<Player*> players;
	std::vector<int> travelTimes;
};
