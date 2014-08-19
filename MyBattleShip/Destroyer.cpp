#include "stdafx.h"
#include "Destroyer.h"


Destroyer::Destroyer()
{
	m_ShipName = "Destroyer";
	m_ShipType = DESTROYER;
	m_Size = 2;
	m_HP = 2;
}


Destroyer::~Destroyer()
{
}

HitResult Destroyer::CheckAttack(ShipPos attackPos)
{
	HitResult result = Ship::CheckAttack(attackPos);

	return (result == DESTROY) ? DESTROYER_DESTROY : result;
}
