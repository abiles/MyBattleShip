#pragma once

class Ship;
class Aircraft;
class BattleShip;
class Cruiser;
class Destroyer;


class Player
{
public:
	//배 추가시 벡터에 넣어줘야 하므로 생성자를 봐야함
	Player();
	~Player();


	void PrintShips();
	bool CheckValidPos(char, char, int, std::vector<Ship>::iterator);
	void AssignShips();


private:

	Aircraft* m_Aircraft;
	BattleShip* m_BattleShip;
	Cruiser* m_Cruiser;
	Destroyer* m_Destroyer;

	std::vector<Ship*> m_ShipVector;
};

