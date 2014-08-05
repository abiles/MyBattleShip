#include "stdafx.h"
#include "Player.h"
#include <vector>
#include <time.h>


Player::Player()
{
	m_ShipVector.push_back(m_Aircraft);
	m_ShipVector.push_back(m_BattleShip);
}


Player::~Player()
{
}

void Player::PrintShips()
{
	m_Aircraft.PrintShipPos();
}

bool Player::CheckValidPos(char startX, char startY, int direction, std::vector<Ship>::iterator Iter)
{

	//1�ܰ� �������� ������ ���� �ʴ��� Ȯ��

	if (direction == NORTH)
	{
		if (startY - Iter->GetSize() >= '1')
		{
			//������
		}
	}
	else if (direction == EAST)
	{

		if (startX + Iter->GetSize() <= 'h')
		{
			//����
		}
	}
	else if (direction == SOUTH)
	{
		if (startY + Iter->GetSize() <= '8')
		{
			//��
		}
	}
	else if (direction == WEST)
	{
		if (startX - Iter->GetSize() >= 'a')
		{
			//��
		}
	}
	else
	{
		printf_s("Wrong Direction\n");
		return false;
	}

	////////2�ܰ� �ٸ� �迡 Ȥ�� ��� �ִ� ������ Ȯ��
}



void Player::AssignShips()
{
	srand(time(NULL));

	while (!m_ShipVector.empty())
	{
		std::vector<Ship>::iterator shipIter = m_ShipVector.begin();

		char startX = rand() % 8 + 'a';
		char startY = rand() % 8 + '1';
		int direction = rand() % MAX_DIRECTION;

		



	}
}


