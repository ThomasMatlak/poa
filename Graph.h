/*---Graph.h-------------------------------------------------------------------
* Thomas Matlak
*
* Graph Class
*
* Operations:
*	drawGraph()         - Output a representation of the graph for debugging
*	traverseSelfish()   - Get the minimum cost path between nodes using
*                         Dijkstra's algorithm, only considering distance
*   traverseOptimal()   - Get the optimal minimum cost path between nodes with
                          Dijkstra's algorithm
*   traversalDistance() - Get the time to travel between nodes using Dijkstra's
                          Algorithm
*   resetGraph()        - Reset the graph edges to their original weights
*----------------------------------------------------------------------------*/

#pragma once

#include <vector>
#include <deque>

const int NUM_NODES = 250;
const int MAX_EDGE_LENGTH = 20;

struct Node {
    std::vector<int> adjacentNodes;
};

/*
* Graph
*/
class Graph
{
public:
	Graph();

	~Graph();

	/*---printGraph()----------------------------------------------------------
	* Output a representation of the graph to the console for debugging
	*
	* pre:  none
	* post: a representation of the graph is output
	*------------------------------------------------------------------------*/
	void printGraph();

	/*---traverseSelfish()-----------------------------------------------------
	* Get the minimum cost path between nodes using Dijkstra's algorithm,
	*   only considering travel distance
	*
	* start - the starting node of the graph
	* dest  - the ending node of the graph
	*
	* pre:  start, finish are indexs of nodes in the graph
	* post: the shortest path is returned
	*------------------------------------------------------------------------*/
	std::deque<int> traverseSelfish(int start, int dest);

	/*---optimalTraverse()-----------------------------------------------------
	* Get the optimal minimum cost path between nodes with Dijkstra's algorithm
	*
	* start - the starting node of the graph
	* dest  - the ending node of the graph
	*
	* pre:  start, finish are indexs of nodes in the graph
	* post: the shortest path is returned
	*------------------------------------------------------------------------*/
	std::deque<int> traverseOptimal(int start, int dest);

    /*---traversalDistance()---------------------------------------------------
    * Get the time to travel between nodes using Dijkstra's Algorithm
    *
    * start - the starting node of the graph
	* dest  - the ending node of the graph
	*
    * pre:  none
    * post: the distance from start to dest is returned
    *------------------------------------------------------------------------*/
    int traversalDistance(int start, int dest);

    /*---resetGraph()----------------------------------------------------------
    * Reset the graph edges to their original weights
    *
    * pre:  none
    * post: edges is set to initialEdges
    *------------------------------------------------------------------------*/
    void resetGraph();

private:
    std::vector<Node*> nodes; /* this could be done as a vector of a vector of
                                 adjacent nodes, but this allows for nodes to
                                 contain more information in the future */
	std::vector<std::vector<int>> edges;
	std::vector<std::vector<int>> initialEdges; // = edges
};
