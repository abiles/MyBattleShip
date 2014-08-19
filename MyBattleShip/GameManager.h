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

	void		InitGame();
	void		PlayingGame();
	void		EndGame();

	bool		IsGameEnd();

	void		GetAttackPosFromPlayer();
	ShipPos		DeliverAttackPos();
	void		SetAttackedResultFromDef(HitResult HitResultFromDef);
	HitResult	GetAttackedResultFromDef();
	void		HitResultPrint();

	//HitResult	JudgeAttackResult();


	/*void DeliverPlayerAttack(ShipPos playerAttackPos);
	void ShowAttackResult();
	void InformAttackStateFromDef();*/

private:
	Player* m_Attacker;
	Player* m_Defender;


	

	ShipPos m_AttackPosFromPlayer;
	HitResult m_AttackedResultFromDef;
};

