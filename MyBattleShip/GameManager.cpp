#include "stdafx.h"
#include "GameManager.h"

#include "Ship.h"
#include "Player.h"

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::DeliverPlayerAttack(ShipPos playerAttackPos)
{
	m_AttackState = m_Defender->CheckAttackResult(playerAttackPos);
}

void GameManager::ShowAttackResult()
{
	if (m_AttackState == HIT)
	{
		printf_s("HIT\n");
	}
	else if (m_AttackState == MISS)
	{
		printf_s("MISS\n");
	}
	else
	{
		printf_s("DESTROY\n");
	}
}

void GameManager::InformAttackStateFromDef()
{
	m_Attaker->
}
