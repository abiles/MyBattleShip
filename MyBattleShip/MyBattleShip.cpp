// MyBattleShip.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Player.h"



int _tmain(int argc, _TCHAR* argv[])
{

	Player Player1;

	Player1.AssignShips();
	Player1.PrintShips();
	Player1.PrintMap();


	
	getchar();
	return 0;
}

