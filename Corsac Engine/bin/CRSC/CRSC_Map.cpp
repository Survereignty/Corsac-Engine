#include "CRSC_Map.h"
#include "ECS/ECS.h"
#include "ECS/Components.h"

extern Manager manager;

CRSC_Map::CRSC_Map(const char* path, int ms, int ts) : path(path), scale(ms), tileSize(ts)
{
	scaledSize = ms * ts;
}
CRSC_Map::~CRSC_Map()
{

}

void CRSC_Map::Load(std::string path, int sizeX, int sizeY)
{
	char c;
	std::fstream mapFile;
	mapFile.open(path);

	int srcX, srcY;

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(c);
			srcY = atoi(&c) * tileSize;
			mapFile.get(c);
			srcX = atoi(&c) * tileSize;
			AddTile(srcX, srcY, x * scaledSize, y * scaledSize);
			mapFile.ignore();
		}
	}

	mapFile.ignore();

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(c);
			if (c == '1')
			{
				auto& tcol(manager.addEntity());
				tcol.addComponent<Collider>("terrain", x * scaledSize, y * scaledSize, scaledSize);
				tcol.addGroup(Game::Colliders);
			}
			mapFile.ignore();
		}
	}

	mapFile.close();
}

void CRSC_Map::AddTile(int srcX, int srcY, int x, int y)
{
	auto& tile(manager.addEntity());
	tile.addComponent<Tile>(srcX, srcY, x, y, tileSize, scale, path);
	tile.addGroup(Game::Map);
}
