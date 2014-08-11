#pragma once

#define MAX_HORIZONTAL 8
#define MAX_VERTICAL 8
#define SHIP_LAUNCH 1

class Map
{
public:
	Map();
	~Map();

public:
	void initMap();
	void PrintMapData();
	int GetEachPosDataInMap(char, char);
	void SetEachPosDataInMap(char, char);

protected:
	int** m_Map;
};

