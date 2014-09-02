#pragma once

#include "EnumHeader.h"


class Map
{
public:
	Map();
	~Map();

public:
	void initMap();
	void SetMap();
	void PrintMapData();
	int GetEachPosDataInMap(ShipPos shipPos);
	int GetEachPosDataInMap(char x, char y);

	void SetEachPosDataInMap(ShipPos shipPos);
	void SetEachPosDataInMap(char x, char y);

	void MarkAttackedPos(ShipPos AttackedPos);
	void MarkAttackedPos(char x, char y);

protected:
	int** m_Map;
};

