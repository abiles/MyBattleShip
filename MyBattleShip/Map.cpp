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
	int tmpData = m_Map[x-'a'][y-'1'];

	return tmpData;
}

void Map::SetEachPosDataInMap(char x, char y)
{
	m_Map[x - 'a'][y - '1'] = SHIP_LAUNCH;

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
