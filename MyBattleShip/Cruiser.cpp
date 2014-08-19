#include "stdafx.h"
#include "Cruiser.h"


Cruiser::Cruiser()
{
	m_ShipName = "Cruiser ";
	m_ShipType = CRUISER;
	m_Size = 3;
	m_HP = 3;
}


Cruiser::~Cruiser()
{
}

HitResult Cruiser::CheckAttack(ShipPos attackPos)
{
	HitResult result = Ship::CheckAttack(attackPos);

	return (result == DESTROY) ? CRUISER_DESTROY : result;
}
