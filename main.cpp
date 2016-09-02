/*---main.cpp------------------------------------------------------------------
* Name: Thomas Matlak
* Assignment: Junior IS Software
* Title: POA Simulator
* Course: CS 200
* Semester: Spring 2016
* Instructor: D. Byrnes
* Date: 2 May 2016
* Sources consulted:
*   For Dijkstra's Algorithm pseudocode and c++ snippets:
*     http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-p
*       ath-algorithm/
*     https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
* Program description:
*   The program compares the average travel times of several players in a graph
*   when they make their own choices regarding how they travel versus being
*   told by a central system telling them their path  to calculate the
*   Price Of Anarchy
*
*	An undirected graph is randomly generated and the starting/ending points of
*   each player are random each time
* Known bugs:
* Instructions:
*   To run the program, simply run the executable
*----------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include "Simulation.h"

int main(int argc, char *argv[])
{
    if (argc > 1) {
        string filename = argv[1];

        ifstream graphFile;
        graphFile.open(filename);

        int numInputNodes;
        graphFile >> numInputNodes;

        std::vector<std::vector<int> > inputGraph(numInputNodes, std::vector<int>(numInputNodes));
        for (int i = 0; i < numInputNodes; ++i) {
            for (int j = 0; k < numInputNodes; ++j) {
                graphFile >> inputGraph[i][j];
            }
        }
    }

    int numPlayers = -1;
    int numNodes = 0;
    int maxEdgeLength = 0;

    while (numPlayers <= 0)
    {
        std::cout << "Enter the number of players to traverse the graph: ";
        std::cin >> numPlayers;
    }

    while (numNodes < 2)
    {
        std::cout << "Enter the number of nodes for the graph to have: ";
        std::cin >> numNodes;
    }

    while (maxEdgeLength < 1)
    {
        std::cout << "Enter the maximum length for a graph edge: ";
        std::cin >> maxEdgeLength;
    }

	Simulation sim(numPlayers, numNodes, maxEdgeLength);

    std::cout << "Number of Nodes: " << numNodes << std::endl;
    std::cout << "Number of Players: " << numPlayers << std::endl;

    float selfishRun = sim.runSim(SELFISH);
    std::cout << "Selfish average travel time: " << selfishRun << std::endl;
    sim.resetGraph();

    float optimalRun = sim.runSim(OPTIMAL);
    std::cout << "Optimal average travel time: " << optimalRun << std::endl;
    sim.resetGraph();

    float poa = optimalRun / selfishRun;

    std::cout << "POA is: " << poa << std::endl;

    std::cout << "The optimal system is " << 100 * ((1 / poa) - 1)
        << "% more efficient" << std::endl;

#ifdef _WIN32 /* this is a Windows specific command to prevent the VS debugger
                 from closing immediately*/
	system("pause");
#endif // _WIN32

	return 0;
}
