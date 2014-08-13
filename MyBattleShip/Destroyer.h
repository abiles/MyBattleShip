#pragma once
#include "Ship.h"
#include "EnumHeader.h"
class Destroyer :
	public Ship
{
public:
	Destroyer();
	~Destroyer();

	AttackState CheckAttack(ShipPos attackPos);
};

