/*---main.cpp------------------------------------------------------------------
* Name: Thomas Matlak
* Assignment: Project Software
* Title: POA Calculator
* Course: CS 200
* Semester: Spring 2016
* Instructor: D. Byrnes
* Date: 25 April 2016
* Sources consulted:
* Program description: The program compares the total travel times of several
*		players in a graph when they make their own choices regarding how they
*		travel versus being told by a central system telling them their path
*		to calculate the Price Of Anarchy
*
*		An undirected graph is randomly generated and the starting/ending
*		points of each player are random each time
* Known bugs:
* Instructions:
*----------------------------------------------------------------------------*/

/*
#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  ifdef _WIN32
#    include <Windows.h>
#  endif
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif
*/

#include <iostream>
#include "Simulation.h"

int main()
{
	Simulation sim;

    sim.displayMap();

    sim.displayPlayers();


#ifdef _WIN32 // this is a Windows specific command to prevent cmd from closing
	system("pause");
#endif // _WIN32

	return 0;
}
