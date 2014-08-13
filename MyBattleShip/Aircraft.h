#pragma once
#include "Ship.h"
#include "EnumHeader.h"

class Aircraft :
	public Ship
{
public:
	Aircraft();
	~Aircraft();

	AttackState CheckAttack(ShipPos attackPos);
};

