#pragma once
#include "Ship.h"
#include "EnumHeader.h"

class BattleShip :
	public Ship
{
public:
	BattleShip();
	~BattleShip();


	AttackState CheckAttack(ShipPos attackPos);
};

