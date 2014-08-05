#include "stdafx.h"
#include "Ship.h"


Ship::Ship()
{
	memset(m_Pos, 0, sizeof(ShipPos)*m_Size);
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

void Ship::PrintShipPos()
{
	
	printf_s("%s : ", m_ShipName.c_str());

	for (int i = 0; i < m_Size; i++)
	{
		if (m_Pos[i].x == 0)
		{
			break;
		}
		printf_s("%c%c\t", m_Pos[i].x, m_Pos[i].y);
	}

	printf_s("\n");
	return;
	
}
