#pragma once
#include "Ship.h"


class BattleShip :
	public Ship
{
public:
	BattleShip();
	~BattleShip();


	HitResult CheckAttack(ShipPos attackPos);
};

