#include "stdafx.h"
#include "BattleShip.h"


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

AttackState BattleShip::CheckAttack(ShipPos attackPos)
{
	AttackState result = Ship::CheckAttack(attackPos);

	return (result == DESTROY) ? BATTLESHIP_DESTROY : result;
}
