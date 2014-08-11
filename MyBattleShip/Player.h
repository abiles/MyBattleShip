#pragma once

class Ship;
class Aircraft;
class BattleShip;
class Cruiser;
class Destroyer;
class Map;

class Player
{
public:
	//배 추가시 벡터에 넣어줘야 하므로 생성자를 봐야함
	Player();
	~Player();


	void PrintShips();
	void PrintMap();
	bool CheckAllShipAssigned();
	bool CheckValidPos(char, char, int, int);
	bool CheckLastPointFine(char, char, int, int);
	bool CheckOtherShipOverlap(char, char, int, int);
	void initMember();
	void delMember();
	void AssignShips();
	void ValidPosLauchToShip(char, char, int, int);
	void ValidPosSetToMap(char, char, int, int);

private:

	Aircraft* m_Aircraft;
	BattleShip* m_BattleShip ;
	Cruiser* m_Cruiser;
	Destroyer* m_Destroyer;

	Map* m_PlayerMap;
	std::vector<Ship*> m_ShipVector;
};

