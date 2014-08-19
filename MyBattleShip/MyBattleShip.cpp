// MyBattleShip.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Player.h"
#include "GameManager.h"


int _tmain(int argc, _TCHAR* argv[])
{

	GameManager g1;

	g1.InitGame();
	g1.PlayingGame();



	
	getchar();
	return 0;
}

