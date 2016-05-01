/*---Player.h------------------------------------------------------------------
* Thomas Matlak
*
* Player Class
*
* Operations:
*	setStart()           - Set the player's starting position
*	setCurrentPosition() - Set the player's current position
*	setDestination()     - Set the player's destination
*	getStart()           - Get the player's starting position
*	getCurrentPosition() - Get the player's current position
*	getDestination()     - Get the player's destination
*	printInfo()          - Outputs the player's start and end positions
*----------------------------------------------------------------------------*/

#pragma once

class Player
{
public:
	Player(int start, int dest);
	~Player();

	/*---getStart()------------------------------------------------------------
	* Get the player's starting position
	*
	* pre:  none
	* post:
	*------------------------------------------------------------------------*/
	int getStart();

	/*---getDestination()------------------------------------------------------
	* Get the player's destination
	*
	* pre:  none
	* post:
	*------------------------------------------------------------------------*/
	int getDestination();

	/*---printInfo()-----------------------------------------------------------
	* Outputs the player's start and end positions
	*
	* pre:  none
	* post: the player's position has been output
	*------------------------------------------------------------------------*/
	void printInfo();
private:
	int startingNode; //the index of the player's starting position

	int destination; // the index of the destination node

	int timeToTraverse;
	// the time it will take the player to go from start to their destination
};
