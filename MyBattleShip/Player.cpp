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
	//1단계 끝지점이 지도를 넘지 않는지 확인

	if (direction == NORTH)
	{
		if (startY - Iter->GetSize() +1 < '1')
		{
			return false;
		}

		//2단계 입력하려는 X Y값에 대하여  다른 배에 같은 X Y가 존재하지 않는지 파악
		for (int i = 0; i < Iter->GetSize(); i++)
		{
			for (findIter = m_ShipVector.begin(); findIter != m_ShipVector.end(); ++findIter)
			{
				if (findIter->OverlapCheck(startX, startY))
				{
					return false;
				}
			}
			
			//그 다음 위치에 대해서 모든 배 찾아보기 위해서 
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
			//타당한 위치 라면
			//이 시작위치 이 방향으로 크기만큼 채워 넣기 
			
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


