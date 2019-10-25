#include "Game.h"
#include "TextureManager.h"

class Map
{
public:
	Map();
	~Map();

	void loadMap(int arr[25][20]);
	void DrawMap();

private:

	SDL_Rect src, dest;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[25][20];
};