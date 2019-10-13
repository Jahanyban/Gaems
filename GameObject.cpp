#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::loadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void GameObject::Update()
{
	xpos++;
	ypos = 0;

	srcRect.h = 42;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = xpos;
	destRect.y = ypos;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}