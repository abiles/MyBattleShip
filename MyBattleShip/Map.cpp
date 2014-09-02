#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	initMap();
}


Map::~Map()
{
}

void Map::initMap()
{
	m_Map = new int*[MAX_HORIZONTAL];

	for (int i = 0; i < MAX_HORIZONTAL; ++i)
	{
		m_Map[i] = new int[MAX_VERTICAL];
		memset(m_Map[i], 0, sizeof(int)*MAX_VERTICAL);
	}
	return;
}

int Map::GetEachPosDataInMap(char x, char y )
{
	ShipPos tmpShipPos;
	tmpShipPos.x = x;
	tmpShipPos.y = y;

	return GetEachPosDataInMap(tmpShipPos);
}

int Map::GetEachPosDataInMap(ShipPos shipPos)
{
	

	int tmpData = m_Map[shipPos.x - 'a'][shipPos.y - '1'];

	return tmpData;
}

void Map::SetEachPosDataInMap(char x, char y)
{
	ShipPos tmpShipPos;
	tmpShipPos.x = x;
	tmpShipPos.y = y;

	SetEachPosDataInMap(tmpShipPos);
	return;
}

void Map::SetEachPosDataInMap(ShipPos shipPos)
{
	m_Map[shipPos.x - 'a'][shipPos.y - '1'] = SHIP_LAUNCH;

	return;
}

void Map::PrintMapData()
{

	printf_s("\n");
	for (int i = 0; i < MAX_HORIZONTAL; ++i)
	{
		for (int j = 0; j < MAX_VERTICAL; ++j)
		{
			printf_s("%d ", m_Map[i][j]);
		}
		printf_s("\n");
	}
}

void Map::MarkAttackedPos(ShipPos AttackedPos)
{
	m_Map[AttackedPos.x-'a'][AttackedPos.y-'1'] = 2;

	//맞은 부분을 0으로 바꾸지 말고 맞았다는 표시를 할 수 있게 하자. 
	return;
}

void Map::MarkAttackedPos(char x, char y)
{
	ShipPos tmpAttackedPos;
	tmpAttackedPos.x = x;
	tmpAttackedPos.y = y;
	MarkAttackedPos(tmpAttackedPos);
}
