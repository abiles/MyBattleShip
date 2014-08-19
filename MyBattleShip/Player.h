#pragma once

#include "EnumHeader.h"
class Ship;

class Map;

class Player
{
public:
	//배 추가시 벡터에 넣어줘야 하므로 생성자를 봐야함
	Player();
	~Player();

	

	//배치
	void AssignShips();
	bool CheckAllShipAssigned();
	bool CheckValidPos(char startX, char startY, int direction, int shipIdx);
	bool CheckLastPointFine(char startX, char startY, int direction, int shipIdx);
	bool CheckOtherShipOverlap(char startX, char startY, int direction, int shipIdx);
	void ValidPosLauchToShip(char startX, char startY, int direction, int shipIdx);
	void ValidPosSetToMap(char startX, char startY, int direction, int shipIdx);

	//맵 제출
	//Map* SubmitMyMapToGM();

	//프린트
	void PrintShips();
	void PrintMap();

	//공격
	ShipPos SelectPosToAttack();

	//방어
	void		 SetAttackedPos(ShipPos attackedPos);
	void		 MarkAttackFromOtherPlayer();
	void		 SetAttackedResult();
	HitResult	 GetAttackedResult();
	bool		 IsAllShipDestroyed();
	/*ShipPos AttackShip();

	void GetAttackResult(AttackState attackState);*/

private:


	Map*					m_PlayerMap;
	Map*					m_OterPlayerMap;
	ShipPos					m_PosAttackedFromPlayer;
	std::vector<Ship*>		m_ShipVector;
	HitResult				m_AttackedResult;
};

