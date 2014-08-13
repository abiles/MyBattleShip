#pragma once

#include "EnumHeader.h"

class Player;
class Ship;

class GameManager
{
public:
	GameManager();
	~GameManager();

	void InitGame();
	void EndGame();

	void DeliverPlayerAttack(ShipPos playerAttackPos);
	void ShowAttackResult();
	void InformAttackStateFromDef();

private:
	Player* m_Attaker;
	Player* m_Defender;
	AttackState m_AttackState;
};

