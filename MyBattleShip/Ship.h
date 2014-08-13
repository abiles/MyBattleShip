#pragma once


#define MAX_SHIP_SIZE 5

enum ShipDirection
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	MAX_DIRECTION,
};


enum ShipType 
{
	SHIP_NONE,
	AIRCRAFT,
	BATTLESHIP,
	CRUISER,
	DESTROYER,

};

enum AttackState
{
	HIT,
	MISS,
	DESTROY,
};


struct ShipPos
{
	char x;
	char y;
};

class Ship
{
public:
	Ship();
	~Ship();

	int GetHP(){ return m_HP; }
	bool SetHP(int);

	std::string GetName(){ return m_ShipName; }
	bool SetName(std::string);

	ShipPos GetPos(int posIdx){ return m_Pos[posIdx]; }
	bool AddPos(ShipPos, int);
	bool AddPos(char, char, int);

	int GetSize(){ return m_Size; }

	ShipType GetShipType(){ return m_ShipType; }

	bool IsPosFull();
	bool OverlapCheck(ShipPos);
	bool OverlapCheck(char, char);

	void MakeDir();
	ShipPos GetDirPos(int);

	void PrintShipPos();

	AttackState CheckAttack(ShipPos attackPos);
	void HitResultApply();

protected:
	ShipType m_ShipType;
	int m_Size;
	int m_HP;
	std::string m_ShipName;
	ShipPos m_Pos[MAX_SHIP_SIZE];
	ShipPos m_ShipDir[MAX_DIRECTION];
	
};

