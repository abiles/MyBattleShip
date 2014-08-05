#pragma once
#include "Aircraft.h"
#include "BattleShip.h"
#include <vector>


class Player
{
public:
	Player();
	~Player();


	void PrintShips();
	bool CheckValidPos(char, char, int, std::vector<Ship>::iterator);
	void AssignShips();


private:

	Aircraft m_Aircraft;
	BattleShip m_BattleShip;

	std::vector<Ship> m_ShipVector;
};

