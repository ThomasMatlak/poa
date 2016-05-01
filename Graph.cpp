/*---Graph.cpp-----------------------------------------------------------------
* Thomas Matlak
*----------------------------------------------------------------------------*/

#include "Graph.h"
#include <random>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <climits>

Graph::Graph()
{
	// randomly make connections between nodes
	std::random_device connectNode;
	std::mt19937 eng(connectNode());
	std::uniform_int_distribution<> distr(1, MAX_EDGE_LENGTH);

    std::random_device doConnectNode;
	std::mt19937 eng2(doConnectNode());
	std::uniform_int_distribution<> distr2(0, NUM_NODES);

    nodes.resize(NUM_NODES, nullptr);
    edges.resize(NUM_NODES, std::vector<int>(NUM_NODES, 0));
    initialEdges.resize(NUM_NODES, std::vector<int>(NUM_NODES, 0));

	for (int i = 0; i < edges.size(); i++)
	{
        for (int j = 0; j < edges[i].size(); j++)
        {
            if (i != j)
            {
                if ((distr2(eng2) % 3) == 0) // control the frequency of edges
                {
                    int randLength = distr(eng);
                    edges[i][j] = randLength;
                    initialEdges[i][j] = randLength;
                }
            }
        }
	}

    // set up node adjacency
	for (int i = 0; i < edges.size(); i++)
	{
        Node* node = new Node;
        nodes[i] = node;
        for (int j = 0; j < edges[i].size(); j++)
        {
            if (edges[i][j] > 0) {
                nodes[i]->adjacentNodes.push_back(j);
            }
        }
    }
}

Graph::~Graph()
{
    for (int i = 0; i < nodes.size(); i++)
    {
        delete nodes[i];
    }
}

void Graph::printGraph()
{
    std::cout << "NODES ADJACENT NODES" << std::endl;
    for (int m = 0; m < NUM_NODES; m++)
    {
        std::cout << m << ": ";
        for (int n = 0; n < nodes[m]->adjacentNodes.size(); n++)
        {
            std::cout << nodes[m]->adjacentNodes[n] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "EDGES:" << std::endl << "  ";
    for (int f = 0; f < NUM_NODES; f++)
    {
        std::cout << f << " ";
    }
    std::cout << std::endl << "  ";
    for (int f = 0; f < NUM_NODES; f++)
    {
        std::cout << "- ";
    }
    std::cout << std::endl;
    for (int i = 0; i < edges.size(); i++)
    {
        std::cout << i << "|";
        for (int j = 0; j < edges[i].size(); j++)
        {
            std::cout << edges[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(std::vector<int> & dist, std::vector<bool> & sptSet)
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < NUM_NODES; v++)
   {
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
   }

   return min_index;
}

std::deque<int> Graph::traverseSelfish(int start, int dest)
{
    std::vector<int> dist; // hold the distances from each node to start
    dist.resize(NUM_NODES, INT_MAX);

    std::vector<bool> sptSet; // is the node included in the shortest path tree
    sptSet.resize(NUM_NODES, false);

    std::vector<int> prev;
    prev.resize(NUM_NODES, -1);

    std::deque<int> shortestPath;

    dist[start] = 0;

    // find the shortest path for each vertex
    for (int i = 0; i < NUM_NODES; i++) // for each node in the graph
    {
        int u = minDistance(dist, sptSet);

        if (u == dest) break;

        sptSet[u] = true;

        for (int j = 0; j < nodes[u]->adjacentNodes.size(); j++) // for each node adjacent to u
        {
            int adjNode = nodes[u]->adjacentNodes[j];

            if ((!sptSet[adjNode]) && (initialEdges[u][adjNode]) && (dist[u] != INT_MAX) && ((dist[u] + initialEdges[u][adjNode]) < dist[adjNode])) // find travel time based solely on distance
            {
                dist[adjNode] = dist[u] + edges[u][adjNode];

                edges[u][adjNode]++; // each player adds congesting to the edges they traverse

                prev[adjNode] = u;
            }
        }
    }

    int u = dest;

    while (prev[u] != -1)
    {
        shortestPath.push_front(u);
        u = prev[u];
    }

    shortestPath.push_front(u);

    return shortestPath;
}

std::deque<int> Graph::traverseOptimal(int start, int dest)
{
    std::vector<int> dist; // hold the distances from each node to start
    dist.resize(NUM_NODES, INT_MAX);

    std::vector<bool> sptSet; // is the node included in the shortest path tree
    sptSet.resize(NUM_NODES, false);

    std::vector<int> prev;
    prev.resize(NUM_NODES, -1);

    std::deque<int> shortestPath;

    dist[start] = 0;

    // find the shortest path for each vertex
    for (int i = 0; i < NUM_NODES; i++) // for each node in the graph
    {
        int u = minDistance(dist, sptSet);

        if (u == dest) break;

        sptSet[u] = true;

        for (int j = 0; j < nodes[u]->adjacentNodes.size(); j++) // for each node adjacent to u
        {
            int adjNode = nodes[u]->adjacentNodes[j];

            if ((!sptSet[adjNode]) && (edges[u][adjNode]) && (dist[u] != INT_MAX) && ((dist[u] + edges[u][adjNode]) < dist[adjNode])) // find travel time based on distance + congestion
            {
                dist[adjNode] = dist[u] + edges[u][adjNode];

                edges[u][adjNode]++; // each player adds congesting to the edges they traverse

                prev[adjNode] = u;
            }
        }
    }

    int u = dest;

    while (prev[u] != -1)
    {
        shortestPath.push_front(u);
        u = prev[u];
    }

    shortestPath.push_front(u);

    return shortestPath;
}

int Graph::traversalDistance(int start, int dest)
{
    std::vector<int> dist; // hold the distances from each node to start
    dist.resize(NUM_NODES, INT_MAX);

    std::vector<bool> sptSet; // is the node included in the shortest path tree
    sptSet.resize(NUM_NODES, false);

    dist[start] = 0;

    // find the shortest path for each vertex
    for (int i = 0; i < NUM_NODES; i++) // for each node in the graph
    {
        int u = minDistance(dist, sptSet);

        if (u == dest) break;

        sptSet[u] = true;

        for (int j = 0; j < nodes[u]->adjacentNodes.size(); j++) // for each node adjacent to u
        {
            int adjNode = nodes[u]->adjacentNodes[j];

            // if adjNode is not in the shortest path tree, there is an edge between u and adjNode,
            if ((!sptSet[adjNode]) && (edges[u][adjNode]) && (dist[u] != INT_MAX) && ((dist[u] + edges[u][adjNode]) < dist[adjNode]))
            {
                dist[adjNode] = dist[u] + edges[u][adjNode];
            }
        }
    }

    return dist[dest];
}

void Graph::resetGraph()
{
    for (int i = 0; i < edges.size(); i++)
        for (int j = 0; j < edges.size(); j++)
            edges[i][j] = initialEdges[i][j];
}
