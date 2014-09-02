#pragma once
#include "EnumHeader.h"


class Player;
class Ship;
class Map;

class GameManager
{
public:
	GameManager();
	~GameManager();

	bool		IsGameEnd();

	void		GetAttackPosFromPlayer();
	ShipPos		DeliverAttackPos();
	void		SetAttackedResultFromDef(HitResult HitResultFromDef);
	HitResult	GetAttackedResultFromDef();
	void		HitResultPrint();

	void		GameRunning();

private:
	void		InitGame();
	void		PlayingGame();
	void		EndGame(int turnNum);


	//HitResult	JudgeAttackResult();


	/*void DeliverPlayerAttack(ShipPos playerAttackPos);
	void ShowAttackResult();
	void InformAttackStateFromDef();*/

private:

	Player*		m_Attacker;
	Player*		m_Defender;

	int			m_TotalTurnNum;
	ShipPos		m_AttackPosFromPlayer;
	HitResult	m_AttackedResultFromDef;
};

