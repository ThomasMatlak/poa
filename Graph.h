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

const int NUM_NODES = 10;
const int MAX_EDGE_LENGTH = 5;

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
	-------------------------------------------------------------------------*/
	void printGraph();

	/*---traverse()------------------------------------------------------------
	* Get the minimun cost path of going from one node to another using
	*   Dijkstra's algorithm
	*
	* pre:  start, finish are indexs of nodes in the graph
	* post: the shortest path is returned
	-------------------------------------------------------------------------*/
	std::deque<int> traverse(int start, int dest);

	/*---optimalTraverse()-----------------------------------------------------
	* Get the minimun cost path of going from one node to another using
	*   Dijkstra's algorithm
	*
	* pre:  start, finish are indexs of nodes in the graph
	* post: the shortest path is returned
	-------------------------------------------------------------------------*/
	std::deque<int> optimalTraverse(int start, int dest);

    int traversalDistance(int start, int dest);

private:
    std::vector<Node*> nodes; // this could be done as a vector of a vector of adjacent nodes, but this allows for nodes to contain more information in the future
	std::vector<std::vector<int>> edges;
	std::vector<std::vector<int>> initialEdges = edges;
};
