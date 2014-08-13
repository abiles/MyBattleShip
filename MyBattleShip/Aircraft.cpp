#include "stdafx.h"
#include "Aircraft.h"


Aircraft::Aircraft()
{
	m_ShipName = "Aircraft";
	m_ShipType = AIRCRAFT;
	m_Size = 5;
	m_HP = 5;
	
}


Aircraft::~Aircraft()
{

}

AttackState Aircraft::CheckAttack(ShipPos attackPos)
{
	AttackState result = Ship::CheckAttack(attackPos);

	return (result == DESTROY) ? AIRCRAFT_DESTROY : result;
}
