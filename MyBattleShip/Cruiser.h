#pragma once
#include "Ship.h"
#include "EnumHeader.h"
class Cruiser :
	public Ship
{
public:
	Cruiser();
	~Cruiser();
	
	HitResult CheckAttack(ShipPos attackPos);
};

