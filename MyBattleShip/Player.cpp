#include "stdafx.h"
#include "Player.h"
#include <time.h>


Player::Player()
{
}


Player::~Player()
{
}

void Player::PrintAllShip()
{
	m_Aircraft.PrintShipPos();
}

void Player::AssignShip()
{
	//일단 랜덤으로 시작 포인트 2개와 방향을 얻는다. 
	//첫번째 배에 배치할 수 있는지 본다. 
}
