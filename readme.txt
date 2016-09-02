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

Input can take place either by typing into the program's prompts or by redirecting
  stdin to a text file containing the desired values.

To create a custom, non-random graph to traverse, create a text file with the following format:
  line containing a number, n, the number of nodes
  n lines of integers, each ilne containing n integers, indicating distance to each other node.
    The value 0 indicates the nodes do not connect, and values are assumed to be <= 0
    The nth value on a given line must be 0

Author
------
Thomas Matlak - The College of Wooster: class of 2018
