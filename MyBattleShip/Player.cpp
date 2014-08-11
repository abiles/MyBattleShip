#include "stdafx.h"
#include "Map.h"
#include "Ship.h"
#include "Player.h"
#include "Aircraft.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"



Player::Player()
{
	initMember();
	m_ShipVector.push_back(m_Aircraft);
	m_ShipVector.push_back(m_BattleShip);
	m_ShipVector.push_back(m_Cruiser);
	m_ShipVector.push_back(m_Destroyer);
}


Player::~Player()
{
	delMember();
}

void Player::PrintShips()
{

	for (std::vector<Ship*>::size_type i = 0; i < m_ShipVector.size(); ++i)
	{
		m_ShipVector[i]->PrintShipPos();
	}

	return;

}


bool Player::CheckValidPos(char startX, char startY, int direction, int shipIdx)
{
	//std::vector<Ship>::iterator findIter;
	//1�ܰ� �������� ������ ���� �ʴ��� Ȯ��

	if (!CheckLastPointFine(startX, startY, direction, shipIdx))
	{
		return false;
	}

	if (CheckOtherShipOverlap(startX, startY, direction, shipIdx))
	{
		return false;
	}

	return true;

}



void Player::AssignShips()
{
	srand((unsigned int)time(NULL));

	
	int shipIdx = 0;

	

	while (!CheckAllShipAssigned())
	{

		char startX = rand() % MAX_HORIZONTAL + 'a';
		char startY = rand() % MAX_VERTICAL + '1';
		int direction = rand() % MAX_DIRECTION;

		
		if (CheckValidPos(startX, startY, direction, shipIdx))
		{
			//Ÿ���� ��ġ ���
			//�� ������ġ �� �������� ũ�⸸ŭ ä�� �ֱ� 
			//�ʿ��� ä�� �ֱ� 
			ValidPosLauchToShip(startX, startY, direction, shipIdx);
			ValidPosSetToMap(startX, startY, direction, shipIdx);
			
			shipIdx++;
		}

	}

	return;
}

bool Player::CheckAllShipAssigned()
{

	ShipPos tmpPos = { 0, };
	//��ü �踦 �ٺ��� ���� for��
	for (std::vector<Ship*>::size_type i = 0; i < m_ShipVector.size(); ++i)
	{
		//������ �踶�� ��� �������� Ȯ���ϱ� ���� for��
		for (int j = 0; j < m_ShipVector[i]->GetSize(); ++j)
		{
			tmpPos = m_ShipVector[i]->GetPos(j);
			if (tmpPos.x == 0 || tmpPos.y == 0)
			{
				return false;
			}
		}
	}

	return true;
}

bool Player::CheckLastPointFine(char startX, char startY, int direction, int shipIdx)
{
	
	m_ShipVector[shipIdx]->MakeDir();

	for (int i = 0; i < m_ShipVector[shipIdx]->GetSize(); ++i)
	{
		startX += m_ShipVector[shipIdx]->GetDirPos(direction).x;
		startY += m_ShipVector[shipIdx]->GetDirPos(direction).y;
	}

	if (startX < 'a' || startX > 'a' + MAX_HORIZONTAL)
	{
		return false;
	}
	if (startY <'1' || startY > '1' + MAX_VERTICAL)
	{
		return false;
	}
		
	return true;
}


bool Player::CheckOtherShipOverlap(char startX, char startY, int direction, int shipIdx)
{
	m_ShipVector[shipIdx]->MakeDir();

	for (int i = 0; i < m_ShipVector[shipIdx]->GetSize(); ++i)
	{
		if (m_PlayerMap->GetEachPosDataInMap(startX, startY) != 0)
		{
			return true;
		}

		startX += m_ShipVector[shipIdx]->GetDirPos(direction).x;
		startY += m_ShipVector[shipIdx]->GetDirPos(direction).y;

	}

	return false;
	
}

void Player::ValidPosLauchToShip(char startX, char startY, int direction, int shipIdx)
{
	m_ShipVector[shipIdx]->MakeDir();

	for (int i = 0; i < m_ShipVector[shipIdx]->GetSize(); ++i)
	{
		m_ShipVector[shipIdx]->AddPos(startX, startY, i);
		startX += m_ShipVector[shipIdx]->GetDirPos(direction).x;
		startY += m_ShipVector[shipIdx]->GetDirPos(direction).y;
	}

	return;
}

void Player::ValidPosSetToMap(char startX, char startY, int direction, int shipIdx)
{
	m_ShipVector[shipIdx]->MakeDir();

	for (int i = 0; i < m_ShipVector[shipIdx]->GetSize(); ++i)
	{
		m_PlayerMap->SetEachPosDataInMap(startX, startY);
		startX += m_ShipVector[shipIdx]->GetDirPos(direction).x;
		startY += m_ShipVector[shipIdx]->GetDirPos(direction).y;
	}

	return;
}

void Player::initMember()
{
	m_Aircraft = new Aircraft;
	m_BattleShip = new BattleShip;
	m_Cruiser = new Cruiser;
	m_Destroyer = new Destroyer;
	m_PlayerMap = new Map;

	return;
}

void Player::delMember()
{
	delete m_Aircraft;
	delete m_BattleShip;
	delete m_Cruiser;
	delete m_Destroyer;
	delete m_PlayerMap;

	return;

}

void Player::PrintMap()
{
	m_PlayerMap->PrintMapData();

	return;
}


