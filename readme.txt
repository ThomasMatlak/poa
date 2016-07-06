POA Simulator
=============

2016-05-02

Description
-----------
The program compares the average travel times of several players in a graph
  when they make their own choices regarding how they travel versus being
  told their path by a central system in order to calculate the Price Of Anarchy

A directed graph is randomly generated and the starting/ending points of
  each player are random each time

Instructions
------------
To run the program, complie source code and run the executable
To change the number of players, change const int NUM_PLAYERS on line 19 of
  Simulation.h
To change the number of nodes, change const int NUM_NODES on line 22 of
  Graph.h
To change the maximum edge length, change const int MAX_EDGE_LENGTH on line
  23 of Graph.h

Future Work
-----------
* add a GUI representation of the graph and the traversal by the players
* run the program through steps of "time" to get real-time congestion

Author
------
Thomas Matlak - The College of Wooster: class of 2018
