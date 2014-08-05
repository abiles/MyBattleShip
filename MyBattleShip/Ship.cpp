#include "stdafx.h"
#include "Ship.h"


Ship::Ship()
{
}


Ship::~Ship()
{
}

bool Ship::SetHP(int inputHP)
{
	if (inputHP < 0)
	{
		return false;
	}

	m_HP = inputHP;

	return true;
}

bool Ship::SetName(std::string inputStr)
{
	if (inputStr.empty())
	{
		return false;
	}

	m_ShipName = inputStr;

	return true;
}

bool Ship::SetPos(ShipPos inputPos, int posIdx)
{
	if (!inputPos.x || !inputPos.y)
	{
		return false;
	}

	m_Pos[posIdx] = inputPos;

	return true;

}
