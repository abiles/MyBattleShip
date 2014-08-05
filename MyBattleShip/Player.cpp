#include "stdafx.h"
#include "Player.h"
#include <time.h>


Player::Player()
{
}


Player::~Player()
{
}

void Player::PrintShip()
{
	m_Aircraft.PrintShipPos();
}

