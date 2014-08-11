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
	//1단계 끝지점이 지도를 넘지 않는지 확인

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
			//타당한 위치 라면
			//이 시작위치 이 방향으로 크기만큼 채워 넣기 
			//맵에도 채워 넣기 
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
	//전체 배를 다보기 위한 for문
	for (std::vector<Ship*>::size_type i = 0; i < m_ShipVector.size(); ++i)
	{
		//각각의 배마다 모든 포지션을 확인하기 위한 for문
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


