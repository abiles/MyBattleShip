#pragma once

#include "EnumHeader.h"
class Ship;

class Map;

class Player
{
public:
	//�� �߰��� ���Ϳ� �־���� �ϹǷ� �����ڸ� ������
	Player();
	~Player();

	

	//��ġ
	void AssignShips();
	bool CheckAllShipAssigned();
	bool CheckValidPos(char startX, char startY, int direction, int shipIdx);
	bool CheckLastPointFine(char startX, char startY, int direction, int shipIdx);
	bool CheckOtherShipOverlap(char startX, char startY, int direction, int shipIdx);
	void ValidPosLauchToShip(char startX, char startY, int direction, int shipIdx);
	void ValidPosSetToMap(char startX, char startY, int direction, int shipIdx);

	//�� ����
	//Map* SubmitMyMapToGM();

	//����Ʈ
	void PrintShips();
	void PrintMap();

	//����
	ShipPos SelectPosToAttack();

	//���
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

