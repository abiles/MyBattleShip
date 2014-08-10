#include "stdafx.h"
#include "Player.h"
#include "Aircraft.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"



Player::Player()
{
	m_ShipVector.push_back(m_Aircraft);
	m_ShipVector.push_back(m_BattleShip);
	m_ShipVector.push_back(m_Cruiser);
	m_ShipVector.push_back(m_Destroyer);
}


Player::~Player()
{
}

void Player::PrintShips()
{
	std::vector<Ship>::iterator printIter = m_ShipVector.begin();

	while (printIter != m_ShipVector.end())
	{
		printIter->PrintShipPos();
		printIter++;
	}

	return;

}

bool Player::CheckValidPos(char startX, char startY, int direction, std::vector<Ship>::iterator Iter)
{
	std::vector<Ship>::iterator findIter;
	//1�ܰ� �������� ������ ���� �ʴ��� Ȯ��

	if (direction == NORTH)
	{
		if (startY - Iter->GetSize() +1 < '1')
		{
			return false;
		}

		//2�ܰ� �Է��Ϸ��� X Y���� ���Ͽ�  �ٸ� �迡 ���� X Y�� �������� �ʴ��� �ľ�
		for (int i = 0; i < Iter->GetSize(); i++)
		{
			for (findIter = m_ShipVector.begin(); findIter != m_ShipVector.end(); ++findIter)
			{
				if (findIter->OverlapCheck(startX, startY))
				{
					return false;
				}
			}
			
			//�� ���� ��ġ�� ���ؼ� ��� �� ã�ƺ��� ���ؼ� 
			startY--;
		}
	}
	else if (direction == EAST)
	{

		if (startX + Iter->GetSize() - 1 > 'h')
		{
			return false;
		}

		for (int i = 0; i < Iter->GetSize(); i++)
		{
			for (findIter = m_ShipVector.begin(); findIter != m_ShipVector.end(); ++findIter)
			{
				if (findIter->OverlapCheck(startX, startY))
				{
					return false;
				}
			}

			
			startX++;
		}
	}
	else if (direction == SOUTH)
	{
		if (startY + Iter->GetSize() - 1 > '8')
		{
			return false;
		}

		for (int i = 0; i < Iter->GetSize(); i++)
		{
			for (findIter = m_ShipVector.begin(); findIter != m_ShipVector.end(); ++findIter)
			{
				if (findIter->OverlapCheck(startX, startY))
				{
					return false;
				}
			}

			startY++;
		}
	}
	else if (direction == WEST)
	{
		if (startX - Iter->GetSize() + 1 < 'a')
		{
			return false;
		}

		for (int i = 0; i < Iter->GetSize(); i++)
		{
			for (findIter = m_ShipVector.begin(); findIter != m_ShipVector.end(); ++findIter)
			{
				if (findIter->OverlapCheck(startX, startY))
				{
					return false;
				}
			}

			startX--;
		}

	}
	else
	{
		printf_s("Wrong Direction\n");
		return false;
	}

	

	

	return true;

}



void Player::AssignShips()
{
	srand((unsigned int)time(NULL));
	std::vector<Ship>::iterator shipIter = m_ShipVector.begin();

	while (shipIter != m_ShipVector.end())
	{

		char startX = rand() % 8 + 'a';
		char startY = rand() % 8 + '1';
		int direction = rand() % MAX_DIRECTION;

		//printf_s("%d\n", startX + shipIter->GetSize());
		
		if (CheckValidPos(startX, startY, direction, shipIter))
		{
			//Ÿ���� ��ġ ���
			//�� ������ġ �� �������� ũ�⸸ŭ ä�� �ֱ� 
			
			if (direction == NORTH)
			{

				for (int i = 0; i < shipIter->GetSize(); i++)
				{
					shipIter->AddPos(startX, startY, i);
					startY--;
				}
			}
			else if (direction == EAST)
			{
				for (int i = 0; i < shipIter->GetSize(); i++)
				{
					shipIter->AddPos(startX, startY, i);
					startX++;
				}
			}
			else if (direction == SOUTH)
			{
				for (int i = 0; i < shipIter->GetSize(); i++)
				{
					shipIter->AddPos(startX, startY, i);
					startY++;
				}
			}
			else
			{

				for (int i = 0; i < shipIter->GetSize(); i++)
				{
					shipIter->AddPos(startX, startY, i);
					startX--;
				}
			}

			shipIter++;
		}

	}

	return;
}


