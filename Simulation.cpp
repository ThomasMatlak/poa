/*---simulation.cpp-----------------------------------------------------------
* Thomas Matlak
*----------------------------------------------------------------------------*/

#include "Simulation.h"
#include <random>
#include <iostream>
#include <climits>
#include <deque>

Simulation::Simulation()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, NUM_NODES - 1);

	for (int k = 0; k < NUM_PLAYERS; k++)
	{
        int playerStart;
        int playerEnd;

        do
        {
            playerStart = distr(eng);
            playerEnd  = distr(eng);
        }
        while ((simMap.traversalDistance(playerStart, playerEnd) == INT_MAX) || (playerStart == playerEnd)); // ensure a player's destination is possible and not starting and ending at the same place

		Player* player = new Player(playerStart, playerEnd);

		players.push_back(player);
	}
}

Simulation::~Simulation()
{
	for (int i = 0; i < players.size(); i++)
	{
        delete players[i];
	}
}

float Simulation::runSim(WhichAlgorithm greedyOrOptimal)
{
    int totalTravelTime = 0;

    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        int start = players[i]->getStart();
        int dest  = players[i]->getDestination();

        if (greedyOrOptimal == SELFISH)
        {
            simMap.traverseSelfish(start, dest);
            totalTravelTime += simMap.traversalDistance(start, dest);
        }
        else if (greedyOrOptimal == OPTIMAL)
        {
            simMap.traverseOptimal(start, dest);
            totalTravelTime += simMap.traversalDistance(start, dest);
        }
    }

    return (float)totalTravelTime / (float)NUM_PLAYERS;
}

void Simulation::displayMap()
{
	simMap.printGraph();
}

void Simulation::displayPlayers()
{
    /*// for debugging
    std::cout << "PLAYERS:" << std::endl;
	for (int i = 0; i < NUM_PLAYERS; i++)
	{
		std::cout << i << ": ";
		players[i]->printInfo();
	}
	*/

	std::cout << "PLAYER TRAVEL DISTANCES:" << std::endl;
	for (int j = 0; j < NUM_PLAYERS; j++)
	{
        int distance = simMap.traversalDistance(players[j]->getStart(), players[j]->getDestination());

        std::cout << j << ": " << distance << std::endl;

        /*// for debugging
        if (distance == INT_MAX)
            std::cout << j << ": " << "This player cannot go here" << std::endl;
        else
        {
            std::cout << j << ": " << distance << "|";
            std::deque<int> path = simMap.traverseSelfish(players[j]->getStart(), players[j]->getDestination());
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
    simMap.resetGraph();
}
