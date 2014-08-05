#pragma once
#include "Aircraft.h"

enum Direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	MAX_DIRECTION,
};

class Player
{
public:
	Player();
	~Player();


	void PrintAllShip();
	void AssignShip();


private:

	Aircraft m_Aircraft;
};

