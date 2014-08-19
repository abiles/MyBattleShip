#include "stdafx.h"
#include "BattleShip.h"
#include "EnumHeader.h"



BattleShip::BattleShip()
{
	m_Size = 4;
	m_HP = 4;
	m_ShipType = BATTLESHIP;
	m_ShipName = "BattleShip";
}


BattleShip::~BattleShip()
{
}

HitResult BattleShip::CheckAttack(ShipPos attackPos)
{
	HitResult result = Ship::CheckAttack(attackPos);

	return (result == DESTROY) ? BATTLESHIP_DESTROY : result;
}
