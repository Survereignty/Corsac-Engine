#pragma once
#include <string>

#include "../Game.h"
#include <fstream>
#include <iostream>

class CRSC_Map
{
public:

	CRSC_Map(const char* path, int ms, int ts);
	~CRSC_Map();

	void AddTile(int srcX, int srcY, int x, int y);
	void Load(std::string path, int sizeX, int sizeY);

private:
	const char* path;
	int scale;
	int tileSize;
	int scaledSize;
};

