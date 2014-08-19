#pragma once

#include "EnumHeader.h"


class Ship
{
public:
	Ship();
	~Ship();

	int				GetHP(){ return m_HP; }
	bool			SetHP(int);

	std::string		GetName(){ return m_ShipName; }
	bool			SetName(std::string);

	ShipPos			GetPos(int posIdx){ return m_Pos[posIdx]; }
	bool			AddPos(ShipPos, int);
	bool			AddPos(char, char, int);

	int				GetSize(){ return m_Size; }

	ShipType		GetShipType(){ return m_ShipType; }

	bool			IsPosFull();
	bool			OverlapCheck(ShipPos);
	bool			OverlapCheck(char, char);

	void			MakeDir();
	ShipPos			GetDirPos(int);

	void			PrintShipPos();

	virtual HitResult 
					CheckAttack(ShipPos attackedPos);
	void			HitResultApply();

protected:
	int			m_Size;
	int			m_HP;
	ShipType	m_ShipType;
	std::string m_ShipName;
	ShipPos		m_Pos[MAX_SHIP_SIZE];
	ShipPos		m_ShipDir[MAX_DIRECTION];
	
};

