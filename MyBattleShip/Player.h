#pragma once

class Ship;
class Aircraft;
class BattleShip;
class Cruiser;
class Destroyer;


class Player
{
public:
	//�� �߰��� ���Ϳ� �־���� �ϹǷ� �����ڸ� ������
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

