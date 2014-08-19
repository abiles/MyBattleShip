
#pragma once

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


enum HitResult
{
	HIT_NONE,
	HIT,
	MISS,
	DESTROY,
	AIRCRAFT_DESTROY,
	BATTLESHIP_DESTROY,
	CRUISER_DESTROY,
	DESTROYER_DESTROY,
};

struct ShipPos
{
	char x;
	char y;
};


#define MAX_SHIP_SIZE 5

#define MAX_HORIZONTAL 8
#define MAX_VERTICAL 8
#define SHIP_LAUNCH 1