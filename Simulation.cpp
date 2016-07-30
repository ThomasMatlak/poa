/*---simulation.cpp-----------------------------------------------------------
* Thomas Matlak
*----------------------------------------------------------------------------*/

#include "Simulation.h"
#include <random>
#include <iostream>
#include <climits> // INT_MAX
#include <deque>

Simulation::Simulation(int setNumPlayers, int setNumNodes, int setMaxEdgeLength)
{
    numPlayers = setNumPlayers;
    simMap = new Graph(setNumNodes, setMaxEdgeLength);

	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, simMap->getNumNodes() - 1);

	for (int k = 0; k < numPlayers; k++)
	{
        int playerStart;
        int playerEnd;

        do
        {
            playerStart = distr(eng);
            playerEnd  = distr(eng);
        }
        /* ensure a player's destination is possible and the player is not
        *  starting and ending at the same place */
        while ((simMap->traversalDistance(playerStart, playerEnd) == INT_MAX)
            || (playerStart == playerEnd));

		Player* player = new Player(playerStart, playerEnd);

		players.push_back(player);
	}
}

Simulation::~Simulation()
{
	for (size_t i = 0; i < players.size(); i++)
	{
        delete players[i];
	}

    delete simMap;
}

float Simulation::runSim(WhichAlgorithm greedyOrOptimal)
{
    int totalTravelTime = 0;

    for (int i = 0; i < numPlayers; i++)
    {
        int start = players[i]->getStart();
        int dest  = players[i]->getDestination();

        if (greedyOrOptimal == SELFISH)
        {
            simMap->traverseSelfish(start, dest);
            totalTravelTime += simMap->traversalDistance(start, dest);
        }
        else if (greedyOrOptimal == OPTIMAL)
        {
            simMap->traverseOptimal(start, dest);
            totalTravelTime += simMap->traversalDistance(start, dest);
        }
    }

    return (float)totalTravelTime / (float)numPlayers;
}

void Simulation::displayMap()
{
	simMap->printGraph();
}

void Simulation::displayPlayers()
{
    /*// for debugging
    std::cout << "PLAYERS:" << std::endl;
	for (int i = 0; i < numPlayers; i++)
	{
		std::cout << i << ": ";
		players[i]->printInfo();
	}
	*/

	std::cout << "PLAYER TRAVEL DISTANCES:" << std::endl;
	for (int j = 0; j < numPlayers; j++)
	{
        int start = players[j]->getStart();
        int dest  = players[j]->getDestination();

        int distance = simMap->traversalDistance(start, dest);

        std::cout << j << ": " << distance << std::endl;

        /*// for debugging
        if (distance == INT_MAX)
            std::cout << j << ": " << "This player cannot go here" << std::endl;
        else
        {
            std::cout << j << ": " << distance << "|";
            std::deque<int> path = simMap.traverseSelfish(start, dest);
            while (!path.empty())
            {
                std::cout << path.front();
                path.pop_front();
                if (!path.empty()) std::cout << "->";
            }
            std::cout << std::endl;
        }
        */
	}
}

void Simulation::resetGraph()
{
    simMap->resetGraph();
}
