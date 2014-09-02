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
	m_ShipVector.push_back(new Aircraft());
	m_ShipVector.push_back(new BattleShip());
	m_ShipVector.push_back(new Cruiser());
	m_ShipVector.push_back(new Destroyer());

	m_PlayerMap = new Map();
	m_OterPlayerMap = new Map();

	
}


Player::~Player()
{
	

	for (auto iterShip = m_ShipVector.begin(); iterShip != m_ShipVector.end();)
	{
		

		if((*iterShip))
		{
			delete (*iterShip);
			*iterShip = nullptr;
			iterShip = m_ShipVector.erase(iterShip);
		}
		else
		{
			iterShip = m_ShipVector.erase(iterShip);
		}
	}

	m_ShipVector.clear();

	delete m_PlayerMap;
	delete m_OterPlayerMap;
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
			//Ÿ���� ��ġ���
			//�� ������ġ �� �������� ũ�⸸ŭ ä�� �ֱ� 
			ValidPosLauchToShip(startX, startY, direction, shipIdx);
			//�ʿ��� ä�� �ֱ� 
			ValidPosSetToMap(startX, startY, direction, shipIdx);
			
			++shipIdx;
		}

	}
	

	return;
}

bool Player::CheckAllShipAssigned()
{

	ShipPos tmpPos = { 0, };
	//��ü �踦 �ٺ��� ���� for��
	//�׻� ��� �踦 �� ���� �Ѵٴ� ������ �ֳ�..

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




void Player::PrintMap()
{
	m_PlayerMap->PrintMapData();

	return;
}

//Map* Player::SubmitMyMapToGM()
//{
//	return m_PlayerMap;
//}

ShipPos Player::SelectPosToAttack()
{
	ShipPos attackPos;

	while (true)
	{

		printf_s("Select Attack Pos X Y: ");
		scanf_s("%c%c", &attackPos.x, 1, &attackPos.y, 1);

		int a = 0;
		while (a != '\n' && a != EOF)
			a = getchar();

		if ((attackPos.x>='a' && attackPos.x<'a' + MAX_HORIZONTAL) &&
			(attackPos.y>='1' && attackPos.y<'1' + MAX_VERTICAL))
		{
			break;
		}
	}
	return attackPos;
}

void Player::SetAttackedPos(ShipPos attackedPos)
{
	m_PosAttackedFromPlayer = attackedPos;

	return;
}

void Player::MarkAttackFromOtherPlayer()
{
	m_PlayerMap->MarkAttackedPos(m_PosAttackedFromPlayer);
	return;
}

void Player::SetAttackedResult()
{
	

	for (std::vector<Ship*>::size_type i = 0; i < m_ShipVector.size(); ++i)
	{
		 m_AttackedResult = m_ShipVector[i]->CheckAttack(m_PosAttackedFromPlayer);
		 if (m_AttackedResult != HIT_NONE)
		 {
			 break;
		 }
	}

	if (m_AttackedResult == HIT_NONE)
	{
		m_AttackedResult = MISS;
	}



	return ;
}

HitResult Player::GetAttackedResult()
{
	return m_AttackedResult;
}

bool Player::IsAllShipDestroyed()
{
	for (char i = 'a'; i < 'a' + MAX_HORIZONTAL; ++i)
	{
		for (char j = '1'; j < '1' + MAX_VERTICAL; ++j)
		{
			if (m_PlayerMap->GetEachPosDataInMap(i, j) == SHIP_LAUNCH)
			{
				return false;
			}
		}
	}

	return true;

}






//ShipPos Player::AttackShip()
//{
//	ShipPos AttackPos;
//
//	AttackPos.x = 'a';
//	AttackPos.y = '1';
//
//	return AttackPos;
//}
//
//AttackState Player::CheckAttackResult(ShipPos attackPos)
//{
//	AttackState tmpState;
//
//	for (int i = 0; i < m_ShipVector.size(); ++i)
//	{
//		tmpState = m_ShipVector[i]->CheckAttack(attackPos);
//		
//		if ( tmpState == HIT || tmpState== DESTROY)
//		{
//			return tmpState;
//		}
//	}
//
//
//	return MISS;
//
//}
//
//void Player::GetAttackResult(AttackState attackState)
//{
//
//}


