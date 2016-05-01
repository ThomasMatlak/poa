/*---Graph.h-------------------------------------------------------------------
* Thomas Matlak
*
* Graph Class
*
* Operations:
*	drawGraph() - Output a representation of the graph
*	traverse()  - Get the cost of going from one node to another
*----------------------------------------------------------------------------*/

#pragma once

#include <vector>
#include <deque>

const int NUM_NODES = 500;
const int MAX_EDGE_LENGTH = 1;

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

	/*---drawGraph()-----------------------------------------------------------
	* Output a representation of the graph to the console
	*
	* pre:  none
	* post: a representation of the graph is output
	*------------------------------------------------------------------------*/
	void printGraph();

	/*---traverseSelfish()-----------------------------------------------------
	* Get the minimun cost path of going from one node to another using
	*   Dijkstra's algorithm
	*
	* pre:  start, finish are indexs of nodes in the graph
	* post: the shortest path is returned
	*------------------------------------------------------------------------*/
	std::deque<int> traverseSelfish(int start, int dest);

	/*---optimalTraverse()-----------------------------------------------------
	* Get the minimun cost path of going from one node to another using
	*   Dijkstra's algorithm
	*
	* pre:  start, finish are indexs of nodes in the graph
	* post: the shortest path is returned
	*------------------------------------------------------------------------*/
	std::deque<int> traverseOptimal(int start, int dest);

    /*---traversalDistance()---------------------------------------------------
    * Get the time to travel from one node to another
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
    std::vector<Node*> nodes; // this could be done as a vector of a vector of adjacent nodes, but this allows for nodes to contain more information in the future
	std::vector<std::vector<int>> edges;
	std::vector<std::vector<int>> initialEdges; // = edges
};
