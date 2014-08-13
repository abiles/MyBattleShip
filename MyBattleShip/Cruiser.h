#pragma once
#include "Ship.h"
#include "EnumHeader.h"
class Cruiser :
	public Ship
{
public:
	Cruiser();
	~Cruiser();
	
	AttackState CheckAttack(ShipPos attackPos);
};

