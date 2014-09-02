#include "stdafx.h"

#include "GameManager.h"

#include "Map.h"
#include "Ship.h"
#include "Player.h"

GameManager::GameManager()
{
	m_Attacker = new Player();
	m_Defender = new Player();
	m_TotalTurnNum = 0;
}


GameManager::~GameManager()
{
	delete m_Attacker;
	delete m_Defender;
}

void GameManager::GetAttackPosFromPlayer()
{
	m_AttackPosFromPlayer = m_Attacker->SelectPosToAttack();

	return;
}

ShipPos GameManager::DeliverAttackPos()
{
	return m_AttackPosFromPlayer;
}

void GameManager::SetAttackedResultFromDef(HitResult HitResultFromDef)
{
	m_AttackedResultFromDef = HitResultFromDef;
	return;
}

HitResult GameManager::GetAttackedResultFromDef()
{
	return m_AttackedResultFromDef;
}

void GameManager::InitGame()
{

	m_Defender->AssignShips();
	m_Defender->PrintShips();
	m_Defender->PrintMap();
}

void GameManager::PlayingGame()
{
	while (!IsGameEnd())
	{
		m_AttackPosFromPlayer = m_Attacker->SelectPosToAttack();
		system("cls");

		//defender가 하는 일을 묶어라?
		//왜? 바로 보이는게 더 나을수도 있다. 
		m_Defender->SetAttackedPos(m_AttackPosFromPlayer);
		m_Defender->MarkAttackFromOtherPlayer();
		m_Defender->SetAttackedResult();
		m_AttackedResultFromDef = m_Defender->GetAttackedResult();
		m_Defender->PrintShips();
		HitResultPrint();
		m_Defender->PrintMap();
		++m_TotalTurnNum;
	}
	
}

bool GameManager::IsGameEnd()
{
	return m_Defender->IsAllShipDestroyed();
}

void GameManager::EndGame(int turnNum)
{
	printf_s("\n");
	printf_s("Game %d's All Ships are Destroyed!!!\n", turnNum); 
	if (turnNum == GAMERUNNUM)
	{
		printf_s("Average attack turnNum = %f", (double)(m_TotalTurnNum / 10));
	}
	m_Defender->GetPlayerMap()->SetMap();
}

void GameManager::HitResultPrint()
{
	printf_s("\n");
	
	switch (m_AttackedResultFromDef)
	{
	case HIT_NONE:
		printf_s("Noting\n");
		break;
	case HIT:
		printf_s("HIT!!\n");
		break;
	case MISS:
		printf_s("MISS!!\n");
		break;
	case DESTROY:
		printf_s("DESTROY!!\n");
		break;
	case AIRCRAFT_DESTROY:
		printf_s("AIRCRAFT_DESTROY\n");
		break;
	case BATTLESHIP_DESTROY:
		printf_s("BATTLESHIP_DESTROY\n");
		break;
	case CRUISER_DESTROY:
		printf_s("CRUISER_DESTROY\n");
		break;
	case DESTROYER_DESTROY:
		printf_s("DESTROYER_DESTROY\n");
		break;
	default:
		break;
	}
	
}

void GameManager::GameRunning()
{
	for (int i = 0; i < GAMERUNNUM; ++i)
	{
		InitGame();
		PlayingGame();
		EndGame(i+1);
	}

}










//void GameManager::DeliverPlayerAttack(ShipPos playerAttackPos)
//{
//	m_AttackState = m_Defender->CheckAttackResult(playerAttackPos);
//}
//
//void GameManager::ShowAttackResult()
//{
//	if (m_AttackState == HIT)
//	{
//		printf_s("HIT\n");
//	}
//	else if (m_AttackState == MISS)
//	{
//		printf_s("MISS\n");
//	}
//	else
//	{
//		printf_s("DESTROY\n");
//	}
//}
//
//void GameManager::InformAttackStateFromDef()
//{
//	m_Attaker->
//}
