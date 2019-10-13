#include "Map.h"
#include "TextureManager.h"

int lvl1[20][20] = {

	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,1,1,1,1,1,0,0,0,0 },
	{ 0,0,0,0,0,1,2,2,2,1,1,0,0,0,0 },
	{ 0,0,0,0,0,0,1,1,2,1,1,0,0,0,0 },
	{ 0,0,0,0,0,0,1,1,2,1,1,0,0,0,0 },
	{ 0,0,0,0,0,0,1,1,2,1,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,2,1,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

Map::Map()
{
	dirt = TextureManager::loadTexture("assets/dirt.PNG");
	grass = TextureManager::loadTexture("assets/grass.PNG");
	water = TextureManager::loadTexture("assets/water.PNG");

	loadMap(lvl1);

	src.x = src.y = 0;
	src.h = dest.h = 32;
	src.w = dest.w = 32;

	dest.x = dest.y = 0;


}

void Map::loadMap(int arr[20][20])
{
	for (int row = 0; row < 20; row++) 	
	{
		for (int column = 0; column < 20; column++)
		{
			map[row][column] = arr[row][column];
		}
	
	}
}

void Map::DrawMap()
{
	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 20; column++)
		{
			type = map[row][column];
			
			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(water, src, dest);
				break;
			case 1:
				TextureManager::Draw(grass, src, dest);
				break;
			case 2:
				TextureManager::Draw(dirt, src, dest);
				break;
			default:
				break;
			}
		}

	}
}