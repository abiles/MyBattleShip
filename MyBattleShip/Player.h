#pragma once
#include "Aircraft.h"
#include "BattleShip.h"


class Player
{
public:
	Player();
	~Player();


	void PrintShip();
	


private:

	Aircraft m_Aircraft;
	BattleShip m_BattleShip;
};

