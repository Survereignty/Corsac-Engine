#include "CRSC_Map.h"

CRSC_Map::CRSC_Map()
{

}
CRSC_Map::~CRSC_Map()
{

}

void CRSC_Map::Load(std::string path, int sizeX, int sizeY)
{
	char tile;
	std::fstream mapFile;
	mapFile.open(path);

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(tile);
			std::cout << atoi(&tile) << std::endl;
			Game::AddTile(atoi(&tile), x * 32, y * 32);
			mapFile.ignore();
		}
	}
	mapFile.close();
}
