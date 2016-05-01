/*---Player.cpp----------------------------------------------------------------
* Thomas Matlak
*----------------------------------------------------------------------------*/

#include "Player.h"
#include <iostream>

Player::Player(int start, int dest)
{
    startingNode = start;
    destination = dest;
}

Player::~Player()
{

}

int Player::getStart()
{
	return startingNode;
}

int Player::getDestination()
{
	return destination;
}

void Player::printInfo()
{
	std::cout << getStart() << "->" << getDestination() << std::endl;
}
