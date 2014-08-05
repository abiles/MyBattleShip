#pragma once

#include <string>
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

	int GetSize(){ return m_Size; }

	ShipType GetShipType(){ return m_ShipType; }

	bool IsPosFull();
	bool OverlapCheck(ShipPos);

	void PrintShipPos();

protected:
	ShipType m_ShipType;
	int m_Size;
	int m_HP;
	std::string m_ShipName;
	ShipPos m_Pos[MAX_SHIP_SIZE];
};

